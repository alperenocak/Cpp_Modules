#!/bin/bash
set -e

# Kullanım:
# ./push42.sh cpp03
# Eğer argüman verilmezse MODULE içinden okur.

MODULE="${1:-cpp05}"
REMOTE_42="$MODULE"          # 42 remote'u (cpp01, cpp02 vs.)
REMOTE_GITHUB="origin"       # GitHub remote'u
BRANCH="main"

# GitHub için verified commit için global config ayarları
GITHUB_USER_NAME="alperenocak"
GITHUB_USER_EMAIL="yusufalperenocak10@gmail.com"

echo "========================================"
echo "  git push helper for 42 & GitHub"
echo "========================================"
echo "MODULE        : $MODULE"
echo "REMOTE (42)   : $REMOTE_42"
echo "REMOTE (GH)   : $REMOTE_GITHUB"
echo "BRANCH        : $BRANCH"
echo "----------------------------------------"

# Global git config ayarla (verified commit için)
echo "🔧 Setting global git config for verified commits..."
git config --global user.name "$GITHUB_USER_NAME"
git config --global user.email "$GITHUB_USER_EMAIL"
echo "✅ Global config set: $GITHUB_USER_NAME <$GITHUB_USER_EMAIL>"
echo "----------------------------------------"

# 1) Prefix klasörü var mı?
if [ ! -d "$MODULE" ]; then
  echo "❌ ERROR: '$MODULE' klasörü bulunamadı."
  echo "📌 Mevcut modüller:"
  ls -d cpp* 2>/dev/null || true
  exit 1
fi

# 2) 42 Remote var mı?
if ! git remote | grep -qx "$REMOTE_42"; then
  echo "❌ ERROR: '$REMOTE_42' remote'u yok."
  echo "📌 Mevcut remoteler:"
  git remote -v
  exit 1
fi

# 3) Working tree temiz mi? (özellikle module içinde)
echo "🔎 Checking changes inside '$MODULE/' ..."
CHANGES_IN_MODULE=$(git status --porcelain -- "$MODULE" | wc -l | tr -d ' ')
if [ "$CHANGES_IN_MODULE" -gt 0 ]; then
  echo "⚠️  '$MODULE/' içinde commitlenmemiş değişiklik var!"
  git status --porcelain -- "$MODULE"
  echo
  echo "✅ Çözüm:"
  echo "   git add $MODULE"
  echo "   git commit -m \"$MODULE: update\""
  echo "   ./push42.sh $MODULE"
  exit 1
else
  echo "✅ '$MODULE/' içinde commitlenmemiş değişiklik yok."
fi

# 4) Module'a dokunan son commitleri göster
echo
echo "🧾 Last commits touching '$MODULE/':"
git log --oneline -- "$MODULE" | head -5 || true

# ==========================================
# GITHUB'A PUSH (Ana repo)
# ==========================================
echo
echo "========================================"
echo "🐙 GITHUB'A PUSH"
echo "========================================"

echo "🌍 Fetching from GitHub..."
git fetch "$REMOTE_GITHUB" "$BRANCH" >/dev/null 2>&1 || true

LOCAL_HEAD=$(git rev-parse HEAD 2>/dev/null || echo "")
GITHUB_HEAD=$(git rev-parse "$REMOTE_GITHUB/$BRANCH" 2>/dev/null || echo "")

if [ "$GITHUB_HEAD" = "$LOCAL_HEAD" ]; then
  echo "✅ GitHub zaten güncel: $REMOTE_GITHUB/$BRANCH == $LOCAL_HEAD"
else
  echo "🚀 Pushing to GitHub..."
  git push "$REMOTE_GITHUB" "$BRANCH"
  echo "✅ GitHub push completed!"
fi

# ==========================================
# 42'YE SUBTREE PUSH
# ==========================================
echo
echo "========================================"
echo "🎓 42'YE SUBTREE PUSH"
echo "========================================"

# 5) Split commit üret
echo "🔨 Creating subtree split commit..."
SPLIT_COMMIT=$(git subtree split --prefix="$MODULE")

if [ -z "$SPLIT_COMMIT" ]; then
  echo "❌ ERROR: subtree split başarısız oldu."
  exit 1
fi

echo "✅ Split commit: $SPLIT_COMMIT"

# 6) Remote branch'te aynı commit var mı?
echo
echo "🌍 Fetch remote branch..."
git fetch "$REMOTE_42" "$BRANCH" >/dev/null 2>&1 || true

REMOTE_HEAD=$(git rev-parse "$REMOTE_42/$BRANCH" 2>/dev/null || echo "")

if [ "$REMOTE_HEAD" = "$SPLIT_COMMIT" ]; then
  echo "✅ 42 Remote zaten güncel: $REMOTE_42/$BRANCH == $SPLIT_COMMIT"
  echo "➡️  Push gerekmiyor (No new revisions)."
else
  # 7) Push to 42
  echo
  echo "🚀 Pushing subtree to 42..."
  echo "git push using: $REMOTE_42 $BRANCH"
  git push "$REMOTE_42" "$SPLIT_COMMIT:refs/heads/$BRANCH"
  echo "✅ 42 push completed!"
fi

echo
echo "========================================"
echo "✅ ALL DONE!"
echo "   📦 $MODULE -> GitHub ($REMOTE_GITHUB)"
echo "   🎓 $MODULE -> 42 ($REMOTE_42)"
echo "========================================"

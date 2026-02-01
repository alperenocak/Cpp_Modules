#!/bin/bash
set -e

# Kullanım:
# ./push42.sh cpp02
# Eğer argüman verilmezse MODULE içinden okur.

MODULE="${1:-cpp02}"
REMOTE="$MODULE"
BRANCH="main"

echo "========================================"
echo "  git subtree push helper for 42"
echo "========================================"
echo "MODULE : $MODULE"
echo "REMOTE : $REMOTE"
echo "BRANCH : $BRANCH"
echo "----------------------------------------"

# 1) Prefix klasörü var mı?
if [ ! -d "$MODULE" ]; then
  echo "❌ ERROR: '$MODULE' klasörü bulunamadı."
  echo "📌 Mevcut modüller:"
  ls -d cpp* 2>/dev/null || true
  exit 1
fi

# 2) Remote var mı?
if ! git remote | grep -qx "$REMOTE"; then
  echo "❌ ERROR: '$REMOTE' remote'u yok."
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

# 5) Split commit üret
echo
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
git fetch "$REMOTE" "$BRANCH" >/dev/null 2>&1 || true

REMOTE_HEAD=$(git rev-parse "$REMOTE/$BRANCH" 2>/dev/null || echo "")

if [ "$REMOTE_HEAD" = "$SPLIT_COMMIT" ]; then
  echo "✅ Remote zaten güncel: $REMOTE/$BRANCH == $SPLIT_COMMIT"
  echo "➡️  Push gerekmiyor (No new revisions)."
  exit 0
fi

# 7) Push
echo
echo "🚀 Pushing subtree..."
echo "git push using: $REMOTE $BRANCH"
git push "$REMOTE" "$SPLIT_COMMIT:refs/heads/$BRANCH"

echo
echo "✅ DONE: $MODULE -> $REMOTE/$BRANCH pushed successfully."

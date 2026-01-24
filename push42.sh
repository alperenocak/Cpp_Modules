#!/bin/bash
set -e

MODULE="cpp01"
REMOTE="fortytwo"
BRANCH="main"

git subtree push --prefix="$MODULE" "$REMOTE" "$BRANCH"


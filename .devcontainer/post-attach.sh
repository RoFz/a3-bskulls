#!/usr/bin/env bash
# Runs each time VS Code attaches to the container (after extensions are installed).

# Fix SQFLint's java.js which uses -jar and relies on a manifest Class-Path with
# Windows backslashes that Java on Linux cannot resolve. Replace with explicit -cp.
SQFLINT_JS=$(find /home/vscode/.vscode-server/extensions -path "*/skacekachna.sqflint-*/client/server/java.js" 2>/dev/null | head -1)
if [ -n "$SQFLINT_JS" ] && grep -q '"\-jar"' "$SQFLINT_JS"; then
    sed -i 's|return child\.spawn(this\.getCallPath(), \["-Dfile\.encoding=UTF-8", "-jar", jar\]\.concat(args));|const libDir = require("path").join(require("path").dirname(jar), "lib"); const cp = [jar, require("path").join(libDir, "commonscli.jar"), require("path").join(libDir, "json.jar")].join(require("path").delimiter); return child.spawn(this.getCallPath(), ["-Dfile.encoding=UTF-8", "-cp", cp, "cz.zipek.sqflint.SQFLint"].concat(args));|' "$SQFLINT_JS"
    echo "[post-attach] Patched SQFLint java.js for Linux classpath compatibility."
fi

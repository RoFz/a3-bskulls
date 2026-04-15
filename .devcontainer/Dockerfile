FROM mcr.microsoft.com/devcontainers/base:ubuntu

RUN mkdir -p /home/vscode/.claude /home/vscode/.codex /home/vscode/.vscode-server \
    && chown vscode:vscode /home/vscode/.claude /home/vscode/.codex /home/vscode/.vscode-server \
    && chmod 777 /home/vscode/.vscode-server

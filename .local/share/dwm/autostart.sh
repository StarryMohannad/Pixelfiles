#!/bin/sh

setsid -f syncthing serve --no-browser # Syncthing for Syncing Files

setsid -f dwmblocks # DWMBlocks for Status
setsid -f picom # Compositor

setsid -f mpDris2 # MPD Dris Compatiblity

setsid -f emacs --daemon # Emacs Daemon

setsid -f "$DWM"/scripts/keepassxc.sh

setsid -f "$DWM"/scripts/volume-tracker.sh

"$DWM"/scripts/wallpaper.sh
setsid -f mpv --no-video "$HOME"/.local/share/sounds/startup.mp3

#!/bin/sh

setsid -f syncthing serve --no-browser # Syncthing for Syncing Files

setsid -f dwmblocks # DWMBlocks for Status
setsid -f xcompmgr # Compositor

setsid -f mpDris2 # MPD Dris Compatiblity

setsid -f "$DWM"/scripts/dwm/startup/keepassxc.sh

"$DWM"/scripts/dwm/startup/wallpaper.sh
setsid -f mpv --no-video "$HOME"/.local/share/sounds/startup.mp3

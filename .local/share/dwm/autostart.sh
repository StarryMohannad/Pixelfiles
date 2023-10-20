#!/bin/sh

setsid -f syncthing serve --no-browser # Syncthing for Syncing Files

setsid -f dwmblocks # DWMBlocks for Status
setsid -f picom # Compositor

setsid -f mpDris2 # MPD Dris Compatiblity

setsid -f emacs --daemon # Emacs Daemon

xwallpaper --stretch "$DWM"/wallpaper.png # Sets the Wallpaper

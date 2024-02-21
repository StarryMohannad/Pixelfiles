#!/bin/bash

FileName="$(date '+%Y%m%d%H%M%S.png')"

setsid -f mpv --no-video ~/.local/share/sounds/menu1.mp3
shotgun -g "$(hacksaw)" ~/Sync/Pictures/Screenshots/"$FileName"
xclip -selection clipboard -t image/png -i ~/Sync/Pictures/Screenshots/"$FileName"
setsid -f mpv --no-video ~/.local/share/sounds/prtsc.mp3
notify-send "Rectangle Screenshot taken" "'$FileName' is now in the clipboard"

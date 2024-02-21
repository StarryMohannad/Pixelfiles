#!/bin/bash

FileName="$(date '+%Y%m%d%H%M%S.png')"

shotgun -s ~/Sync/Pictures/Screenshots/"$FileName"
xclip -selection clipboard -t image/png -i ~/Sync/Pictures/Screenshots/"$FileName"
setsid -f mpv --no-video ~/.local/share/sounds/prtsc.mp3
notify-send "Full Screenshot taken" "'$FileName' is now in the clipboard"

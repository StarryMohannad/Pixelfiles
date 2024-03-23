#!/bin/sh

# pamixer -d 5
$DWM/scripts/dwm/hotkeys/volume-changer.sh down
setsid -f mpv --no-video /usr/share/sounds/freedesktop/stereo/bell.oga

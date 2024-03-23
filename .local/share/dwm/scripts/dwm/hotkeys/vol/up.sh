#!/bin/sh

$DWM/scripts/dwm/hotkeys/volume-changer.sh up
setsid -f mpv --no-video /usr/share/sounds/freedesktop/stereo/bell.oga

#!/bin/sh

$DWM/scripts/dwm/hotkeys/volume-changer.sh mute
setsid -f mpv --no-video /usr/share/sounds/freedesktop/stereo/bell.oga

#!/bin/sh

pamixer -i 5
setsid -f mpv --no-video /usr/share/sounds/freedesktop/stereo/bell.oga

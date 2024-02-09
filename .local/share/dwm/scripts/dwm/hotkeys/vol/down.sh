#!/bin/sh

pamixer -d 5
setsid -f mpv --no-video /usr/share/sounds/freedesktop/stereo/bell.oga

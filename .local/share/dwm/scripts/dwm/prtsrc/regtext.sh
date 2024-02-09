#!/bin/sh

setsid -f mpv --no-video ~/.local/share/sounds/menu1.mp3

shotgun -g "$(hacksaw)" "/tmp/regtext-screenshot.png"
tesseract /tmp/regtext-screenshot.png /tmp/regtext-text
/bin/cat /tmp/regtext-text.txt | xsel -b

rm -rf /tmp/regtext-*

setsid -f mpv --no-video ~/.local/share/sounds/menu2.mp3
notify-send "Text Coppied from Region" "the text is now in the clipboard"

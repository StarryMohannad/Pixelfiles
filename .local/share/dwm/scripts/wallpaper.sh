#!/bin/sh

WallpaperChoice="$(/bin/ls -1 ~/.local/share/wallpapers | shuf -n 1)"
wal -i "$HOME"/.local/share/wallpapers/"$WallpaperChoice"
wpg -a "$HOME"/.local/share/wallpapers/"$WallpaperChoice"
wpg -s "$HOME"/.local/share/wallpapers/"$WallpaperChoice"
pywal-discord -p "$HOME"/.config/Vencord/themes
xdotool key Super+F5
cp -r "$HOME"/.cache/wall/colors.css /tmp/pywal-pixelfiles-colors.css
cp -r "$HOME"/.cache/wall/colors.scss /tmp/pywal-pixelfiles-colors.scss

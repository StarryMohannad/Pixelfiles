#!/bin/bash

mkdir -p "$HOME"/.config
mkdir -p "$HOME"/.local/share

PF_DIR="$HOME"/.local/pf
PF_SOURCE="$PF_DIR"/src
PF_CONFIG="$PF_DIR"/.config
PF_LOCAL="$PF_DIR"/.local

# Installing Paru
sudo pacman -S --needed base-devel
git clone https://aur.archlinux.org/paru.git /tmp/paru
cd /tmp/paru
makepkg -si

# Installing Packages
paru -S shotgun hacksaw xwallpaper \
    coreutils wget curl\
    xcompmgr\
    kpmenu xsel\
    mpv zathura\
    upower alsa-utils\
    bat btop cava zoxide eza\
    glibc harfbuzz libx11 libxft libxinerama\
    fontconfig freetype2 ttf-dejavu ttf-firacode-nerd\
    xorg xorg-xinit\
    nwg-look-bin kvantum\
    catppuccin-cursors-macchiato papirus-folders-catppuccin-git catppuccin-gtk-theme-macchiato\
    zsh starship zsh-autosuggestions zsh-syntax-highlighting\
    lf ueberzug perl-file-mimeinfo\
    mpd mpc ncmpcpp mpd-discord-rpc mpDris2 playerctl\
    emacs ripgrep fd

# Building Suckless Tools
cd "$PF_SOURCE"/dwm
sudo make clean install

cd "$PF_SOURCE"/dwmblocks
sudo make clean install

cd "$PF_SOURCE"/st
sudo make clean install

cd "$PF_SOURCE"/dmenu
sudo make clean install

cd "$PF_SOURCE"/sxiv
sudo make clean install

# Linking Configs
ln -s "$PF_CONFIG"/bat             "$HOME"/.config/bat
ln -s "$PF_CONFIG"/btop            "$HOME"/.config/btop
ln -s "$PF_CONFIG"/cava            "$HOME"/.config/cava
ln -s "$PF_CONFIG"/doom            "$HOME"/.config/doom
ln -s "$PF_CONFIG"/dunst           "$HOME"/.config/dunst
ln -s "$PF_CONFIG"/discord-rpc     "$HOME"/.config/discord-rpc
ln -s "$PF_CONFIG"/firefox         "$HOME"/.config/firefox
ln -s "$PF_COFNIG"/git             "$HOME"/.config/git
ln -s "$PF_CONFIG"/gtk-2.0         "$HOME"/.config/gtk-2.0
ln -s "$PF_CONFIG"/gtk-3.0         "$HOME"/.config/gtk-3.0
ln -s "$PF_CONFIG"/heroicthemes    "$HOME"/.config/heroicthemes
ln -s "$PF_CONFIG"/kpmenu          "$HOME"/.config/kpmenu
ln -s "$PF_CONFIG"/Kvantum         "$HOME"/.config/Kvantum
ln -s "$PF_CONFIG"/lf              "$HOME"/.config/lf
ln -s "$PF_CONFIG"/mpd             "$HOME"/.config/mpd
ln -s "$PF_CONFIG"/mpv             "$HOME"/.config/mpv
ln -s "$PF_CONFIG"/npm             "$HOME"/.config/npm
ln -s "$PF_CONFIG"/sxiv            "$HOME"/.config/sxiv
ln -s "$PF_CONFIG"/X11             "$HOME"/.config/X11
ln -s "$PF_CONFIG"/zathura         "$HOME"/.config/zathura
ln -s "$PF_CONFIG"/zsh             "$HOME"/.config/zsh

ln -s "$PF_CONFIG"/picom.conf      "$HOME"/.config/picom.conf
ln -s "$PF_CONFIG"/starship.toml   "$HOME"/.config/starship.toml

ln -s "$PF_LOCAL"/share/sounds     "$HOME"/.local/share/sounds
ln -s "$PF_LOCAL"/share/dwm        "$HOME"/.local/share/dwm

cp -r "$PF_CONFIG"/pf              "$HOME"/.config/pf

# Installing Doom Emacs
git clone --depth 1 https://github.com/doomemacs/doomemacs ~/.config/emacs
~/.config/emacs/bin/doom install

# Themeing
papirus-folders -C cat-macchiato-blue --theme Papirus-Dark
bat cache --build

# Finishing Up
echo 'export ZDOTDIR="$HOME"/.config/zsh' | sudo tee -a /etc/zsh/zshenv
chsh -s /bin/zsh

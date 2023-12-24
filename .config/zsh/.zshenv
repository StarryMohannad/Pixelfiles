# Default Apps
export BROWSER="firefox"
export TERMINAL="st"
export EDITOR="nvim"
export MENU="dmenu -z 525 -i -p"

# XDG-DIRS
export XDG_DATA_HOME="$HOME"/.local/share
export XDG_CONFIG_HOME="$HOME"/.config
export XDG_STATE_HOME="$HOME"/.local/state
export XDG_CACHE_HOME="$HOME"/.cache

export DWM="$XDG_DATA_HOME"/dwm

# CleanUP
export XAUTHORITY="$XDG_RUNTIME_DIR"/Xauthority
export CARGO_HOME="$XDG_DATA_HOME"/cargo
export HISTFILE="${XDG_STATE_HOME}"/bash/history
export GNUPGHOME="$XDG_DATA_HOME"/gnupg
export GTK2_RC_FILES="$XDG_CONFIG_HOME"/gtk-2.0/gtkrc
export NPM_CONFIG_USERCONFIG="$XDG_CONFIG_HOME"/npm/npmrc
export W3M_DIR="$XDG_DATA_HOME"/w3m
export LESSHISTFILE="-"
export XCURSOR_PATH=/usr/share/icons:${XDG_DATA_HOME}/icons
export RUSTUP_HOME="$XDG_DATA_HOME"/rustup
export _JAVA_OPTIONS=-Djava.util.prefs.userRoot="$XDG_CONFIG_HOME"/java
export LESSHISTFILE="$XDG_CACHE_HOME"/less/history
export XINITRC="$XDG_CONFIG_HOME"/X11/xinitrc
export XAUTHORITY="$XDG_RUNTIME_DIR"/Xauthority
export SSB_HOME="$XDG_DATA_HOME"/zoom
export WINEPREFIX="$XDG_DATA_HOME"/wine

# Theme
export QT_STYLE_OVERRIDE="kvantum"
export XCURSOR_THEME="Catppuccin-Macchiato-Dark-Cursors"
export BAT_THEME="Catppuccin-macchiato"

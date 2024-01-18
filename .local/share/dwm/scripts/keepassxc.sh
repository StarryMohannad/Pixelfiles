#!/bin/bash

source "$XDG_CONFIG_HOME"/pf/shell-config.sh

setsid -f keepassxc
sleep 1
dbus-send --print-reply --dest=org.keepassxc.KeePassXC.MainWindow /keepassxc org.keepassxc.KeePassXC.MainWindow.openDatabase string:"$KeePassDB" string:"$KeePassPW" string:""


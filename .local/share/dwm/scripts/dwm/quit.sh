#!/bin/sh

setsid -f mpv --no-video "$XDG_DATA_HOME"/sounds/menu1.mp3
choice="$(printf "Power Off\nReboot\nLock\nClose DWM\nExit" | ${MENU} 'Bye :D' )"

case "$choice" in
    "Power Off")
        poweroff
    ;;

    "Reboot")
        reboot
    ;;

    "Lock")
        slock
    ;;

    "Close DWM")
        killall dwm
    ;;

    "Exit")
        return 0
    ;;
esac

setsid -f mpv --no-video "$XDG_DATA_HOME"/sounds/menu2.mp3

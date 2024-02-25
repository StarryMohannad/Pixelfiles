if [[ "$(tty)" = "/dev/tty1" ]] ; then
    startx
fi

export PATH="$HOME"/.local/bin:$PATH

export HISTFILE="$ZDOTDIR"/zshistory
export HISTSIZE=10000
export SAVEHIST=10000
setopt HIST_IGNORE_ALL_DUPS
setopt HIST_FIND_NO_DUPS

autoload -Uz compinit
compinit -d "$XDG_CACHE_HOME"/zsh/zcompdump-"$ZSH_VERSION"

source "$ZDOTDIR"/zshalias
source "$ZDOTDIR"/zshplugins
eval "$(starship init zsh)"

export NVM_DIR="$HOME/.local/share/nvm"
[ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh"  # This loads nvm
[ -s "$NVM_DIR/bash_completion" ] && \. "$NVM_DIR/bash_completion"  # This loads nvm bash_completion
export PATH="$HOME"/.local/share/npm/bin:$PATH

export DENO_INSTALL=""$HOME"/.local/share/deno"
export PATH="$DENO_INSTALL/bin:$PATH"

bindkey -v
eval "$(zoxide init zsh)"

export PATH="$XDG_DATA_HOME"/cargo/bin:$PATH
export PATH="$XDG_DATA_HOME"/gem/ruby/3.0.0/bin:$PATH

eval "$(/home/linuxbrew/.linuxbrew/bin/brew shellenv)"

_zlf() {
    emulate -L zsh
    local d=$(mktemp -d) || return 1
    {
        mkfifo -m 600 $d/fifo || return 1
        tmux split -bf zsh -c "exec {ZLE_FIFO}>$d/fifo; export ZLE_FIFO; exec ~/.local/share/dwm/scripts/bin/lfub" || return 1
        local fd
        exec {fd}<$d/fifo
        zle -Fw $fd _zlf_handler
    } always {
        rm -rf $d
    }
}
zle -N _zlf
bindkey '\ek' _zlf

_zlf_handler() {
    emulate -L zsh
    local line
    if ! read -r line <&$1; then
        zle -F $1
        exec {1}<&-
        return 1
    fi
    eval $line
    zle -R
}
zle -N _zlf_handler

if [ "$TMUX" = "" ]; then tmux && exit; fi

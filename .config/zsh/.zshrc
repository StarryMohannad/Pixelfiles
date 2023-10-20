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

export DENO_INSTALL=""$HOME"/.local/share/deno"
export PATH="$DENO_INSTALL/bin:$PATH"

bindkey -v
eval "$(zoxide init zsh)"


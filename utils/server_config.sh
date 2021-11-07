#to use ssh on a new device or when server is new/reset
#ssh-keyscan -t ecdsa my.server.domain >> ~/.ssh/known_hosts

#yum install git
#yum install vim

if [ -d "~/.oh-my-zsh" ]; then
	echo "Installing oh my zsh"
	sh -c "$(curl -fsSL https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"
	echo "Installed!"
else
	echo "Hai oh my zsh installato! Doing nothing..."
fi

FILE="/Users/dmangola/.zshrc"

#annamaria aggiunge gli alias alla fine del file .zshrc nella home, se ci sono già, non fa niente
function annamaria() {
	if grep -q "$1" $FILE; then
		echo "$1 found! doing nothing..."
	else
		echo $1 >> $FILE
	fi
}

annamaria "alias lista='ls -G'"
annamaria "alias cambia='/usr/bin/cd'"
annamaria "alias cartella='pwd'"
annamaria "alias cerca='/usr/bin/grep'"
annamaria "alias contaparola='/usr/bin/wc'"
annamaria "alias gatto='/usr/bin/git'"
annamaria "alias quale='/usr/bin/which'"
annamaria "alias norma='/usr/bin/norminette'"
annamaria "alias urla='/bin/echo'"
annamaria "alias gita='git add *'"
annamaria "alias gitc='git commit -m'"
annamaria "alias gitp='git push'"
annamaria "alias gitl='git pull'"
annamaria "alias gitd='git diff'"
annamaria "alias gitb='git branch'"
annamaria "alias di='say -v luca'"
annamaria "alias spazio='du -sh * | sort -hr | head -n10'"
annamaria "alias py3='python3.9'"


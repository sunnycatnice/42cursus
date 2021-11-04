#annamaria aggiunge gli alias alla fine del file .zshrc nella home
FILE="/Users/dmangola/.zshrc"

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
annamaria "alias spazio='du -sh * | sort -hr | head -n10'"

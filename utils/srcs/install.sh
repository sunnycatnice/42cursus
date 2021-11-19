#!/bin/zsh
#DO NOT RUN THIS SCRIPT DIRECTLY, RUN config.sh INSTEAD

FILE_ZSHRC="$HOME/.zshrc"
FILE_ZSHRC_TXT="srcs/zshrc.txt"
FILE_VIMRC="$HOME/.vimrc"
FILE_VIMRC_TXT="srcs/vimrc.txt"

#install vim
if [ -d "~/.vimrc" ]; then
	echo "Installing vim"
	apt-get install vim
	echo "Installed!"
else
	echo "Hai vim installato! Doing nothing..."
fi

#function that reads from check if FILE_ZSHRC is present, if not, it creates it
function check_zsh() {
	if [ -f $FILE_ZSHRC ]; then
		echo "File $FILE_ZSHRC found!"
	else
		echo "File $FILE_ZSHRC not found! Creating it..."
		touch $FILE_ZSHRC
		echo "File $FILE_ZSHRC created!"
	fi
}

#funzione che controlla se il file FILE_VIMRC è presente, se non lo è, lo crea
function check_vimrc() {
	if [ -f $FILE_VIMRC ]; then
		echo "File $FILE_VIMRC found!"
	else
		echo "File $FILE_VIMRC not found! Creating it..."
		touch $FILE_VIMRC
		echo "File $FILE_VIMRC created!"
	fi
}

#annamaria aggiunge gli alias alla fine del file .zshrc nella home, se ci sono già, non fa niente
function annamaria() {
	if grep -q "$1" $FILE_ZSHRC; then
		echo "$1 found! doing nothing..."
	else
		echo $1 >> $FILE_ZSHRC
	fi
}

#annabella aggiunge al file FILE_VIMRC le impostazioni di VIM, se ci sono già, non fa niente
function annabella() {
	if grep -q "$1" $FILE_VIMRC; then
		echo "$1 found! doing nothing..."
	else
		echo $1 >> $FILE_VIMRC
	fi
}


#funzione che legge linea per linea il file FILE_ZSHRC_TXT e lo copia in FILE_ZSHRC, se la linea è presente nel file FILE_ZSHRC, non fa niente
function copy_zsh() {
	while read line; do
		if grep -q "$line" $FILE_ZSHRC; then
			echo "$line found! doing nothing..."
		else
			echo $line >> $FILE_ZSHRC
		fi
	done < $FILE_ZSHRC_TXT
}

#funzione che legge linea per linea il file FILE_VIMRC_TXT e lo copia in FILE_VIMRC, se la linea è già presente, non fa niente
function copy_vimrc() {
	while read line; do
		if grep -q "$line" $FILE_VIMRC; then
			echo "$line found! doing nothing..."
		else
			echo $line >> $FILE_VIMRC
		fi
	done < $FILE_VIMRC_TXT
}

copy_zsh
copy_vimrc
git config --global user.name "dani-MacOS"
git config --global user.email "sio2guanoeleo@gmail.com"
echo "Git configured!"

exec zsh

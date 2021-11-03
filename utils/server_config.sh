#to use ssh on a new device or when server is new/reset
#ssh-keyscan -t ecdsa my.server.domain >> ~/.ssh/known_hosts

#yum install git
#yum install vim

echo "alias lista='ls -G'" >> ~/.zshrc
echo "alias cambia='/usr/bin/cd'" >> ~/.zshrc
echo "alias cartella='pwd'" >> ~/.zshrc
echo "alias cerca='/usr/bin/grep'" >> ~/.zshrc
echo "alias contaparola='/usr/bin/wc'" >> ~/.zshrc
echo "alias gatto='/usr/bin/git'" >> ~/.zshrc
echo "alias quale='/usr/bin/which'" >> ~/.zshrc
echo "alias norma='/usr/bin/norminette'" >> ~/.zshrc
echo "alias urla='/bin/echo'" >> ~/.zshrc
echo "alias gita='git add *'" >> ~/.zshrc
echo "alias gitc='git commit -m'" >> ~/.zshrc
echo "alias gitp='git push'" >> ~/.zshrc
echo "alias spazio='du -sh * | sort -hr | head -n10'">> ~/.zshrc

if [ -d "~/.oh-my-zsh" ]; then
	echo "Installing oh my zsh"
	sh -c "$(curl -fsSL https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"
	echo "Installed!"
else
	echo "Hai oh my zsh installato! Doing nothing..."
fi

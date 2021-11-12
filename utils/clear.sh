#!/bin/zsh

FILE_RM="./srcs/rm.txt"
test="$HOME/Libary/Caches/*"

rm -f $test

#function that reads from FILE_RM and removes the files
function remove_files() {
	while read line; do
		rm -rf $line
		echo "Removed $line"
	done < $FILE_RM
}


remove_files

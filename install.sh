#!/bin/sh 

echo "1: Default"
echo "2: Desert"
echo "3: Doxy"
echo "4: Moon"
echo "5: TTY-Support ( Designed to work with TTY Session users )"


printf "Please Pick a Style?(1) "

read style_id 

if [ -z $style_id ] || [ $style_id = "1" ] 
then
	Style=default
elif [ $style_id = "2" ] 
then
	Style=desert
elif [ $style_id = "3" ] 
then
	Style=doxy
elif [ $style_id = "4" ] 
then
	Style=moon
elif [ $style_id = "5" ] 
then
	Style=tty-support
else
	echo "Error: $style_id is not an option"
	exit 1
fi


printf "\nDo you want to install Local or Global?[L G] "
read scope

if [ -z $scope ] || [ $scope = "L" ] || [ $scope = "l" ]
then
	echo -e "\nRunning make and installing locally..."
	make mk
	make build STYLE=$Style

	echo -e "\nMD installed locally to ./bin/md man file ./md.1.gz"
elif [ $scope = "G" ] || [ $scope = "g" ]
then
	echo -e "\nRunning make and installing globally..."
	sudo make install STYLE=$Style

	echo -e "\nMD installed globally to /usr/bin/md man file /usr/share/man/man1/md.1.gz document files /usr/doc/md/"
else 
	echo "Error: $scope is not an option"
	exit 1
fi

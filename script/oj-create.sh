#!/usr/bin/env bash

if [ $# -lt 1 ];
then
	echo "Please tell me the target folder."
	exit
fi

if [ -d "${1}" ];
then
	echo "The directory is existing."
	exit
fi

cp ~/.local/oj-template/cpp_template ${1} -r
cd ${1}
ln -s ~/.local/oj-template/algo_template .
mv main.cpp main.cpp.bk
echo "/*" >> main.cpp
echo " * author: weissle" >> main.cpp
TMP=`date "+%c"`
echo " * create: ${TMP}" >> main.cpp
echo "*/" >> main.cpp
cat main.cpp.bk >> main.cpp
rm main.cpp.bk

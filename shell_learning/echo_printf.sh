#!/bin/bash
read name
echo $name it is a test

echo -e "OK! \n"
echo "it is a test"
echo -e "OK! \c" #²»»»ÐÐ
echo "it is a test"

myfile=$(dirname $0)
myfile=${myfile}/tmp.txt
echo $myfile
file="/home/cidi/Desktop/Learning/shell_learning/tmp.txt"
if [ -e $file ]; then
    echo "file exit"
else
    echo "file do not exit"
fi
echo "it is a test" >$file
echo $(pwd)

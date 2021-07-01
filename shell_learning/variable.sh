#!/bin/bash

var="renjie"
var=$(ls ~)
echo $var
for skill in Ada coffe Action Jave;do
    echo "I am good at ${skill}"
done

readonly var
#var='file2'

var1='file1'
unset var1 

var2="this is a string ${var}"
echo ${var2}
var2='this is a string ${var}'
echo ${var2}

string="abcde"
echo ${#string}

string="renjie is a good man"
echo ${string:0:6}

echo `expr index "$string" i`

array_name=($var $var1 $var2)
echo ${array_name[0]}
echo ${#array_name[0]}

index=0
echo $index
echo ${array_name[index]}

name="renjie"
str="hello,I know you are \"$name\"! \n"
echo -e $str

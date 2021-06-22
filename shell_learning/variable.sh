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

string="runoob is a great site"
echo ${string:1:4}

echo `expr index "$string" i`

array_name=($var $var1 $var2)
echo ${#array_name[@]}
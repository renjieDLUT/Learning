#!/usr/bin
array=(A B "C" D)
echo ${array[@]}
echo ${array[0]}
echo ${#array[*]}
echo ${#array[@]}

#operation

val=$(expr 2 + 2)
echo ${val}

a=4
b=3
echo $(expr $a + $b)
echo $(expr $a - $b)
echo $(expr $a \* $b)
echo $(expr $a / $b)
echo $(expr $a % $b)
a=$b
echo $a
[ $a == $b ]
[ $a != $b ]

val=$(expr $a + $b)
echo "a + b : ${val}"
val=$(expr $a - $b)
echo "a - b : ${val}"
val=$(expr $a \* $b)
echo "a \* b : ${val}"
val=$(expr $a / $b)
echo "a / b : ${val}"
if [ $a == $b ]; then
    echo "a == b"
fi

if [ $a != $b ]; then
    echo "a != b"
fi

if [ $a -eq $b ]; then
    echo "a = b "
else
    echo "a != b"
fi

if [ $a -ne $b ]; then
    echo "a != b"
else
    echo "a = b"
fi

if [ $a -eq 3 -o $b -eq 3 ]; then
    echo "true"
else
    echo "false"
fi

# zifuchuan yunsuanfu
a="abc"
b="efg"

if [ $a = $b ]; then
    echo "$a = $b : a 等于 b"
else
    echo "$a = $b: a 不等�? b"
fi
if [ $a != $b ]; then
    echo "$a != $b : a 不等�? b"
else
    echo "$a != $b: a 等于 b"
fi
if [ -z $a ]; then
    echo "-z $a : 字�?�串长度�? 0"
else
    echo "-z $a : 字�?�串长度不为 0"
fi
if [ -n "$a" ]; then
    echo "-n $a : 字�?�串长度不为 0"
else
    echo "-n $a : 字�?�串长度�? 0"
fi
if [ $a ]; then
    echo "$a : 字�?�串不为�?"
else
    echo "$a : 字�?�串为空"
fi

file=$(pwd)
echo $file
if [ -d $file ]; then
    echo "this is a directory"
fi

echo $0
string=$0
n=${#string}
echo $n
str=$(pwd)${string:1:n-1}
echo $str

if [ -e $str ]; then
    echo "have the file: $str"
fi

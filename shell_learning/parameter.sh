#!/usr/bin/env bash
echo "执行的文件名：$0"
echo "文件输入的第一个参数为：$1"
echo $*
echo $?
string=($*)
echo ${#string[@]}

string=("$@")
echo ${#string[@]}
array=(renjie hxj)
echo ${array[$#]}
for i in $*; do
    echo $i
done

for i in $@; do
    echo $i
done
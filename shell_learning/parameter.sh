#!/usr/bin/env bash
echo "ִ�е��ļ�����$0"
echo "�ļ�����ĵ�һ������Ϊ��$1"
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
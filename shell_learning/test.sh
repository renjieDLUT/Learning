num1=10
num2=20
printf "num1:%d, num2=%d\n" $num1 $num2

if test $[num1]  -eq $[num2]
then
		echo " \"test $[num1] -eq $[num2]\": 两个数相等！"
else
		echo "\"test $[num1] -eq $[num2]\": 两个数不相等！"
fi


if test $[num1]  -ne $[num2]
then
		echo " \"test $[num1] -ne $[num2]\": 两个数不相等! "
else
		echo "\"test $[num1] -ne $[num2]\": 两个数相等！"
fi

a=5
b=6
result=`expr $a + $b`
echo "result: $result"

if test ! $num1 = $num2
then
    echo "not equal"
else
    echo "equal"
fi

if [ $a = $b ]
then
    echo "$a = $b "
else
    echo "$a != $b"
fi

cd /bin
if test -e ./bash
then
    echo '文件已存在!'
else
    echo '文件不存在!'
fi

if [ $(ps -ef|grep -c "ssh") -gt 1 ]
then
    echo "true"
fi



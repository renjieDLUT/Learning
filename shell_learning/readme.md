## 1 变量
### 1.1 变量命名的规范



### 1.2 变量的使用

1. 定义一个变量，只要在变量名前加**$**符号
2. 变量名外面尽量加**花括号**，可帮助解释器识别变量的边界
3. 已定义的变量可重新定义
4. 

### 1.3 只读变量
```shell
readonly var
var='other'           #error,  var  是只读变量
```

### 1.4 删除变量
变量被删除后不能再次使用，不能删除只读变量
```shell
var="name"
unset var
```

### 1.5 变量类型

1. 局部变量
2. 环境变量
3. shell变量
### 1.6 shell字符串
字符串可以用**单引号**，也可以**双引号**，也可**不用引号**。
1.**单引号**： 字符串中的变量是无效的；不可以使用转义符“\”
2.**双引号**：可以有变量，可以出现转义符
```shell
name=renjie
var="hello,I know you are \"$name\"! \n"
echo -e $str
```
#### 1.7字符拼接
#### 1.7.1 获取字符串长度
```shell
string="abcde"
echo ${#string}
```
#### 1.7.2 提取字符串
```shell
string="renjie is a good  man"
echo ${string:0:6}  #输出 renjie  0:首位索引值，6:开始提取多少个
```
#### 1.7.3 查找子字符串
```shell
echo `expr index "$string" i`
```
### 1.8 shell数组
只支持一维数组（不支持多维数组）
#### 1.8.1 定义数组
```shell
array_name=("ren" "jie")
```
#### 1.8.2 读取数组
```shell
index=0
echo ${array_name[index]}
echo ${array_name[@]}  #可以获取数组中的所有元素
```
#### 1.8.3 获取数组的长度
```shell
index=0
echo ${#array_name[index]}
```
## 2 传递参数
向脚本传递参数，脚本内获取参数的格式为：$n，n代表第几个参数。
1. n=0，为执行的文件名

```shell
echo "执行的文件名：$0"
```

参数        |                   说明
---------     |                ------
$#           | 传递到脚本的参数个数
$*           | 所有向脚本传递的参数。 <font color=#FF000>“$*”，输出为：“$1 $2 ... $n”</font> 
$$          | 当前进程ID号
$!          |  后台运行的最后一个进程ID号
$@        |  与$*相同，但是使用时加引号，并在引号中返回每个参数。<font color=#FF000>“$@”，输出为：“$1“ ”$2“ ... "、”$n”</font> 
$-          |  显示shell使用的当前选项
$?          |   显示最后命令的退出状态。0表示没有错误，其他任何值表明有错误
```shell
for i in $*; do
    echo $i
done

for i in $@; do
    echo $i
done
```


## 3 shell 数组
只支持一维数组。数组元素的下标由**0**开始。数组由**括号**表示
```shell
array=(A B C D)
```
### 3.1 读取数组
```shell
${array[index]}
```
## 4 shell基本运算符
**注意**：表达式和运算符之间要有空格；使用反引号 " `"，而不是单引号" ' "
```shell
val=`expr 2 + 2`
echo $val    #输出4

val=`expr 2+2`
echo $val   #输出2+2
```
### 4.1 算法运算符
运算符 |说明|举例
:------    |------ |--------
 +    |  加法  |  `expr $a + $b`
 -     |  减法  |  `expr $a - $b`
 *    | 乘法  |  `expr $a \* $b`
 /    |除法   | `expr $a / $b`
 %   |取余   | `expr $a % $b`
 = |  赋值   | a=$b
 ==  |判等   |[ $a == $b ]
 !=  |判不等  | [ $a != $b ]

 **注意**：条件表达式要放在方括号之间，而且要有空格；乘号*前必须加反斜杠 \ 
### 4.2 关系运算符
 运算符 |说明|举例
-------    |------ |--------
-eq |判相等 | [ $a -eq $b ]
-ne |判不相等 | [ $a -ne $b ]
-gt |  大于 | [ $a -gt $b ]
-lt | 小于 | [ $a -lt $b ]
-ge |大于等于 |[ $a -ge $b ]
-le  | 小于等于 | [ $a -le $b ]

### 4.3 布尔运算符
 运算符 |说明|举例
-------    |------ |--------
！   |   非运算|  [ !false ]
-o  |  或    |  [ $a -eq 30 -o $b -ne 30 ]
-a |与   |[ $a -eq 30 -a $b -ne 30 ]
&& | 与 | [ $a -eq 30 && $b -ne 30 ]
\|\| | 或  |[ $a -eq 30 \|\| $b -ne 30 ]  

### 4.4 字符串运算符
运算符 |说明|举例
-------    |------ |--------
=          |字符串是否相等 | [ $a = $b ]
!=  |
-z  | 检测字符串长度是否为0 | [-z $a ]
-n | 检测字符串长度是否不为 0  | [ -n $a ]

### 4.5 文件测试运算符

运算符 |说明|举例
-------       |   ------ |--------
[ -b file ] | 文件是否为块设备文件 | 
[ -c file ]  | 文件是否为字符设备文件 |
[ -d file ]  | 文件是否为目录   |
[ -f file ]  | 文件是否为普通文件 | 
[ -r file ] | 文件是否可读  |
[ -w file ]| 文件是否可写 |
[ -x file ] |文件是否可执行 |
[ -s file ] |文件是否不为空 |
[-e file ] |文件是否存在 |

## echo命令
### 显示变量
```shell
read name 
echo "$name it is a test"
# -e 开启转义
echo -e "OK! \n"  
echo "it is a test"
echo -e "OK! \c"   #不换行
echo "it is a test"
```
### 显示结果定向至文件
```shell

echo "it is a test" >$file
```

## printf命令
printf使用引用文本或空格分隔的参数，外面可以在printf中使用格式化字符串，还可以制定字符串的宽度和左右对齐方式等。默认printf不会像echo自动添加换行符，需手动添加‘\n’ 。
```shell
printf format-string   [arguments ...]

# format-string: 格式控制字符串
# arguments: 为参数列表
```
```shell
printf "%-10s %-8s %-4s\n" 姓名 性别 体重kg
printf "%-10s %-8s %-4s\n"任杰 男 62kg
```
**%s %c %d %f**: 格式替代符
格式替代符 | 说明
------------- |----------
%s    | 输出一个字符串
%d    | 输出整型
%c    | 输出一个字符
%f     | 输出实数  （浮点型）
%-10s | 字符串的**宽度**为10  （**‘ - ’ 表示左对齐，没有则表示右对齐**）
%-4.2f |格式化小数，其中**‘ .2 ’**指保留2位小数

```shell
# format-string为双引号
printf "%d %s\n" 1 "abc"

# 单引号与双引号效果一样
printf '%d %s\n' 1 "abc"

# 没有引号也可以输出
printf %s abcdef

# 格式只指定了一个参数，但多出的参数仍然会按照该格式输出，format-string 被重用
printf %s abc def

printf "%s\n" abc def

printf "%s %s %s\n" a b c d e f g h i j

# 如果没有 arguments，那么 %s 用NULL代替，%d 用 0 代替
printf "%s and %d \n"
```

## test命令
test命令用于检查某个条件是否成立，可以进行数值、字符和文件
### 数值测试
参数   |  说明
------ |--------
-eq   | **等于** 则为真
-ne   |**不等**与则为真
-gt   | **大于**则为真
-ge  | **大于等于**则为真
-lt    | **小于**则为真
-le | **小于等于**则为真

```python
if test $[num1]  -eq $[num2]
then
		echo "两个数相等！"
else
		echo "两个数不相等！"
fi
```

### 字符串测试
参数  |说明
------ | ---------
=      | 等于
!=    | 不等于
-z 字符串| 字符串的长度为零
-n 字符串|字符串的长度不为零

```python
num1="ru1noob"
num2="runoob"
if test $num1 = $num2
then
    echo '两个字符串相等!'
else
    echo '两个字符串不相等!'
fi
```
### 文件测试
参数                |说明
-------------------|--------
-e 文件名        |文件存在
-r 文件名        |

## 流程控制
### if-else
```shell
if condition
then
		command1
		command2
		...
		commandn
fi
```
```shell
if  [ $(ps -ef |grep -c "ssh") -gt 1 ]; then echo "true";fi
```
### if-elif-else
```shell
if condition1
then 
		command11
		command12
		...
		command1n
elif condition2
then
		command21
		command22
		...
		command2n
else
		command31
fi
```
### for 循环
```shell
for var in item1 item2 ... itemN
do
		command1
		command2
		...
		commandN
done
```
### while语句
```shell
while condition
do
		command
done
```
```shell
int=1
while ( (  $int<=5 ) )
do
	echo $int
	let "int++"
done
```
### 无限循环
```shell
while ：
do
	command
done
```

### until循环
```shell
until condition
do
		command
done
```
### case ... esac
```shell
echo '输入 1 到 4 之间的数字:'
echo '你输入的数字为:'
read aNum
case $aNum in
    1)  echo '你选择了 1'
    ;;
    2)  echo '你选择了 2'
    ;;
    3)  echo '你选择了 3'
    ;;
    4)  echo '你选择了 4'
    ;;
    *)  echo '你没有输入 1 到 4 之间的数字'
    ;;
esac
```
### 跳出循环（break命令、continue命令）
```shell
while :
do
    echo -n "输入 1 到 5 之间的数字:"
    read aNum
    case $aNum in
        1|2|3|4|5) echo "你输入的数字为 $aNum!"
        ;;
        *) echo "你输入的数字不是 1 到 5 之间的! 游戏结束"
            break
        ;;
    esac
done
```
```shell
while :
do
    echo -n "输入 1 到 5 之间的数字: "
    read aNum
    case $aNum in
        1|2|3|4|5) echo "你输入的数字为 $aNum!"
        ;;
        *) echo "你输入的数字不是 1 到 5 之间的!"
            continue
            echo "游戏结束"
        ;;
    esac
done
```

## 函数
linux shell 可以用户定义函数，然后在shell脚本中随便调用。
```shell
[ function ] funname [()]
{
		action
		[ return int ]
}
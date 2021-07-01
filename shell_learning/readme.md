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
$*           | 所有向脚本传递的参数 
$$          | 当前进程ID号
$!          |  后台运行的最后一个进程ID号
$@        |  与$*相同，但是使用时加引号，并在引号中返回每个参数。
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


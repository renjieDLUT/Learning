## 简介
一种**解释型**，**交互式**，**面向对象**的语言
### 编码
```python 
# -*- coding:cp-1252 -*-
```
### 标识符
### 保留字
```python
>>> import keyword
>>> keyword.kwlist

['False', 'None', 'True', 'and', 'as', 'assert', 'async', 'await', 'break', 'class', 'continue', 'def', 'del', 'elif', 'else', 'except', 'finally', 'for', 'from', 'global', 'if', 'import', 'in', 'is', 'lambda', 'nonlocal', 'not', 'or', 'pass', 'raise', 'return', 'try', 'while', 'with', 'yield']
```
### 行与缩进
python最具特色的就是使用缩进来表示代码块，不需要使用大括号 {}.缩进的空格数是可变的，但是同一个代码块的语句必须包含**相同的缩进空格数**
### 多行语句
Python 通常是一行写完一条语句，但如果语句很长，我们可以使用**反斜杠 \ 来实现多行语句**
```python
total = item_one + \
		item_two + \
		item_three
```
### 数字类型
四种类型：整数，布尔型，浮点型，复数

### 字符串

1. 单引号和双引号使用完全相同
2. 使用三引号可以指定一个多行字符串
3. 反斜杠转义符\，使用r可以让反斜杠不发生转义
4. 按字面意义级联字符串，如"this " "is " "string"会被自动转换为this is string
5. 可使用“ + ”运算符连接在一起，用“ * ”运算符重复
6. **两种索引方式**，从左往右以 0 开始，从右往左以 -1 开始
7. 有单独的字符类型，一个字符就是长度为 1 的字符串
8. 字符串的截取的语法格式如下：变量[头下标:尾下标:步长]
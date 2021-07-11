#!/usr/bin/python3
# -*- coding: windows-1252 -*-
# Êý×ÖÀàÐÍ
a, b, c, d = 20, 5.5, True, 4+3J
print(type(a), type(b), type(c), type(d))

# ×Ö·û´®
# ¿ÉË÷Òý£¬¿É½ØÈ¡
# ²»¿É¸Ä±äÔªËØ
str = "renjie"
print(str)
print(str[0:-1])
print(str[-1::-1])

# ÁÐ±í,´æ´¢µÄÔªËØÀàÐÍ¿É²»Í¬
# ¿ÉË÷Òý£¬¿É½ØÈ¡£¬ÔªËØ¿É¸Ä±ä£¬
list = ['abcd', 786, 2.23, 'runoob', 70.2]
print(list)
print(list[-1])
print(list[0:3:2])
list[0] = 8
print(list)

# Ôª×é£¬´æ´¢µÄÔªËØÀàÐÍ¿É²»Í¬£¬¿É°üº¬listÁÐ±í
# ¿ÉË÷Òý£¬¿É½ØÈ¡
# ²»¿ÉÐÞ¸ÄÔªËØ
# ÌØÊâÔª×é£¬£¨°üº¬1¸ö£¬0¸öÔªËØµÄÔª×é£©
tuple = ('abcd', 10, [1, 2, 3], 'name')
print(tuple[0])
print(tuple[0:3:1])
tup1 = ()
tup2 = (65,)

# ¼¯ºÏ£¬´æ´¢µÄÔªËØÀàÐÍ¿É²»Í¬£¬É¾³ýÖØ¸´ÔªËØ
# ³ÉÔ±¹ØÏµ²âÊÔ
# ²»¿ÉË÷Òý£¬²»¿É½ØÈ¡
sets = {'google', 8, 'baidu', 'name'}
print(sets)
if "google" in sets:
    print("google in set")
else:
    print("google not in set")

b = set(["renjie", "hxj"])
print(b)


# ×Öµä£¬ÎÞÐòµÄ¶ÔÏó¼¯ºÏ
# ¿ÉÍ¨¹ý¼üÀ´Ë÷Òý£¬¼ükey±ØÐëÊ¹ÓÃ²»¿É±äÀàÐÍ
tinydict = {'name': 'runoob', 'code': 1, 'site': 'www.runoob.com'}
print(tinydict['name'])


# Êý¾ÝÀàÐÍ×ª»»
a = 8
print(type(oct(a)))
print(int(oct(a), 8))

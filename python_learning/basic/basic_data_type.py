#!/usr/bin/python3
# -*- coding: windows-1252 -*-
# ��������
a, b, c, d = 20, 5.5, True, 4+3J
print(type(a), type(b), type(c), type(d))

# �ַ���
# ���������ɽ�ȡ
# ���ɸı�Ԫ��
str = "renjie"
print(str)
print(str[0:-1])
print(str[-1::-1])

# �б�,�洢��Ԫ�����Ϳɲ�ͬ
# ���������ɽ�ȡ��Ԫ�ؿɸı䣬
list = ['abcd', 786, 2.23, 'runoob', 70.2]
print(list)
print(list[-1])
print(list[0:3:2])
list[0] = 8
print(list)

# Ԫ�飬�洢��Ԫ�����Ϳɲ�ͬ���ɰ���list�б�
# ���������ɽ�ȡ
# �����޸�Ԫ��
# ����Ԫ�飬������1����0��Ԫ�ص�Ԫ�飩
tuple = ('abcd', 10, [1, 2, 3], 'name')
print(tuple[0])
print(tuple[0:3:1])
tup1 = ()
tup2 = (65,)

# ���ϣ��洢��Ԫ�����Ϳɲ�ͬ��ɾ���ظ�Ԫ��
# ��Ա��ϵ����
# �������������ɽ�ȡ
sets = {'google', 8, 'baidu', 'name'}
print(sets)
if "google" in sets:
    print("google in set")
else:
    print("google not in set")

b = set(["renjie", "hxj"])
print(b)


# �ֵ䣬����Ķ��󼯺�
# ��ͨ��������������key����ʹ�ò��ɱ�����
tinydict = {'name': 'runoob', 'code': 1, 'site': 'www.runoob.com'}
print(tinydict['name'])


# ��������ת��
a = 8
print(type(oct(a)))
print(int(oct(a), 8))

#!/usr/bin/python3

import sys
import keyword


print("hello renjie")

if True:
    print("True")
else:
    print("False")

str = '123456789'
print(str)
print(str[0])
print(str[0:-1])
input("\n\nplease enter")


print('================Python import mode==========================')
print('command line parameter is:')
sum = 0
for i in sys.argv:
    print(i)
    sum += 1
print('\n python path is', sys.path)
print(sum)

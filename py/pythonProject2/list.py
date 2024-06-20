List1 = ['s', 'a', 'H', 'hello']
l = (1, 5, 7)
print(l)
List2 = list(range(1, 10, 2))
List3 = list['hello world']
List1.pop(2)
# print(List1, List2, List3)
List2.append(710)
List1.sort()  ## 改变原素组
## sorted 则是生成新的数组
print(List1)
# List2.insert(3, 'o')
# for index in List2:
#    print(index)
# 也可以根据索引进行遍历
# or
# for index, name in enumerate(List2, 2):
# print(index, name)
# List2[1] = 'my cicle'
# List3 = List2.copy()
# List2.reverse()
# List2.sort()
# print(List2, List3)
# List1.append(45)
# List1.append(0)
# L = sorted(List1)
# print(List1, L)


# 生成
import random

lst1 = [i for i in range(10)]
lst2 = [index * index for index in range(10)]
lst3 = [random.randint(1, 99) for i in range(5)]
lst4 = [i for i in range(1, 55) if i % 7 == 1]
# print(lst4)
# print(lst3)

# asd = ',aa,hhj,kk,op;'
# l = list(asd)
# leng = len(asd)
# print(leng)
# for i in range(leng):
#     if l[i].isalpha():
#         print(l[i], end='')


print('asda' + 'ppp', 'hhhh', sep=':', end='')
print('\n')

fp = open('text.txt', 'w')
print('easymoney?', file=fp)
fp.close()

# a = input("sth: ")
# match a:
#     case 's':
#         print('wow')
#     case '1':
#         print('?')
lll = ['lz', 'lz', 'like', 'lz', 'like', 'like', 'pancake']

lll2 = lll[:]  # 完全复制
lll3 = lll  # just a reference
del lll[1]
# print(lll, lll2, lll3, sep='\n')
# from collections import Counter
#
# c = Counter(lll)
# c = dict(c)
# x = c.items()
# print(c, x)
# c = sorted(c.items(), key=lambda x: (-x[1], x[0]))
# print(c)
from operator import itemgetter

cc = [['hh', 23], ['ee', 0], ['aa', 24], ['dd', 8]]
a = sorted(cc, key=itemgetter(0, 1))
b = sorted(cc, key=lambda x: (x[0], x[1]))
cc.sort(key=itemgetter(0))
print(cc)
cc.sort(key=itemgetter(1))
# print(a, b, cc, sep='\n')
aaa = 'what are u saying'
# print(aaa[:2])

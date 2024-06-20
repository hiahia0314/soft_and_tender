d = {1001: 'hh', 1005: 'limei', 1007: 'hanlei'}
d[1008] = 1
d['ll'] = 10
# print(d)
ld = list(d.values())  # 列表 []
td = tuple(d.values())  # 元组()
# print(ld, td)
# Key 不能更改 所以为元组 字典转到键值对
# lst = list(d.items())
# print(lst)
#
# s = d.pop(1001)
# print(s,d)

# 字典生成 {}
import random

d1 = {item: random.randint(1, 45) for item in range(5)}

# print(d1)

lst1 = [1001, 1002, 1003, 1004]
lst2 = ['li', 'mei', 'han', 'a']
d2 = {key: value for key, value in zip(lst1, lst2)}
# print(d2)

# 集合
jihe = {10, 20, 40, 70}
s = set(range(1, 41))
# print(jihe & s, jihe - s, s - jihe, s ^ jihe)
# 交&   并|    差-   补^

s = set([10, 50, 40])  # 无序
# print(s)
# list 是 unhashable
zoo1 = ('zebra', 'monkey', 'elephant')
newzoo = zoo1, 'hourse'
zoo2 = ['hourse', 'p']
l1 = [1, 2, 3, 4]
l2 = [4, -5, 7, 9]
from functools import reduce

t = list(map(lambda x: x + 5, l2))
t2 = list(filter(lambda x: x % 2, l2))
t3 = reduce(lambda x, y: x + y, l2)
print(t, t2, t3)


def us(*agr):
    print(agr)


# 元组

def uus(ans, **agr):
    for i in agr.items():
        print(i)
    print(ans)

# 字典

# us(4, 'wa', 56)
# uus(1, nam=10, ige='www')

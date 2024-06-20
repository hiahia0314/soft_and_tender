d = {10: 'dog', 20: 'we', 30: 'pp', 'quq': 45}
# 字典是无序的 so 没有index
print(d[10], d.get(10))
# 如果key不存在 前者报错，后者返回默认值
print(len(d))
lis1 = ['as', 12, 312, 4]
lis2 = ['qq', 122, ';', 11]
zzip = zip(lis1, lis2)
a = tuple(zzip)
# zip translated to dictionary list or tuple
print(a)
list1 = [1, 2, 3]
list2 = ['a', 'b', 'c']
zipped = zip(list1, list2)

for item in zipped:
    print(item)

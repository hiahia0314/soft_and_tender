# 遍历字符串
for i in 'hello':
    print(i)
while True:
    break
    pass  # 相对于啥都没有,仅仅让语法不报错
name = 'paprika'
age = 18
print('%s%.3f' % ('a', 3.1415926))
print('%s%d' % ('sss', 1))  # 占位符
print(f'name={name},age={age}')  # notice the 'f'
print('name=={},age=={}'.format(name, age))
print('{:*>2}'.format(name))  # : 表示引导 `<`表示左对齐 `^`表示居中  `2`表示至少两个 不足时用`*`填充
# 注意`花括号`,`''` `:` 都必不可少
print('{:.3f}'.format(3.141599))
print('{:.5}'.format(name))
print('{0:.5f},{0:.3E},{0:3e},{0:.4%}'.format(3141.5926))  # notice 顺序位都是0

s1 = 'hello woRLD'
low_s1 = s1.lower()
# or upper
print(low_s1, s1)
e_mail = '2112067238@qq.com'
lst = e_mail.split('@')  # split之后都是换位List
print(lst[0])
# print(s1.count('o'), s1.find('o'))  # find 结果为-1时没有找到
# 判断 startwith endwith
print(s1.endswith('D'), s1.startswith('a'))
s1_r = s1.replace('o', 'what', 1)  # 替换次数 默认全部替换
# print(s1_r)
# print(s1.center(20, '*'))
s1 = 'DD' + s1
# print(s1, s1.strip('D'), s1.lstrip('D'), s1.rstrip('D'), sep='\n')

ss = 'lllllldddllalddddddldzldldl'
# print(ss.strip('ld'))  # 包含 l or d 都会被去除，和顺序无关

x = 'xswl'
x = x.replace('s', 'sl')
print(x)

from collections import Counter
s1=input()
s2=input()
print(Counter(s1[::2])==Counter(s2[::2]) and Counter(s1[1::2])==Counter(s2[1::2]))
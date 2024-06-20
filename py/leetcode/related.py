# from collections import Counter
# s1=input()
# s2=input()
# c1=Counter(s1)
# c2=Counter(s2)
# boo1=c1.keys()==c2.keys()
# boo2=sorted(c1.values())==sorted(c2.values())
# print(boo1,boo2)
str1=input()
str2=input()
s1=list(str1)
s2=list(str2)
l1=len(str1)
l2=len(str2)
if l1>l2:
    print('n')
for i in s1:
    if i in s2:
        s2.remove(i)
    else:
        print("n")
print('y')
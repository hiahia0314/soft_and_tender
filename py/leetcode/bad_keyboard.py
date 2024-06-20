class Solution(object):
    def finalString(self, s):
        lst=list(s)
        ans = []
        for i in lst:
            if i == 'i':
                ans.reverse()
            else:
                ans.append(i)
        print('"' + ''.join(ans) + '"')

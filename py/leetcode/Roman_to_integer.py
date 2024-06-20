class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        ans=0
        l = len(s) + 1
        i = -1
        for t in range(0, len(s)):
            if i == len(s) - 1:
                break
            i += 1
            if s[i] == 'M':
                ans += 1000
            elif s[i] == 'D':
                ans += 500
            elif s[i] == 'C':
                if i + 1 < l - 1 and s[i + 1] == 'D':
                    ans += 400
                    i += 1
                elif i + 1 < l - 1 and s[i + 1] == 'M':
                    ans += 900
                    i += 1
                else:
                    ans += 100
            elif s[i] == 'L':
                ans += 50
            elif s[i] == 'X':
                if i + 1 < l - 1 and s[i + 1] == 'L':
                    ans += 40
                    i += 1
                elif i + 1 < l - 1 and s[i + 1] == 'C':
                    ans += 90
                    i += 1
                else:
                    ans += 10
            elif s[i] == 'V':
                ans += 5
            elif s[i] == 'I':
                if i + 1 < l - 1 and s[i + 1] == 'V':
                    ans += 4
                    i += 1
                elif i + 1 < l - 1 and s[i + 1] == 'X':
                    ans += 9
                    i += 1
                else:
                    ans += 1
        return ans

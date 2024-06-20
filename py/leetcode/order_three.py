class Solution(object):
    def maximumTripletValue(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans=0
        pre_max = 0
        gap = 0
        for k in nums:
            ans = max(pre_max * k, ans)
            gap = max(gap, pre_max - k)
            pre_max = max(pre_max, k)
        return ans

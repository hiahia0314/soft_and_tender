class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ans=[]
        nums.sort()
        n=len(nums)
        for i in range(n-2):
            if i>0 and nums[i]==nums[i-1]:
                continue
            for k in range(i+1,n-1):
                if k > i+1 and nums[k]==nums[k-1]:
                    continue
                for j in range(k+1,n):
                    if j>k+1 and nums[j]==nums[j-1]:
                        continue
                    if nums[i]+nums[j]+nums[k]==0:
                        ans.append([nums[i],nums[j],nums[k]])


        return ans


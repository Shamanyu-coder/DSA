class Solution(object):
    def smallestIndex(self, nums): 
        # :type nums: List[int]
        # :rtype: int
        # """
        for i  , val in enumerate(nums):
            digit_sum=sum(int(digit) for digit in str(nums[i])) 
            if digit_sum==i:
                return i
              
        return -1
        
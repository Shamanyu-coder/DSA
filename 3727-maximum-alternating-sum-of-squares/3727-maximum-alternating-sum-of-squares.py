class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        squared=sorted([x*x for x in nums])
        n=len(squared)
        mid=n//2
        ans=0

        for i in range(mid):
            ans-=squared[i]
        for i in range(mid,n):
            ans+=squared[i]
        return ans
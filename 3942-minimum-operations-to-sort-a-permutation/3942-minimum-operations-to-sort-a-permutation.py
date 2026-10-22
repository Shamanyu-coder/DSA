class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return 0
        
        idx0 = nums.index(0)
        idx_max = nums.index(n - 1)
        
        is_inc = all(nums[(idx0 + i) % n] == i for i in range(n))
        is_dec = all(nums[(idx_max + i) % n] == (n - 1 - i) for i in range(n))
        
        ans = float('inf')
        
        if is_inc:
            ans = min(ans, idx0)
            if idx0 > 0:
                ans = min(ans, (n - idx0) + 2)
                
        if is_dec:
            rev_idx0 = (n - 1 - idx0)
            ans = min(ans, 1 + rev_idx0)
            ans = min(ans, 1 + (idx0 + 1) % n)
            
        return ans if ans != float('inf') else -1
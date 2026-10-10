class Solution:
    def minSumSquareDiff(self, nums1: list[int], nums2: list[int], k1: int, k2: int) -> int:
        k = k1 + k2
        
        diff = [abs(a - b) for a, b in zip(nums1, nums2)]
        
        if sum(diff) <= k:
            return 0
        
        # Check if we can make all differences <= x
        def can(x):
            need = 0
            for d in diff:
                if d > x:
                    need += d - x
            return need <= k
        
        # Binary search the final maximum difference
        left, right = 0, max(diff)
        
        while left < right:
            mid = (left + right) // 2
            if can(mid):
                right = mid
            else:
                left = mid + 1
        
        limit = left
        
        # Reduce all values above limit
        remaining = k
        ans = []
        
        for d in diff:
            if d > limit:
                remaining -= d - limit
                d = limit
            ans.append(d)
        
        # Use remaining operations to reduce largest values by 1
        ans.sort(reverse=True)
        
        i = 0
        while remaining > 0:
            ans[i] -= 1
            remaining -= 1
            i += 1
        
        return sum(x*x for x in ans)
class SegmentTree:
    def __init__(self, n):
        self.n = n
        self.tree_sum = [0] * (4 * n)
        self.tree_sq = [0] * (4 * n)
        self.lazy = [0] * (4 * n)

    def _push(self, node, l, r):
        if self.lazy[node] != 0:
            val = self.lazy[node]
            mid = (l + r) // 2
            
            # Left child
            left = 2 * node
            len_l = mid - l + 1
            self.tree_sq[left] = (self.tree_sq[left] + 2 * val * self.tree_sum[left] + val * val * len_l)
            self.tree_sum[left] += val * len_l
            self.lazy[left] += val

            # Right child
            right = 2 * node + 1
            len_r = r - mid
            self.tree_sq[right] = (self.tree_sq[right] + 2 * val * self.tree_sum[right] + val * val * len_r)
            self.tree_sum[right] += val * len_r
            self.lazy[right] += val

            self.lazy[node] = 0

    def update_range(self, node, l, r, ql, qr, val):
        if ql <= l and r <= qr:
            length = r - l + 1
            self.tree_sq[node] += 2 * val * self.tree_sum[node] + val * val * length
            self.tree_sum[node] += val * length
            self.lazy[node] += val
            return

        self._push(node, l, r)
        mid = (l + r) // 2
        if ql <= mid:
            self.update_range(2 * node, l, mid, ql, qr, val)
        if qr > mid:
            self.update_range(2 * node + 1, mid + 1, r, ql, qr, val)

        self.tree_sum[node] = self.tree_sum[2 * node] + self.tree_sum[2 * node + 1]
        self.tree_sq[node] = self.tree_sq[2 * node] + self.tree_sq[2 * node + 1]

    def query_sq(self, node, l, r, ql, qr):
        if ql <= l and r <= qr:
            return self.tree_sq[node]

        self._push(node, l, r)
        mid = (l + r) // 2
        res = 0
        if ql <= mid:
            res += self.query_sq(2 * node, l, mid, ql, qr)
        if qr > mid:
            res += self.query_sq(2 * node + 1, mid + 1, r, ql, qr)
        return res


class Solution:
    def sumCounts(self, nums: list[int]) -> int:
        MOD = 10**9 + 7
        n = len(nums)
        st = SegmentTree(n)
        last_pos = {}
        total_sum_sq = 0

        for i, val in enumerate(nums):
            prev_idx = last_pos.get(val, -1)
            # Add 1 to distinct counts for all subarrays starting between prev_idx + 1 and i
            st.update_range(1, 0, n - 1, prev_idx + 1, i, 1)
            
            # Accumulate the sum of squares of distinct counts for all subarrays ending at index i
            total_sum_sq = (total_sum_sq + st.query_sq(1, 0, n - 1, 0, i)) % MOD
            
            # Update last seen position
            last_pos[val] = i

        return total_sum_sq
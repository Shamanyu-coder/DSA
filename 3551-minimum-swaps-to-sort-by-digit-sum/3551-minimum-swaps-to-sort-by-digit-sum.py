class Solution:

    def minSwaps(self, nums: List[int]) -> int:
        def digit_sum(n):
            s = 0
            while n > 0:
                s += n % 10
                n //= 10
            return s

        n = len(nums)
        # Pair each number with its (digit_sum, value, original_index)
        indexed_nums = []
        for i, val in enumerate(nums):
            indexed_nums.append((digit_sum(val), val, i))

        # Sort based on digit sum, then value
        indexed_nums.sort(key=lambda x: (x[0], x[1]))

        # Find the minimum swaps to sort the array based on target positions
        visited = [False] * n
        swaps = 0

        for i in range(n):
            if visited[i] or indexed_nums[i][2] == i:
                continue

            # Cycle detection
            cycle_size = 0
            curr = i
            while not visited[curr]:
                visited[curr] = True
                curr = indexed_nums[curr][2]
                cycle_size += 1

            if cycle_size > 1:
                swaps += cycle_size - 1

        return swaps
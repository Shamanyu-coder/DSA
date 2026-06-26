class Solution {
private:
    int tree[200005];
    int size;

    // Fenwick Tree (BIT) me value update karne ke liye function
    void update(int i, int delta) {
        for (; i < size; i += i & -i) {
            tree[i] += delta;
        }
    }

    // Kuch index tak ka sum (count) nikalne ke liye function
    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) {
            sum += tree[i];
        }
        return sum;
    }

public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        size = 2 * n + 2;
        fill(tree, tree + size, 0); // Tree ko zero se initialize kiya

        long long result = 0;
        int prefix_sum = 0;
        int offset = n + 1; // Negative indices se bachne ke liye shift lagaya

        // Starting me prefix sum 0 hota hai, uski frequency ko 1 kiya
        update(0 + offset, 1);

        for (int x : nums) {
            // Agar number target ke barabar hai toh +1, nahi toh -1
            prefix_sum += (x == target) ? 1 : -1;

            // Purane saare prefix_sums check karo jo current se chhote hain
            result += query(prefix_sum + offset - 1);

            // Current prefix sum ko tree me insert/update karo
            update(prefix_sum + offset, 1);
        }

        return result; // Total valid subarrays ka count return kiya
    }
};
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return -1;
        
        // Precompute prefix max: prefix_max[i] = max(nums[0..i])
        vector<int> prefix_max(n);
        prefix_max[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix_max[i] = max(prefix_max[i-1], nums[i]);
        }
        
        // Precompute suffix min: suffix_min[i] = min(nums[i..n-1])
        vector<int> suffix_min(n);
        suffix_min[n-1] = nums[n-1];
        for (int i = n - 2; i >= 0; i--) {
            suffix_min[i] = min(suffix_min[i+1], nums[i]);
        }
        
        // Find smallest index i where prefix_max[i] - suffix_min[i] <= k
        for (int i = 0; i < n; i++) {
            if (prefix_max[i] - suffix_min[i] <= k) {
                return i;
            }
        }
        
        return -1;
    }
};
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        int mn = nums[0];
        int mx = nums[0];

        unordered_set<int> st;

        // Find minimum, maximum and store elements
        for (int x : nums) {
            mn = min(mn, x);
            mx = max(mx, x);
            st.insert(x);
        }

        vector<int> ans;

        // Check every number in the range
        for (int i = mn + 1; i < mx; i++) {
            if (st.find(i) == st.end()) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
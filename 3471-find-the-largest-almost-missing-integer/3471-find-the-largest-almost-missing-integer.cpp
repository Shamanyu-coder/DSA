class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> count(51, 0);

        for (int i = 0; i <= n - k; i++) {
            set<int> present;

            for (int j = i; j < i + k; j++) {
                present.insert(nums[j]);
            }

            for (int x : present) {
                count[x]++;
            }
        }

        int answer = -1;

        for (int x = 0; x <= 50; x++) {
            if (count[x] == 1) {
                answer = x;
            }
        }

        return answer;
    }
};
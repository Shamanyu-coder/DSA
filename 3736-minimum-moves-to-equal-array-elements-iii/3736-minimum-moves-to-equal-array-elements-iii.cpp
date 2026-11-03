class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max_val = *max_element(nums.begin(), nums.end());
        int total_move = 0;
        
        for (int num : nums) {
            total_move += (max_val - num);
        }
        
        return total_move;
    }
};
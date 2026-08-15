class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int totalXOR=0;
        int num;
        for(int i=0;i<nums.size();i++){
            totalXOR=totalXOR ^ nums[i];
        }
        if(totalXOR!=0){
            return nums.size();
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                return nums.size()-1;
            }
        }
        return 0;
    }
};
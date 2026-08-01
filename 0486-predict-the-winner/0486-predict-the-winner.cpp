class Solution {
public:
    int dp[21][21];
    int solve(int left,int right,vector<int>& nums){
        if(left==right)
        return nums[left];
        if(dp[left][right]!=-1)
        return dp[left][right];
        int takeLeft =nums[left]-solve(left+1,right,nums);
        int takeRight =nums[right] -solve(left,right-1,nums);
        dp[left][right]=max(takeLeft,takeRight);
        return dp[left][right];

    }
    bool predictTheWinner(vector<int>& nums){
        memset(dp,-1, sizeof(dp));
        int answer=solve(0, nums.size()-1,nums);
        if(answer>=0)
        return true;
        
        return false;
    }};

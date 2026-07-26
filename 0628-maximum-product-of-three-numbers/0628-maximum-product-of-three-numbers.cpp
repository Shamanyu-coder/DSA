class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n =nums.size();
        // three larget number
        int product1 =nums[n-1]*nums[n-2]*nums[n-3];
        // two smallest negative numbers + larget number 
        int product2 = nums[0] * nums[1] * nums[n-1];
        return max(product1,product2);
    }
};
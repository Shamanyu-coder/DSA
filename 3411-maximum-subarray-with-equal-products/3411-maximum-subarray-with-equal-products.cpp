class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n=nums.size();
        int max_len=1;
        const long long MAX_LIMIT=25200;
        for(int i =0;i<n;++i){
            long long prod=1;
            int current_gcd=0;
             int current_lcm=1;
             for(int j=i;j<n;++j){
                prod*=nums[j];
                if(prod>MAX_LIMIT){
                    break;
                }
                current_gcd=gcd(current_gcd,nums[j]);
                current_lcm=lcm(current_lcm, nums[j]);
                if(prod==1LL*current_gcd*current_lcm){
                    max_len=max(max_len,j-i+1);
                }
             }
        }
        return max_len;
    }
};
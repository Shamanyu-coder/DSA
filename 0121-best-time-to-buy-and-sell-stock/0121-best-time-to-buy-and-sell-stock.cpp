class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0];
        int profit =0;
         for( int i=1;i<prices.size();i++){
            if(prices[i]<buy){
                buy=prices[i];
            }
            int currentProfit=prices[i]-buy;
            if(currentProfit>profit){
                profit=currentProfit;

            }
         }
        return  profit;
    }
};
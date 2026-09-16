class Solution {
public:
int seg;
int M =1e9+7;
int dp[1001][1001];
    int numberOfSets(int n, int k) {
        for(int i=0; i<=n;i++){
            dp[0][i]=(i<n)?1:0;
        }
        for(int seg =1;seg<=k; seg++){
            vector<int> prevRowSum(n+1 ,0);
            for (int x=n-1;x>=0;x--)
{
    prevRowSum[x]=(prevRowSum[x+1]+dp[seg-1][x])%M;
}
for(int i=n-1;i>=0;i--){
    int skip= dp[seg][i+1];
    int take = prevRowSum[i+1];
    dp[seg][i]=(take +skip)%M;
}
        }
        return dp[k][0];
    }
};
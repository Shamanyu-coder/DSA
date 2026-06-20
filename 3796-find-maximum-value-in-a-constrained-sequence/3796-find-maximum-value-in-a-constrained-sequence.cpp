class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        vector<long long> limit(n,1e18) ;
        limit[0]=0;
        for( auto&r:restrictions){
            limit[r[0]]=min(limit[r[0]],(long long)r[1]);

        }
        // yaha se left se right gyagya hai
        for(int i=0;i<n-1;i++){
            limit[i+1]=min(limit[i+1],limit[i]+diff[i]);
        }
        // right to left 
        for(int i=n-2; i>=0; i--){
            limit[i]=min(limit[i],limit[i+1]+diff[i]) ;       
          }
          long long ans=0;
          for(int i =0;i<n;i++){
            ans=max(ans ,limit[i]);
          }
         


                    
                    return(int)ans;
                    }

};


class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
         restrictions.push_back({1,0});
         sort(restrictions.begin(),restrictions.end());
          // yaha pe building pe restrictions add kiya gya hai 
          if(restrictions.back()[0]!=n){
            int h= restrictions.back()[1]+(n-restrictions.back()[0]);
            restrictions.push_back({n,h});
                      }
    
    int m =restrictions.size();
     
     // yaha pe hamne left se right dekha hai or kiya hai
     for(int i=1; i<m; i++)
     {
        restrictions[i][1]=min(
            restrictions[i][1],
            restrictions[i-1][1]+
            (restrictions[i][0]-restrictions[i-1][0])

        );
}

     // right to left
     for (int i = m - 2; i >= 0; i--) {
            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i + 1][1] +
                (restrictions[i + 1][0] - restrictions[i][0])
            );
        }

     
     long long ans =0;
     for(int i=1;i<m;i++){
        long long x1=restrictions[i-1][0];
        long long h1= restrictions[i-1][1];
         
         long long x2= restrictions[i][0];
         long long h2 =restrictions[i][1];
         long long dist = x2-x1;
         long long peak=(h1+h2+dist)/2;
         ans =max(ans,peak);
     }
     return (int)ans;
}
};
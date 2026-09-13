class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
         int n =img1.size();
         vector<pair<int , int >> ones_img1, ones_img2;
          for(int i=0;i<n;++i){
            for(int j=0; j<n; ++j)
{
    if(img1[i][j]==1) ones_img1.push_back({i,j});
    if(img2[i][j]==1) ones_img2.push_back({i,j});
    
}
          }
          map<pair<int , int > ,int > count;
          int res=0;
          for(auto& p1: ones_img1){
            for(auto& p2: ones_img2){
                pair<int, int> shift ={p2.first-p1.first, p2.second-p1.second};
                count[shift]++;
                res=max(res, count[shift]);

            }
          }
        return res;
    }
};
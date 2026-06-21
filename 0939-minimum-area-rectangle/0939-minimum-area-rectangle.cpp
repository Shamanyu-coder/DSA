class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_set<string> st;
        for(auto&p:points){
            st.insert(to_string(p[0])+"#"+to_string(p[1]));
        }
        int ans=INT_MAX;
        int n= points.size();
        for(int i=0;i<n;i++){
            for(int j=i+1; j<n;j++){
                int x1 =points[i][0];
                int y1=points[i][1];
                int x2=points[j][0];
                int y2=points[j][1];
                 // diagonal cheak karna padega yaha pe 
                 if(x1==x2||y1==y2)
                 continue ;
                 
                 string p1=to_string(x1)+"#"+ to_string(y2);
                 
                 string p2=to_string(x2)+"#"+ to_string(y1);
                 if (st.count(p1) && st.count(p2)){
                    int area = abs(x1-x2)* abs(y1-y2);
                    ans =min(ans,area);

                 }
            }
        }
        return ans == INT_MAX?0:ans;
    }
};
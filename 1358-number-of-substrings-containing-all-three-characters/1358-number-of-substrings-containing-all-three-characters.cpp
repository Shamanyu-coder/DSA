class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> lastSeen(3,-1);
        int count=0;
        for(int right=0;right<s.length();++right){
            lastSeen[s[right]-'a']=right;
            if(lastSeen[0]!=-1 && lastSeen[1]!=-1 && lastSeen[2]!=-1){
            count += min({lastSeen[0], lastSeen[1], lastSeen[2]}) + 1;
            }
        }
return count;
    }
    
};



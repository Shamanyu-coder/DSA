class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans=0;
        for(int i=0; i< patterns.size();i++){
            string pat=patterns[i];
            int len =pat.size();
            bool found = false;
    
        // yaha pe window move kiye hai
        for(int j=0;j<= (int) word.size()-len;j++){
            if(word.substr(j,len)== pat){
                found =true;
                break;
            }
        }
            if(found)
            ans++;
        
        }
        return ans;
        }

    };
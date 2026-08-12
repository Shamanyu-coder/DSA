class Solution {
public:
    int longestSubstring(string s, int k) {
        

        if(s.length()<k)
{
 return 0;
} 
vector<int>freq(26,0);
for(char ch:s){
    freq[ch-'a']++;

} 
for(int i =0; i<s.length();i++){
     if( freq[s[i] - 'a']<k){
        string leftPart=s.substr(0,i);
          string rightPart=s.substr(i+1);
          int leftAnswer =longestSubstring(leftPart,k);
           int rightAnswer =longestSubstring(rightPart,k);
           return max(leftAnswer, rightAnswer);

     }
}
return s.length();
  }
};
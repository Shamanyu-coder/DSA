class Solution {
public:
vector<string> ans;
void fun(string digits, int index,string s){
    if(index == digits.size()){
        ans.push_back(s);
        return;
    }
    string a;
    if(digits[index]=='2')a="abc";
    else if(digits[index]=='3') a="def";
     else if(digits[index]=='4') a="ghi";
      else if(digits[index]=='5') a="jkl";
       else if(digits[index]=='6') a="mno";
        else if(digits[index]=='7') a="pqrs";
         else if(digits[index]=='8') a="tuv";
          else if(digits[index]=='9') a="wxyz";
           

           for( int i=0;i<a.size(); i++){
            fun(digits, index+1,s+a[i]);

           }
}
vector<string> letterCombinations(string digits){
    if(digits=="")
    return {};
    fun (digits, 0,"");
    return ans;
}
    
};
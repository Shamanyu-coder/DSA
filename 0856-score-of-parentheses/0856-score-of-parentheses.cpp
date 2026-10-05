class Solution {
public:
    int scoreOfParentheses(string s) {
        vector<int> st;
        st.push_back(0);
        for(char c:s){
            if(c=='(')
{
    st.push_back(0);

}   
else{
    int top=st.back();
    st.pop_back();
    int cur=(top==0)? 1:2*top;
    int prev =st.back();
    
    st.pop_back();
    st.push_back(prev+cur);

} 
    }
     return st.back();
    }
};
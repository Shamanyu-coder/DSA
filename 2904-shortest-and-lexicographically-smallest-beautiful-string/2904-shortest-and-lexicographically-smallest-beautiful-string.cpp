class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int> ones;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '1') {
                ones.push_back(i);
            }
        }
        
        if (ones.size() < k) {
            return "";
        }
        
        string result = "";
        int min_len = s.length() + 1;
        
        for (int i = 0; i <= (int)ones.size() - k; ++i) {
            int start = ones[i];
            int end = ones[i + k - 1];
            int current_len = end - start + 1;
            string current_sub = s.substr(start, current_len);
            
            if (current_len < min_len) {
                min_len = current_len;
                result = current_sub;
            } else if (current_len == min_len) {
                if (current_sub < result) {
                    result = current_sub;
                }
            }
        }
        
        return result;
    }
};
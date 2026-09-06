class Solution {
public:
    int numDistinct(string str1, string str2) {  // ← Function name changed
        int len1 = str1.length();
        int len2 = str2.length();
        vector<vector<unsigned int>> dpTable(len1 + 1, vector<unsigned int>(len2 + 1));
        
        for (int i = 0; i <= len1; i++) {
            dpTable[i][len2] = 1;
        }
        
        for (int j = len2 - 1; j >= 0; j--) {
            for (int i = len1 - 1; i >= 0; i--) {
                if (str1[i] == str2[j]) {
                    dpTable[i][j] = dpTable[i + 1][j + 1] + dpTable[i + 1][j];
                } else {
                    dpTable[i][j] = dpTable[i + 1][j];
                }
            }
        }
        
        return dpTable[0][0];
    }
};
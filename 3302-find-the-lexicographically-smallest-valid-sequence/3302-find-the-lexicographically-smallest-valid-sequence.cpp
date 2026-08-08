#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        
        // dp[i] stores the maximum length of suffix of word2 
        // that can be matched strictly (no changes) using word1[i...n-1]
        vector<int> dp(n + 1, 0);
        
        // Build the DP array from right to left
        for (int i = n - 1; i >= 0; --i) {
            if (dp[i + 1] < m && word1[i] == word2[m - dp[i + 1] - 1]) {
                dp[i] = dp[i + 1] + 1;
            } else {
                dp[i] = dp[i + 1];
            }
        }
        
        vector<int> ans;
        int word2_idx = 0;
        bool used_change = false;
        
        // Greedily match word1 from left to right to build the lexicographically smallest sequence
        for (int i = 0; i < n && word2_idx < m; ++i) {
            bool matches = (word1[i] == word2[word2_idx]);
            
            if (matches) {
                // Exact match: take it greedily
                ans.push_back(i);
                word2_idx++;
            } else if (!used_change) {
                // Characters differ, but we haven't used our single allowed change yet.
                // Check if the remaining suffix word1[i+1...n-1] can match 
                // the remaining suffix of word2 (length m - word2_idx - 1) strictly.
                int remaining_needed = m - word2_idx - 1;
                if (dp[i + 1] >= remaining_needed) {
                    ans.push_back(i);
                    word2_idx++;
                    used_change = true;
                }
            }
        }
        
        // If we matched the full word2, return the sequence; otherwise return empty array
        return (ans.size() == m) ? ans : vector<int>();
    }
};
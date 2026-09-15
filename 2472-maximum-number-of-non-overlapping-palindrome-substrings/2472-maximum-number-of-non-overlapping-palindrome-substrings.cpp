class Solution {
public:
    int maxPalindromes(string s, int k) {

        int n = s.size();

        // pal[i][j] = true if s[i...j] is a palindrome
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        // Build palindrome table
        for (int i = n - 1; i >= 0; i--) {

            for (int j = i; j < n; j++) {

                if (s[i] == s[j] &&
                    (j - i <= 2 || pal[i + 1][j - 1])) {

                    pal[i][j] = true;
                }
            }
        }

        // dp[i] = maximum number of palindromes
        // that can be selected from s[i...n-1]
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {

            // Option 1: skip s[i]
            dp[i] = dp[i + 1];

            // Option 2: take a palindrome of length k
            if (i + k <= n && pal[i][i + k - 1]) {

                dp[i] = max(
                    dp[i],
                    1 + dp[i + k]
                );
            }

            // Option 3: take palindrome of length k + 1
            if (i + k + 1 <= n &&
                pal[i][i + k]) {

                dp[i] = max(
                    dp[i],
                    1 + dp[i + k + 1]
                );
            }
        }

        return dp[0];
    }
};
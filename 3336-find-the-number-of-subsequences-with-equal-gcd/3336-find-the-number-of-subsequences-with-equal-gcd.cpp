#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int MOD = 1e9 + 7;
        
        // dp[g1][g2] stores the number of disjoint subsequence pairs
        // with GCD g1 for seq1 and GCD g2 for seq2.
        // Initially, gcd = 0 represents an empty subsequence.
        vector<vector<int>> dp(201, vector<int>(201, 0));
        dp[0][0] = 1; 

        for (int num : nums) {
            vector<vector<int>> next_dp = dp;
            for (int g1 = 0; g1 <= 200; ++g1) {
                for (int g2 = 0; g2 <= 200; ++g2) {
                    if (dp[g1][g2] == 0) continue;

                    // Option 1: num ko seq1 mein include karo
                    int ng1 = (g1 == 0) ? num : std::gcd(g1, num);
                    next_dp[ng1][g2] = (next_dp[ng1][g2] + dp[g1][g2]) % MOD;

                    // Option 2: num ko seq2 mein include karo
                    int ng2 = (g2 == 0) ? num : std::gcd(g2, num);
                    next_dp[g1][ng2] = (next_dp[g1][ng2] + dp[g1][g2]) % MOD;
                }
            }
            dp = move(next_dp);
        }

        long long ans = 0;
        // Dono subsequences non-empty honi chahiye (i.e., g1 > 0 and g2 > 0)
        // aur dono ka GCD equal hona chahiye (g1 == g2)
        for (int g = 1; g <= 200; ++g) {
            ans = (ans + dp[g][g]) % MOD;
        }

        return ans;
    }
};
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        long long MOD = 1e9 + 7;
        
        // Filter out non-zero digits and track their original indices
        vector<int> digits;
        vector<int> positions;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != '0') {
                digits.push_back(s[i] - '0');
                positions.push_back(i);
            }
        }
        
        int n = digits.size();
        if (n == 0) {
            // If there are no non-zero digits at all, all query answers are 0
            return vector<int>(queries.size(), 0);
        }
        
        // Precompute powers of 10 modulo 10^9 + 7
        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }
        
        // Build prefix arrays
        vector<long long> pref_sum(n + 1, 0);
        vector<long long> pref_val(n + 1, 0);
        
        for (int i = 0; i < n; ++i) {
            pref_sum[i + 1] = pref_sum[i] + digits[i];
            pref_val[i + 1] = (pref_val[i] * 10 + digits[i]) % MOD;
        }
        
        vector<int> answer;
        answer.reserve(queries.size());
        
        for (const auto& q : queries) {
            int ql = q[0];
            int qr = q[1];
            
            // Find the range of non-zero elements within [ql, qr]
            auto it1 = lower_bound(positions.begin(), positions.end(), ql);
            auto it2 = upper_bound(positions.begin(), positions.end(), qr);
            
            int L = distance(positions.begin(), it1);
            int R = distance(positions.begin(), it2) - 1;
            
            if (L > R) {
                answer.push_back(0);
                continue;
            }
            
            // 1-based indexing for prefix arrays
            int idxL = L + 1;
            int idxR = R + 1;
            int len = R - L + 1;
            
            // Calculate substring integer value x % MOD
            long long x = (pref_val[idxR] - (pref_val[idxL - 1] * pow10[len]) % MOD + MOD) % MOD;
            
            // Calculate sum of digits
            long long sum = pref_sum[idxR] - pref_sum[idxL - 1];
            
            // Compute the final result for the query
            long long res = (x * (sum % MOD)) % MOD;
            answer.push_back(res);
        }
        
        return answer;
    }
};
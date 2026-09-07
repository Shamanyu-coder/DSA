#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1'000'000'007;
        long long ends[26] = {0};  // ends[i] = # distinct subsequences ending with ('a' + i)

        for (char ch : s) {
            int idx = ch - 'a';

            long long total = 0;
            for (int i = 0; i < 26; ++i) {
                total += ends[i];
                if (total >= MOD) total -= MOD;
            }

            ends[idx] = (total + 1) % MOD;
        }

        long long ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans += ends[i];
            if (ans >= MOD) ans -= MOD;
        }

        return (int)ans;
    }
};
class Solution {
public:
    static const int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        int k = r - l + 1;

        vector<int> up(k + 1), down(k + 1);
        vector<int> nup(k + 1), ndown(k + 1);

        for (int v = 1; v <= k; v++) {
            down[v] = k - v;
            up[v] = v - 1;
        }

        for (int len = 3; len <= n; len++) {

            long long pref = 0;
            for (int v = 1; v <= k; v++) {
                nup[v] = pref;
                pref += down[v];
                pref %= MOD;
            }

            long long suff = 0;
            for (int v = k; v >= 1; v--) {
                ndown[v] = suff;
                suff += up[v];
                suff %= MOD;
            }

            swap(up, nup);
            swap(down, ndown);
        }

        long long ans = 0;

        for (int v = 1; v <= k; v++) {
            ans += up[v];
            ans += down[v];
        }

        return ans % MOD;
    }
};
class Solution {
public:
    static const long long MOD = 1000000007LL;
    using Matrix = vector<vector<long long>>;

    Matrix multiply(Matrix &A, Matrix &B) {
        int n = A.size();
        Matrix C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;

                for (int j = 0; j < n; j++) {
                    if (B[k][j] == 0) continue;

                    C[i][j] =
                        (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int n = base.size();

        Matrix res(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++)
            res[i][i] = 1;

        while (exp) {
            if (exp & 1)
                res = multiply(res, base);

            base = multiply(base, base);
            exp >>= 1;
        }

        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        if (n == 1) return m;

        int S = 2 * m;

        Matrix T(S, vector<long long>(S, 0));

        for (int y = 0; y < m; y++) {
            for (int x = 0; x < y; x++) {
                T[y][m + x] = 1;
            }
        }

        for (int y = 0; y < m; y++) {
            for (int x = y + 1; x < m; x++) {
                T[m + y][x] = 1;
            }
        }

        vector<long long> init(S, 0);

        for (int a = 0; a < m; a++) {
            for (int b = 0; b < m; b++) {
                if (a == b) continue;

                if (a < b)
                    init[b]++;
                else
                    init[m + b]++;
            }
        }

        Matrix P = power(T, n - 2);

        vector<long long> state(S, 0);

        for (int i = 0; i < S; i++) {
            for (int j = 0; j < S; j++) {
                state[i] =
                    (state[i] + P[i][j] * init[j]) % MOD;
            }
        }

        long long ans = 0;

        for (long long x : state)
            ans = (ans + x) % MOD;

        return (int)ans;
    }
};
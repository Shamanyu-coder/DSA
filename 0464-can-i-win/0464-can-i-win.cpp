class Solution {
public:
    unordered_map<int, bool> dp;

    bool solve(int mask, int total, int n) {

        if (dp.count(mask))
            return dp[mask];

        for (int i = 1; i <= n; i++) {

            // if number i is not used
            if ((mask & (1 << i)) == 0) {

                // take i and win immediately
                if (i >= total)
                    return dp[mask] = true;

                // if opponent loses, then I win
                if (!solve(mask | (1 << i), total - i, n))
                    return dp[mask] = true;
            }
        }

        return dp[mask] = false;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {

        if (desiredTotal <= 0)
            return true;

        int sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;

        if (sum < desiredTotal)
            return false;

        return solve(0, desiredTotal, maxChoosableInteger);
    }
};
class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {

        vector<vector<int>> cnt(n, vector<int>(11, 0));

        // Count balls of each color for every player
        for (auto x : pick) {
            int player = x[0];
            int color = x[1];
            cnt[player][color]++;
        }

        int ans = 0;

        // Check every player
        for (int i = 0; i < n; i++) {

            for (int color = 0; color <= 10; color++) {

                if (cnt[i][color] > i) {
                    ans++;
                    break;   // This player is already a winner
                }
            }
        }

        return ans;
    }
};
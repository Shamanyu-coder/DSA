#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int MOD = 1e9 + 7;

        // dp_score[i][j] stores the max score to reach (i, j) from (0, 0)
        vector<vector<int>> dp_score(n, vector<int>(n, -1));
        // dp_paths[i][j] stores the number of paths to reach (i, j) with max score
        vector<vector<int>> dp_paths(n, vector<int>(n, 0));

        // Base case at the destination 'E' (0, 0)
        dp_score[0][0] = 0;
        dp_paths[0][0] = 1;

        // Iterate through the grid row by row, column by column
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // Skip the destination cell itself and any obstacles
                if ((i == 0 && j == 0) || board[i][j] == 'X') {
                    continue;
                }

                int max_prev_score = -1;
                int paths_count = 0;

                // 3 possible movements to reach (i, j):
                // From Top (i-1, j), From Left (i, j-1), From Top-Left (i-1, j-1)
                vector<pair<int, int>> directions = {{i - 1, j}, {i, j - 1}, {i - 1, j - 1}};

                for (auto& dir : directions) {
                    int r = dir.first;
                    int c = dir.second;

                    // Ensure bounds are valid and the predecessor cell is reachable
                    if (r >= 0 && c >= 0 && dp_score[r][c] != -1) {
                        if (dp_score[r][c] > max_prev_score) {
                            max_prev_score = dp_score[r][c];
                            paths_count = dp_paths[r][c];
                        } else if (dp_score[r][c] == max_prev_score) {
                            paths_count = (paths_count + dp_paths[r][c]) % MOD;
                        }
                    }
                }

                // If at least one predecessor was reachable, update current cell
                if (max_prev_score != -1) {
                    int current_val = (board[i][j] == 'S') ? 0 : (board[i][j] - '0');
                    dp_score[i][j] = max_prev_score + current_val;
                    dp_paths[i][j] = paths_count;
                }
            }
        }

        // The start cell 'S' is at the bottom-right corner (n-1, n-1)
        if (dp_score[n - 1][n - 1] == -1) {
            return {0, 0};
        }
        return {dp_score[n - 1][n - 1], dp_paths[n - 1][n - 1]};
    }
};
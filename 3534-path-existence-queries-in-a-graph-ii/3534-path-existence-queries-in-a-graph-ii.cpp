class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int, int>> sorted_nodes(n);
        for (int i = 0; i < n; ++i) {
            sorted_nodes[i] = {nums[i], i};
        }
        sort(sorted_nodes.begin(), sorted_nodes.end());

        vector<int> sorted_pos(n);
        for (int i = 0; i < n; ++i) {
            sorted_pos[sorted_nodes[i].second] = i;
        }

        vector<int> next_hop(n);
        int r = 0;
        for (int i = 0; i < n; ++i) {
            while (r < n && sorted_nodes[r].first - sorted_nodes[i].first <= maxDiff) {
                r++;
            }
            next_hop[i] = r - 1;
        }

        int max_power = 20;
        vector<vector<int>> up(n, vector<int>(max_power));
        for (int i = 0; i < n; ++i) {
            up[i][0] = next_hop[i];
        }

        for (int k = 1; k < max_power; ++k) {
            for (int i = 0; i < n; ++i) {
                up[i][k] = up[up[i][k - 1]][k - 1];
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int su = sorted_pos[q[0]];
            int sv = sorted_pos[q[1]];

            if (su > sv) swap(su, sv);
            if (su == sv) {
                ans.push_back(0);
                continue;
            }

            int steps = 0;
            for (int k = max_power - 1; k >= 0; --k) {
                if (up[su][k] < sv) {
                    steps += (1 << k);
                    su = up[su][k];
                }
            }

            steps++;
            su = next_hop[su];

            if (su >= sv) {
                ans.push_back(steps);
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};
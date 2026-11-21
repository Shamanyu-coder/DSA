
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> last(26, -1);
        vector<int> newParent = parent;

        auto dfs = [&](auto&& self, int u) -> void {
            int c = s[u] - 'a';
            int prev = last[c];

            if (prev != -1) {
                newParent[u] = prev;
            }

            last[c] = u;

            for (int v : adj[u]) {
                self(self, v);
            }

            last[c] = prev;
        };

        dfs(dfs, 0);

        // Rebuild the tree using updated parents
        vector<vector<int>> tree(n);

        for (int i = 1; i < n; i++) {
            tree[newParent[i]].push_back(i);
        }

        vector<int> ans(n, 1);

        auto calculate = [&](auto&& self, int u) -> int {
            for (int v : tree[u]) {
                ans[u] += self(self, v);
            }

            return ans[u];
        };

        calculate(calculate, 0);

        return ans;
    }
};

#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (const auto& inv : invocations) {
            adj[inv[0]].push_back(inv[1]);
        }

        // Step 1: Find all suspicious methods starting from k using BFS
        vector<bool> is_suspicious(n, false);
        queue<int> q;
        
        q.push(k);
        is_suspicious[k] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int neighbor : adj[curr]) {
                if (!is_suspicious[neighbor]) {
                    is_suspicious[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        // Step 2: Check if any non-suspicious method invokes a suspicious method
        bool can_remove = true;
        for (const auto& inv : invocations) {
            int u = inv[0];
            int v = inv[1];
            if (!is_suspicious[u] && is_suspicious[v]) {
                can_remove = false;
                break;
            }
        }

        // Step 3: Construct the answer based on whether removal is possible
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (!can_remove || !is_suspicious[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
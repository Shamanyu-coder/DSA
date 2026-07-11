class Solution {
public:
    void dfs(int node, const vector<vector<int>>& adj, vector<bool>& visited, int& node_count, int& total_degrees) {
        visited[node] = true;
        node_count++;
        total_degrees += adj[node].size();

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, node_count, total_degrees);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int complete_components = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int node_count = 0;
                int total_degrees = 0;
                
                dfs(i, adj, visited, node_count, total_degrees);
                
                // For a complete component, total degrees must equal node_count * (node_count - 1)
                if (total_degrees == node_count * (node_count - 1)) {
                    complete_components++;
                }
            }
        }

        return complete_components;
    }
};
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // comp[i] will store the component ID for node i
        vector<int> comp(n, 0);
        int currentId = 0;
        
        // Step 1: Preprocess and find connected components in O(n)
        for (int i = 1; i < n; ++i) {
            if (nums[i] - nums[i - 1] > maxDiff) {
                currentId++; // Start a new connected component
            }
            comp[i] = currentId;
        }
        
        // Step 2: Answer each query in O(1)
        vector<bool> answer;
        answer.reserve(queries.size());
        
        for (const auto& query : queries) {
            int u = query[0];
            int v = query[1];
            // If they belong to the same component, a path exists
            answer.push_back(comp[u] == comp[v]);
        }
        
        return answer;
    }
};
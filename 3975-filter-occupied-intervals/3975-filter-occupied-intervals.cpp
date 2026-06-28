class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>&         occupiedIntervals,
    int freeStart, int freeEnd) {
      sort(occupiedIntervals.begin(), occupiedIntervals.end());
       vector<vector<int>> merged;
        for (auto &it : occupiedIntervals) {

        if (merged.empty() || it[0] > merged.back()[1] + 1) {
                merged.push_back(it);
            } else {
                merged.back()[1] = max(merged.back()[1], it[1]);
            }
        }

        vector<vector<int>> ans;

        for (auto &it : merged) {

            int l = it[0];
            int r = it[1];

           // koi overlap nahi ho rh hai yah pe
            if (r < freeStart || l > freeEnd) {
                ans.push_back({l, r});
            }

            // sab remove kiuya gya hai bhai mere
            else if (l >= freeStart && r <= freeEnd) {
                continue;
            }

            // divide into 2 parts
            else if (l < freeStart && r > freeEnd) {
                ans.push_back({l, freeStart - 1});
                ans.push_back({freeEnd + 1, r});
            }

            // Right part removed
            else if (l < freeStart) {
                ans.push_back({l, freeStart - 1});
            }

            // Left part removed
            else {
                ans.push_back({freeEnd + 1, r});
            }
        }

        return ans;
    }
};
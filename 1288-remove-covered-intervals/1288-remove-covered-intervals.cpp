#include <vector>
#include <algorithm>

class Solution {
public:
    int removeCoveredIntervals(std::vector<std::vector<int>>& intervals) {
        // Sort by start point ascending, and by end point descending if starts are equal
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        
        int remaining = 0;
        int max_end = 0;
        
        for (const auto& interval : intervals) {
            // If the current end point is greater than the max end seen so far,
            // this interval is NOT fully covered.
            if (interval[1] > max_end) {
                remaining++;
                max_end = interval[1]; // Update the boundary
            }
        }
        
        return remaining;
    }
};
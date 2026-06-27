#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> counts;
        for (int num : nums) {
            counts[num]++;
        }
        
        // Handle the special case for 1
        int max_len = 0;
        if (counts.count(1)) {
            int count1 = counts[1];
            // If even, we take the largest odd number less than count1
            max_len = (count1 % 2 == 0) ? count1 - 1 : count1;
        }
        
        // Check for chains with x > 1
        for (auto& [num, count] : counts) {
            if (num == 1) continue;
            
            long long current = num;
            int current_len = 0;
            
            // We need at least 2 elements to keep extending the outer layers
            while (counts.count(current) && counts[current] >= 2) {
                current_len += 2;
                current = current * current; // Move to x^2
            }
            
            // The peak element in the center only needs to appear at least once
            if (counts.count(current) && counts[current] >= 1) {
                current_len += 1;
            } else {
                // If there's no peak element available, we have to reduce 
                // the last step because it can't be an end-cap.
                current_len -= 1;
            }
            
            max_len = max(max_len, current_len);
        }
        
        return max_len;
    }
};
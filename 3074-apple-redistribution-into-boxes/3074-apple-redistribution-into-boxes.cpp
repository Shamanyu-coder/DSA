class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {

        int total = 0;

        // Count total apples
        for (int x : apple)
            total += x;

        // Sort capacities in descending order
        sort(capacity.begin(), capacity.end(), greater<int>());

        int boxes = 0;

        // Use the largest boxes first
        for (int x : capacity) {
            total -= x;
            boxes++;

            if (total <= 0)
                return boxes;
        }

        return boxes;
    }
};
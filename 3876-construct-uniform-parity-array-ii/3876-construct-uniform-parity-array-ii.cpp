class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;
        bool hasOdd = false;
        bool hasEven = false;

        for (int num : nums1) {
            if (num % 2 != 0) {
                hasOdd = true;
                minOdd = min(minOdd, num);
            } else {
                hasEven = true;
            }
        }

        // If all elements already have the same parity, it's uniform
        if (!hasOdd || !hasEven) return true;

        // Check if we can make all elements odd:
        // Every even element must be strictly greater than the minimum odd element
        bool canMakeAllOdd = true;
        for (int num : nums1) {
            if (num % 2 == 0 && num <= minOdd) {
                canMakeAllOdd = false;
                break;
            }
        }
        if (canMakeAllOdd) return true;

        // Check if we can make all elements even:
        // Every odd element must be strictly greater than the minimum odd element
        bool canMakeAllEven = true;
        for (int num : nums1) {
            if (num % 2 != 0 && num <= minOdd) {
                canMakeAllEven = false;
                break;
            }
        }

        return canMakeAllEven;
    }
};
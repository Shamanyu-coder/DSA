class Solution {
public:
    bool sumGame(string num) {

        int n = num.length();
        int half = n / 2;

        int leftSum = 0;
        int rightSum = 0;

        int leftQ = 0;
        int rightQ = 0;

        // First half
        for (int i = 0; i < half; i++) {

            if (num[i] == '?') {
                leftQ++;
            }
            else {
                leftSum += num[i] - '0';
            }
        }

        // Second half
        for (int i = half; i < n; i++) {

            if (num[i] == '?') {
                rightQ++;
            }
            else {
                rightSum += num[i] - '0';
            }
        }

        // If total '?' is odd,
        // Alice gets one extra move.
        if ((leftQ + rightQ) % 2 == 1) {
            return true;
        }

        // Difference in number of '?'s
        int qDifference = leftQ - rightQ;

        // Difference in fixed digit sums
        int sumDifference = leftSum - rightSum;

        // If left side has more '?'
        if (qDifference > 0) {

            sumDifference += (qDifference / 2) * 9;

        }
        // If right side has more '?'
        else {

            sumDifference -= ((-qDifference) / 2) * 9;
        }

        // If the difference is zero,
        // Bob can make the sums equal.
        if (sumDifference == 0) {
            return false;
        }

        // Otherwise Alice wins.
        return true;
    }
};
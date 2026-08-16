class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {

        int count0 = 0;
        int count1 = 0;
        int count2 = 0;

        for (int i = 0; i < stones.size(); i++) {

            int remainder = stones[i] % 3;

            if (remainder == 0) {
                count0++;
            }
            else if (remainder == 1) {
                count1++;
            }
            else {
                count2++;
            }
        }

        if (count0 % 2 == 0) {

            if (count1 > 0 && count2 > 0) {
                return true;
            }

            return false;
        }

        else {

            int difference = abs(count1 - count2);

            if (difference > 2) {
                return true;
            }

            return false;
        }
    }
};

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {

        long long a = (long long)need1 * cost1 + (long long)need2 * cost2;

        long long b = (long long)max(need1, need2) * costBoth;

        int common = min(need1, need2);

        long long c = (long long)common * costBoth;

        c += (long long)(need1 - common) * cost1;

        c += (long long)(need2 - common) * cost2;

        return min(a, min(b, c));
    }
};

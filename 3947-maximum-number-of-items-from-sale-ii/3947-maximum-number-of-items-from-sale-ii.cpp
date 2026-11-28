
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        // Har factor kitni baar aaya hai, uski frequency store karenge
        vector<int> cnt(n + 1, 0);

        // Har factor ke liye kitne free-item opportunities hain
        vector<int> gain(n + 1, 0);

        int minPrice = INT_MAX;

        // Step 1: Factor ki frequency aur minimum price find karo
        for (auto &item : items) {
            int factor = item[0];
            int price = item[1];

            cnt[factor]++;

            minPrice = min(minPrice, price);
        }

        // Step 2: Har factor ke divisible items count karo
        for (int f = 1; f <= n; f++) {

            int total = 0;

            // f ke saare multiples check karo
            for (int j = f; j <= n; j += f) {
                total += cnt[j];
            }

            // Current item ko exclude karenge
            gain[f] = total - 1;
        }

        // Step 3: Special deals ko store karo
        vector<pair<int, int>> deals;

        for (auto &item : items) {

            int factor = item[0];
            int price = item[1];

            // Agar free item mil sakta hai
            // Aur special deal normal purchase se beneficial hai
            if (gain[factor] > 0 && price < 2 * minPrice) {

                // First value = price, second value = gain
                deals.push_back({price, gain[factor]});
            }
        }

        // Step 4: Sabse saste deals ko pehle rakho
        sort(deals.begin(), deals.end());

        long long ans = 0;
        long long remaining = budget;

        // Step 5: Special deals ko greedily purchase karo
        for (auto &[price, count] : deals) {

            // Budget ke according maximum kitne deals le sakte hain
            long long buy = min(
                (long long)count,
                remaining / price
            );

            // Har special purchase se 2 items milenge
            ans += buy * 2;

            // Purchase ke baad budget update karo
            remaining -= buy * price;
        }

        // Step 6: Bacha hua budget cheapest item par spend karo
        ans += remaining / minPrice;

        return (int)ans;
    }
};

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> numbers;
        int n = digits.size();

        for (int i = 0; i < n; i++) {
            if (digits[i] % 2) continue;

            for (int j = 0; j < n; j++) {
                if (j == i) continue;

                for (int k = 0; k < n; k++) {
                    if (k == i || k == j || digits[k] == 0) continue;

                    numbers.insert(digits[k] * 100 + digits[j] * 10 + digits[i]);
                }
            }
        }

        return numbers.size();
    }
};
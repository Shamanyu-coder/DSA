class Solution {
public:
    string lexGreaterPermutation(string s, string target) {

        int n = s.size();

        // Count frequency of characters
        vector<int> count(26, 0);

        for (char c : s) {
            count[c - 'a']++;
        }

        string prefix = "";

        // Try to match target from left to right
        for (int i = 0; i < n; i++) {

            int x = target[i] - 'a';

            // Same character is available
            if (count[x] > 0) {
                prefix += target[i];
                count[x]--;
            }
            else {
                // Find smallest character greater than target[i]
                for (int j = x + 1; j < 26; j++) {

                    if (count[j] > 0) {
                        prefix += char('a' + j);
                        count[j]--;

                        // Add remaining characters in sorted order
                        for (int k = 0; k < 26; k++) {
                            prefix += string(count[k], char('a' + k));
                        }

                        return prefix;
                    }
                }

                // Cannot match or make current position greater
                break;
            }
        }

        // Backtrack from right to left
        for (int i = (int)prefix.size() - 1; i >= 0; i--) {

            // Put current character back
            count[prefix[i] - 'a']++;

            int x = target[i] - 'a';

            // Find smallest available character greater than target[i]
            for (int j = x + 1; j < 26; j++) {

                if (count[j] > 0) {

                    // Keep characters before i same
                    string answer = prefix.substr(0, i);

                    // Put the smallest greater character
                    answer += char('a' + j);
                    count[j]--;

                    // Add remaining characters in sorted order
                    for (int k = 0; k < 26; k++) {
                        answer += string(count[k], char('a' + k));
                    }

                    return answer;
                }
            }
        }

        return "";
    }
};
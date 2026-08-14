class Solution {
public:
    int maximumLengthSubstring(string s) {

        // Ye array har character ki frequency store karega
        int freq[26] = {0};

        // Left pointer
        int left = 0;

        // Answer store karne ke liye
        int ans = 0;

        // Right pointer string par chalega
        for (int right = 0; right < s.length(); right++) {

            // Current character ki frequency badhao
            freq[s[right] - 'a']++;

            // Agar koi character 2 se zyada baar aa gaya
            // to left ko aage move karo
            while (freq[s[right] - 'a'] > 2) {

                // Left wale character ko window se hatao
                freq[s[left] - 'a']--;

                // Left ko aage badhao
                left++;
            }

            // Current window ki length
            int length = right - left + 1;

            // Maximum length update karo
            ans = max(ans, length);
        }

        // Final answer
        return ans;
    }
};
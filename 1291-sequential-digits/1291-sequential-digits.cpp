class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string digits = "123456789";
        vector<int> result;
        
        // Loop through all possible lengths of sequential digits (from 2 to 9)
        for (int length = 2; length <= 9; ++length) {
            // Sliding window to extract substrings of the given length
            for (int start = 0; start <= 9 - length; ++start) {
                string sub = digits.substr(start, length);
                int num = stoi(sub);
                
                // Check if the generated number falls within the specified range
                if (num >= low && num <= high) {
                    result.push_back(num);
                }
            }
        }
        
        return result;
    }
};
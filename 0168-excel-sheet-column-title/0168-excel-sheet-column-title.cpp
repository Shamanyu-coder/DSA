class Solution {
public:
    string convertToTitle(int columnNumber) {

        string answer = "";

        while (columnNumber > 0) {

            columnNumber--;

            int remainder = columnNumber % 26;

            char letter = 'A' + remainder;

            answer = letter + answer;

            columnNumber = columnNumber / 26;
        }

        return answer;
    }
};
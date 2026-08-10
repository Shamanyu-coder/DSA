class Solution {
public:
    bool winnerSquareGame(int n) {
        
        // t[i] batayega ki agar current number i hai,
        // toh current player game jeet sakta hai ya nahi
        vector<bool> t(n + 1, false);

        // 0 par koi move possible nahi hai,
        // isliye 0 losing state hai
        t[0] = false;

        // Har number i ke liye check karenge
        for (int i = 1; i <= n; i++) {

            // Har possible perfect square k*k try karenge
            for (int k = 1; k * k <= i; k++) {

                // Agar square minus karne ke baad wali state
                // losing hai, toh current player jeet sakta hai
                if (t[i - (k * k)] == false) {

                    // Current state winning state ban jayegi
                    t[i] = true;

                    // Ek winning move mil gaya,
                    // ab aur check karne ki zarurat nahi
                    break;
                }
            }
        }

        // n ki state return karenge
        // true = current player jeetega
        // false = current player harega
        return t[n];
    }
};
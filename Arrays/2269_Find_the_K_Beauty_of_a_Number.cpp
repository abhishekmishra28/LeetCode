/*
 * Problem: 2269. Find the K-Beauty of a Number
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * The k-beauty of an integer num is defined as the number of
 * substrings of length k in its decimal representation such that:
 *
 *        substring_value ≠ 0
 *        AND
 *        num % substring_value == 0
 *
 * Return the k-beauty of num.
 *
 * ------------------------------------------------------------
 * EXAMPLE:
 *
 * num = 240
 * k = 2
 *
 * Substrings:
 *
 * "24" → 24 → 240 % 24 == 0 → valid
 * "40" → 40 → 240 % 40 == 0 → valid
 *
 * Output = 2
 *
 * ------------------------------------------------------------
 * CORE IDEA:
 *
 * Convert the number into a string and examine every
 * substring of length k.
 *
 * Instead of converting every substring using substr()
 * (which would be slower),
 * we maintain the numeric value using a sliding window.
 *
 * ------------------------------------------------------------
 * SLIDING WINDOW MECHANISM:
 *
 * Example:
 *
 * num = 430043
 * k = 2
 *
 * Windows:
 *
 * "43"
 * "30"
 * "00"
 * "04"
 * "43"
 *
 * To move the window efficiently we:
 *
 *      Remove the leftmost digit
 *      Multiply by 10
 *      Add the new digit
 *
 * ------------------------------------------------------------
 * MATHEMATICAL TRICK:
 *
 * To remove the leftmost digit we use:
 *
 *      currNum % pow10
 *
 * where
 *
 *      pow10 = 10^(k-1)
 *
 * ------------------------------------------------------------
 * ALGORITHM STEPS:
 *
 * 1️⃣ Convert num → string.
 *
 * 2️⃣ Build the first window of size k.
 *
 * 3️⃣ Check if:
 *
 *        currNum != 0
 *        AND
 *        num % currNum == 0
 *
 *    If yes → increment count.
 *
 * 4️⃣ Slide the window:
 *
 *        currNum = (currNum % pow10) * 10 + new_digit
 *
 * 5️⃣ Repeat the divisibility check.
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * num = 430043
 * k = 2
 *
 * Windows:
 *
 * 43 → valid
 * 30 → invalid
 * 00 → ignored
 * 04 → valid (4 divides 430043? no)
 * 43 → valid
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 *      O(n)
 *
 * Space Complexity:
 *      O(n) for string conversion
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - Classic sliding window over digits.
 * - Avoid repeated substring → integer conversion.
 * - Useful trick: (curr % pow10) * 10 + digit.
 */

class Solution {
public:
    int divisorSubstrings(int num, int k) {

        string str = to_string(num);

        int n = str.size();
        int cnt = 0;

        int currNum = 0;

        int pow10 = pow(10, k - 1);

        // Initial window
        for(int i = 0; i < k; i++){
            currNum = currNum * 10 + (str[i] - '0');
        }

        if(currNum != 0 && num % currNum == 0)
            cnt++;

        // Sliding window
        for(int i = k; i < n; i++){

            currNum = (currNum % pow10) * 10 + (str[i] - '0');

            if(currNum != 0 && num % currNum == 0)
                cnt++;
        }

        return cnt;
    }
};

/*
 * Problem: 1922. Count Good Numbers
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * A digit string is called good if:
 * - Digits at even indices (0-based) are even digits → {0,2,4,6,8}
 * - Digits at odd indices are prime digits → {2,3,5,7}
 *
 * You are given an integer n.
 * Return the total number of good digit strings of length n.
 *
 * Since the answer can be very large, return it modulo (1e9 + 7).
 *
 * ------------------------------------------------------------
 * APPROACH: Mathematical Counting + Fast Exponentiation
 *
 * ------------------------------------------------------------
 * KEY OBSERVATION:
 *
 * 1️⃣ Indexing is 0-based
 *
 * - Even indices: 0, 2, 4, ...
 *   → Total choices per position = 5  (0,2,4,6,8)
 *
 * - Odd indices: 1, 3, 5, ...
 *   → Total choices per position = 4  (2,3,5,7)
 *
 * ------------------------------------------------------------
 * COUNT NUMBER OF POSITIONS:
 *
 * Let n = length of string
 *
 * - Number of even positions:
 *      even_pos = (n + 1) / 2
 *
 * - Number of odd positions:
 *      odd_pos = n / 2
 *
 * ------------------------------------------------------------
 * TOTAL NUMBER OF GOOD STRINGS:
 *
 * For each even position → 5 choices
 * For each odd position  → 4 choices
 *
 * So,
 *   Answer = (5 ^ even_pos) × (4 ^ odd_pos)
 *
 * ------------------------------------------------------------
 * WHY FAST EXPONENTIATION?
 *
 * - n can be as large as 10^15
 * - Direct power calculation is too slow
 * - We use Binary Exponentiation (O(log n))
 *
 * ------------------------------------------------------------
 * STEP-BY-STEP EXPLANATION:
 *
 * 1️⃣ Count number of even and odd positions
 * 2️⃣ Compute:
 *      pow(5, even_pos) % MOD
 *      pow(4, odd_pos)  % MOD
 * 3️⃣ Multiply both results modulo MOD
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * n = 4
 *
 * Indices: 0  1  2  3
 *           E  O  E  O
 *
 * even_pos = (4 + 1)/2 = 2
 * odd_pos  = 4/2       = 2
 *
 * Answer = (5^2) * (4^2)
 *        = 25 * 16
 *        = 400
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 * - O(log n) → binary exponentiation
 *
 * Space Complexity:
 * - O(1)
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - This is NOT a DP problem
 * - It is a combinatorics + math optimization problem
 * - Binary exponentiation is mandatory
 */

class Solution {
public:
    static const int MOD = 1e9 + 7;

    // Fast exponentiation: (base^exp) % MOD
    long long modPOW(long long base, long long exp) {
        long long result = 1;
        base %= MOD;

        while (exp > 0) {
            if (exp & 1)
                result = (result * base) % MOD;

            base = (base * base) % MOD;
            exp >>= 1;
        }
        return result;
    }

    int countGoodNumbers(long long n) {

        // Number of even and odd index positions
        long long odd_pos  = n / 2;
        long long even_pos = (n + 1) / 2;

        // Calculate final answer
        long long ans =
            (modPOW(5, even_pos) * modPOW(4, odd_pos)) % MOD;

        return ans;
    }
};

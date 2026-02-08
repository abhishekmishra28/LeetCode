/*
 * Problem: 231. Power of Two
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given an integer n, return true if it is a power of two.
 * Otherwise, return false.
 *
 * A number n is a power of two if:
 *   n = 2^k for some integer k ≥ 0
 *
 * ------------------------------------------------------------
 * APPROACH OVERVIEW:
 *
 * We include ALL commonly asked approaches in a single file:
 *
 * 1️⃣ Recursive Division by 2
 * 2️⃣ Iterative Division by 2
 * 3️⃣ Bit Manipulation (Optimal & Interview Favorite)
 *
 * ------------------------------------------------------------
 * APPROACH 1: Recursive Division by 2
 *
 * Idea:
 * - A power of two can be divided by 2 repeatedly
 * - If we finally reach 1 → it is a power of two
 *
 * Steps:
 * - If n == 0 → false
 * - If n == 1 → true
 * - If n is odd → false
 * - Else → recurse on n / 2
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(log n) (recursion stack)
 *
 * ------------------------------------------------------------
 * APPROACH 2: Iterative Division by 2
 *
 * Idea:
 * - Same logic as recursion
 * - Avoid recursion stack
 *
 * Steps:
 * - While n is divisible by 2 → divide by 2
 * - At the end check if n == 1
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 *
 * ------------------------------------------------------------
 * APPROACH 3: Bit Manipulation (Optimal)
 *
 * Key Insight:
 * - A power of two has exactly ONE set bit in binary
 *
 * Examples:
 *   1  → 0001
 *   2  → 0010
 *   4  → 0100
 *   8  → 1000
 *
 * Trick:
 *   n & (n - 1) removes the lowest set bit
 *
 * For powers of two:
 *   n & (n - 1) == 0
 *
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTE:
 *
 * - Start with recursive explanation
 * - Optimize to iterative
 * - End with bit manipulation as final answer
 */

class Solution {
private:
    /* ========================================================
     * APPROACH 1: Recursive Division
     * ======================================================== */
    bool isPowerOfTwoRecursive(int n) {
        if (n == 0) return false;
        if (n == 1) return true;
        return (n % 2 == 0) && isPowerOfTwoRecursive(n / 2);
    }

    /* ========================================================
     * APPROACH 2: Iterative Division
     * ======================================================== */
    bool isPowerOfTwoIterative(int n) {
        if (n <= 0) return false;
        while (n % 2 == 0) {
            n /= 2;
        }
        return n == 1;
    }

    /* ========================================================
     * APPROACH 3: Bit Manipulation (Optimal)
     * ======================================================== */
    bool isPowerOfTwoBitwise(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }

public:
    bool isPowerOfTwo(int n) {

        // ======= Select ONE approach =======

        // return isPowerOfTwoRecursive(n);   // Approach 1
        // return isPowerOfTwoIterative(n);   // Approach 2
        return isPowerOfTwoBitwise(n);        // Approach 3 (Recommended)
    }
};

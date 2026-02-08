/*
 * Problem: 342. Power of Four
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given an integer n, return true if it is a power of four.
 * Otherwise, return false.
 *
 * A number n is a power of four if:
 *   n = 4^k for some integer k ≥ 0
 *
 * ------------------------------------------------------------
 * APPROACH OVERVIEW:
 *
 * This file includes ALL important approaches:
 *
 * 1️⃣ Recursive Division by 4 (Your Approach)
 * 2️⃣ Iterative Division by 4
 * 3️⃣ Bit Manipulation (Interview Favorite)
 * 4️⃣ Mathematical Trick
 *
 * ------------------------------------------------------------
 * APPROACH 1: Recursive Division by 4 (Your Approach)
 *
 * Idea:
 * - A power of four can be divided by 4 repeatedly
 * - If it finally becomes 1 → valid
 *
 * Steps:
 * - If n == 0 → false
 * - If n == 1 → true
 * - If n % 4 != 0 → false
 * - Else → recurse on n / 4
 *
 * Time Complexity: O(log₄ n)
 * Space Complexity: O(log₄ n)
 *
 * ------------------------------------------------------------
 * APPROACH 2: Iterative Division by 4
 *
 * Same logic as recursion, but avoids recursion stack.
 *
 * Time Complexity: O(log₄ n)
 * Space Complexity: O(1)
 *
 * ------------------------------------------------------------
 * APPROACH 3: Bit Manipulation (Best Interview Answer)
 *
 * Key Observations:
 * - Power of 4 must also be a power of 2
 * - Power of 2 ⇒ only one bit set
 * - That bit must be at an EVEN position (0-based)
 *
 * Conditions:
 * 1. n > 0
 * 2. (n & (n - 1)) == 0   → power of 2
 * 3. (n & 0x55555555) != 0 → bit at even position
 *
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 *
 * ------------------------------------------------------------
 * APPROACH 4: Mathematical Trick
 *
 * Insight:
 * - Maximum power of 4 within 32-bit int is:
 *
 *     4^15 = 1073741824
 *
 * - If n divides this number evenly → power of 4
 *
 * Condition:
 *   n > 0 AND (1073741824 % n == 0)
 *
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 *
 * ------------------------------------------------------------
 * INTERVIEW TIP:
 *
 * - Start with recursion for clarity
 * - Optimize to iteration
 * - Impress with bit manipulation
 */

class Solution {
private:
    /* ========================================================
     * APPROACH 1: Recursive Division (Your Approach)
     * ======================================================== */
    bool isPowerOfFourRecursive(int n) {
        if (n == 0) return false;
        if (n == 1) return true;
        return (n % 4 == 0) && isPowerOfFourRecursive(n / 4);
    }

    /* ========================================================
     * APPROACH 2: Iterative Division
     * ======================================================== */
    bool isPowerOfFourIterative(int n) {
        if (n <= 0) return false;
        while (n % 4 == 0) {
            n /= 4;
        }
        return n == 1;
    }

    /* ========================================================
     * APPROACH 3: Bit Manipulation (Recommended)
     * ======================================================== */
    bool isPowerOfFourBitwise(int n) {
        return n > 0 &&
               (n & (n - 1)) == 0 &&      // power of 2
               (n & 0x55555555) != 0;     // even bit position
    }

    /* ========================================================
     * APPROACH 4: Mathematical Trick
     * ======================================================== */
    bool isPowerOfFourMath(int n) {
        return n > 0 && (1073741824 % n == 0);
    }

public:
    bool isPowerOfFour(int n) {

        // ======= Choose ONE approach =======

        // return isPowerOfFourRecursive(n);  // Approach 1
        // return isPowerOfFourIterative(n);  // Approach 2
        return isPowerOfFourBitwise(n);       // Approach 3 (Best)
        // return isPowerOfFourMath(n);       // Approach 4
    }
};

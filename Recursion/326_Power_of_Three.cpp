/*
 * Problem: 326. Power of Three
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given an integer n, return true if it is a power of three.
 * Otherwise, return false.
 *
 * A number n is a power of three if:
 *   n = 3^k for some integer k ≥ 0
 *
 * ------------------------------------------------------------
 * APPROACH OVERVIEW:
 *
 * We include ALL commonly discussed approaches in ONE file:
 *
 * 1️⃣ Recursive Division by 3 (Your Approach)
 * 2️⃣ Iterative Division by 3
 * 3️⃣ Mathematical / Constant-Time Trick (Optimal)
 *
 * ------------------------------------------------------------
 * APPROACH 1: Recursive Division by 3 (Your Approach)
 *
 * Idea:
 * - A power of three can be repeatedly divided by 3
 * - If we finally reach 1 → it is a power of three
 *
 * Steps:
 * - If n == 0 → false
 * - If n == 1 → true
 * - If n % 3 != 0 → false
 * - Else → recurse on n / 3
 *
 * Time Complexity: O(log₃ n)
 * Space Complexity: O(log₃ n) (recursion stack)
 *
 * ------------------------------------------------------------
 * APPROACH 2: Iterative Division by 3
 *
 * Idea:
 * - Same logic as recursion
 * - Avoid recursion stack
 *
 * Steps:
 * - While n is divisible by 3 → divide by 3
 * - At the end, check if n == 1
 *
 * Time Complexity: O(log₃ n)
 * Space Complexity: O(1)
 *
 * ------------------------------------------------------------
 * APPROACH 3: Mathematical Trick (Optimal)
 *
 * Key Insight:
 * - The maximum power of 3 that fits in a 32-bit signed integer is:
 *
 *     3^19 = 1162261467
 *
 * - If n is a power of three, it must divide 3^19 evenly
 *
 * Condition:
 *   n > 0 AND (1162261467 % n == 0)
 *
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTE:
 *
 * - Start with recursive explanation (clear logic)
 * - Optimize to iterative
 * - Finish with math trick (best answer)
 */

class Solution {
private:
    /* ========================================================
     * APPROACH 1: Recursive Division (Your Approach)
     * ======================================================== */
    bool isPowerOfThreeRecursive(int n) {
        if (n == 0) return false;
        if (n == 1) return true;
        return (n % 3 == 0) && isPowerOfThreeRecursive(n / 3);
    }

    /* ========================================================
     * APPROACH 2: Iterative Division
     * ======================================================== */
    bool isPowerOfThreeIterative(int n) {
        if (n <= 0) return false;
        while (n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }

    /* ========================================================
     * APPROACH 3: Mathematical Trick (Optimal)
     * ======================================================== */
    bool isPowerOfThreeMath(int n) {
        return n > 0 && 1162261467 % n == 0;
    }

public:
    bool isPowerOfThree(int n) {

        // ======= Select ONE approach =======

        // return isPowerOfThreeRecursive(n);   // Approach 1
        // return isPowerOfThreeIterative(n);   // Approach 2
        return isPowerOfThreeMath(n);           // Approach 3 (Recommended)
    }
};

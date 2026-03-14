/*
 * Problem: 1342. Number of Steps to Reduce a Number to Zero
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given an integer num, return the number of steps
 * required to reduce it to zero.
 *
 * Rules:
 *
 * If the current number is EVEN:
 *
 *      divide it by 2
 *
 * If the current number is ODD:
 *
 *      subtract 1 from it
 *
 * Continue the process until the number becomes 0.
 *
 * ------------------------------------------------------------
 * EXAMPLE:
 *
 * num = 14
 *
 * Steps:
 *
 * 14 → 7  (divide by 2)
 * 7  → 6  (subtract 1)
 * 6  → 3  (divide by 2)
 * 3  → 2  (subtract 1)
 * 2  → 1  (divide by 2)
 * 1  → 0  (subtract 1)
 *
 * Total steps = 6
 *
 * ------------------------------------------------------------
 * APPROACH: Recursion
 *
 * ------------------------------------------------------------
 * CORE IDEA:
 *
 * At every step:
 *
 *      if num is even → num / 2
 *      if num is odd  → num - 1
 *
 * We count one step and recursively
 * apply the same rule until num becomes 0.
 *
 * ------------------------------------------------------------
 * RECURSIVE RELATION:
 *
 *      f(num) =
 *
 *          0                        if num == 0
 *
 *          1 + f(num / 2)           if num is even
 *
 *          1 + f(num - 1)           if num is odd
 *
 * ------------------------------------------------------------
 * BASE CASE:
 *
 *      num == 0 → return 0
 *
 * ------------------------------------------------------------
 * DRY RUN:
 *
 * num = 8
 *
 * 8 → 4 → 2 → 1 → 0
 *
 * Steps = 4
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 *      O(log n)
 *
 * Because every divide-by-2 operation
 * reduces the number exponentially.
 *
 * Space Complexity:
 *      O(log n)
 *
 * Due to recursion stack.
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * This problem is often used to test
 * understanding of recursion and bit operations.
 *
 * Observation:
 *
 *      even numbers → right shift
 *      odd numbers  → subtract 1
 */

class Solution {
public:
    int numberOfSteps(int num) {

        if(num == 0)
            return 0;

        return 1 + numberOfSteps(
                        num % 2
                        ? num - 1
                        : num / 2
                    );
    }
};

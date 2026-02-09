/*
 * Problem: 70. Climbing Stairs
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * You are climbing a staircase. It takes `n` steps to reach the top.
 * Each time you can either climb 1 step or 2 steps.
 *
 * Return the number of distinct ways to reach the top.
 *
 * ------------------------------------------------------------
 * APPROACH: Recursion + Memoization (Top-Down DP)
 *
 * Core Observation:
 * - To reach step `n`, you must come from:
 *     • step (n - 1)  OR
 *     • step (n - 2)
 *
 * So,
 *   ways(n) = ways(n - 1) + ways(n - 2)
 *
 * This is exactly the Fibonacci pattern.
 *
 * ------------------------------------------------------------
 * WHY NOT PURE RECURSION?
 *
 * Pure recursion recalculates the same subproblems again and again,
 * leading to exponential time complexity.
 *
 * Memoization stores already computed results and avoids recomputation.
 *
 * ------------------------------------------------------------
 * STEP-BY-STEP EXPLANATION:
 *
 * 1️⃣ Define a helper function `helper(n, memo)`:
 *    - Returns number of ways to reach step `n`
 *
 * 2️⃣ Base Cases:
 *    - If n <= 2, return n directly
 *        • n = 1 → 1 way
 *        • n = 2 → 2 ways
 *
 * 3️⃣ Memoization Check:
 *    - If memo[n] is already computed, return it
 *
 * 4️⃣ Recursive Relation:
 *    - memo[n] = helper(n - 1) + helper(n - 2)
 *
 * 5️⃣ Final Answer:
 *    - Call helper(n) from `climbStairs`
 *
 * ------------------------------------------------------------
 * DRY RUN (n = 5):
 *
 * helper(5)
 *  = helper(4) + helper(3)
 *  = (helper(3) + helper(2)) + (helper(2) + helper(1))
 *  = (3 + 2) = 5
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 * - O(n) → Each value computed once
 *
 * Space Complexity:
 * - O(n) → Memo array + recursion stack
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - This is a classic DP introduction problem
 * - Fibonacci-based reasoning is expected
 * - Memoization shows optimization awareness
 * - Can be further optimized to O(1) space
 */

class Solution {
private:
    int helper(int n, vector<int> &memo) {
        // Base case
        if (n <= 2) return n;

        // If already computed, return stored value
        if (memo[n] != -1) return memo[n];

        // Compute and store result
        memo[n] = helper(n - 1, memo) + helper(n - 2, memo);
        return memo[n];
    }

public:
    int climbStairs(int n) {
        // Memo array initialized with -1
        vector<int> memo(n + 1, -1);

        // Start recursion with memoization
        return helper(n, memo);
    }
};

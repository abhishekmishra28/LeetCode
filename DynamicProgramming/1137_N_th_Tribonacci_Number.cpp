/*
 * Problem: 1137. N-th Tribonacci Number
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * The Tribonacci sequence Tn is defined as:
 *
 * T0 = 0
 * T1 = 1
 * T2 = 1
 *
 * Tn = T(n-1) + T(n-2) + T(n-3)  for n >= 3
 *
 * Given n, return the value of Tn.
 *
 * ------------------------------------------------------------
 * APPROACH: Recursion + Memoization (Top-Down DP)
 *
 * ------------------------------------------------------------
 * KEY OBSERVATIONS:
 *
 * 1️⃣ This is similar to Fibonacci,
 *    but each term depends on THREE previous terms.
 *
 * 2️⃣ Pure recursion would cause exponential time complexity
 *    due to repeated recalculations.
 *
 * 3️⃣ We use memoization to store already computed results.
 *
 * ------------------------------------------------------------
 * STRATEGY:
 *
 * - Use a helper function with memo vector
 * - If value already computed → return from memo
 * - Otherwise compute recursively and store result
 *
 * ------------------------------------------------------------
 * BASE CASES:
 *
 * T0 = 0
 * T1 = 1
 * T2 = 1
 *
 * ------------------------------------------------------------
 * RECURSIVE RELATION:
 *
 * Tn = T(n-1) + T(n-2) + T(n-3)
 *
 * ------------------------------------------------------------
 * ALGORITHM STEPS:
 *
 * 1️⃣ Create memo array of size n+1 initialized with -1
 * 2️⃣ Call helper(n, memo)
 * 3️⃣ In helper:
 *     - If base case → return value
 *     - If already computed → return memo[n]
 *     - Otherwise compute and store in memo
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * n = 4
 *
 * T0 = 0
 * T1 = 1
 * T2 = 1
 * T3 = 2   (1+1+0)
 * T4 = 4   (2+1+1)
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 * - O(n)
 *   (Each state computed once)
 *
 * Space Complexity:
 * - O(n) memo array
 * - O(n) recursion stack
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - Classic DP problem
 * - Can be optimized further to O(1) space
 *   using iterative bottom-up approach
 */

class Solution {
private:
    int helper(int n, vector<int>& memo) {

        // Base cases
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;

        // If already computed
        if (memo[n] != -1)
            return memo[n];

        // Compute and store result
        return memo[n] =
            helper(n - 1, memo) +
            helper(n - 2, memo) +
            helper(n - 3, memo);
    }

public:
    int tribonacci(int n) {

        // Initialize memo array with -1
        vector<int> memo(n + 1, -1);

        return helper(n, memo);
    }
};

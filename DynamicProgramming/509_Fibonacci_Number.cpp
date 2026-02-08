/*
 * Problem: 509. Fibonacci Number
 *
 * Statement:
 * The Fibonacci numbers are defined as:
 *   fib(0) = 0
 *   fib(1) = 1
 *   fib(n) = fib(n-1) + fib(n-2) for n >= 2
 *
 * Given an integer n, return fib(n).
 *
 * ------------------------------------------------------------
 * APPROACH OVERVIEW
 *
 * We discuss 3 common approaches:
 *
 * 1️⃣ Pure Recursion (Brute Force)        → Exponential time
 * 2️⃣ Dynamic Programming (Bottom-Up)    → Linear time
 * 3️⃣ Memoization with Recursion (Top-Down) ✅ (Your Final Choice)
 *
 * ------------------------------------------------------------
 * APPROACH 1: Pure Recursive (Brute Force)
 *
 * Idea:
 * - Directly follow Fibonacci definition
 *
 * Code:
 *   fib(n) = fib(n-1) + fib(n-2)
 *
 * Problems:
 * - Recomputes same subproblems again and again
 * - Very slow for large n
 *
 * Time Complexity: O(2^n)
 * Space Complexity: O(n) (recursion stack)
 *
 * ------------------------------------------------------------
 * APPROACH 2: Dynamic Programming (Bottom-Up)
 *
 * Idea:
 * - Store previously computed values
 * - Build solution iteratively from 0 → n
 *
 * Steps:
 * - dp[0] = 0
 * - dp[1] = 1
 * - dp[i] = dp[i-1] + dp[i-2]
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * ------------------------------------------------------------
 * APPROACH 3: Memoization + Recursion (Top-Down) ✅
 * (This is what your final code uses)
 *
 * Core Idea:
 * - Use recursion but store results to avoid recomputation
 * - Each Fibonacci value is computed only once
 *
 * ------------------------------------------------------------
 * Helper Function: fibo(n, memo)
 *
 * Logic:
 * - If n <= 1 → return n
 * - If memo[n] already computed → return memo[n]
 * - Else:
 *     memo[n] = fibo(n-1) + fibo(n-2)
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Converts exponential recursion into linear recursion
 * - Retains clean recursive structure
 * - Avoids repeated subproblem computation
 *
 * ------------------------------------------------------------
 * Example:
 *
 * n = 5
 *
 * fib(5)
 *  ├─ fib(4)
 *  │   ├─ fib(3)
 *  │   │   ├─ fib(2)
 *  │   │   └─ fib(1)
 *  │   └─ fib(2)
 *  └─ fib(3)
 *
 * With memoization → each fib(x) computed once
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - O(n)
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(n) for memo array
 * - O(n) recursion stack
 *
 * ------------------------------------------------------------
 * Interview Notes:
 *
 * - Memoization is preferred when recursion is natural
 * - Bottom-up DP is preferred when recursion stack is a concern
 * - Both DP and memoization reduce time from exponential to linear
 */

class Solution {
private:
    // Helper function for memoized recursion
    int fibo(int n, vector<int> &memo) {
        if (n <= 1) return n;
        if (memo[n] != -1) return memo[n];

        memo[n] = fibo(n - 1, memo) + fibo(n - 2, memo);
        return memo[n];
    }

public:
    int fib(int n) {

        /*
        // ---------- APPROACH 1: Pure Recursion ----------
        if(n <= 1) return n;
        return fib(n - 1) + fib(n - 2);
        */

        /*
        // ---------- APPROACH 2: Bottom-Up Dynamic Programming ----------
        if(n <= 1) return n;
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
        */

        // ---------- APPROACH 3: Memoization + Recursion (Chosen) ----------
        vector<int> memo(n + 1, -1);
        return fibo(n, memo);
    }
};

/*
 * Problem: 1411. Number of Ways to Paint N × 3 Grid
 *
 * Statement:
 * You are given an integer n representing the number of rows in an n × 3 grid.
 * You must paint each cell using one of the 3 colors such that:
 *
 * 1) No two adjacent cells in the SAME row have the same color
 * 2) No two adjacent cells in the SAME column have the same color
 *
 * Return the total number of valid ways to paint the grid.
 * Since the answer can be large, return it modulo 1e9 + 7.
 *
 * ------------------------------------------------------------
 * Key Observations:
 *
 * - Grid width is FIXED = 3 columns
 * - Height (n rows) can be large (up to 5000)
 * - Constraints are LOCAL (adjacent cells only)
 *
 * This allows us to use Dynamic Programming row-by-row.
 *
 * ------------------------------------------------------------
 * Core Insight (VERY IMPORTANT):
 *
 * For each row of length 3, there are only TWO valid color patterns:
 *
 * 1️⃣ Type A (ABA pattern)
 *    Example: R G R, B R B
 *    - First and third colors are SAME
 *    - Middle color is DIFFERENT
 *
 * 2️⃣ Type B (ABC pattern)
 *    Example: R G B, B R G
 *    - All three colors are DIFFERENT
 *
 * ------------------------------------------------------------
 * Counting Possibilities for ONE row:
 *
 * Type A (ABA):
 * - Choose color for first cell: 3 ways
 * - Choose different color for middle cell: 2 ways
 * - Third cell is FIXED (same as first)
 * → Total = 3 × 2 = 6
 *
 * Type B (ABC):
 * - Choose color for first cell: 3 ways
 * - Choose different color for second cell: 2 ways
 * - Choose different color for third cell: 1 way
 * → Total = 3 × 2 × 1 = 6
 *
 * So initially:
 * typeA = 6
 * typeB = 6
 *
 * ------------------------------------------------------------
 * APPROACH 1 : DP Transition Between Rows:
 *
 * Let:
 * - a = number of ways ending with Type A row
 * - b = number of ways ending with Type B row
 *
 * From previous row to current row:
 *
 * New Type A can be formed from:
 * - Previous Type A → 3 ways
 * - Previous Type B → 2 ways
 *
 * New Type B can be formed from:
 * - Previous Type A → 2 ways
 * - Previous Type B → 2 ways
 *
 * ------------------------------------------------------------
 * DP Recurrence:
 *
 * newA = (a * 3 + b * 2) % MOD
 * newB = (a * 2 + b * 2) % MOD
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - We do NOT track actual colors
 * - We only track pattern types
 * - This drastically reduces state space
 *
 * ------------------------------------------------------------
 * Example:
 *
 * n = 1
 * typeA = 6
 * typeB = 6
 * answer = 12
 *
 * n = 2
 * typeA = 6*3 + 6*2 = 30
 * typeB = 6*2 + 6*2 = 24
 * answer = 54
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n)
 *
 * Space Complexity:
 * - O(1)
 *   (only two variables maintained)
 *
 * ------------------------------------------------------------
 * Note:
 * This is the OPTIMAL solution for problem 1411.
 * Cleaner and faster than state-compression DP.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;

        // Base case: first row
        long long typeA = 6; // ABA patterns
        long long typeB = 6; // ABC patterns

        for (int i = 2; i <= n; i++) {
            long long newA = (typeA * 3 + typeB * 2) % MOD;
            long long newB = (typeA * 2 + typeB * 2) % MOD;

            typeA = newA;
            typeB = newB;
        }

        return (typeA + typeB) % MOD;
    }
};
// ****************************************************************************************

/*
 * Problem: 1411. Number of Ways to Paint N × 3 Grid
 *
 * ------------------------------------------------------------
 * APPROACH 2: State Compression + DP on Rows
 *
 * This approach solves the SAME problem as Approach 1
 * but in a more GENERAL and STRUCTURED way using:
 *
 * - State compression
 * - Column (row-pattern) generation
 * - Dynamic Programming with memoization
 *
 * ------------------------------------------------------------
 * Why this approach?
 *
 * - It models the problem as a graph of valid states
 * - Very useful when:
 *   • Grid height is small (fixed = 3)
 *   • Constraints depend on previous row
 * - This approach generalizes well to similar grid-coloring problems
 *
 * ------------------------------------------------------------
 * Core Idea:
 *
 * Instead of coloring cell-by-cell, we:
 * - Treat each ROW as a "state"
 * - Each state is a string of length 3 (e.g. "RGB")
 *
 * A valid row-state must satisfy:
 * - No two adjacent cells in the SAME row have the same color
 *
 * ------------------------------------------------------------
 * Step 1: Generate all valid row states
 *
 * Colors = {R, G, B}
 * Row length = 3
 *
 * Rules:
 * - Adjacent cells in a row must have different colors
 *
 * Total valid states:
 * - 3 × 2 × 2 = 12
 *
 * Example valid states:
 * "RGB", "RGR", "GRB", "BRG", ...
 *
 * These are stored in `columnStates`
 *
 * ------------------------------------------------------------
 * Step 2: Define DP State
 *
 * dp[r][i] = number of ways to color `r` remaining rows
 *            when the previous row uses state `i`
 *
 * ------------------------------------------------------------
 * Step 3: Transition
 *
 * From prevState → currState is VALID if:
 * - For every column j:
 *     prevState[j] != currState[j]
 *
 * (No two adjacent cells in the SAME column can have same color)
 *
 * ------------------------------------------------------------
 * Step 4: Recursion + Memoization
 *
 * - Try all valid transitions
 * - Memoize results to avoid recomputation
 *
 * ------------------------------------------------------------
 * Example:
 *
 * n = 2
 *
 * Pick any valid first row (12 choices)
 * For each, try all compatible second rows
 * Count all valid transitions
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - Number of states = 12
 * - DP transitions per row = 12 × 12
 * - Total = O(n × 12 × 12) → O(n)
 *
 * Space Complexity:
 * - DP table = O(n × 12)
 *
 * ------------------------------------------------------------
 * Comparison with Approach 1:
 *
 * Approach 1 (Pattern-based):
 * - Faster
 * - Cleaner
 * - Uses math observation (ABA / ABC)
 *
 * Approach 2 (State Compression):
 * - More general
 * - Easier to extend
 * - Great for learning DP on grids
 *
 * ------------------------------------------------------------
 * Note:
 * This approach is slightly heavier but VERY INTERVIEW-SAFE
 * and demonstrates strong DP fundamentals.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> columnStates;   // All valid row states
    vector<vector<int>> dp;        // DP memo table
    int Mod = 1e9 + 7;

    /*
     * Generates all valid row states of length m
     * such that adjacent cells have different colors
     */
    void generateColumnStates(string curr, char prevChar, int l, int m) {
        // Base case: full row generated
        if (l == m) {
            columnStates.push_back(curr);
            return;
        }

        // Try all 3 colors
        for (char ch : {'R', 'G', 'B'}) {
            if (ch == prevChar) continue;
            generateColumnStates(curr + ch, ch, l + 1, m);
        }
    }

    /*
     * DP recursion:
     * prevIdx  → index of previous row state
     * remRows  → remaining rows to color
     */
    int solve(int prevIdx, int remRows, int m) {
        // All rows colored
        if (remRows == 0) return 1;

        // Memoized result
        if (dp[remRows][prevIdx] != -1)
            return dp[remRows][prevIdx];

        int ways = 0;
        string prevState = columnStates[prevIdx];

        // Try all current row states
        for (int i = 0; i < columnStates.size(); i++) {
            if (i == prevIdx) continue;

            string currState = columnStates[i];
            bool valid = true;

            // Check column-wise constraint
            for (int j = 0; j < m; j++) {
                if (prevState[j] == currState[j]) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                ways = (ways + solve(i, remRows - 1, m)) % Mod;
            }
        }

        return dp[remRows][prevIdx] = ways;
    }

    int numOfWays(int n) {
        int m = 3; // fixed columns

        // Step 1: Generate valid row states
        generateColumnStates("", '#', 0, m);

        int sz = columnStates.size();

        // Step 2: Initialize DP table
        dp = vector<vector<int>>(n + 1, vector<int>(sz + 1, -1));

        // Step 3: Try all possible first rows
        int result = 0;
        for (int i = 0; i < columnStates.size(); i++) {
            result = (result + solve(i, n - 1, m)) % Mod;
        }

        return result;
    }
};

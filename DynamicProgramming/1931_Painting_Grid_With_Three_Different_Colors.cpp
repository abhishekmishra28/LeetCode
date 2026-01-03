/*
 * Problem: 1931. Painting a Grid With Three Different Colors
 *
 * Statement:
 * You are given two integers m and n representing the number of rows
 * and columns of a grid respectively.
 *
 * You need to color each cell using one of the 3 colors such that:
 *
 * 1) No two adjacent cells in the SAME row have the same color
 * 2) No two adjacent cells in the SAME column have the same color
 *
 * Return the total number of valid ways to color the grid.
 * Since the answer can be large, return it modulo 1e9 + 7.
 *
 * ------------------------------------------------------------
 * This problem is a GENERALIZATION of Problem 1411:
 *
 * - In 1411 → grid is n × 3 (fixed width)
 * - In 1931 → grid is m × n (m ≤ 5, n ≤ 1000)
 *
 * Because m is SMALL and n is LARGE,
 * we use STATE COMPRESSION + DP.
 *
 * ============================================================
 * APPROACH 1: State Compression + DP on Columns (GENERAL SOLUTION)
 * ============================================================
 *
 * Core Idea:
 * - Treat each COLUMN as a "state"
 * - A column state is a string of length m (rows)
 * - Each state represents coloring of one column
 *
 * ------------------------------------------------------------
 * Valid Column State Conditions:
 *
 * - Adjacent cells in the SAME column must have different colors
 *
 * Example (m = 3):
 * Valid:   "RGB", "RGR", "BRG"
 * Invalid: "RRG", "BBB"
 *
 * ------------------------------------------------------------
 * Step 1: Generate all valid column states
 *
 * Using recursion:
 * - At each row, try {R, G, B}
 * - Skip if same as previous row color
 *
 * Total states:
 * - At most 3 × 2^(m-1)
 * - For m ≤ 5 → very small (≤ 48)
 *
 * ------------------------------------------------------------
 * Step 2: DP Definition
 *
 * dp[c][i] = number of ways to color `c` remaining columns
 *            if the previous column uses state `i`
 *
 * ------------------------------------------------------------
 * Step 3: State Transition
 *
 * prevState → currState is VALID if:
 * - For all rows j:
 *     prevState[j] != currState[j]
 *
 * (No two adjacent cells in the SAME row across columns)
 *
 * ------------------------------------------------------------
 * Step 4: Recursion + Memoization
 *
 * - Try all valid transitions
 * - Use memoization to avoid recomputation
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - States ≈ 3 × 2^(m-1)
 * - DP = O(n × states²)
 * - Efficient due to small m
 *
 * Space Complexity:
 * - O(n × states)
 *
 * ------------------------------------------------------------
 * This approach works for ALL valid constraints
 * and is the MOST INTERVIEW-SAFE solution.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> columnStates;     // All valid column colorings
    vector<vector<int>> dp;          // DP memo table
    int Mod = 1e9 + 7;

    /*
     * Generate all valid column states of height m
     * such that adjacent cells have different colors
     */
    void generateColumnStates(string curr, char prevChar, int l, int m) {
        if (l == m) {
            columnStates.push_back(curr);
            return;
        }

        for (char ch : {'R', 'G', 'B'}) {
            if (ch == prevChar) continue;
            generateColumnStates(curr + ch, ch, l + 1, m);
        }
    }

    /*
     * DP recursion:
     * prevIdx  → index of previous column state
     * remCols  → remaining columns to color
     */
    int solve(int prevIdx, int remCols, int m) {
        if (remCols == 0) return 1;

        if (dp[remCols][prevIdx] != -1)
            return dp[remCols][prevIdx];

        int ways = 0;
        string prevState = columnStates[prevIdx];

        for (int i = 0; i < columnStates.size(); i++) {
            if (i == prevIdx) continue;

            string currState = columnStates[i];
            bool valid = true;

            // Check row-wise adjacency constraint
            for (int j = 0; j < m; j++) {
                if (prevState[j] == currState[j]) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                ways = (ways + solve(i, remCols - 1, m)) % Mod;
            }
        }

        return dp[remCols][prevIdx] = ways;
    }

    int colorTheGrid(int m, int n) {
        // Step 1: Generate all valid column states
        generateColumnStates("", '#', 0, m);

        int sz = columnStates.size();

        // Step 2: Initialize DP table
        dp = vector<vector<int>>(n + 1, vector<int>(sz + 1, -1));

        // Step 3: Try all possible first columns
        int result = 0;
        for (int i = 0; i < columnStates.size(); i++) {
            result = (result + solve(i, n - 1, m)) % Mod;
        }

        return result;
    }
};

/*
 * Problem: 62. Unique Paths
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * A robot is located at the top-left corner of an m × n grid.
 *
 * The robot wants to reach the bottom-right corner.
 *
 * The robot can only move:
 *
 *      → Right
 *      ↓ Down
 *
 * Return the number of unique paths that the robot can take
 * to reach the destination.
 *
 * ------------------------------------------------------------
 * EXAMPLE:
 *
 * m = 3, n = 7
 *
 * Possible paths = 28
 *
 * ------------------------------------------------------------
 * APPROACH: Dynamic Programming (2D Grid DP)
 *
 * ------------------------------------------------------------
 * CORE IDEA:
 *
 * Let:
 *
 *      dp[i][j] = number of ways to reach cell (i, j)
 *
 * Since the robot can only come from:
 *
 *      top cell (i-1, j)
 *      left cell (i, j-1)
 *
 * So the transition becomes:
 *
 *      dp[i][j] = dp[i-1][j] + dp[i][j-1]
 *
 * ------------------------------------------------------------
 * BASE CASE:
 *
 * First row:
 *
 *      Only one way (all moves right)
 *
 * First column:
 *
 *      Only one way (all moves down)
 *
 * Therefore initialize entire first row and column as 1.
 *
 * ------------------------------------------------------------
 * ALGORITHM STEPS:
 *
 * 1️⃣ Create DP table of size m × n.
 *
 * 2️⃣ Initialize all cells with 1 because
 *     first row and column have exactly one path.
 *
 * 3️⃣ Fill the rest using recurrence:
 *
 *      dp[i][j] = dp[i-1][j] + dp[i][j-1]
 *
 * 4️⃣ Return value at destination cell:
 *
 *      dp[m-1][n-1]
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * m = 3, n = 3
 *
 * DP Table:
 *
 *      1 1 1
 *      1 2 3
 *      1 3 6
 *
 * Answer = 6
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 *      O(m × n)
 *
 * Space Complexity:
 *      O(m × n)
 *
 * ------------------------------------------------------------
 * SPACE OPTIMIZATION:
 *
 * Can be optimized to O(n) using a single row DP array.
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * This is a classic grid dynamic programming problem.
 *
 * Also solvable using combinatorics:
 *
 *      (m+n-2)C(m-1)
 */

class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m, vector<int>(n, 1));

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){

                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};

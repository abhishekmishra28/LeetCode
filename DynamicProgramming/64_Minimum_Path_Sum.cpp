/*
 * Problem: 64. Minimum Path Sum
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given an m × n grid filled with non-negative numbers,
 * find a path from the top-left corner to the bottom-right corner
 * that minimizes the sum of all numbers along its path.
 *
 * You can only move:
 *
 *      → Right
 *      ↓ Down
 *
 * ------------------------------------------------------------
 * GOAL:
 *
 * Find the minimum possible sum from (0,0) → (m-1,n-1).
 *
 * ------------------------------------------------------------
 * APPROACH 1: MEMOIZATION (Top-Down Dynamic Programming)
 *
 * ------------------------------------------------------------
 * CORE IDEA:
 *
 * Let:
 *
 *      f(i, j) = minimum cost to reach cell (i, j)
 *
 * Since we can only come from:
 *
 *      top cell    → (i-1, j)
 *      left cell   → (i, j-1)
 *
 * Recurrence:
 *
 *      f(i,j) = grid[i][j] +
 *               min(
 *                    f(i-1, j),
 *                    f(i, j-1)
 *                  )
 *
 * ------------------------------------------------------------
 * BASE CASE:
 *
 * Start cell:
 *
 *      f(0,0) = grid[0][0]
 *
 * Out of bounds:
 *
 *      return large value (INT_MAX)
 *
 * ------------------------------------------------------------
 * APPROACH 2: TABULATION (Bottom-Up DP)
 *
 * ------------------------------------------------------------
 * Build DP table iteratively.
 *
 * dp[i][j] = minimum cost to reach (i,j).
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
 * INTERVIEW NOTE:
 *
 * This is a classic grid DP problem
 * similar to:
 *
 *      • Unique Paths
 *      • Unique Paths II
 */

class Solution {
private:

    /*--------------------------------------------------
      MEMOIZATION (TOP-DOWN)
    --------------------------------------------------*/
    int solve(int i, int j,
              vector<vector<int>>& grid,
              vector<vector<int>>& memo){

        if(i < 0 || j < 0)
            return INT_MAX;

        if(i == 0 && j == 0)
            return grid[0][0];

        if(memo[i][j] != -1)
            return memo[i][j];

        int up   = solve(i-1, j, grid, memo);
        int left = solve(i, j-1, grid, memo);

        return memo[i][j] =
               grid[i][j] + min(up, left);
    }

public:

    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        /*-----------------------------------------
          MEMOIZATION SOLUTION
        -----------------------------------------*/
        vector<vector<int>> memo(m, vector<int>(n, -1));
        int memoAns = solve(m-1, n-1, grid, memo);

        /*-----------------------------------------
          TABULATION SOLUTION
        -----------------------------------------*/
        vector<vector<int>> dp(m, vector<int>(n));

        dp[0][0] = grid[0][0];

        // First row
        for(int j = 1; j < n; j++)
            dp[0][j] = dp[0][j-1] + grid[0][j];

        // First column
        for(int i = 1; i < m; i++)
            dp[i][0] = dp[i-1][0] + grid[i][0];

        // Fill remaining cells
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){

                dp[i][j] = grid[i][j] +
                           min(dp[i-1][j],
                               dp[i][j-1]);
            }
        }

        int tabAns = dp[m-1][n-1];

        // Both methods produce the same result
        return tabAns;
    }
};

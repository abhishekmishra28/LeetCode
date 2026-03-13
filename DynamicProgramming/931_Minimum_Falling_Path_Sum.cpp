/*
 * Problem: 931. Minimum Falling Path Sum
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given an n × n integer matrix, return the minimum sum
 * of any falling path through the matrix.
 *
 * A falling path starts at any element in the first row
 * and chooses one element from each row.
 *
 * From position (r,c) you may move to:
 *
 *      ↓  (r+1, c)
 *      ↙  (r+1, c-1)
 *      ↘  (r+1, c+1)
 *
 * ------------------------------------------------------------
 * GOAL:
 *
 * Find the minimum possible sum from the first row
 * to the last row following the allowed moves.
 *
 * ------------------------------------------------------------
 * APPROACHES:
 *
 * 1️⃣ Recursion
 * 2️⃣ Memoization (Top-Down DP)
 * 3️⃣ Tabulation (Bottom-Up DP)  ← Used in final solution
 *
 * ------------------------------------------------------------
 * APPROACH 1: RECURSION
 *
 * At cell (r,c) we can move to:
 *
 *      (r+1, c)
 *      (r+1, c-1)
 *      (r+1, c+1)
 *
 * Recurrence:
 *
 *      f(r,c) =
 *          matrix[r][c] +
 *          min(
 *               f(r+1,c),
 *               f(r+1,c-1),
 *               f(r+1,c+1)
 *             )
 *
 * Base case:
 *
 *      r == n-1
 *
 * ------------------------------------------------------------
 * APPROACH 2: MEMOIZATION
 *
 * Store results in dp to avoid repeated calculations.
 *
 * dp[r][c] stores the minimum falling path
 * starting from (r,c).
 *
 * ------------------------------------------------------------
 * APPROACH 3: TABULATION (BOTTOM-UP)
 *
 * Start from the second last row
 * and build answers upward.
 *
 * Let:
 *
 *      dp[i][j] = minimum falling path starting at (i,j)
 *
 * Transition:
 *
 *      dp[i][j] =
 *          matrix[i][j] +
 *          min(
 *              dp[i+1][j],
 *              dp[i+1][j-1],
 *              dp[i+1][j+1]
 *             )
 *
 * Boundary checks required for j-1 and j+1.
 *
 * Final answer:
 *
 *      minimum value in dp[0][j]
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * matrix =
 *
 *      2 1 3
 *      6 5 4
 *      7 8 9
 *
 * DP after computation:
 *
 *      13 12 13
 *      13 13 13
 *       7  8  9
 *
 * Answer = 12
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 *      O(n²)
 *
 * Space Complexity:
 *      O(n²)
 *
 * Space can be optimized to O(n).
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTE:
 *
 * This is a classic grid DP problem similar to:
 *
 *      • Triangle Minimum Path Sum
 *      • Minimum Path Sum
 */

class Solution {
private:

    /*--------------------------------------------------
      MEMOIZATION (Top-Down)
    --------------------------------------------------*/
    int solve(int r, int c, int n,
              vector<vector<int>>& matrix,
              vector<vector<int>>& dp) {

        if(c < 0 || c >= n)
            return 1e9;

        if(r == n-1)
            return matrix[r][c];

        if(dp[r][c] != INT_MAX)
            return dp[r][c];

        int leftDiag  = solve(r+1, c-1, n, matrix, dp);
        int down      = solve(r+1, c,   n, matrix, dp);
        int rightDiag = solve(r+1, c+1, n, matrix, dp);

        return dp[r][c] =
               matrix[r][c] +
               min({leftDiag, down, rightDiag});
    }

public:

    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();

        /*--------------------------------------------------
          TABULATION (Bottom-Up DP)
        --------------------------------------------------*/

        vector<vector<int>> dp = matrix;

        for(int i = n-2; i >= 0; i--){

            for(int j = 0; j < n; j++){

                int down = dp[i+1][j];

                int left =
                    (j > 0)
                    ? dp[i+1][j-1]
                    : INT_MAX;

                int right =
                    (j < n-1)
                    ? dp[i+1][j+1]
                    : INT_MAX;

                dp[i][j] =
                    dp[i][j] +
                    min({down, left, right});
            }
        }

        return *min_element(dp[0].begin(), dp[0].end());
    }
};

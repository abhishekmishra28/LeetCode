/*
 * Problem: 120. Triangle
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given a triangle array, return the minimum path sum
 * from top to bottom.
 *
 * At each step you may move to:
 *
 *      directly below
 *      diagonally below-right
 *
 * ------------------------------------------------------------
 * Example:
 *
 * triangle =
 *
 *      [2]
 *     [3,4]
 *    [6,5,7]
 *   [4,1,8,3]
 *
 * Possible path:
 *
 * 2 → 3 → 5 → 1
 *
 * Minimum sum = 11
 *
 * ------------------------------------------------------------
 * APPROACHES:
 *
 * 1️⃣ Recursion (Brute Force)
 * 2️⃣ Memoization (Top-Down DP)
 * 3️⃣ Tabulation (Bottom-Up DP)
 *
 * ------------------------------------------------------------
 * APPROACH 1: RECURSION
 *
 * At position (r,c) we have two choices:
 *
 *      down  → (r+1, c)
 *      diag  → (r+1, c+1)
 *
 * Recurrence:
 *
 *      f(r,c) =
 *          triangle[r][c] +
 *          min(f(r+1,c), f(r+1,c+1))
 *
 * Base case:
 *
 *      r == last row
 *
 * ------------------------------------------------------------
 * APPROACH 2: MEMOIZATION
 *
 * Store results in dp to avoid recomputation.
 *
 * dp[r][c] stores minimum path sum from (r,c).
 *
 * ------------------------------------------------------------
 * APPROACH 3: TABULATION (BOTTOM-UP)
 *
 * Start from the last row and move upward.
 *
 * For each cell:
 *
 *      dp[i][j] =
 *          triangle[i][j] +
 *          min(dp[i+1][j], dp[i+1][j+1])
 *
 * Final answer:
 *
 *      dp[0][0]
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
 * Can be optimized to O(n) space.
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTE:
 *
 * Classic DP triangle problem.
 * Often asked to implement all three approaches.
 */

class Solution {
private:

    /*--------------------------------------------------
      1️⃣ RECURSION
    --------------------------------------------------*/
    int solve(int r, int c, vector<vector<int>> &t) {

        if(r == t.size() - 1)
            return t[r][c];

        int down = solve(r + 1, c, t);
        int diag = solve(r + 1, c + 1, t);

        return t[r][c] + min(down, diag);
    }

    /*--------------------------------------------------
      2️⃣ MEMOIZATION
    --------------------------------------------------*/
    int memo(int r, int c,
             vector<vector<int>> &t,
             vector<vector<int>> &dp) {

        if(r == t.size() - 1)
            return t[r][c];

        if(dp[r][c] != INT_MAX)
            return dp[r][c];

        int down = memo(r + 1, c, t, dp);
        int diag = memo(r + 1, c + 1, t, dp);

        return dp[r][c] = t[r][c] + min(down, diag);
    }

public:

    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();

        /*--------------------------------------------------
          TABULATION (BOTTOM-UP DP)
        --------------------------------------------------*/

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Copy last row
        for(int k = 0; k < n; k++){
            dp[n-1][k] = triangle[n-1][k];
        }

        // Fill from bottom to top
        for(int i = n-2; i >= 0; i--){
            for(int j = 0; j <= i; j++){

                int down = dp[i+1][j];
                int diag = dp[i+1][j+1];

                dp[i][j] = triangle[i][j] +
                           min(down, diag);
            }
        }

        return dp[0][0];
    }
};

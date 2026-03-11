/*
 * Problem: 63. Unique Paths II
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * A robot is located at the top-left corner of an m × n grid.
 *
 * The robot wants to reach the bottom-right corner.
 *
 * The robot can move only:
 *
 *      → Right
 *      ↓ Down
 *
 * However, some cells contain obstacles.
 *
 * In the grid:
 *
 *      0 → empty cell
 *      1 → obstacle
 *
 * The robot cannot pass through obstacle cells.
 *
 * Return the number of unique paths to reach the
 * bottom-right corner.
 *
 * ------------------------------------------------------------
 * KEY DIFFERENCE FROM "UNIQUE PATHS":
 *
 * In the basic problem every cell was reachable.
 *
 * Here obstacles block certain paths,
 * so those cells must contribute 0 paths.
 *
 * ------------------------------------------------------------
 * APPROACH: Dynamic Programming (Grid DP)
 *
 * ------------------------------------------------------------
 * CORE IDEA:
 *
 * Let:
 *
 *      dp[i][j] = number of ways to reach cell (i, j)
 *
 * If the cell has an obstacle:
 *
 *      dp[i][j] = 0
 *
 * Otherwise the robot can come from:
 *
 *      top cell      → dp[i-1][j]
 *      left cell     → dp[i][j-1]
 *
 * So:
 *
 *      dp[i][j] = dp[i-1][j] + dp[i][j-1]
 *
 * ------------------------------------------------------------
 * BASE CONDITION:
 *
 * If the starting cell has an obstacle:
 *
 *      grid[0][0] == 1
 *
 * then no path exists → return 0.
 *
 * Otherwise:
 *
 *      dp[0][0] = 1
 *
 * ------------------------------------------------------------
 * ALGORITHM STEPS:
 *
 * 1️⃣ Create a DP grid of size m × n initialized to 0.
 *
 * 2️⃣ If the start cell is blocked → return 0.
 *
 * 3️⃣ Set:
 *
 *      dp[0][0] = 1
 *
 * 4️⃣ Traverse each cell:
 *
 *      If obstacle:
 *          dp[i][j] = 0
 *
 *      Otherwise:
 *
 *          dp[i][j] += dp[i-1][j]
 *          dp[i][j] += dp[i][j-1]
 *
 * 5️⃣ Return dp[m-1][n-1].
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * grid =
 *
 *      0 0 0
 *      0 1 0
 *      0 0 0
 *
 * DP Table:
 *
 *      1 1 1
 *      1 0 1
 *      1 1 2
 *
 * Answer = 2
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
 * This can be optimized to O(n)
 * using a single row DP array.
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * Very common grid dynamic programming problem.
 * Often appears with variations like:
 *
 *      • Minimum Path Sum
 *      • Unique Paths
 *      • Grid obstacles
 */

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        // If starting cell has obstacle
        if(grid[0][0] == 1)
            return 0;

        dp[0][0] = 1;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                if(grid[i][j] == 1){
                    dp[i][j] = 0;
                    continue;
                }

                if(i > 0)
                    dp[i][j] += dp[i-1][j];

                if(j > 0)
                    dp[i][j] += dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};

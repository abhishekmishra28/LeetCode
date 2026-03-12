/*
 * Problem: 221. Maximal Square
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given an m × n binary matrix filled with '0' and '1',
 * find the largest square containing only '1's
 * and return its AREA.
 *
 * ------------------------------------------------------------
 * EXAMPLE:
 *
 * Input matrix:
 *
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 *
 * Largest square of 1's:
 *
 * 1 1
 * 1 1
 *
 * Side length = 2
 *
 * Area = 2² = 4
 *
 * ------------------------------------------------------------
 * KEY IDEA:
 *
 * Let:
 *
 *      dp[i][j] = size of the largest square
 *                 whose TOP-LEFT corner is (i, j)
 *
 * If mat[i][j] == '1', we can form a square only if
 * the three neighboring squares also allow expansion.
 *
 * So:
 *
 *      dp[i][j] = 1 + min(
 *                          right,
 *                          down,
 *                          diagonal
 *                       )
 *
 * where:
 *
 *      right    = dp[i][j+1]
 *      down     = dp[i+1][j]
 *      diagonal = dp[i+1][j+1]
 *
 * ------------------------------------------------------------
 * WHY THIS WORKS:
 *
 * A square of size k can exist at (i,j) only if
 * the right, down, and diagonal neighbors
 * can support at least size (k-1).
 *
 * ------------------------------------------------------------
 * TRAVERSAL ORDER:
 *
 * We compute DP from bottom-right → top-left
 * because each state depends on future cells.
 *
 * ------------------------------------------------------------
 * ALGORITHM STEPS:
 *
 * 1️⃣ Create dp matrix of size (m+1) × (n+1)
 *    initialized with 0.
 *
 * 2️⃣ Traverse matrix from bottom-right.
 *
 * 3️⃣ If mat[i][j] == '1':
 *
 *        dp[i][j] = 1 + min(
 *                            dp[i+1][j],
 *                            dp[i][j+1],
 *                            dp[i+1][j+1]
 *                         )
 *
 * 4️⃣ Track maximum square side length.
 *
 * 5️⃣ Return area = side².
 *
 * ------------------------------------------------------------
 * DRY RUN:
 *
 * Matrix:
 *
 * 1 1
 * 1 1
 *
 * DP table (side lengths):
 *
 * 2 1
 * 1 1
 *
 * Largest side = 2
 * Area = 4
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
 * Can be reduced to O(n) using rolling arrays.
 */

class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        int maxi = 0;

        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){

                if(mat[i][j] == '1'){

                    int right = dp[i + 1][j];
                    int down  = dp[i][j + 1];
                    int diag  = dp[i + 1][j + 1];

                    dp[i][j] = 1 + min({right, down, diag});

                    maxi = max(maxi, dp[i][j]);
                }
            }
        }

        return maxi * maxi;
    }
};

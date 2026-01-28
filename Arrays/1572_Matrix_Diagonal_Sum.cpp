/*
 * Problem: 1572. Matrix Diagonal Sum
 *
 * Statement:
 * You are given a square matrix `mat` of size n × n.
 *
 * Return the sum of:
 *  - Primary diagonal elements  (top-left → bottom-right)
 *  - Secondary diagonal elements (top-right → bottom-left)
 *
 * If an element lies on BOTH diagonals (center element in odd n),
 * it should be counted ONLY ONCE.
 *
 * ------------------------------------------------------------
 * APPROACH: Single Pass Diagonal Traversal — Your Approach
 *
 * Core Idea:
 *
 * - Traverse the matrix row by row
 * - At each row i:
 *     • Primary diagonal element is mat[i][i]
 *     • Secondary diagonal element is mat[i][n - i - 1]
 *
 * - Add both diagonals
 * - If n is odd, subtract the middle element once
 *   because it gets counted twice
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. Let n = size of matrix
 *
 * 2. Initialize:
 *      primary   = 0
 *      secondary = 0
 *
 * 3. Loop for i from 0 to n-1:
 *
 *      primary   += mat[i][i]
 *      secondary += mat[i][n - i - 1]
 *
 * 4. Compute total sum:
 *
 *      sum = primary + secondary
 *
 * 5. Handle double-counted center (only if n is odd):
 *
 *      if (n % 2 == 1):
 *          sum -= mat[n/2][n/2]
 *
 * 6. Return sum
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Every diagonal element is visited exactly once
 * - Middle element (for odd n) lies on both diagonals
 * - Explicit subtraction avoids double counting
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * mat =
 * [
 *  [1, 2, 3],
 *  [4, 5, 6],
 *  [7, 8, 9]
 * ]
 *
 * Primary diagonal:   1 + 5 + 9 = 15
 * Secondary diagonal: 3 + 5 + 7 = 15
 *
 * Total = 30
 * Center element = 5 (counted twice)
 *
 * Final Answer = 30 - 5 = 25
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - n = 1 → only one element, counted once
 * - Even n → no overlapping center
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - O(n)
 *   Single traversal of rows
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(1)
 *   Constant extra space
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Matrix Diagonal Traversal"
 *
 * Seen in:
 * - Matrix sum problems
 * - Grid-based computations
 * - Diagonal pattern questions
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int primary = 0;
        int secondary = 0;

        for (int i = 0; i < n; i++) {
            primary += mat[i][i];
            secondary += mat[i][n - i - 1];
        }

        int sum = primary + secondary;

        // Remove double-counted center element (if n is odd)
        if (n % 2 == 1)
            sum -= mat[n / 2][n / 2];

        return sum;
    }
};

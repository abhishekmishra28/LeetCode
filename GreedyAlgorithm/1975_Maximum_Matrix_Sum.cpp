/*
 * Problem: 1975. Maximum Matrix Sum
 *
 * Statement:
 * You are given an n × m integer matrix.
 * You are allowed to perform the following operation any number of times:
 *
 * - Choose any two adjacent elements and multiply BOTH by -1.
 *
 * Return the MAXIMUM possible sum of all elements of the matrix
 * after applying the operations optimally.
 *
 * ------------------------------------------------------------
 * Key Observations:
 *
 * - Multiplying two adjacent elements by -1 does NOT change
 *   the parity (even/odd) of the count of negative numbers
 *
 * - The absolute value of elements never changes
 * - Only the SIGNS of elements can change
 *
 * ------------------------------------------------------------
 * Core Insight:
 *
 * The maximum possible sum is achieved by:
 * 👉 Making as many elements POSITIVE as possible
 *
 * BUT there is a constraint:
 * - If the total number of negative elements is EVEN,
 *   we can make ALL elements positive
 * - If the total number of negative elements is ODD,
 *   exactly ONE element must remain negative
 *
 * ------------------------------------------------------------
 * Optimal Strategy:
 *
 * 1) Convert ALL elements to their absolute values
 * 2) Count how many negative elements were originally present
 * 3) Track the MINIMUM absolute value in the matrix
 *
 * Why track minimum absolute value?
 * - If one element MUST remain negative (odd negatives),
 *   we want the SMALLEST possible loss
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Approach):
 *
 * 1. Initialize:
 *    - sum = 0 → sum of absolute values
 *    - cntNeg = 0 → count of negative numbers
 *    - minNeg = +∞ → minimum absolute value
 *
 * 2. Traverse the matrix:
 *    - If element < 0 → increment cntNeg
 *    - Add abs(element) to sum
 *    - Update minNeg = min(minNeg, abs(element))
 *
 * 3. If cntNeg is EVEN:
 *    - All elements can be made positive
 *    - Return sum
 *
 * 4. If cntNeg is ODD:
 *    - One element must stay negative
 *    - Subtract twice the smallest absolute value
 *    - Return sum - 2 × minNeg
 *
 * ------------------------------------------------------------
 * Why subtract 2 × minNeg?
 *
 * - The element minNeg was counted as +minNeg
 * - Keeping it negative changes it to -minNeg
 * - Net loss = minNeg + minNeg = 2 × minNeg
 *
 * ------------------------------------------------------------
 * Example:
 *
 * matrix = [[1, -2],
 *           [-3, 4]]
 *
 * Absolute sum = 1 + 2 + 3 + 4 = 10
 * cntNeg = 2 (even)
 * Answer = 10
 *
 * ------------------------------------------------------------
 * Example 2:
 *
 * matrix = [[1, -2],
 *           [-3, -4]]
 *
 * Absolute sum = 1 + 2 + 3 + 4 = 10
 * cntNeg = 3 (odd)
 * minNeg = 1
 * Answer = 10 - 2 = 8
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Matrix with all positive values
 * - Matrix with all negative values
 * - Matrix containing zeros (minNeg = 0 → no loss)
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n × m)
 *   Single traversal of the matrix
 *
 * Space Complexity:
 * - O(1)
 *   Only constant extra variables
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Greedy + Parity of Negatives" problem
 *
 * Similar ideas appear in:
 * - Maximize array sum after K negations
 * - Sign-flipping optimization problems
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        long long sum = 0;
        int minNeg = INT_MAX;
        int cntNeg = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (matrix[i][j] < 0)
                    cntNeg++;

                minNeg = min(minNeg, abs(matrix[i][j]));
                sum += llabs(matrix[i][j]);
            }
        }

        // If even negatives → all positive possible
        if (cntNeg % 2 == 0)
            return sum;

        // Otherwise one smallest value must stay negative
        return sum - 2LL * minNeg;
    }
};

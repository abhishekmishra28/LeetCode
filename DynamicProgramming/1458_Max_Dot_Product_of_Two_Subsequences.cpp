/*
 * Problem: 1458. Max Dot Product of Two Subsequences
 *
 * Statement:
 * You are given two integer arrays `nums1` and `nums2`.
 * Your task is to find the MAXIMUM dot product of two NON-EMPTY subsequences
 * (one from nums1 and one from nums2) of equal length.
 *
 * The dot product of two sequences a and b is:
 *     a[0]*b[0] + a[1]*b[1] + ... + a[k]*b[k]
 *
 * ------------------------------------------------------------
 * Key Challenges:
 *
 * - Subsequences must be NON-EMPTY
 * - Arrays may contain NEGATIVE numbers
 * - We cannot simply skip everything (must pick at least one pair)
 *
 * ------------------------------------------------------------
 * Core Insight:
 *
 * This is a classic Dynamic Programming problem similar to LCS,
 * but instead of matching characters, we are maximizing a numeric value.
 *
 * At every position (i, j), we have four choices:
 *
 * 1) Take nums1[i] and nums2[j] as a NEW subsequence
 * 2) Take nums1[i] and nums2[j] AND extend an existing subsequence
 * 3) Skip nums1[i]
 * 4) Skip nums2[j]
 *
 * ------------------------------------------------------------
 * DP Definition:
 *
 * dp[i][j] = maximum dot product we can achieve using:
 *            nums1[i ... end] and nums2[j ... end]
 *
 * dp array is initialized with INT_MIN to correctly handle
 * cases where all products are negative.
 *
 * ------------------------------------------------------------
 * Transition Logic (Your Exact Approach):
 *
 * For each (i, j):
 *
 * take      = nums1[i] * nums2[j]
 *
 * takeMore = take + dp[i+1][j+1]
 *            (only if i+1 < n and j+1 < m)
 *
 * skip1    = dp[i+1][j]   // skip element from nums1
 * skip2    = dp[i][j+1]   // skip element from nums2
 *
 * dp[i][j] = max(take, takeMore, skip1, skip2)
 *
 * ------------------------------------------------------------
 * Why `take` is considered separately?
 *
 * - Because subsequences must be NON-EMPTY
 * - dp[i+1][j+1] might be INT_MIN
 * - Taking a single pair alone may give the best result
 *
 * ------------------------------------------------------------
 * Iteration Order:
 *
 * - We fill the DP table from bottom-right to top-left
 * - This ensures dp[i+1][*] and dp[*][j+1] are already computed
 *
 * ------------------------------------------------------------
 * Example:
 *
 * nums1 = [2,1,-2,5]
 * nums2 = [3,0,-6]
 *
 * Best subsequence:
 * [2, -2] · [3, -6] = 6 + 12 = 18
 *
 * Output = 18
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - All numbers negative
 * - One array much larger than the other
 * - Best answer uses only one pair
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n × m)
 *
 * Space Complexity:
 * - O(n × m)
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This problem is a variant of:
 *   - LCS (Longest Common Subsequence)
 *   - Sequence DP with optimization objective
 *
 * Requires careful handling of NEGATIVE values.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        // dp[i][j] = max dot product from nums1[i..] and nums2[j..]
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MIN));

        // Fill DP table bottom-up
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {

                int take = nums1[i] * nums2[j];

                int takeMore = take;
                if (i + 1 < n && j + 1 < m)
                    takeMore += dp[i + 1][j + 1];

                int skip1 = dp[i + 1][j];
                int skip2 = dp[i][j + 1];

                dp[i][j] = max({take, takeMore, skip1, skip2});
            }
        }

        return dp[0][0];
    }
};

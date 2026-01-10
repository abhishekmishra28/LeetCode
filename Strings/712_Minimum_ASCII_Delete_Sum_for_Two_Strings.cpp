/*
 * Problem: 712. Minimum ASCII Delete Sum for Two Strings
 *
 * Statement:
 * You are given two strings `s1` and `s2`.
 * You can delete characters from either string.
 *
 * The cost of deleting a character is its ASCII value.
 *
 * Return the MINIMUM total ASCII value of characters
 * you must delete to make the two strings equal.
 *
 * ------------------------------------------------------------
 * Key Observations:
 *
 * - Deletions can happen in BOTH strings
 * - Order of remaining characters must be preserved
 * - This is NOT about making strings empty,
 *   but about making them IDENTICAL
 *
 * ------------------------------------------------------------
 * Core Insight:
 *
 * Instead of thinking:
 *   "Which characters should I delete?"
 *
 * Think in reverse:
 *   "Which characters should I KEEP in both strings?"
 *
 * ------------------------------------------------------------
 * Important Transformation:
 *
 * If we KEEP a common subsequence in both strings,
 * then all OTHER characters must be deleted.
 *
 * Let:
 * - TOTAL = sum of ASCII values of all characters in s1 and s2
 * - COMMON = maximum possible ASCII sum of a COMMON SUBSEQUENCE
 *
 * Then:
 *
 *   Minimum Delete Cost = TOTAL - 2 × COMMON
 *
 * Why multiply by 2?
 * - The common subsequence is kept in BOTH strings
 * - Everything else is deleted from BOTH sides
 *
 * ------------------------------------------------------------
 * APPROACH: DP on Longest Common Subsequence (ASCII-based)
 *
 * This is similar to LCS, but instead of length,
 * we maximize the ASCII SUM of the common subsequence.
 *
 * ------------------------------------------------------------
 * DP Definition:
 *
 * dp[i][j] = maximum ASCII sum of a common subsequence
 *            between:
 *              s1[0 ... i-1] and s2[0 ... j-1]
 *
 * ------------------------------------------------------------
 * DP Transitions (Your Exact Logic):
 *
 * If s1[i-1] == s2[j-1]:
 *    dp[i][j] = dp[i-1][j-1] + ASCII(s1[i-1])
 *
 * Else:
 *    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm:
 *
 * 1. Create a DP table of size (n+1) × (m+1)
 *    initialized with 0
 *
 * 2. Fill the DP table using the rules above
 *
 * 3. Compute TOTAL ASCII sum of all characters
 *    in both strings
 *
 * 4. Answer = TOTAL - 2 × dp[n][m]
 *
 * ------------------------------------------------------------
 * Example:
 *
 * s1 = "sea"
 * s2 = "eat"
 *
 * ASCII values:
 * s = 115, e = 101, a = 97, t = 116
 *
 * TOTAL = 115 + 101 + 97 + 101 + 97 + 116 = 627
 *
 * Common subsequence = "ea"
 * ASCII sum = 101 + 97 = 198
 *
 * Answer = 627 - 2 × 198 = 231
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - One string empty → delete all characters of other
 * - No common characters
 * - Strings already equal → cost = 0
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n × m)
 *   Standard 2D DP
 *
 * Space Complexity:
 * - O(n × m)
 *   DP table
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - We keep the most "valuable" common subsequence
 * - Everything else is optimally deleted
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "LCS-style DP with cost optimization"
 *
 * Related problems:
 * - Longest Common Subsequence
 * - Edit Distance
 * - String alignment problems
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();

        // dp[i][j] = max ASCII sum of common subsequence
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (s1[i] == s2[j])
                    dp[i + 1][j + 1] = dp[i][j] + s1[i];
                else
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }

        // Total ASCII sum of both strings
        int total = 0;
        for (char c : s1) total += c;
        for (char c : s2) total += c;

        // Minimum delete sum
        return total - 2 * dp[n][m];
    }
};

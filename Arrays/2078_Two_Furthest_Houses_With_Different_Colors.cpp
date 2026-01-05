/*
 * Problem: 2078. Two Furthest Houses With Different Colors
 *
 * Statement:
 * You are given an array `colors` where colors[i] represents the color
 * of the i-th house.
 *
 * Your task is to find the MAXIMUM distance between two houses
 * such that their colors are DIFFERENT.
 *
 * Distance between house i and j is defined as |i - j|.
 *
 * ------------------------------------------------------------
 * Key Observations:
 *
 * - We need two indices i and j:
 *     • colors[i] != colors[j]
 *     • |i - j| is maximized
 *
 * - The maximum distance in an array is always achieved
 *   by using one of the ENDPOINTS (0 or n-1)
 *
 * Why?
 * - Any middle-to-middle distance is smaller than an end-to-end distance
 *
 * ------------------------------------------------------------
 * Core Insight:
 *
 * The answer must involve:
 * - Either the FIRST house (index 0)
 * - Or the LAST house (index n-1)
 *
 * So we only need to check:
 * 1) Farthest house from index 0 with a different color
 * 2) Farthest house from index n-1 with a different color
 *
 * ------------------------------------------------------------
 * Your Exact Approach:
 *
 * - Fix the first house (index 0):
 *     → Find the farthest index i where colors[i] != colors[0]
 *     → Distance = i
 *
 * - Fix the last house (index n-1):
 *     → Find the farthest index i where colors[i] != colors[n-1]
 *     → Distance = (n - 1 - i)
 *
 * - Take the maximum of all valid distances
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm:
 *
 * 1. Initialize:
 *    - n = size of array
 *    - ans = 0
 *
 * 2. Loop through all indices i from 0 to n-1:
 *
 *    a) If colors[i] != colors[0]:
 *         ans = max(ans, i)
 *
 *    b) If colors[i] != colors[n-1]:
 *         ans = max(ans, n - 1 - i)
 *
 * 3. Return ans
 *
 * ------------------------------------------------------------
 * Example:
 *
 * Input:
 * colors = [1,1,1,6,1,1,1]
 *
 * - Compare with colors[0] = 1:
 *     i = 3 → colors[3] = 6 ≠ 1 → distance = 3
 *
 * - Compare with colors[n-1] = 1:
 *     i = 3 → colors[3] = 6 ≠ 1 → distance = 6 - 3 = 3
 *
 * Output: 3
 *
 * ------------------------------------------------------------
 * Another Example:
 *
 * colors = [1,8,3,8,3]
 *
 * - From index 0:
 *     i = 4 → colors[4] ≠ colors[0] → distance = 4
 *
 * Answer = 4
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - All houses have same color → answer = 0
 * - Only two houses → simple comparison
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n)
 *   Single pass through the array
 *
 * Space Complexity:
 * - O(1)
 *   Constant extra space
 *
 * ------------------------------------------------------------
 * Why This Is Optimal:
 *
 * - Avoids nested loops
 * - Uses problem constraints intelligently
 * - Very clean greedy logic
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            // Compare with first house
            if (colors[i] != colors[0])
                ans = max(ans, i);

            // Compare with last house
            if (colors[i] != colors[n - 1])
                ans = max(ans, n - 1 - i);
        }

        return ans;
    }
};

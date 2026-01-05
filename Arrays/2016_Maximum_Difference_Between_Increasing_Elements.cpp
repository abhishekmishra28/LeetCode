/*
 * Problem: 2016. Maximum Difference Between Increasing Elements
 *
 * Statement:
 * You are given an integer array `nums`.
 * You need to find the maximum value of:
 *
 *     nums[j] - nums[i]
 *
 * such that:
 * - i < j
 * - nums[i] < nums[j]
 *
 * If no such pair exists, return -1.
 *
 * ------------------------------------------------------------
 * Key Observations:
 *
 * - Order matters: i must come BEFORE j
 * - We only care about increasing pairs
 * - A brute-force solution would check all pairs (i, j)
 *
 * ------------------------------------------------------------
 * APPROACH 1: Brute Force (Not Used)
 *
 * - Try all pairs (i, j) where i < j
 * - Compute nums[j] - nums[i]
 *
 * Time Complexity:
 * - O(n²) → too slow
 *
 * ------------------------------------------------------------
 * APPROACH 2: Optimal Single-Pass (Your Approach)
 *
 * Core Insight:
 *
 * - For each element nums[j], the BEST nums[i] (i < j)
 *   is the MINIMUM value seen so far before j
 *
 * - Maintain a running minimum while scanning from left to right
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm:
 *
 * 1. Initialize:
 *    - preMin = nums[0]  → smallest element so far
 *    - maxDiff = -1     → result
 *
 * 2. Traverse array from index 1 to n-1:
 *
 *    a) If nums[i] > preMin:
 *         - Update maxDiff = max(maxDiff, nums[i] - preMin)
 *
 *    b) Else:
 *         - Update preMin = nums[i]
 *
 * 3. Return maxDiff
 *
 * ------------------------------------------------------------
 * Example:
 *
 * Input:
 * nums = [7,1,5,4]
 *
 * Steps:
 * preMin = 7
 * i=1 → 1 < 7 → preMin = 1
 * i=2 → 5 > 1 → maxDiff = 4
 * i=3 → 4 > 1 → maxDiff = max(4,3) = 4
 *
 * Output: 4
 *
 * ------------------------------------------------------------
 * Example 2:
 *
 * nums = [9,4,3,2]
 *
 * No increasing pair exists
 * Output = -1
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Strictly decreasing array
 * - Array of size < 2
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n)
 *   Single pass
 *
 * Space Complexity:
 * - O(1)
 *   Constant extra space
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - At every position, we make the optimal greedy choice:
 *   use the smallest possible previous value
 *
 * - This guarantees the maximum difference
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int maxDiff = -1;
        int preMin = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] > preMin) {
                maxDiff = max(maxDiff, nums[i] - preMin);
            } else {
                preMin = nums[i];
            }
        }

        return maxDiff;
    }
};

/*
 * Problem: 1200. Minimum Absolute Difference
 *
 * Statement:
 * You are given an array of DISTINCT integers `nums`.
 *
 * Find all pairs of elements with the MINIMUM absolute difference
 * between any two elements in the array.
 *
 * Return the pairs in ascending order.
 *
 * ------------------------------------------------------------
 * APPROACH: Sorting + Adjacent Comparison (Greedy) — Your Approach
 *
 * Core Observation:
 *
 * - After sorting the array, the minimum absolute difference
 *   can ONLY occur between ADJACENT elements.
 *
 * - There is no need to compare every pair (which would be O(n²)).
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. Sort the array `nums` in ascending order
 *
 * 2. Initialize:
 *      minDiff = +∞
 *
 * 3. First pass:
 *    - Traverse from index 1 to n-1
 *    - Compute difference between adjacent elements:
 *
 *         diff = nums[i] - nums[i-1]
 *
 *    - Update:
 *         minDiff = min(minDiff, diff)
 *
 * 4. Second pass:
 *    - Again traverse adjacent pairs
 *    - If:
 *         nums[i] - nums[i-1] == minDiff
 *      then:
 *         add pair {nums[i-1], nums[i]} to result
 *
 * 5. Return the result array
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Sorting puts numbers in increasing order
 * - The smallest gap must be between neighbors
 * - This reduces complexity drastically
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * nums = [4,2,1,3]
 *
 * After sorting:
 * nums = [1,2,3,4]
 *
 * Adjacent differences:
 *   2-1 = 1
 *   3-2 = 1
 *   4-3 = 1
 *
 * minDiff = 1
 *
 * Valid pairs:
 *   [1,2], [2,3], [3,4]
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - nums size = 2 → only one possible pair
 * - Negative numbers handled naturally
 * - Large values supported
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - Sorting: O(n log n)
 * - Linear scans: O(n)
 *
 * Overall:
 *   O(n log n)
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(1) extra space (excluding output)
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Sort + Adjacent Difference" problem
 *
 * Seen in:
 * - Minimum difference problems
 * - Range minimization
 * - Greedy adjacent comparisons
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        int minDiff = INT_MAX;

        // First pass: find minimum adjacent difference
        for (int i = 1; i < n; i++) {
            minDiff = min(minDiff, nums[i] - nums[i - 1]);
        }

        // Second pass: collect all pairs with minDiff
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] == minDiff) {
                ans.push_back({nums[i - 1], nums[i]});
            }
        }
        return ans;
    }
};

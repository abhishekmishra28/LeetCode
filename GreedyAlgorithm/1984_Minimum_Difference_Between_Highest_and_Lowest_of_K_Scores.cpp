/*
 * Problem: 1984. Minimum Difference Between Highest and Lowest of K Scores
 *
 * Statement:
 * You are given an integer array `nums`, where each element represents a score,
 * and an integer `k`.
 *
 * You need to choose ANY `k` scores such that:
 *   (maximum score - minimum score) is MINIMIZED.
 *
 * Return this minimum possible difference.
 *
 * ------------------------------------------------------------
 * APPROACH: Sorting + Sliding Window (Greedy) — Your Approach
 *
 * Core Observation:
 *
 * - If we sort the array, then for any group of `k` elements:
 *     • The minimum = first element of the group
 *     • The maximum = last element of the group
 *
 * - So the difference for a group starting at index `i` is:
 *
 *       nums[i + k - 1] - nums[i]
 *
 * - We just need to check this difference for all possible
 *   contiguous subarrays of length `k` in the sorted array.
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. Sort the array `nums` in ascending order
 *
 * 2. Initialize:
 *      ans = nums[k - 1] - nums[0]
 *    (difference for the first window of size k)
 *
 * 3. Slide a window of size `k` across the array:
 *
 *      for i from 0 to n - k:
 *          diff = nums[i + k - 1] - nums[i]
 *          ans = min(ans, diff)
 *
 * 4. Return `ans`
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Sorting ensures that values in a window are ordered
 * - Any optimal group of k elements will appear as
 *   a contiguous block in the sorted array
 * - Sliding window checks all such possibilities efficiently
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * nums = [9, 4, 1, 7]
 * k = 2
 *
 * After sorting:
 * nums = [1, 4, 7, 9]
 *
 * Windows of size 2:
 *   [1, 4] → diff = 3
 *   [4, 7] → diff = 3
 *   [7, 9] → diff = 2  ← minimum
 *
 * Answer = 2
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - k == 1:
 *     Any single element → diff = 0
 *
 * - k == nums.size():
 *     diff = max(nums) - min(nums)
 *
 * - nums already sorted or reverse sorted
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - Sorting: O(n log n)
 * - Sliding window: O(n)
 *
 * Overall:
 *   O(n log n)
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(1) extra space (excluding sort stack)
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Sort + Fixed Size Sliding Window" problem
 *
 * Seen in:
 * - Score range minimization
 * - Window-based difference problems
 * - Greedy range selection
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = nums[k - 1] - nums[0];

        for (int i = 0; i + k <= n; i++) {
            ans = min(ans, nums[i + k - 1] - nums[i]);
        }
        return ans;
    }
};

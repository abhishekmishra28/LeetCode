/*
 * Problem: 16. 3Sum Closest
 *
 * Statement:
 * You are given an integer array `nums` and an integer `target`.
 *
 * Find THREE integers in `nums` such that:
 *   their sum is closest to `target`.
 *
 * Return the SUM of the three integers.
 *
 * It is guaranteed that exactly one solution exists.
 *
 * ------------------------------------------------------------
 * APPROACH: Sorting + Two Pointers (Optimal)
 *
 * This problem is a VARIANT of the classic 3Sum problem.
 *
 * Key difference:
 * - Instead of finding sum == target
 * - We track the sum that is CLOSEST to target
 *
 * ------------------------------------------------------------
 * Core Idea:
 *
 * - Sort the array
 * - Fix one element nums[i]
 * - Use two pointers to explore all possible pairs
 * - Keep updating the closest sum found so far
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. Sort the array `nums`
 *
 * 2. Initialize:
 *      closest = nums[0] + nums[1] + nums[2]
 *    This acts as the initial best answer
 *
 * 3. Loop `i` from 0 to n-3:
 *
 *    a) Skip duplicate fixed elements:
 *         if (i > 0 && nums[i] == nums[i-1]) continue;
 *
 *    b) Initialize two pointers:
 *         l = i + 1
 *         r = n - 1
 *
 *    c) While l < r:
 *
 *         sum = nums[i] + nums[l] + nums[r]
 *
 *         - If |target - sum| < |target - closest|
 *             → Update closest = sum
 *
 *         - If sum > target:
 *             → Decrease sum → r--
 *
 *         - Else if sum < target:
 *             → Increase sum → l++
 *
 *         - Else (sum == target):
 *             → This is the closest possible
 *             → Return sum immediately
 *
 * 4. After all iterations, return `closest`
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Sorting enables two-pointer optimization
 * - Every possible triplet is considered efficiently
 * - Pointer movement guarantees we move toward target
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * nums = [-1, 2, 1, -4]
 * target = 1
 *
 * After sorting:
 * nums = [-4, -1, 1, 2]
 *
 * Initial closest = -4 + -1 + 1 = -4
 *
 * i = 0:
 *   sum = -4 + -1 + 2 = -3
 *   closer than -4 → update closest = -3
 *
 * i = 1:
 *   sum = -1 + 1 + 2 = 2
 *   |1 - 2| < |1 - (-3)| → update closest = 2
 *
 * Final Answer = 2
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - nums size = exactly 3
 * - All positive or all negative numbers
 * - Target far outside possible sums
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - Sorting: O(n log n)
 * - Outer loop + two pointers: O(n²)
 *
 * Overall:
 *   O(n²)
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(1) extra space (excluding sorting stack)
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This problem follows the:
 *   "Fix One + Two Pointers" pattern
 *
 * Closely related to:
 * - 3Sum
 * - 4Sum
 * - 3Sum Smaller
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int closest = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {

            // Optional optimization: skip duplicate fixed elements
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int l = i + 1;
            int r = n - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                // Update closest sum if better
                if (abs(target - sum) < abs(target - closest)) {
                    closest = sum;
                }

                if (sum > target) {
                    r--;
                } else if (sum < target) {
                    l++;
                } else {
                    // Exact match is the closest possible
                    return sum;
                }
            }
        }
        return closest;
    }
};

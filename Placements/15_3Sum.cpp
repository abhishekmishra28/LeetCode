/*
 * Problem: 15. 3Sum
 *
 * Statement:
 * You are given an integer array `nums`.
 *
 * Return ALL UNIQUE triplets [nums[i], nums[j], nums[k]] such that:
 *
 *   nums[i] + nums[j] + nums[k] == 0
 *
 * Conditions:
 * - i, j, k are distinct indices
 * - Triplets must be UNIQUE (no duplicates)
 *
 * ------------------------------------------------------------
 * APPROACH: Sorting + Two Pointers (Optimal & Interview Standard)
 *
 * Core Idea:
 *
 * - Fix one element nums[i]
 * - Reduce the problem to:
 *
 *     Find two numbers in the remaining array
 *     whose sum is = -nums[i]
 *
 * - This becomes a classic TWO-SUM problem
 * - Sorting helps:
 *     • Use two pointers efficiently
 *     • Skip duplicates easily
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. Sort the array `nums`
 *
 * 2. Iterate `i` from 0 to n-3:
 *
 *    a) Skip duplicates for the first element:
 *
 *         if (i > 0 && nums[i] == nums[i-1]) continue;
 *
 *    b) Initialize two pointers:
 *         left  = i + 1
 *         right = n - 1
 *
 *    c) While left < right:
 *
 *         sum = nums[i] + nums[left] + nums[right]
 *
 *         Case 1: sum == 0
 *         ----------------
 *         - Valid triplet found
 *         - Store it in result
 *         - Move both pointers:
 *             left++, right--
 *
 *         - Skip duplicates:
 *             while(left < right && nums[left] == nums[left-1]) left++;
 *             while(left < right && nums[right] == nums[right+1]) right--;
 *
 *         Case 2: sum < 0
 *         ----------------
 *         - Need a larger sum
 *         - Move left pointer to the right
 *
 *         Case 3: sum > 0
 *         ----------------
 *         - Need a smaller sum
 *         - Move right pointer to the left
 *
 * 3. Continue until all i are processed
 *
 * ------------------------------------------------------------
 * Why Duplicate Handling is Important:
 *
 * - Sorting groups equal values together
 * - Skipping duplicates ensures:
 *     • No repeated triplets in output
 *     • Each unique combination is added once
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * nums = [-1, 0, 1, 2, -1, -4]
 *
 * After sorting:
 * nums = [-4, -1, -1, 0, 1, 2]
 *
 * i = 1 → nums[i] = -1
 * left = 2, right = 5
 *
 * sum = -1 + (-1) + 2 = 0 ✔
 * → add [-1, -1, 2]
 *
 * Move pointers and skip duplicates
 *
 * Next valid:
 * → [-1, 0, 1]
 *
 * Final Answer:
 * [[-1, -1, 2], [-1, 0, 1]]
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Array with fewer than 3 elements → return []
 * - All zeros → one valid triplet [0,0,0]
 * - No valid triplet → return []
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - Sorting: O(n log n)
 * - Two-pointer scan inside loop: O(n)
 *
 * Overall:
 *   O(n²)
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(1) extra space (excluding result array)
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Fix one + Two Pointer" pattern
 *
 * Used in:
 * - 3Sum
 * - 4Sum
 * - Closest Sum problems
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {

            // Skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;

                    // Skip duplicates for left and right
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;

                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return res;
    }
};

/*
 * Problem: 724. Find Pivot Index
 *
 * Statement:
 * You are given an integer array `nums`.
 *
 * The pivot index is an index `i` such that:
 *
 *   sum of elements to the LEFT of i
 *        ==
 *   sum of elements to the RIGHT of i
 *
 * If no such index exists, return -1.
 * If multiple pivot indices exist, return the LEFTMOST one.
 *
 * ------------------------------------------------------------
 * APPROACH: Prefix Sum / Running Sum — Your Approach
 *
 * Core Idea:
 *
 * - Instead of recalculating left and right sums for every index
 *   (which would be O(n²)),
 *   we maintain a running `leftSum`.
 *
 * - If we know the TOTAL sum of the array,
 *   the right sum at index i can be computed as:
 *
 *       rightSum = totalSum - leftSum - nums[i]
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. Compute the total sum of the array:
 *
 *      total = sum(nums)
 *
 * 2. Initialize:
 *
 *      leftSum = 0
 *
 * 3. Traverse the array from index 0 to n-1:
 *
 *      For each index i:
 *
 *      a) Compute rightSum:
 *
 *           rightSum = total - leftSum - nums[i]
 *
 *      b) If leftSum == rightSum:
 *           → i is the pivot index
 *           → return i
 *
 *      c) Update leftSum:
 *
 *           leftSum += nums[i]
 *
 * 4. If no pivot index is found:
 *      → return -1
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - leftSum stores sum of elements before index i
 * - total - leftSum - nums[i] gives sum after index i
 * - Only one pass is needed
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * nums = [1, 7, 3, 6, 5, 6]
 *
 * total = 28
 *
 * i = 0:
 *   leftSum = 0
 *   rightSum = 28 - 0 - 1 = 27 → not equal
 *
 * i = 1:
 *   leftSum = 1
 *   rightSum = 28 - 1 - 7 = 20 → not equal
 *
 * i = 2:
 *   leftSum = 8
 *   rightSum = 28 - 8 - 3 = 17 → not equal
 *
 * i = 3:
 *   leftSum = 11
 *   rightSum = 28 - 11 - 6 = 11 → ✔ pivot found
 *
 * Answer = 3
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Pivot at index 0:
 *     leftSum = 0
 *
 * - Pivot at last index:
 *     rightSum = 0
 *
 * - Single element array:
 *     index 0 is the pivot
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - O(n)
 *   Single pass through the array
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(1)
 *   Only constant extra space
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Prefix Sum / Running Sum" problem
 *
 * Seen in:
 * - Balance index problems
 * - Partitioning arrays
 * - Range sum optimizations
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int leftSum = 0;
        int total = accumulate(nums.begin(), nums.end(), 0);

        for (int i = 0; i < n; i++) {
            int rightSum = total - leftSum - nums[i];
            if (leftSum == rightSum)
                return i;
            leftSum += nums[i];
        }
        return -1;
    }
};

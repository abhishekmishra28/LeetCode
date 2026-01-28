/*
 * Problem: 303. Range Sum Query – Immutable
 *
 * Statement:
 * You are given an integer array `nums`.
 *
 * You need to implement a class `NumArray` that supports:
 *
 *   - NumArray(nums): initializes the object with the integer array
 *   - sumRange(left, right): returns the sum of elements
 *     between indices `left` and `right` (inclusive)
 *
 * Important:
 * - The array is IMMUTABLE (no updates)
 * - Multiple sumRange queries will be asked
 *
 * ------------------------------------------------------------
 * APPROACH: Prefix Sum Array — Your Approach
 *
 * Core Idea:
 *
 * - Directly computing sum for each query would take O(n)
 * - With multiple queries, this becomes inefficient
 *
 * - Instead, PRECOMPUTE prefix sums so that:
 *
 *     sum(left, right) =
 *        prefix[right] - prefix[left - 1]
 *
 * ------------------------------------------------------------
 * What is a Prefix Sum?
 *
 * prefix[i] = sum of elements from index 0 to i
 *
 * Example:
 * nums = [2, 4, 6, 8]
 *
 * prefix = [2, 6, 12, 20]
 *
 * ------------------------------------------------------------
 * Constructor Logic: NumArray(nums)
 *
 * 1. Create a prefix array of same size as nums
 *
 * 2. Initialize:
 *      prefix[0] = nums[0]
 *
 * 3. Build prefix sums:
 *
 *      for i = 1 to n-1:
 *          prefix[i] = nums[i] + prefix[i-1]
 *
 * This preprocessing is done ONCE.
 *
 * ------------------------------------------------------------
 * Query Logic: sumRange(left, right)
 *
 * Case 1: left == 0
 * --------------------------------
 * - Sum from index 0 to right:
 *     return prefix[right]
 *
 * Case 2: left > 0
 * --------------------------------
 * - Subtract the prefix before `left`:
 *
 *     return prefix[right] - prefix[left - 1]
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - prefix[right] contains sum from 0 → right
 * - prefix[left-1] contains sum from 0 → left-1
 * - Subtracting removes unwanted part
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * nums = [-2, 0, 3, -5, 2, -1]
 *
 * prefix = [-2, -2, 1, -4, -2, -3]
 *
 * Query: sumRange(2, 5)
 *
 * result = prefix[5] - prefix[1]
 *        = -3 - (-2)
 *        = -1
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - left == right → return nums[left]
 * - left == 0
 * - Single element array
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * Constructor:
 * - O(n)  (building prefix array)
 *
 * sumRange:
 * - O(1)  (constant-time query)
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(n)
 *   Prefix array storage
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Prefix Sum / Cumulative Sum" problem
 *
 * Seen in:
 * - Range sum queries
 * - Subarray sum problems
 * - 2D matrix sum queries
 */

#include <bits/stdc++.h>
using namespace std;

class NumArray {
private:
    vector<long long> prefix;

public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix.resize(n);

        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = nums[i] + prefix[i - 1];
        }
    }

    int sumRange(int left, int right) {
        if (left == 0) {
            return prefix[right];
        }
        return prefix[right] - prefix[left - 1];
    }
};

/**
 * Usage:
 * NumArray* obj = new NumArray(nums);
 * int result = obj->sumRange(left, right);
 */

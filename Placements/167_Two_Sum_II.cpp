/*
 * Problem: 167. Two Sum II – Input Array Is Sorted
 *
 * Statement:
 * You are given a 1-indexed array `numbers` that is already SORTED
 * in non-decreasing order, and an integer `target`.
 *
 * Find TWO numbers such that:
 *   numbers[i] + numbers[j] == target
 *
 * Return their indices as:
 *   [i + 1, j + 1]
 *
 * Constraints:
 * - Exactly one valid solution exists
 * - You may NOT use the same element twice
 * - Must use O(1) extra space
 *
 * ------------------------------------------------------------
 * APPROACH: Two Pointers (Optimal & Expected)
 *
 * Core Idea:
 *
 * - Since the array is SORTED:
 *     • If the sum is too small → move left pointer right
 *     • If the sum is too large → move right pointer left
 *
 * This allows us to find the solution in ONE PASS.
 *
 * ------------------------------------------------------------
 * Pointer Strategy:
 *
 * - `lo` → starts at the beginning (index 0)
 * - `hi` → starts at the end (index n-1)
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. Initialize:
 *      lo = 0
 *      hi = n - 1
 *
 * 2. While lo < hi:
 *
 *    a) Compute:
 *         sum = numbers[lo] + numbers[hi]
 *
 *    b) If sum == target:
 *         → Found the answer
 *         → Return {lo + 1, hi + 1}
 *           (because array is 1-indexed)
 *
 *    c) If sum > target:
 *         → We need a smaller sum
 *         → Move right pointer left:
 *             hi--
 *
 *    d) If sum < target:
 *         → We need a larger sum
 *         → Move left pointer right:
 *             lo++
 *
 * 3. The loop always finds the solution due to problem guarantee
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * numbers = [2, 7, 11, 15]
 * target = 9
 *
 * lo = 0 (2), hi = 3 (15)
 * sum = 17 > 9 → hi--
 *
 * lo = 0 (2), hi = 1 (7)
 * sum = 9 ✔
 *
 * return {1, 2}
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Sorted array guarantees monotonic behavior
 * - Moving pointers reduces the search space every step
 * - No extra memory required
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Minimum size array (n = 2)
 * - Negative numbers
 * - Large values
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n)
 *   Single pass using two pointers
 *
 * Space Complexity:
 * - O(1)
 *   Constant extra space
 *
 * ------------------------------------------------------------
 * Comparison with Two Sum (Unsorted):
 *
 * | Problem Type | Approach | Time | Space |
 * |-------------|----------|------|-------|
 * | Unsorted | Hash Map | O(n) | O(n) |
 * | Sorted | Two Pointers | O(n) | O(1) |
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Two Pointers on Sorted Array"
 *
 * Used in:
 * - Two Sum II
 * - Pair with given sum
 * - Container with most water
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int lo = 0;
        int hi = n - 1;

        while (lo < hi) {
            int sum = numbers[lo] + numbers[hi];

            if (sum == target) {
                // +1 because the array is 1-indexed
                return {lo + 1, hi + 1};
            } else if (sum > target) {
                hi--;
            } else {
                lo++;
            }
        }
        return {-1, -1}; // guaranteed not to reach here
    }
};

/*
 * Problem: 3804. Number of Centered Subarrays
 *
 * Statement:
 * You are given an integer array `nums`.
 *
 * A subarray nums[l ... r] is called a **CENTERED subarray** if:
 *
 *   (sum of elements in the subarray)
 *        ==
 *   (one of the elements present inside that subarray)
 *
 * Your task is to count the total number of such centered subarrays.
 *
 * ------------------------------------------------------------
 * Key Observations:
 *
 * - We need to consider ALL possible subarrays
 * - For each subarray:
 *     • Compute its sum
 *     • Check whether this sum equals ANY element inside it
 *
 * - Order matters → subarray must be contiguous
 *
 * ------------------------------------------------------------
 * Approach: Brute Force with Prefix Expansion (Your Approach)
 *
 * Core Idea:
 * - Fix the starting index `i`
 * - Extend the subarray to the right (ending index `j`)
 * - Maintain:
 *     • running sum of the subarray
 *     • a set of elements present in the subarray
 *
 * If at any point:
 *     sum ∈ elements of subarray
 * → this subarray is CENTERED
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Approach):
 *
 * 1. Initialize:
 *    - n = size of nums
 *    - ans = 0 → total centered subarrays
 *
 * 2. Loop over all possible starting indices `i`:
 *
 *    a) Initialize:
 *       - sum = 0
 *       - unordered_set `seen` (stores elements in current subarray)
 *
 *    b) Extend subarray ending at index `j` (j from i to n-1):
 *
 *       - sum += nums[j]
 *       - insert nums[j] into `seen`
 *
 *       - If `seen` contains `sum`:
 *           → increment ans
 *
 * 3. Return ans
 *
 * ------------------------------------------------------------
 * Example:
 *
 * nums = [1, 2, 3]
 *
 * Subarrays:
 *
 * [1]       → sum = 1, elements = {1} → centered
 * [1,2]     → sum = 3, elements = {1,2} → not centered
 * [1,2,3]   → sum = 6, elements = {1,2,3} → not centered
 *
 * [2]       → sum = 2, elements = {2} → centered
 * [2,3]     → sum = 5, elements = {2,3} → not centered
 *
 * [3]       → sum = 3, elements = {3} → centered
 *
 * Answer = 3
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Single-element subarrays:
 *     • Always centered (sum == element)
 *
 * - Negative numbers:
 *     • Still valid, since sum can match an element
 *
 * - Repeated numbers:
 *     • Set ensures presence check works correctly
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - O(n²)
 *   • Two nested loops over subarrays
 *   • Set insert & lookup are O(1) average
 *
 * Space Complexity:
 *
 * - O(n)
 *   • Set can grow up to size of subarray
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Every subarray is examined exactly once
 * - The set accurately tracks all elements in the subarray
 * - Running sum avoids recomputing sums repeatedly
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This problem follows:
 *   "Subarray Enumeration + On-the-fly Validation"
 *
 * Common in:
 * - Special subarray counting problems
 * - Prefix-based brute force with pruning
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            long long sum = 0;
            unordered_set<long long> seen;

            for (int j = i; j < n; j++) {
                sum += nums[j];
                seen.insert(nums[j]);

                // Check centered condition
                if (seen.count(sum))
                    ans++;
            }
        }
        return ans;
    }
};

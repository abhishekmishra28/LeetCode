/*
 * Problem: 219. Contains Duplicate II
 *
 * Statement:
 * You are given an integer array `nums` and an integer `k`.
 *
 * Your task is to determine whether there exist TWO DISTINCT indices
 * i and j such that:
 *
 *   - nums[i] == nums[j]
 *   - |i - j| ≤ k
 *
 * Return:
 * - true  → if such a pair exists
 * - false → otherwise
 *
 * ------------------------------------------------------------
 * Key Observations:
 *
 * - We are not only checking for duplicates
 * - The INDEX DISTANCE between duplicates must be ≤ k
 *
 * ------------------------------------------------------------
 * Approach: Hash Map to Track Last Seen Index (Your Approach)
 *
 * Core Idea:
 * - For each number, store the LAST index where it appeared
 * - When the same number appears again:
 *     • Compare current index with last index
 *     • If distance ≤ k → valid pair found
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Approach):
 *
 * 1. Initialize an empty unordered_map `mpp`
 *    - Key   → number
 *    - Value → last index where the number appeared
 *
 * 2. Traverse the array from left to right:
 *
 *    a) If nums[i] already exists in map:
 *        - Compute index difference:
 *              i - mpp[nums[i]]
 *        - If difference ≤ k:
 *              → return true
 *
 *    b) Update map:
 *        - mpp[nums[i]] = i
 *
 * 3. If loop finishes without finding valid pair:
 *    - return false
 *
 * ------------------------------------------------------------
 * Example 1:
 *
 * Input:
 * nums = [1,2,3,1]
 * k = 3
 *
 * Indices of 1: 0 and 3
 * |3 - 0| = 3 ≤ k → true
 *
 * ------------------------------------------------------------
 * Example 2:
 *
 * Input:
 * nums = [1,0,1,1]
 * k = 1
 *
 * Indices of 1: 2 and 3
 * |3 - 2| = 1 ≤ k → true
 *
 * ------------------------------------------------------------
 * Example 3:
 *
 * Input:
 * nums = [1,2,3,1,2,3]
 * k = 2
 *
 * All duplicates have distance > 2
 * Output = false
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - k = 0 → always false (distinct indices required)
 * - Array size < 2
 * - All elements unique
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n)
 *   Each element is processed once
 *
 * Space Complexity:
 * - O(n)
 *   Hash map storing last seen indices
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - We only need the MOST RECENT occurrence of a number
 * - Earlier indices are less optimal for satisfying |i - j| ≤ k
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Sliding window / last occurrence tracking" problem
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;

        for (int i = 0; i < n; i++) {
            // If number seen before
            if (mpp.find(nums[i]) != mpp.end()) {
                if (i - mpp[nums[i]] <= k) {
                    return true;
                }
            }
            // Update last seen index
            mpp[nums[i]] = i;
        }

        return false;
    }
};

/*
 * Problem: 560. Subarray Sum Equals K
 *
 * Statement:
 * You are given an integer array `nums` and an integer `k`.
 *
 * Return the total number of continuous subarrays
 * whose sum equals `k`.
 *
 * ------------------------------------------------------------
 * APPROACH 1: Brute Force (Commented in Code)
 *
 * Idea:
 * - Fix a starting index i
 * - Keep adding elements from i to j
 * - Check if the running sum equals k
 *
 * Time Complexity:
 * - O(n²)
 *
 * Space Complexity:
 * - O(1)
 *
 * This approach works but is too slow for large inputs.
 *
 * ------------------------------------------------------------
 * APPROACH 2: Prefix Sum + Hash Map (Optimal) — Your Approach
 *
 * Core Insight:
 *
 * Let:
 *   prefixSum[j] = nums[0] + nums[1] + ... + nums[j]
 *
 * A subarray from index i+1 to j has sum = k if:
 *
 *   prefixSum[j] - prefixSum[i] = k
 *
 * Rearranging:
 *
 *   prefixSum[i] = prefixSum[j] - k
 *
 * So for every prefix sum `sum`,
 * we just need to know how many times `(sum - k)`
 * has appeared before.
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. Initialize:
 *      sum = 0          // running prefix sum
 *      cnt = 0          // answer
 *
 * 2. Use a hash map `mpp`:
 *      mpp[prefixSum] = frequency
 *
 * 3. Important base case:
 *      mpp[0] = 1
 *
 *    (This handles subarrays starting from index 0)
 *
 * 4. Traverse each element x in nums:
 *
 *      a) sum += x
 *
 *      b) If (sum - k) exists in map:
 *           cnt += mpp[sum - k]
 *
 *      c) Increment frequency of current sum:
 *           mpp[sum]++
 *
 * 5. Return cnt
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Hash map allows O(1) lookup of previous prefix sums
 * - Every valid (i, j) pair is counted
 * - Handles:
 *     • Negative numbers
 *     • Zero values
 *     • Overlapping subarrays
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * nums = [1, 1, 1], k = 2
 *
 * prefix sums:
 *   sum = 1 → need -1 (not found)
 *   sum = 2 → need 0  (found once) → cnt = 1
 *   sum = 3 → need 1  (found once) → cnt = 2
 *
 * Answer = 2
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Subarray starts from index 0
 * - Negative numbers in array
 * - k = 0
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - O(n)
 *   Single pass through array
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(n)
 *   Hash map storing prefix sums
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Prefix Sum + Hash Map" problem
 *
 * Seen in:
 * - Subarray sum problems
 * - Range sum counting
 * - Zero-sum subarrays
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        int sum = 0;
        unordered_map<int,int> mpp;

        // Base case for subarrays starting at index 0
        mpp[0] = 1;

        for (int x : nums) {
            sum += x;

            if (mpp.find(sum - k) != mpp.end()) {
                cnt += mpp[sum - k];
            }

            mpp[sum]++;
        }
        return cnt;
    }
};

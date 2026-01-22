/*
 * Problem: 18. 4Sum
 *
 * Statement:
 * You are given an integer array `nums` and an integer `target`.
 *
 * Return ALL UNIQUE quadruplets:
 *   [nums[a], nums[b], nums[c], nums[d]]
 * such that:
 *
 *   nums[a] + nums[b] + nums[c] + nums[d] == target
 *
 * Conditions:
 * - a, b, c, d are distinct indices
 * - Quadruplets must be UNIQUE
 *
 * ------------------------------------------------------------
 * APPROACH: Sorting + Two Fixed Indices + Two Pointers
 *
 * This is a natural EXTENSION of the 3Sum problem.
 *
 * Core Idea:
 *
 * - Fix TWO numbers: nums[i] and nums[j]
 * - Reduce the problem to a TWO-SUM problem on the remaining array
 * - Use two pointers to find pairs that complete the target
 *
 * ------------------------------------------------------------
 * Why Sorting is Important:
 *
 * - Enables two-pointer technique
 * - Makes it easy to SKIP duplicates
 * - Ensures uniqueness of quadruplets
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. Sort the array `nums`
 *
 * 2. First loop: fix index `i` from 0 to n-4
 *
 *    a) Skip duplicate values for i:
 *         if (i > 0 && nums[i] == nums[i-1]) continue;
 *
 * 3. Second loop: fix index `j` from i+1 to n-3
 *
 *    a) Skip duplicate values for j:
 *         if (j > i+1 && nums[j] == nums[j-1]) continue;
 *
 * 4. Reduce the target:
 *
 *      newTarget = target - nums[i] - nums[j]
 *
 * 5. Apply TWO POINTERS on the remaining array:
 *
 *      lo = j + 1
 *      hi = n - 1
 *
 * 6. While lo < hi:
 *
 *    a) Compute:
 *         sum = nums[lo] + nums[hi]
 *
 *    b) If sum == newTarget:
 *         - Found a valid quadruplet
 *         - Store {nums[i], nums[j], nums[lo], nums[hi]}
 *         - Move both pointers:
 *             lo++, hi--
 *         - Skip duplicates:
 *             while(lo < hi && nums[lo] == nums[lo-1]) lo++;
 *             while(lo < hi && nums[hi] == nums[hi+1]) hi--;
 *
 *    c) If sum > newTarget:
 *         - Need smaller sum → hi--
 *
 *    d) If sum < newTarget:
 *         - Need larger sum → lo++
 *
 * 7. Continue until all valid quadruplets are found
 *
 * ------------------------------------------------------------
 * Why long long is used:
 *
 * - nums[i] + nums[j] + nums[lo] + nums[hi] can overflow int
 * - Casting to long long ensures correctness
 *
 * ------------------------------------------------------------
 * Example:
 *
 * nums = [1,0,-1,0,-2,2]
 * target = 0
 *
 * After sorting:
 * nums = [-2,-1,0,0,1,2]
 *
 * Valid quadruplets:
 * [-2,-1,1,2]
 * [-2,0,0,2]
 * [-1,0,0,1]
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - nums.size() < 4 → return empty
 * - All elements same
 * - Large positive/negative values (overflow handled)
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - Sorting: O(n log n)
 * - Two nested loops + two pointers: O(n²)
 *
 * Overall:
 *   O(n³)
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(1) extra space (excluding output)
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This follows the pattern:
 *   "K-Sum Problem"
 *
 * Where:
 * - 2Sum → Hashing / Two Pointers
 * - 3Sum → Fix one + Two Pointers
 * - 4Sum → Fix two + Two Pointers
 *
 * Generalizable to K-Sum using recursion.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                long long newTarget = (long long)target - nums[i] - nums[j];
                int lo = j + 1;
                int hi = n - 1;

                while (lo < hi) {
                    long long sum = (long long)nums[lo] + nums[hi];

                    if (sum == newTarget) {
                        ans.push_back({nums[i], nums[j], nums[lo], nums[hi]});
                        lo++;
                        hi--;

                        while (lo < hi && nums[lo] == nums[lo - 1]) lo++;
                        while (lo < hi && nums[hi] == nums[hi + 1]) hi--;

                    } else if (sum > newTarget) {
                        hi--;
                    } else {
                        lo++;
                    }
                }
            }
        }
        return ans;
    }
};

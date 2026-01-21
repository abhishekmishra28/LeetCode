/*
 * Problem: 1. Two Sum
 *
 * Statement:
 * You are given an array of integers `nums` and an integer `target`.
 *
 * Return the INDICES of the two numbers such that:
 *   nums[i] + nums[j] == target
 *
 * Assumptions:
 * - Exactly one valid answer exists
 * - You may not use the same element twice
 * - Return indices in any order
 *
 * ------------------------------------------------------------
 * APPROACH: Hash Map (One Pass) — Your Approach
 *
 * Core Idea:
 *
 * - While traversing the array, for each element nums[i],
 *   check if the value needed to reach the target
 *   (target - nums[i]) has already been seen.
 *
 * - If yes → we have found the required pair.
 * - If no  → store the current number with its index.
 *
 * ------------------------------------------------------------
 * Why Hash Map?
 *
 * - We need FAST lookup to check if a complement exists
 * - unordered_map provides average O(1) time complexity
 *
 * Map stores:
 *   value → index
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. Create an unordered_map `mpp`
 *      - Key   → number from array
 *      - Value → its index
 *
 * 2. Traverse the array from i = 0 to n-1:
 *
 *    a) Compute:
 *         need = target - nums[i]
 *
 *    b) If `need` exists in the map:
 *         → We already saw a number that completes the sum
 *         → Return { mpp[need], i }
 *
 *    c) Otherwise:
 *         → Store current number and its index:
 *             mpp[nums[i]] = i
 *
 * 3. If no pair is found (theoretically not needed as per problem):
 *      → Return {-1, -1}
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Each element is checked only once
 * - We never reuse the same index twice because:
 *     • We check BEFORE inserting the current element
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * nums = [2, 7, 11, 15]
 * target = 9
 *
 * i = 0:
 *   nums[i] = 2
 *   need = 7
 *   map = {}
 *   → insert (2, 0)
 *
 * i = 1:
 *   nums[i] = 7
 *   need = 2
 *   map contains 2 → index 0
 *   → return {0, 1}
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Array size = 2
 * - Negative numbers
 * - Zero values
 * - Target = 0
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n)
 *   Single traversal of the array
 *
 * Space Complexity:
 * - O(n)
 *   Hash map storing visited elements
 *
 * ------------------------------------------------------------
 * Alternative Approach (For Completeness):
 *
 * - Brute force using two nested loops
 * - Time: O(n²)
 * - Space: O(1)
 * - Not preferred in interviews
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Hash Map + Complement Lookup" problem
 *
 * Appears in:
 * - Two Sum variations
 * - Subarray sum problems
 * - Pair finding problems
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        // value -> index
        unordered_map<int, int> mpp;

        for (int i = 0; i < n; i++) {
            int need = target - nums[i];

            if (mpp.find(need) != mpp.end()) {
                return {mpp[need], i};
            }

            mpp[nums[i]] = i;
        }

        // As per problem constraints, this line is usually never reached
        return {-1, -1};
    }
};

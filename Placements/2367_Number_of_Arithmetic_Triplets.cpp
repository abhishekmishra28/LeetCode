/*
 * Problem: 2367. Number of Arithmetic Triplets
 *
 * Statement:
 * You are given a strictly increasing integer array `nums`
 * and an integer `diff`.
 *
 * An arithmetic triplet (i, j, k) is valid if:
 *   i < j < k
 *   nums[j] - nums[i] == diff
 *   nums[k] - nums[j] == diff
 *
 * Return the number of arithmetic triplets.
 *
 * ------------------------------------------------------------
 * APPROACH 1: Brute Force (Your Approach)
 *
 * Core Idea:
 *
 * - Try all possible triplets (i, j, k)
 * - Check whether they form the required arithmetic progression
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Approach 1):
 *
 * 1. Iterate i from 0 to n-1
 * 2. Iterate j from i+1 to n-1
 * 3. Iterate k from j+1 to n-1
 *
 * 4. If:
 *      nums[j] - nums[i] == diff
 *      AND
 *      nums[k] - nums[j] == diff
 *    → Increment count
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n³)
 *
 * Space Complexity:
 * - O(1)
 *
 * ------------------------------------------------------------
 * Drawback:
 *
 * - Very slow for large n
 * - Clearly not optimal
 *
 * ------------------------------------------------------------
 * APPROACH 2: Optimal using Hash Set ⭐
 *
 * Core Insight:
 *
 * Since nums is STRICTLY INCREASING:
 *
 * For any middle element nums[j],
 * the triplet exists if and only if:
 *
 *   nums[j] - diff exists in nums
 *   nums[j] + diff exists in nums
 *
 * So instead of checking all i, j, k,
 * we fix j and check existence.
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Approach 2):
 *
 * 1. Insert all elements of nums into a hash set
 *
 * 2. For each element x in nums:
 *      - If (x - diff) exists in set
 *        AND (x + diff) exists in set
 *          → One valid arithmetic triplet found
 *          → Increment count
 *
 * 3. Return count
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Strictly increasing array guarantees order
 * - Hash set provides O(1) lookup
 * - Each triplet counted exactly once
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * nums = [0,1,4,6,7,10]
 * diff = 3
 *
 * x = 1:
 *   1-3 = -2 ✘
 *
 * x = 4:
 *   4-3 = 1 ✔
 *   4+3 = 7 ✔
 *   → count++
 *
 * x = 7:
 *   7-3 = 4 ✔
 *   7+3 = 10 ✔
 *   → count++
 *
 * Answer = 2
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n)
 *
 * Space Complexity:
 * - O(n)
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This problem is a classic:
 *   "Fix Middle + Hash Lookup"
 *
 * Seen in:
 * - Arithmetic sequences
 * - Triplet counting problems
 * - Difference-based problems
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // -----------------------------
    // Approach 1: Brute Force
    // -----------------------------
    /*
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n = nums.size();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[j] - nums[i] == diff &&
                        nums[k] - nums[j] == diff) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
    */

    // -----------------------------
    // Approach 2: Optimal (Hash Set)
    // -----------------------------
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_set<int> st(nums.begin(), nums.end());
        int cnt = 0;

        for (int x : nums) {
            if (st.count(x - diff) && st.count(x + diff)) {
                cnt++;
            }
        }
        return cnt;
    }
};

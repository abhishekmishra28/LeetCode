/*
 * Problem: 1877. Minimize Maximum Pair Sum in Array
 *
 * Statement:
 * You are given an array `nums` of EVEN length.
 *
 * You must pair the elements such that:
 * - Each element is used exactly once
 * - You form n/2 pairs
 *
 * Define:
 *   pairSum = nums[i] + nums[j]
 *
 * Your task:
 *   Minimize the MAXIMUM pair sum among all pairs.
 *
 * Return that minimum possible maximum pair sum.
 *
 * ------------------------------------------------------------
 * APPROACH: Sorting + Two Pointers (Greedy) — Your Approach
 *
 * Core Greedy Insight:
 *
 * - To minimize the maximum pair sum:
 *     Pair the SMALLEST number with the LARGEST number
 *
 * - This balances large values and prevents a big number
 *   from being paired with another big number
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. Sort the array `nums` in ascending order
 *
 * 2. Initialize:
 *      lo = 0           // smallest element index
 *      hi = n - 1       // largest element index
 *      ans = -∞         // stores maximum pair sum
 *
 * 3. While lo < hi:
 *
 *    a) Form a pair:
 *         pairSum = nums[lo] + nums[hi]
 *
 *    b) Update the answer:
 *         ans = max(ans, pairSum)
 *
 *    c) Move pointers:
 *         lo++
 *         hi--
 *
 * 4. After all pairs are formed, return ans
 *
 * ------------------------------------------------------------
 * Why This Works (Greedy Proof Intuition):
 *
 * - Pairing largest with smallest limits the impact
 * - Any other pairing will result in a larger max pair sum
 * - This greedy choice is globally optimal
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * nums = [3,5,2,3]
 *
 * After sorting:
 * nums = [2,3,3,5]
 *
 * Pairs:
 * (2,5) → sum = 7
 * (3,3) → sum = 6
 *
 * Maximum = 7 → answer
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - All elements equal
 * - Large values
 * - Minimum size array (n = 2)
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - Sorting: O(n log n)
 * - Two pointer pairing: O(n)
 *
 * Overall:
 *   O(n log n)
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(1) extra space (excluding sort stack)
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This problem follows the:
 *   "Greedy Pairing Extremes" pattern
 *
 * Seen in:
 * - Boat rescue problems
 * - Pair sum minimization
 * - Load balancing problems
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = INT_MIN;
        int lo = 0;
        int hi = n - 1;

        // Form n/2 pairs
        while (lo < hi) {
            ans = max(ans, nums[lo] + nums[hi]);
            lo++;
            hi--;
        }
        return ans;
    }
};

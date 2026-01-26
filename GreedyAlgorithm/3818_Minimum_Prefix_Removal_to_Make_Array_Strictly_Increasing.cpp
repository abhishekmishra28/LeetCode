/*
 * Problem: 3818. Minimum Prefix Removal to Make Array Strictly Increasing
 *
 * Statement:
 * You are given an integer array `nums`.
 *
 * You may remove a PREFIX (possibly empty) from the array.
 *
 * After removing the prefix, the remaining array must be
 * STRICTLY INCREASING.
 *
 * Return the MINIMUM length of the prefix that needs to be removed.
 *
 * ------------------------------------------------------------
 * APPROACH: Scan from Right to Left (Greedy) — Your Approach
 *
 * Core Observation:
 *
 * - A strictly increasing array means:
 *     nums[i-1] < nums[i] for all valid i
 *
 * - Instead of guessing the prefix to remove,
 *   we find the LONGEST suffix that is already
 *   strictly increasing.
 *
 * - Everything before that suffix must be removed.
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. Let n = nums.size()
 *
 * 2. Start from the END of the array:
 *      i = n - 1
 *
 * 3. Move left while the array is strictly increasing:
 *
 *      while (i > 0 && nums[i-1] < nums[i])
 *          i--
 *
 * 4. When the condition breaks:
 *      - Index `i` is the first position
 *        where increasing order fails
 *
 * 5. Return `i`
 *      → length of the prefix to remove
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - The suffix starting at index `i` is already strictly increasing
 * - Removing any smaller prefix (index < i) would keep a violation
 * - Removing exactly `i` elements is the minimum required
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * nums = [1, 2, 3, 2, 4, 5]
 *
 * Start from right:
 *   4 < 5 ✔
 *   2 < 4 ✔
 *   3 < 2 ✘  ← break
 *
 * i = 3
 *
 * Remove prefix of length 3:
 * Remaining = [2, 4, 5] (strictly increasing)
 *
 * Answer = 3
 *
 * ------------------------------------------------------------
 * Special Cases:
 *
 * 1) Already strictly increasing:
 *    nums = [1, 2, 3, 4]
 *    → i moves to 0
 *    → return 0 (remove nothing)
 *
 * 2) Fully decreasing:
 *    nums = [5, 4, 3, 2]
 *    → i stops at n-1
 *    → return n-1
 *
 * 3) Single element:
 *    nums = [10]
 *    → already increasing
 *    → return 0
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n)
 *   Single backward traversal
 *
 * Space Complexity:
 * - O(1)
 *   No extra space used
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This problem follows the:
 *   "Longest Valid Suffix" pattern
 *
 * Similar to:
 * - Shortest subarray removal problems
 * - Prefix/suffix optimization
 * - Greedy boundary detection
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n = nums.size();
        int i = n - 1;

        // Find longest strictly increasing suffix
        while (i > 0 && nums[i - 1] < nums[i]) {
            i--;
        }

        // Minimum prefix to remove
        return i;
    }
};

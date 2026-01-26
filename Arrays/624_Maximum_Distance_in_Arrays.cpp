/*
 * Problem: 624. Maximum Distance in Arrays
 *
 * Statement:
 * You are given `n` integer arrays `arrays`, where:
 * - Each array is sorted in ascending order
 * - You must choose one element from one array and
 *   another element from a DIFFERENT array
 *
 * The distance is defined as:
 *   |a - b|
 *
 * Return the MAXIMUM possible distance.
 *
 * ------------------------------------------------------------
 * APPROACH: Track Global Minimum & Maximum (Greedy) — Your Approach
 *
 * Core Observation:
 *
 * - Since each array is already sorted:
 *     • The smallest value of an array = arrays[i][0]
 *     • The largest value of an array  = arrays[i].back()
 *
 * - To maximize |a - b|:
 *     • Use the smallest element from one array
 *     • Use the largest element from a DIFFERENT array
 *
 * ------------------------------------------------------------
 * Strategy:
 *
 * - Maintain:
 *     mini → minimum value seen so far (from previous arrays)
 *     maxi → maximum value seen so far (from previous arrays)
 *
 * - For each new array:
 *     • Compare its maximum with the global minimum
 *     • Compare its minimum with the global maximum
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. Initialize:
 *      mini = arrays[0][0]
 *      maxi = arrays[0].back()
 *      max_d = 0
 *
 * 2. Iterate from array index 1 to n-1:
 *
 *    a) Possible distance using current array's maximum:
 *         |arrays[i].back() - mini|
 *
 *    b) Possible distance using current array's minimum:
 *         |maxi - arrays[i][0]|
 *
 *    c) Update maximum distance:
 *         max_d = max(max_d, both distances)
 *
 *    d) Update global extremes:
 *         mini = min(mini, arrays[i][0])
 *         maxi = max(maxi, arrays[i].back())
 *
 * 3. Return max_d
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - We always compare elements from DIFFERENT arrays
 *   (since mini/maxi come from previous arrays)
 *
 * - Greedy choice of extremes guarantees the maximum distance
 *
 * - No need to check all pairs (which would be expensive)
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * arrays = [[1,2,3], [4,5], [1,2,3]]
 *
 * Start:
 *   mini = 1, maxi = 3
 *
 * i = 1:
 *   |5 - 1| = 4
 *   |3 - 4| = 1
 *   max_d = 4
 *   mini = 1, maxi = 5
 *
 * i = 2:
 *   |3 - 1| = 2
 *   |5 - 1| = 4
 *   max_d = 4
 *
 * Answer = 4
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Only 2 arrays
 * - Arrays with negative numbers
 * - Arrays with single elements
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n)
 *   One pass through arrays
 *
 * ------------------------------------------------------------
 * Space Complexity:
 * - O(1)
 *   Constant extra space
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Greedy with Global Extremes" problem
 *
 * Seen in:
 * - Maximum difference problems
 * - Range optimization
 * - Multi-array comparisons
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();

        int mini = arrays[0][0];
        int maxi = arrays[0].back();
        int max_d = 0;

        for (int i = 1; i < n; i++) {
            max_d = max(max_d, abs(arrays[i].back() - mini));
            max_d = max(max_d, abs(maxi - arrays[i][0]));

            mini = min(mini, arrays[i][0]);
            maxi = max(maxi, arrays[i].back());
        }

        return max_d;
    }
};

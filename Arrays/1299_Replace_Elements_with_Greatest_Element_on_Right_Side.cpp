/*
 * Problem: 1299. Replace Elements with Greatest Element on Right Side
 *
 * Statement:
 * You are given an integer array `arr`.
 * For each index i:
 *   - Replace arr[i] with the GREATEST element among the elements
 *     to its RIGHT side.
 *   - For the last element, there is no element to its right,
 *     so replace it with -1.
 *
 * Return the resulting array.
 *
 * ------------------------------------------------------------
 * Key Observations:
 *
 * - For each index i, we need information about elements to its RIGHT
 * - A naive approach would repeatedly scan the right side
 * - This leads to unnecessary repeated work
 *
 * ------------------------------------------------------------
 * APPROACH 1: Brute Force (Commented in Code)
 *
 * Idea:
 * - For each index i:
 *   - Traverse the subarray arr[i+1 ... n-1]
 *   - Find the maximum element
 * - Replace arr[i] with that maximum
 *
 * Time Complexity:
 * - O(n²)
 *
 * Space Complexity:
 * - O(1)
 *
 * Drawback:
 * - Too slow for large arrays
 *
 * ------------------------------------------------------------
 * APPROACH 2: Optimal (Right-to-Left Scan)
 *
 * Core Insight:
 *
 * - While moving from RIGHT to LEFT, we can keep track of the
 *   maximum element seen so far
 *
 * - This allows us to compute the answer in ONE PASS
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Optimal Approach):
 *
 * 1. Initialize:
 *    - maxi = -1   → stores maximum seen so far on the right
 *    - ans array of same size as arr
 *
 * 2. Traverse array from RIGHT to LEFT:
 *    - ans[i] = maxi
 *    - Update maxi = max(maxi, arr[i])
 *
 * 3. Return ans
 *
 * ------------------------------------------------------------
 * Example:
 *
 * Input:
 * arr = [17, 18, 5, 4, 6, 1]
 *
 * Traversal:
 * i=5 → ans[5] = -1, maxi = 1
 * i=4 → ans[4] = 1,  maxi = 6
 * i=3 → ans[3] = 6,  maxi = 6
 * i=2 → ans[2] = 6,  maxi = 6
 * i=1 → ans[1] = 6,  maxi = 18
 * i=0 → ans[0] = 18
 *
 * Output:
 * [18, 6, 6, 6, 1, -1]
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Array of size 1 → output [-1]
 * - Array already in decreasing order
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n)
 *   Single backward pass
 *
 * Space Complexity:
 * - O(n)
 *   Output array
 *
 * ------------------------------------------------------------
 * Note:
 *
 * - If in-place modification is required,
 *   we can reuse the input array instead of `ans`
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {

        // Optimal Approach: Right-to-left traversal
        int maxi = -1;
        vector<int> ans(arr.size());

        for (int i = arr.size() - 1; i >= 0; i--) {
            ans[i] = maxi;
            maxi = max(maxi, arr[i]);
        }

        return ans;
    }
};

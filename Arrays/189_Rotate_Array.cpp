/*
 * Problem: 189. Rotate Array
 *
 * Statement:
 * You are given an integer array `nums` and an integer `k`.
 *
 * Rotate the array to the RIGHT by `k` steps.
 *
 * Note:
 * - Rotation is cyclic
 * - You must modify the array IN-PLACE
 *
 * ------------------------------------------------------------
 * APPROACH 1: Extra Array (Using Temporary Storage)
 *
 * Idea:
 * - Store the first (n - k) elements in a temp array
 * - Shift the last k elements to the front
 * - Copy back the stored elements
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * (Commented in code)
 *
 * ------------------------------------------------------------
 * APPROACH 2: Index Mapping with Extra Array
 *
 * Idea:
 * - Create a temp array of size n
 * - Place each element nums[i] at index (i + k) % n
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * (Commented in code)
 *
 * ------------------------------------------------------------
 * APPROACH 3: In-Place Reversal Algorithm ⭐ (Optimal)
 *
 * This is the MOST OPTIMAL approach.
 *
 * Core Idea:
 *
 * Right rotation by k can be achieved by:
 * 1) Reverse the entire array
 * 2) Reverse the first k elements
 * 3) Reverse the remaining n - k elements
 *
 * ------------------------------------------------------------
 * Why Reversal Works:
 *
 * Original array:
 *   [a b c d e f g]
 * k = 3
 *
 * Step 1: Reverse whole array
 *   [g f e d c b a]
 *
 * Step 2: Reverse first k elements
 *   [e f g d c b a]
 *
 * Step 3: Reverse remaining elements
 *   [e f g a b c d]  ✔
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. Compute:
 *      k = k % n
 *    (to handle k >= n)
 *
 * 2. Reverse the entire array
 *
 * 3. Reverse the first k elements
 *
 * 4. Reverse the elements from index k to n-1
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * nums = [1,2,3,4,5,6,7], k = 3
 *
 * Reverse all:
 *   [7,6,5,4,3,2,1]
 *
 * Reverse first 3:
 *   [5,6,7,4,3,2,1]
 *
 * Reverse rest:
 *   [5,6,7,1,2,3,4]
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - k = 0 → array remains same
 * - k >= n → handled by modulo
 * - n = 1 → no change
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n)
 *
 * Space Complexity:
 * - O(1)  (IN-PLACE)
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Array Rotation using Reversal"
 *
 * Frequently asked in:
 * - FAANG interviews
 * - In-place array manipulation problems
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        // Optimal Approach (In-place)
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

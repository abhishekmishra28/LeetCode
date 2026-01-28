/*
 * Problem: 1588. Sum of All Odd Length Subarrays
 *
 * Statement:
 * You are given an integer array `nums`.
 * Return the sum of all possible subarrays that have ODD length.
 *
 * ------------------------------------------------------------
 * APPROACH: Contribution Technique (Optimal) — Your Approach
 *
 * Core Idea:
 *
 * Instead of generating all subarrays, we calculate how many
 * ODD-length subarrays each element contributes to.
 *
 * Then we add:
 *     nums[i] × (number of odd-length subarrays containing nums[i])
 *
 * ------------------------------------------------------------
 * Key Observation:
 *
 * For an index i:
 *
 * - Number of choices for the START of subarray:
 *       start = i + 1
 *
 * - Number of choices for the END of subarray:
 *       end = n - i
 *
 * → Total subarrays that include nums[i]:
 *
 *       totalSub = start × end
 *
 * Among these:
 * - Half are odd-length
 * - Half are even-length
 *
 * If totalSub is odd, odd-length subarrays are one more than even.
 *
 * Therefore:
 *
 *       oddSub = (totalSub + 1) / 2
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. Initialize:
 *      sum = 0
 *
 * 2. For each index i from 0 to n-1:
 *
 *    a) start = i + 1
 *    b) end   = n - i
 *    c) totalSub = start * end
 *    d) oddSub   = (totalSub + 1) / 2
 *
 *    e) Add contribution:
 *         sum += nums[i] * oddSub
 *
 * 3. Return sum
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Every odd-length subarray contributes its elements once
 * - Counting contributions avoids redundant subarray generation
 * - Converts an O(n³) / O(n²) problem into O(n)
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * nums = [1, 4, 2, 5, 3]
 *
 * For i = 2 (nums[i] = 2):
 *   start = 3
 *   end   = 3
 *   totalSub = 9
 *   oddSub = (9 + 1) / 2 = 5
 *   contribution = 2 × 5 = 10
 *
 * Repeat for all indices and sum contributions
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Single element array → element itself is counted
 * - Works for any integer values (positive/negative)
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - O(n)
 *   Single pass through the array
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(1)
 *   Constant extra space
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Contribution / Counting Technique"
 *
 * Very common in:
 * - Subarray problems
 * - Mathematical optimizations
 * - Competitive programming
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            int start = i + 1;
            int end = n - i;
            int totalSub = start * end;
            int oddSub = (totalSub + 1) / 2;

            sum += nums[i] * oddSub;
        }
        return sum;
    }
};

/*
 * Problem: 922. Sort Array By Parity II
 *
 * Statement:
 * You are given an integer array `nums` of EVEN length.
 *
 * Exactly half of the elements are EVEN
 * and the other half are ODD.
 *
 * Your task is to rearrange the array such that:
 * - Elements at EVEN indices are EVEN numbers
 * - Elements at ODD indices are ODD numbers
 *
 * You may return ANY valid answer.
 *
 * ------------------------------------------------------------
 * APPROACH: Two-Pointer Index Fixing (Your Approach)
 *
 * Core Idea:
 * - Even indices must contain even numbers
 * - Odd indices must contain odd numbers
 *
 * We fix mismatches at even indices by swapping
 * with a suitable mismatch at odd indices.
 *
 * ------------------------------------------------------------
 * Pointer Strategy:
 *
 * - `i` → iterates over EVEN indices (0, 2, 4, ...)
 * - `j` → iterates over ODD indices (1, 3, 5, ...)
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. Initialize:
 *      n = nums.size()
 *      j = 1   // first odd index
 *
 * 2. Iterate over EVEN indices using `i` (i += 2):
 *
 *    a) If nums[i] is EVEN:
 *         → correct placement, do nothing
 *
 *    b) If nums[i] is ODD (wrong position):
 *         - Move pointer `j` until:
 *             nums[j] is EVEN
 *           (this means it's wrongly placed at odd index)
 *
 *         - Swap nums[i] and nums[j]
 *
 * 3. Continue until all even indices are fixed
 *
 * 4. Return nums
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Since the array has equal count of even and odd numbers,
 *   a suitable swap candidate is guaranteed to exist
 *
 * - Each swap fixes TWO positions at once
 *
 * ------------------------------------------------------------
 * Example:
 *
 * nums = [4,2,5,7]
 *
 * i = 0 → nums[0]=4 (even) ✔
 *
 * i = 2 → nums[2]=5 (odd ❌)
 *   j = 1 → nums[1]=2 (even ❌)
 *   swap → [4,5,2,7]
 *
 * Now:
 * - even indices → 4,2
 * - odd indices  → 5,7
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Array already valid
 * - Minimum size array (n = 2)
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n)
 *   Each element is visited at most once
 *
 * Space Complexity:
 * - O(1)
 *   In-place rearrangement
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Index-based Two Pointer" problem
 *
 * Seen in:
 * - Parity arrangement problems
 * - Index constraint rearrangements
 * - In-place array correction tasks
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        int j = 1; // pointer for odd indices

        // Traverse even indices
        for (int i = 0; i < n; i += 2) {
            // If even index has odd number
            if (nums[i] % 2 == 1) {
                // Find an odd index with even number
                while (nums[j] % 2 == 1) {
                    j += 2;
                }
                // Swap to fix both positions
                swap(nums[i], nums[j]);
            }
        }
        return nums;
    }
};

/*
 * Problem: 75. Sort Colors
 *
 * Statement:
 * You are given an array `nums` containing only 0s, 1s, and 2s.
 * You must sort the array IN-PLACE so that:
 *
 *   0s come first, then 1s, then 2s
 *
 * Constraint:
 * - You are NOT allowed to use the built-in sort function.
 *
 * ------------------------------------------------------------
 * APPROACH: Dutch National Flag Algorithm (One Pass, In-Place)
 *
 * This is the OPTIMAL and INTERVIEW-EXPECTED solution.
 *
 * ------------------------------------------------------------
 * Core Idea:
 *
 * Maintain THREE regions in the array using pointers:
 *
 *   [ 0 ... lo-1 ]     → all 0s (sorted)
 *   [ lo ... mid-1 ]   → all 1s (sorted)
 *   [ mid ... hi ]     → unknown (to be processed)
 *   [ hi+1 ... end ]   → all 2s (sorted)
 *
 * We process the array using the `mid` pointer.
 *
 * ------------------------------------------------------------
 * Pointer Meaning:
 *
 * - lo   → boundary for 0s
 * - mid  → current element under inspection
 * - hi   → boundary for 2s
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. Initialize:
 *      lo = 0
 *      mid = 0
 *      hi = nums.size() - 1
 *
 * 2. While mid <= hi:
 *
 *    Case 1: nums[mid] == 0
 *    ---------------------
 *    - Swap nums[mid] with nums[lo]
 *    - Increment BOTH lo and mid
 *
 *    Reason:
 *    - 0 belongs to the left region
 *    - After swap, both positions are correctly placed
 *
 *    -----------------------------------------------
 *
 *    Case 2: nums[mid] == 1
 *    ---------------------
 *    - Just increment mid
 *
 *    Reason:
 *    - 1 already belongs in the middle region
 *
 *    -----------------------------------------------
 *
 *    Case 3: nums[mid] == 2
 *    ---------------------
 *    - Swap nums[mid] with nums[hi]
 *    - Decrement hi ONLY
 *
 *    Reason:
 *    - 2 belongs to the right region
 *    - Do NOT increment mid here because
 *      the swapped element from hi is still unprocessed
 *
 * 3. Loop ends when mid > hi
 *
 * ------------------------------------------------------------
 * Example Dry Run:
 *
 * nums = [2,0,2,1,1,0]
 *
 * lo=0, mid=0, hi=5
 *
 * mid=0 → nums[mid]=2 → swap(mid,hi)
 * [0,0,2,1,1,2], hi=4
 *
 * mid=0 → nums[mid]=0 → swap(mid,lo)
 * [0,0,2,1,1,2], lo=1, mid=1
 *
 * mid=1 → nums[mid]=0 → swap(mid,lo)
 * [0,0,2,1,1,2], lo=2, mid=2
 *
 * mid=2 → nums[mid]=2 → swap(mid,hi)
 * [0,0,1,1,2,2], hi=3
 *
 * mid=2 → nums[mid]=1 → mid++
 *
 * mid=3 → nums[mid]=1 → mid++
 *
 * Done ✅
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Each element is examined AT MOST once
 * - Swaps ensure correct region placement
 * - No extra space used
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n)
 *   Single pass through the array
 *
 * Space Complexity:
 * - O(1)
 *   In-place sorting
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is the classic:
 *   "Three-Way Partitioning" problem
 *
 * Also known as:
 *   Dutch National Flag Algorithm
 *
 * Used in:
 * - Partitioning problems
 * - QuickSort variants
 * - Multi-category in-place sorting
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo = 0;
        int mid = 0;
        int hi = nums.size() - 1;

        while (mid <= hi) {
            if (nums[mid] == 2) {
                swap(nums[mid], nums[hi--]);
            } else if (nums[mid] == 0) {
                swap(nums[mid++], nums[lo++]);
            } else { // nums[mid] == 1
                mid++;
            }
        }
    }
};

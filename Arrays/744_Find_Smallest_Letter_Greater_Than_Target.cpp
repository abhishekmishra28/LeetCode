/*
 * Problem: 744. Find Smallest Letter Greater Than Target
 *
 * Statement:
 * You are given a sorted array of characters `letters`
 * and a character `target`.
 *
 * Return the smallest character in the array that is
 * strictly GREATER than `target`.
 *
 * Note:
 * - The array is circular.
 * - If no character is greater than target,
 *   return the first character of the array.
 *
 * ------------------------------------------------------------
 * APPROACH 3: Binary Search (Your Final & Optimal Approach)
 *
 * Core Idea:
 *
 * - Since `letters` is already SORTED,
 *   we can apply Binary Search to efficiently find
 *   the smallest character greater than `target`.
 *
 * - This is essentially finding:
 *      upper_bound(target)
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. Initialize:
 *      lo = 0
 *      hi = letters.size() - 1
 *      ans = letters[0]   // default (circular condition)
 *
 * 2. While lo <= hi:
 *
 *      mid = lo + (hi - lo) / 2
 *
 *      a) If letters[mid] > target:
 *           → This is a valid candidate
 *           → Store it in ans
 *           → Try to find a smaller valid character on the left
 *             hi = mid - 1
 *
 *      b) Else:
 *           → letters[mid] <= target
 *           → Move right
 *             lo = mid + 1
 *
 * 3. Return ans
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Binary search narrows down the FIRST character
 *   that is strictly greater than target
 *
 * - Initializing ans = letters[0] automatically handles
 *   the circular wrap-around case
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * letters = ['c','f','j']
 * target  = 'd'
 *
 * mid = 'f' > 'd' → ans = 'f', move left
 * Result = 'f'
 *
 * ------------------------------------------------------------
 * Circular Case Example:
 *
 * letters = ['c','f','j']
 * target  = 'j'
 *
 * No character > 'j'
 * ans remains letters[0] = 'c'
 *
 * ------------------------------------------------------------
 * Other Approaches (Brief):
 *
 * APPROACH 1: Linear Scan
 * - Check each character
 * - First one greater than target → return
 * - Else return letters[0]
 * - Time: O(n)
 *
 * APPROACH 2: STL upper_bound
 * - idx = upper_bound(...)
 * - If idx == size → return letters[0]
 * - Time: O(log n)
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - O(log n)
 *   Binary Search
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
 *   "Upper Bound / Binary Search on Sorted Array"
 *
 * Seen in:
 * - Next greater element problems
 * - Circular array searches
 * - Lower/Upper bound questions
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int lo = 0;
        int hi = letters.size() - 1;
        char ans = letters[0];  // handles circular case

        while (lo <= hi) {
            int mid = lo + ((hi - lo) >> 1);

            if (letters[mid] > target) {
                ans = letters[mid];
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};

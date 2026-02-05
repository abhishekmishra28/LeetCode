/*
 * Problem: 1985. Find the Kth Largest Integer in the Array
 *
 * Statement:
 * You are given an array of strings `nums`, where each string represents
 * a non-negative integer (without leading zeros).
 *
 * Return the k-th LARGEST integer in the array.
 *
 * Note:
 * - Numbers can be very large, so direct numeric conversion may overflow
 * - Comparison must be done as STRINGS
 *
 * ------------------------------------------------------------
 * APPROACH: Custom Sorting with String Comparison — Your Approach
 *
 * Core Insight:
 *
 * - Larger numbers have:
 *     • Greater length (number of digits)
 * - If lengths are equal:
 *     • Lexicographical (string) comparison works
 *
 * So, we sort strings using:
 *   1) Length (descending)
 *   2) Lexicographical order (descending)
 *
 * ------------------------------------------------------------
 * Custom Comparator Logic:
 *
 * Given two strings a and b:
 *
 *   if (a.size() != b.size())
 *       → the longer string represents the larger number
 *
 *   else
 *       → both have same digits
 *       → compare lexicographically (a > b)
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm:
 *
 * 1. Sort the array `nums` using a custom comparator:
 *
 *      - Primary key   → string length (descending)
 *      - Secondary key → lexicographical order (descending)
 *
 * 2. After sorting:
 *
 *      nums[0] → largest number
 *      nums[1] → 2nd largest
 *      ...
 *      nums[k-1] → k-th largest
 *
 * 3. Return nums[k-1]
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - No integer conversion → avoids overflow
 * - String length directly maps to numeric magnitude
 * - Lexicographical order works for same-length numbers
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * Input:
 *   nums = ["3","6","7","10"]
 *   k = 4
 *
 * Sorting order:
 *
 *   "10" (length 2)
 *   "7"
 *   "6"
 *   "3"
 *
 * k = 4 → nums[3] = "3"
 *
 * Output = "3"
 *
 * ------------------------------------------------------------
 * Another Example:
 *
 * nums = ["2","21","12","1"]
 *
 * Sorted:
 *   "21"
 *   "12"
 *   "2"
 *   "1"
 *
 * k = 2 → "12"
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Very large numbers (100+ digits)
 * - Numbers with same length
 * - k = 1 (largest)
 * - k = nums.size() (smallest)
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - O(n log n)
 *   Sorting with custom comparator
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(1) extra space (in-place sort)
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Sorting with Custom Comparator on Strings"
 *
 * Appears in:
 * - Large number comparisons
 * - Kth largest / smallest problems
 * - String-based numeric ordering
 */

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {

        sort(nums.begin(), nums.end(),
             [](const string &a, const string &b) {
                 if (a.size() != b.size())
                     return a.size() > b.size(); // longer = larger
                 return a > b;                  // lexicographical
             });

        return nums[k - 1];
    }
};

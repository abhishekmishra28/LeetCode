/*
 * Problem: 3798. Largest Even Number
 *
 * Statement:
 * You are given a string `s` consisting only of characters '1' and '2'.
 * You may delete any number of characters from `s` WITHOUT changing
 * the relative order of the remaining characters (i.e., form a subsequence).
 *
 * Return the LARGEST possible resultant string that represents an EVEN integer.
 * If no such string exists, return an empty string "".
 *
 * ------------------------------------------------------------
 * Key Observations:
 *
 * 1) A number is EVEN if and only if its LAST digit is even.
 * 2) In this problem, the only even digit available is '2'.
 * 3) Since deletions are allowed, we can remove characters
 *    but CANNOT rearrange them.
 *
 * ------------------------------------------------------------
 * Core Insight:
 *
 * - Any valid even number MUST end with '2'.
 * - To maximize the number:
 *     • We want the result to be as LONG as possible.
 *     • Keeping more digits on the left always makes the number larger.
 *
 * Therefore:
 * 👉 The best strategy is to find the RIGHTMOST '2'
 * 👉 Keep ALL characters from the start up to that position (inclusive)
 *
 * Any character AFTER the last '2' must be removed,
 * otherwise the number would end with '1' (odd).
 *
 * Any character BEFORE the last '2' should be kept,
 * because deleting it would only reduce the value of the number.
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Approach):
 *
 * 1. Traverse the string from RIGHT to LEFT.
 * 2. Find the index of the RIGHTMOST '2'.
 * 3. If no '2' exists:
 *    - No even number is possible → return ""
 * 4. Otherwise:
 *    - Return the substring from index 0 to that position (inclusive).
 *
 * ------------------------------------------------------------
 * Example 1:
 *
 * Input:  "1112"
 * Rightmost '2' at index 3
 * Result: "1112"
 *
 * ------------------------------------------------------------
 * Example 2:
 *
 * Input:  "221"
 * Rightmost '2' at index 1
 * Result: "22"
 *
 * ------------------------------------------------------------
 * Example 3:
 *
 * Input:  "1"
 * No '2' found
 * Result: ""
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - String contains only '1's → no valid answer
 * - String ends with '2' → keep entire string
 * - Single character "2" → valid answer
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n)
 *   Single backward scan of the string
 *
 * Space Complexity:
 * - O(1)
 *   No extra space used (excluding output)
 *
 * ------------------------------------------------------------
 * Note:
 * This solution is optimal, clean, and interview-ready.
 * It relies purely on parity logic and greedy reasoning.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestEven(string s) {
        int n = s.size();
        int cnt = -1;

        // Find the rightmost '2'
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '2') {
                cnt = i;
                break;
            }
        }

        // No even digit found
        if (cnt == -1) return "";

        // Keep the longest possible subsequence ending with '2'
        return s.substr(0, cnt + 1);
    }
};

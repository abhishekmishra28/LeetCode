/*
 * Problem: 28. Find the Index of the First Occurrence in a String
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given two strings:
 *   - haystack
 *   - needle
 *
 * Return the index of the first occurrence of needle
 * in haystack.
 *
 * If needle is not part of haystack, return -1.
 *
 * ------------------------------------------------------------
 * APPROACH: Brute Force (Sliding Window Comparison)
 *
 * ------------------------------------------------------------
 * KEY OBSERVATIONS:
 *
 * 1️⃣ If needle is empty → return 0.
 *
 * 2️⃣ If needle length > haystack length → impossible → return -1.
 *
 * 3️⃣ For each possible starting position i in haystack:
 *    - Compare substring of length m with needle.
 *
 * ------------------------------------------------------------
 * STRATEGY:
 *
 * Let:
 *   n = haystack.size()
 *   m = needle.size()
 *
 * Loop i from 0 → n - m:
 *
 *   - Compare haystack[i + j] with needle[j]
 *   - If mismatch → break
 *   - If all characters match → return i
 *
 * ------------------------------------------------------------
 * LOOP RANGE:
 *
 * for (i = 0; i <= n - m; i++)
 *
 * Ensures:
 * - We only check valid starting positions.
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * haystack = "sadbutsad"
 * needle   = "sad"
 *
 * i = 0 → match → return 0
 *
 * Example 2:
 *
 * haystack = "leetcode"
 * needle   = "leeto"
 *
 * No match → return -1
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 * - O(n * m)
 *   (Worst case full comparison at each position)
 *
 * Space Complexity:
 * - O(1)
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - This is naive substring search.
 *
 * - More optimized approaches:
 *     - KMP Algorithm → O(n + m)
 *     - Rabin-Karp
 *     - Z Algorithm
 *
 * - For interviews, mention KMP if optimization is required.
 */

class Solution {
public:
    int strStr(string haystack, string needle) {

        int n = haystack.size();
        int m = needle.size();

        // Edge case: empty needle
        if (m == 0)
            return 0;

        // Needle longer than haystack
        if (m > n)
            return -1;

        // Try every possible starting index
        for (int i = 0; i <= n - m; i++) {

            int j = 0;

            // Compare substring
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }

            // Full match found
            if (j == m)
                return i;
        }

        return -1;
    }
};

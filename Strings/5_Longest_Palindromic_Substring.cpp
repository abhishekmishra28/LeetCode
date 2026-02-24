/*
 * Problem: 5. Longest Palindromic Substring
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given a string s,
 * return the longest palindromic substring in s.
 *
 * A palindrome reads the same forward and backward.
 *
 * ------------------------------------------------------------
 * APPROACH: Expand Around Center
 *
 * ------------------------------------------------------------
 * KEY OBSERVATIONS:
 *
 * 1️⃣ Every palindrome is centered around a point.
 *
 * 2️⃣ There are two types of centers:
 *    - Odd length palindrome → single character center
 *    - Even length palindrome → between two characters
 *
 * 3️⃣ For each index i:
 *    - Expand around (i, i)        → odd case
 *    - Expand around (i, i + 1)    → even case
 *
 * ------------------------------------------------------------
 * STRATEGY:
 *
 * 1️⃣ For each index i:
 *       - Calculate len1 (odd center)
 *       - Calculate len2 (even center)
 *
 * 2️⃣ Take maximum of both.
 *
 * 3️⃣ If larger than previous maximum:
 *       Update start index
 *       Update max length
 *
 * ------------------------------------------------------------
 * EXPAND FUNCTION:
 *
 * expand(s, left, right):
 *
 *   While:
 *     left >= 0
 *     right < s.size()
 *     s[left] == s[right]
 *
 *   Expand outward.
 *
 *   Return length = right - left - 1
 *
 * ------------------------------------------------------------
 * WHY right - left - 1 ?
 *
 * Because loop stops after crossing valid boundary.
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * s = "babad"
 *
 * Centers checked:
 *
 * i = 0 → "b"
 * i = 1 → "bab"
 * i = 2 → "aba"
 *
 * Longest = "bab" (or "aba")
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 * - O(n^2)
 *   (Each center may expand fully)
 *
 * Space Complexity:
 * - O(1)
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - More optimized solution:
 *   Manacher’s Algorithm → O(n)
 *
 * - Expand-around-center is easiest and most common.
 */

class Solution {
private:
    int expand(string s, int left, int right) {

        while (left >= 0 &&
               right < s.size() &&
               s[left] == s[right]) {

            left--;
            right++;
        }

        return right - left - 1;
    }

public:
    string longestPalindrome(string s) {

        int n = s.size();

        if (s.empty())
            return "";

        int start = 0;
        int maxLen = 0;

        for (int i = 0; i < n; i++) {

            // Odd length palindrome
            int len1 = expand(s, i, i);

            // Even length palindrome
            int len2 = expand(s, i, i + 1);

            int len = max(len1, len2);

            if (len > maxLen) {

                maxLen = len;

                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, maxLen);
    }
};

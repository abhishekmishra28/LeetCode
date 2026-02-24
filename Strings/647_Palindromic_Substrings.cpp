/*
 * Problem: 647. Palindromic Substrings
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given a string s,
 * return the total number of palindromic substrings in it.
 *
 * A substring is a contiguous sequence of characters.
 *
 * ------------------------------------------------------------
 * APPROACH: Expand Around Center
 *
 * ------------------------------------------------------------
 * KEY OBSERVATIONS:
 *
 * 1️⃣ Every palindrome has a center.
 *
 * 2️⃣ Two types of centers:
 *    - Odd length → single character center (i, i)
 *    - Even length → between two characters (i, i+1)
 *
 * 3️⃣ For every index i:
 *    - Count palindromes centered at (i, i)
 *    - Count palindromes centered at (i, i+1)
 *
 * ------------------------------------------------------------
 * STRATEGY:
 *
 * 1️⃣ For each index i:
 *       cnt += expand(s, i, i)       → odd case
 *       cnt += expand(s, i, i + 1)   → even case
 *
 * 2️⃣ expand() returns number of palindromes
 *    found from that center.
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
 *   Each successful match → one palindrome.
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * s = "aaa"
 *
 * Centers:
 *
 * i = 0:
 *   (0,0) → "a"
 *   (0,1) → "aa"
 *
 * i = 1:
 *   (1,1) → "a"
 *   (1,2) → "aa"
 *
 * i = 2:
 *   (2,2) → "a"
 *
 * Total = 6
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 * - O(n^2)
 *
 * Space Complexity:
 * - O(1)
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - Same pattern as Longest Palindromic Substring.
 * - Alternative approach:
 *     DP solution O(n^2) space.
 * - Expand-around-center is simplest.
 */

class Solution {
private:
    int expand(string s, int left, int right) {

        int cnt = 0;

        while (left >= 0 &&
               right < s.size() &&
               s[left] == s[right]) {

            cnt++;
            left--;
            right++;
        }

        return cnt;
    }

public:
    int countSubstrings(string s) {

        int n = s.size();

        if (s.empty())
            return 0;

        int cnt = 0;

        for (int i = 0; i < n; i++) {

            // Odd length palindromes
            cnt += expand(s, i, i);

            // Even length palindromes
            cnt += expand(s, i, i + 1);
        }

        return cnt;
    }
};

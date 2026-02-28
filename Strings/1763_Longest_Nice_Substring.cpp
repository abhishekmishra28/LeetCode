/*
 * Problem: 1763. Longest Nice Substring
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * A string is called "nice" if:
 *
 *   For every character in the string,
 *   both its lowercase and uppercase forms
 *   are also present.
 *
 * Example:
 *   "aA"     → nice
 *   "aAa"    → nice
 *   "aAb"    → not nice (b and B mismatch)
 *
 * Return the longest nice substring of s.
 * If multiple answers exist, return any one of them.
 *
 * ------------------------------------------------------------
 * APPROACH: Brute Force + Set Validation
 *
 * ------------------------------------------------------------
 * CORE IDEA:
 *
 * 1️⃣ Generate all possible substrings.
 *
 * 2️⃣ For each substring:
 *      - Store characters in a set.
 *      - Check if it satisfies "nice" condition.
 *
 * 3️⃣ Track the longest valid substring.
 *
 * ------------------------------------------------------------
 * NICE CONDITION CHECK:
 *
 * For each character c in substring:
 *
 *   If c is lowercase:
 *       Its uppercase must exist.
 *
 *   If c is uppercase:
 *       Its lowercase must exist.
 *
 * If any character fails → not nice.
 *
 * ------------------------------------------------------------
 * STRATEGY:
 *
 * Outer loop:
 *   Fix starting index i.
 *
 * Inner loop:
 *   Extend substring till j.
 *
 *   - Insert s[j] into set.
 *   - Check if current substring is nice.
 *   - Update result if longer.
 *
 * ------------------------------------------------------------
 * HELPER FUNCTION:
 *
 * isNice(seen):
 *
 *   For every char c:
 *       Check opposite case exists.
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * s = "YazaAay"
 *
 * Substrings checked:
 *
 * "Y"
 * "Ya"
 * ...
 * "aAa" → valid
 *
 * Longest nice substring = "aAa"
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Let n = length of string
 *
 * Time Complexity:
 * - O(n^3)
 *   (n² substrings × O(n) check)
 *
 * Space Complexity:
 * - O(52)
 *   (At most all letters)
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - This brute force works for small constraints.
 *
 * - More optimized solution:
 *     Divide and conquer approach → O(n²)
 *
 * - Key pattern:
 *     Substring + validation using set.
 */

class Solution {
private:
    bool isNice(unordered_set<char> seen) {

        for (char c : seen) {

            char opp = (islower(c))
                       ? toupper(c)
                       : tolower(c);

            if (!seen.count(opp))
                return false;
        }

        return true;
    }

public:
    string longestNiceSubstring(string s) {

        int n = s.size();
        string res = "";

        for (int i = 0; i < n; i++) {

            unordered_set<char> seen;

            for (int j = i; j < n; j++) {

                seen.insert(s[j]);

                if (isNice(seen)) {

                    if (j - i + 1 > res.size()) {
                        res = s.substr(i, j - i + 1);
                    }
                }
            }
        }

        return res;
    }
};

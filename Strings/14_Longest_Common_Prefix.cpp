/*
 * Problem: 14. Longest Common Prefix
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Write a function to find the longest common prefix
 * string amongst an array of strings.
 *
 * If there is no common prefix, return an empty string "".
 *
 * ------------------------------------------------------------
 * APPROACH: Vertical Scanning
 *
 * ------------------------------------------------------------
 * KEY OBSERVATIONS:
 *
 * 1️⃣ If the array is empty → answer is "".
 *
 * 2️⃣ The common prefix cannot be longer than
 *    the first string.
 *
 * 3️⃣ Compare characters column-by-column
 *    (same index across all strings).
 *
 * ------------------------------------------------------------
 * STRATEGY:
 *
 * 1️⃣ Iterate over characters of first string.
 *
 * 2️⃣ For each index i:
 *    - Store character c = strs[0][i]
 *
 * 3️⃣ Compare this character with
 *    all other strings at index i.
 *
 * 4️⃣ If:
 *      - Index exceeds any string length OR
 *      - Characters mismatch
 *    → Return prefix till i.
 *
 * 5️⃣ If loop completes → entire first string
 *    is common prefix.
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * strs = ["flower","flow","flight"]
 *
 * Compare:
 * f == f == f ✔
 * l == l == l ✔
 * o == o != i ✖
 *
 * Return "fl"
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 * - O(n * m)
 *   n = number of strings
 *   m = length of shortest string
 *
 * Space Complexity:
 * - O(1)
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - Alternative approaches:
 *   - Horizontal scanning
 *   - Sorting and comparing first & last string
 *   - Trie-based solution
 *
 * - Vertical scanning is simple and efficient.
 */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if (strs.empty())
            return "";

        // Traverse character-by-character of first string
        for (int i = 0; i < strs[0].size(); i++) {

            char c = strs[0][i];

            // Compare with all other strings
            for (int j = 1; j < strs.size(); j++) {

                // Check boundary and mismatch
                if (i >= strs[j].size() || strs[j][i] != c)
                    return strs[0].substr(0, i);
            }
        }

        // Entire first string is common prefix
        return strs[0];
    }
};

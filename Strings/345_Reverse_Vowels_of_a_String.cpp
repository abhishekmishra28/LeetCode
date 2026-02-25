/*
 * Problem: 345. Reverse Vowels of a String
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given a string s,
 * reverse only the vowels in the string
 * and return the modified string.
 *
 * Vowels:
 *   a, e, i, o, u (both lowercase and uppercase)
 *
 * ------------------------------------------------------------
 * APPROACH: Two-Pointer Technique
 *
 * ------------------------------------------------------------
 * KEY OBSERVATIONS:
 *
 * 1️⃣ We only need to reverse vowels,
 *    not the entire string.
 *
 * 2️⃣ Use two pointers:
 *       i → start
 *       j → end
 *
 * 3️⃣ Move pointers inward until both point to vowels.
 *    Then swap.
 *
 * ------------------------------------------------------------
 * STRATEGY:
 *
 * 1️⃣ Create a copy of string (w).
 *
 * 2️⃣ Maintain:
 *       vowels = "aeiouAEIOU"
 *
 * 3️⃣ While i < j:
 *       - Move i forward until vowel found.
 *       - Move j backward until vowel found.
 *       - Swap.
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * s = "hello"
 *
 * i → 'h' (skip)
 * i → 'e' (vowel)
 *
 * j → 'o' (vowel)
 *
 * Swap:
 * "holle"
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 * - O(n)
 *   (Each character visited at most once)
 *
 * Space Complexity:
 * - O(1) extra (excluding output copy)
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - Can optimize vowel checking using:
 *     unordered_set<char>
 *   for O(1) lookup.
 *
 * - Classic two-pointer string problem.
 */

class Solution {
public:
    string reverseVowels(string s) {

        string w = s;

        int n = s.size();
        int i = 0;
        int j = n - 1;

        string vowels = "aeiouAEIOU";

        while (i < j) {

            // Move i until vowel
            while (i < j &&
                   vowels.find(w[i]) == string::npos)
                i++;

            // Move j until vowel
            while (i < j &&
                   vowels.find(w[j]) == string::npos)
                j--;

            // Swap vowels
            swap(w[i++], w[j--]);
        }

        return w;
    }
};

/*
 * Problem: 125. Valid Palindrome
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given a string s, determine if it is a palindrome,
 * considering only alphanumeric characters and ignoring cases.
 *
 * Return true if it is a palindrome, otherwise false.
 *
 * ------------------------------------------------------------
 * DEFINITION:
 *
 * - Ignore non-alphanumeric characters.
 * - Treat uppercase and lowercase letters as the same.
 *
 * ------------------------------------------------------------
 * APPROACH: String Filtering + Two-Pointer Technique
 *
 * ------------------------------------------------------------
 * KEY OBSERVATIONS:
 *
 * 1️⃣ Only letters and digits matter.
 *    → Use isalnum() to filter characters.
 *
 * 2️⃣ Case does not matter.
 *    → Convert everything to lowercase.
 *
 * 3️⃣ After cleaning the string,
 *    simply check if it is a palindrome.
 *
 * ------------------------------------------------------------
 * STRATEGY:
 *
 * 1️⃣ Build a new string:
 *      - Keep only alphanumeric characters.
 *      - Convert to lowercase.
 *
 * 2️⃣ Use two pointers:
 *      i → start
 *      j → end
 *
 * 3️⃣ Compare characters while i < j.
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * s = "A man, a plan, a canal: Panama"
 *
 * Cleaned string:
 * "amanaplanacanalpanama"
 *
 * Compare from both ends → valid palindrome.
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 * - O(n)
 *
 * Space Complexity:
 * - O(n) (extra filtered string)
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - Alternative approach:
 *   Use two pointers directly on original string
 *   without building a new string (O(1) space).
 */

class Solution {
public:
    bool isPalindrome(string s) {

        string str = "";

        // Filter and normalize string
        for (auto ch : s) {
            if (isalnum(ch))
                str += tolower(ch);
        }

        // Two-pointer check
        int i = 0;
        int j = str.length() - 1;

        while (i < j) {
            if (str[i++] != str[j--])
                return false;
        }

        return true;
    }
};

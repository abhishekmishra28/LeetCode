/*
 * Problem: 17. Letter Combinations of a Phone Number
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given a string digits containing digits from 2-9,
 * return all possible letter combinations that the number
 * could represent (like on a phone keypad).
 *
 * Mapping:
 * 2 → abc
 * 3 → def
 * 4 → ghi
 * 5 → jkl
 * 6 → mno
 * 7 → pqrs
 * 8 → tuv
 * 9 → wxyz
 *
 * Return the answer in any order.
 *
 * ------------------------------------------------------------
 * APPROACH: Backtracking (Cartesian Product Generation)
 *
 * ------------------------------------------------------------
 * KEY OBSERVATIONS:
 *
 * 1️⃣ Each digit maps to multiple characters.
 *
 * 2️⃣ For each digit position:
 *    - We must try every possible mapped character.
 *
 * 3️⃣ This forms a recursive tree where:
 *    - Level = digit index
 *    - Branches = number of letters mapped to that digit
 *
 * ------------------------------------------------------------
 * STRATEGY:
 *
 * backtrack(idx, digits, mapping, curr, result)
 *
 * idx     → current position in digits
 * curr    → currently formed string
 * result  → stores final combinations
 *
 * ------------------------------------------------------------
 * BASE CASE:
 *
 * If idx == digits.size():
 * → One full combination formed
 * → Add to result
 *
 * ------------------------------------------------------------
 * RECURSION FLOW:
 *
 * For current digit:
 *   1️⃣ Get mapped string
 *   2️⃣ For each character in mapped string:
 *        - Append character
 *        - Recurse for next index
 *        - Backtrack (remove character)
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * digits = "23"
 *
 * 2 → "abc"
 * 3 → "def"
 *
 * Output:
 * ad ae af
 * bd be bf
 * cd ce cf
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 * - O(4^n)
 *   (Each digit can map to at most 4 letters)
 *
 * Space Complexity:
 * - O(n) recursion depth
 * - O(4^n) to store results
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - Classic backtracking problem
 * - Essentially generating Cartesian product
 * - Always check for empty input first
 */

class Solution {
private:
    void backtrack(int idx,
                   string digits,
                   vector<string> mapping,
                   string& curr,
                   vector<string>& result) {

        // Base case: full combination formed
        if (idx >= digits.size()) {
            result.push_back(curr);
            return;
        }

        // Get digit and its corresponding letters
        int num = digits[idx] - '0';
        string letters = mapping[num];

        // Try each possible letter
        for (int i = 0; i < letters.size(); i++) {

            curr.push_back(letters[i]);

            backtrack(idx + 1,
                      digits,
                      mapping,
                      curr,
                      result);

            // Backtrack
            curr.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {

        // Edge case: empty input
        if (digits.empty())
            return {};

        // Phone keypad mapping
        vector<string> mapping = {
            "",      // 0
            "",      // 1
            "abc",   // 2
            "def",   // 3
            "ghi",   // 4
            "jkl",   // 5
            "mno",   // 6
            "pqrs",  // 7
            "tuv",   // 8
            "wxyz"   // 9
        };

        vector<string> result;
        string curr;

        backtrack(0, digits, mapping, curr, result);

        return result;
    }
};

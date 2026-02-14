/*
 * Problem: 1249. Minimum Remove to Make Valid Parentheses
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given a string s containing:
 * - lowercase letters
 * - '('
 * - ')'
 *
 * Remove the minimum number of parentheses so that
 * the resulting string is valid.
 *
 * Return any valid string.
 *
 * ------------------------------------------------------------
 * DEFINITION OF VALID PARENTHESES STRING:
 *
 * 1️⃣ Every '(' must have a matching ')'
 * 2️⃣ At no point should ')' exceed '('
 *
 * ------------------------------------------------------------
 * APPROACH: Two-Pass Greedy Traversal
 *
 * ------------------------------------------------------------
 * KEY OBSERVATIONS:
 *
 * 1️⃣ Invalid ')' occur when:
 *    - There is no unmatched '(' available.
 *
 * 2️⃣ Invalid '(' remain if:
 *    - They were never matched with ')'.
 *
 * 3️⃣ We can fix this in TWO PASSES:
 *
 *    Pass 1 → Remove extra ')'
 *    Pass 2 → Remove extra '('
 *
 * ------------------------------------------------------------
 * STRATEGY:
 *
 * PASS 1 (Left → Right):
 * - Maintain a counter `open`
 * - If '(' → increment open
 * - If ')':
 *     - If open == 0 → invalid → mark for removal
 *     - Else → decrement open
 *
 * PASS 2 (Right → Left):
 * - If '(' still unmatched (open > 0)
 * - Mark extra '(' for removal
 *
 * Finally:
 * - Build result string ignoring marked characters
 *
 * ------------------------------------------------------------
 * WHY MARK WITH '*' ?
 *
 * Instead of removing characters immediately
 * (which would shift indices),
 * we mark them and build final string later.
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * s = "a)b(c)d"
 *
 * Pass 1:
 *   ')' at index 1 → invalid → mark
 *
 * Pass 2:
 *   no extra '('
 *
 * Result = "ab(c)d"
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 * - O(n)
 *
 * Space Complexity:
 * - O(n) (for result string)
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - Greedy two-pass solution
 * - No stack needed
 * - Very clean O(n) approach
 */

class Solution {
public:
    string minRemoveToMakeValid(string s) {

        int n = s.size();
        int open = 0;

        // PASS 1: Remove invalid ')'
        for (int i = 0; i < n; i++) {

            if (s[i] == '(') {
                open++;
            }
            else if (s[i] == ')') {

                // No matching '(' available
                if (open == 0) {
                    s[i] = '*';  // mark for removal
                }
                else {
                    open--;
                }
            }
        }

        // PASS 2: Remove extra '(' from right
        for (int i = n - 1; i >= 0; i--) {

            if (s[i] == '(' && open > 0) {
                s[i] = '*';  // mark extra '('
                open--;
            }
        }

        // Build final valid string
        string result;
        for (int i = 0; i < n; i++) {
            if (s[i] != '*')
                result.push_back(s[i]);
        }

        return result;
    }
};

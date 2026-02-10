/*
 * Problem: 2116. Check if a Parentheses String Can Be Valid
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * You are given two strings:
 * - s      → a parentheses string consisting of '(' and ')'
 * - locked → a binary string where:
 *            '1նելով' means the character at that index is locked (cannot be changed)
 *            '0' means the character is free (can be changed to '(' or ')')
 *
 * Return true if you can make the string s a valid parentheses string.
 *
 * ------------------------------------------------------------
 * DEFINITION OF VALID PARENTHESES STRING:
 *
 * - Every opening '(' has a corresponding closing ')'
 * - At any point, number of ')' must NOT exceed '('
 * - Total length must be even
 *
 * ------------------------------------------------------------
 * APPROACH: Stack-based Greedy Validation
 *
 * ------------------------------------------------------------
 * KEY OBSERVATIONS:
 *
 * 1️⃣ Length must be even
 *    - Odd-length strings can never be valid
 *
 * 2️⃣ Locked characters cannot be changed
 *
 * 3️⃣ Free characters ('0') can be used as either '(' or ')'
 *    - We will assign them greedily when needed
 *
 * ------------------------------------------------------------
 * STRATEGY:
 *
 * Use TWO stacks:
 *
 * - open → indices of locked '(' characters
 * - free → indices of unlocked characters ('0')
 *
 * ------------------------------------------------------------
 * ALGORITHM STEPS:
 *
 * 1️⃣ If n is odd → return false
 *
 * 2️⃣ Traverse the string from left to right:
 *    - If character is unlocked → push index into free stack
 *    - Else if locked '(' → push index into open stack
 *    - Else locked ')':
 *         a) Try to match with an open '('
 *         b) Else use a free character as '('
 *         c) Else → invalid
 *
 * 3️⃣ After traversal:
 *    - Match remaining '(' using free characters
 *    - Ensure free index appears AFTER '(' index
 *
 * ------------------------------------------------------------
 * WHY INDEX CHECK IS IMPORTANT?
 *
 * - A free character can only close a '(' if it appears later
 * - Order must be preserved for validity
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * s      = "))()("
 * locked = "01011"
 *
 * Step-by-step matching ensures:
 * - Free positions are used only when needed
 * - Order constraints are respected
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 * - O(n)
 *
 * Space Complexity:
 * - O(n) (stacks)
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - Greedy + Stack based solution
 * - Similar to valid parentheses but with flexibility
 * - Index comparison is the key trick
 */

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();

        // Odd length strings can never be valid
        if (n % 2 == 1)
            return false;

        // Stack for locked '(' positions
        stack<int> open;

        // Stack for free (unlocked) positions
        stack<int> free;

        // Traverse the string
        for (int i = 0; i < n; i++) {

            // If character is unlocked, store its index
            if (locked[i] == '0') {
                free.push(i);
            }
            // Locked opening bracket
            else if (s[i] == '(') {
                open.push(i);
            }
            // Locked closing bracket
            else {
                // Try to match with an opening bracket
                if (!open.empty()) {
                    open.pop();
                }
                // Or use a free position as '('
                else if (!free.empty()) {
                    free.pop();
                }
                // No valid match possible
                else {
                    return false;
                }
            }
        }

        // Match remaining '(' using free characters
        while (!open.empty()) {

            // No free character left to balance
            if (free.empty())
                return false;

            // Free index must be after '(' index
            if (open.top() > free.top())
                return false;

            open.pop();
            free.pop();
        }

        return true;
    }
};

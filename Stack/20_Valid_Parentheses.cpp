/*
 * Problem: 20. Valid Parentheses
 *
 * Statement:
 * Given a string `s` consisting of characters:
 *     '(', ')', '{', '}', '[', ']'
 *
 * Determine if the input string is VALID.
 *
 * A string is valid if:
 * - Open brackets are closed by the same type of brackets
 * - Open brackets are closed in the correct order
 * - Every closing bracket has a corresponding opening bracket
 *
 * ------------------------------------------------------------
 * APPROACH: Stack-Based Validation — Your Approach
 *
 * Core Idea:
 *
 * - Use a STACK to keep track of opening brackets
 * - Whenever a closing bracket appears:
 *     • It must match the MOST RECENT opening bracket
 *
 * This matches the LIFO (Last In, First Out) nature of stacks.
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. Initialize an empty stack `st`
 *
 * 2. Traverse each character `c` in string `s`:
 *
 *      a) If `c` is an OPENING bracket:
 *           '(' or '{' or '['
 *           → push it onto the stack
 *
 *      b) Else (it is a CLOSING bracket):
 *
 *           i) If stack is EMPTY:
 *                → No opening bracket to match
 *                → return false
 *
 *           ii) Check top of stack:
 *
 *                - '(' matches ')'
 *                - '{' matches '}'
 *                - '[' matches ']'
 *
 *                If matched:
 *                    → pop the opening bracket
 *                Else:
 *                    → mismatch → return false
 *
 * 3. After processing all characters:
 *
 *      If stack is EMPTY:
 *          → all brackets matched correctly → return true
 *      Else:
 *          → some opening brackets left unmatched → return false
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Stack always stores unmatched opening brackets
 * - The most recent opening bracket must be closed first
 * - Any mismatch or premature closing is detected immediately
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * Input: "{[()]}"
 *
 * Stack operations:
 *
 *   '{' → push
 *   '[' → push
 *   '(' → push
 *   ')' → pop '('
 *   ']' → pop '['
 *   '}' → pop '{'
 *
 * Stack empty at end → VALID ✔
 *
 * ------------------------------------------------------------
 * Example (Invalid):
 *
 * Input: "{[(])}"
 *
 * At character ']':
 *   top = '(' but expected '['
 *   → mismatch → INVALID ✘
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Empty string → valid
 * - String starting with closing bracket → invalid
 * - Odd length string → invalid
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - O(n)
 *   Each character is processed once
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(n)
 *   Stack may store all opening brackets
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Stack + Matching Pairs" problem
 *
 * Seen in:
 * - Expression validation
 * - Syntax checking
 * - Compiler parsing basics
 */

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            else if (!st.empty()) {
                if (st.top() == '(' && c == ')') st.pop();
                else if (st.top() == '{' && c == '}') st.pop();
                else if (st.top() == '[' && c == ']') st.pop();
                else return false;
            } 
            else {
                return false;
            }
        }

        return st.empty();
    }
};

/*
 * Problem: 22. Generate Parentheses
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given an integer n, generate all combinations of
 * well-formed (valid) parentheses consisting of n pairs.
 *
 * ------------------------------------------------------------
 * APPROACH: Backtracking with Validity Constraints
 *
 * ------------------------------------------------------------
 * KEY OBSERVATIONS:
 *
 * 1️⃣ Total length of a valid parentheses string = 2 * n.
 *
 * 2️⃣ We must maintain two conditions:
 *
 *    - Number of '(' used cannot exceed n.
 *    - Number of ')' used cannot exceed number of '(' used.
 *
 * 3️⃣ Instead of generating all strings and checking validity,
 *    we enforce validity during generation.
 *
 * ------------------------------------------------------------
 * STRATEGY:
 *
 * backtrack(n, open, close, curr, result)
 *
 * n      → total pairs required
 * open   → number of '(' used so far
 * close  → number of ')' used so far
 * curr   → current parentheses string
 * result → stores valid combinations
 *
 * ------------------------------------------------------------
 * BASE CASE:
 *
 * If curr.size() == 2 * n:
 * → Valid parentheses string formed
 * → Add to result
 *
 * ------------------------------------------------------------
 * RECURSION RULES:
 *
 * 1️⃣ Add '(' if open < n
 *
 * 2️⃣ Add ')' if close < open
 *    (Ensures string remains valid at every step)
 *
 * ------------------------------------------------------------
 * RECURSION TREE IDEA:
 *
 * For n = 2:
 *
 * ""
 * ├── "("
 * │   ├── "(("
 * │   │   └── "(())"
 * │   └── "()"
 * │       └── "()()"
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * n = 3
 *
 * Output:
 * ((()))
 * (()())
 * (())()
 * ()(())
 * ()()()
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 * - O(Catalan(n))
 * - Approximately O(4^n / sqrt(n))
 *
 * Space Complexity:
 * - O(n) recursion depth
 * - O(Catalan(n)) to store results
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - Classic backtracking problem
 * - Key trick: enforce validity while building string
 * - Do NOT generate all 2^(2n) strings
 * - Use constraints smartly
 */

class Solution {
private:
    void backtrack(int n,
                   int open,
                   int close,
                   string& curr,
                   vector<string>& result) {

        // Base case: valid parentheses string formed
        if (curr.size() == 2 * n) {
            result.push_back(curr);
            return;
        }

        // Add '(' if we still can
        if (open < n) {
            curr.push_back('(');
            backtrack(n, open + 1, close, curr, result);
            curr.pop_back();
        }

        // Add ')' only if it won't invalidate the string
        if (close < open) {
            curr.push_back(')');
            backtrack(n, open, close + 1, curr, result);
            curr.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {

        vector<string> result;
        string curr;

        backtrack(n, 0, 0, curr, result);

        return result;
    }
};

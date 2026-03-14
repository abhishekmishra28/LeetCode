/*
 * Problem: 3174. Clear Digits
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * You are given a string s containing lowercase letters
 * and digits.
 *
 * The rule is:
 *
 * Whenever a digit appears, remove the digit and also
 * remove the closest character to its left.
 *
 * Continue this process for the entire string and return
 * the resulting string.
 *
 * ------------------------------------------------------------
 * EXAMPLE:
 *
 * s = "abc3d2"
 *
 * Process:
 *
 * 'a' → keep
 * 'b' → keep
 * 'c' → keep
 * '3' → remove '3' and remove 'c'
 * string becomes "ab"
 *
 * 'd' → keep → "abd"
 * '2' → remove '2' and remove 'd'
 *
 * Result = "ab"
 *
 * ------------------------------------------------------------
 * APPROACH: Stack Simulation
 *
 * ------------------------------------------------------------
 * CORE IDEA:
 *
 * We simulate the process using a string as a stack.
 *
 * For each character in s:
 *
 * If it is a letter:
 *
 *      push it into the stack.
 *
 * If it is a digit:
 *
 *      remove the previous character
 *      (pop from stack).
 *
 * Digits themselves are not added to the stack.
 *
 * ------------------------------------------------------------
 * ALGORITHM STEPS:
 *
 * 1️⃣ Initialize an empty string (stack).
 *
 * 2️⃣ Traverse each character in the input string.
 *
 * 3️⃣ If character is a digit:
 *
 *      pop the last character from stack
 *      (if stack is not empty).
 *
 * 4️⃣ If character is a letter:
 *
 *      push it into stack.
 *
 * 5️⃣ Return the stack as the final result.
 *
 * ------------------------------------------------------------
 * DRY RUN:
 *
 * s = "ab1c2"
 *
 * stack = ""
 *
 * a → push → "a"
 * b → push → "ab"
 * 1 → pop → "a"
 * c → push → "ac"
 * 2 → pop → "a"
 *
 * Result = "a"
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 *      O(n)
 *
 * Space Complexity:
 *      O(n)
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * This problem is essentially
 * a stack simulation problem.
 *
 * Instead of using an explicit stack,
 * we use a string and pop_back().
 */

class Solution {
public:
    string clearDigits(string s) {

        string st;

        int n = s.size();

        for(int i = 0; i < n; i++){

            if(isdigit(s[i])){

                if(!st.empty()){
                    st.pop_back();
                }

            } else {

                st.push_back(s[i]);
            }
        }

        return st;
    }
};

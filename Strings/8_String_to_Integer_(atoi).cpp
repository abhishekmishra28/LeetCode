/*
 * Problem: 8. String to Integer (atoi)
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Implement the myAtoi(string s) function,
 * which converts a string to a 32-bit signed integer.
 *
 * Rules:
 *
 * 1️⃣ Ignore leading whitespace.
 *
 * 2️⃣ Check optional sign (+ or -).
 *
 * 3️⃣ Read digits until:
 *       - Non-digit character appears
 *       - End of string
 *
 * 4️⃣ Clamp result within 32-bit range:
 *
 *       INT_MAX =  2147483647
 *       INT_MIN = -2147483648
 *
 * ------------------------------------------------------------
 * APPROACH: Step-by-Step Parsing
 *
 * ------------------------------------------------------------
 * KEY OBSERVATIONS:
 *
 * 1️⃣ We must carefully handle overflow BEFORE it happens.
 *
 * 2️⃣ Overflow condition:
 *
 *    If:
 *       res > (INT_MAX - digit) / 10
 *
 *    Then next multiplication would overflow.
 *
 * ------------------------------------------------------------
 * STRATEGY:
 *
 * Step 1:
 *   Skip leading spaces.
 *
 * Step 2:
 *   Check for '+' or '-'.
 *
 * Step 3:
 *   Process numeric characters.
 *
 * Step 4:
 *   Before updating res:
 *       Check overflow condition.
 *
 * Step 5:
 *   Return result * sign.
 *
 * ------------------------------------------------------------
 * OVERFLOW LOGIC EXPLAINED:
 *
 * If:
 *   res * 10 + digit > INT_MAX
 *
 * Then:
 *   res > (INT_MAX - digit) / 10
 *
 * So we check that BEFORE updating.
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * Input: "   -42"
 *
 * Skip spaces → "-42"
 * Sign → -1
 *
 * res = 4
 * res = 42
 *
 * Output = -42
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 * - O(n)
 *
 * Space Complexity:
 * - O(1)
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - Be careful with overflow.
 * - Always check overflow before multiplication.
 * - Very common edge-case heavy problem.
 */

class Solution {
public:
    int myAtoi(string s) {

        int n = s.size();
        int i = 0;

        int flag = 1;   // sign
        int res = 0;

        // Step 1: Skip leading spaces
        while (i < n && s[i] == ' ')
            i++;

        // Step 2: Check sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {

            flag = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Process digits
        while (i < n && isdigit(s[i])) {

            int digit = s[i] - '0';

            // Step 4: Overflow check
            if (res > (INT_MAX - digit) / 10) {
                return (flag == 1) ? INT_MAX : INT_MIN;
            }

            res = res * 10 + digit;
            i++;
        }

        return res * flag;
    }
};

/*
 * Problem: 67. Add Binary
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given two binary strings a and b,
 * return their sum as a binary string.
 *
 * The input strings contain only '0' and '1'.
 *
 * ------------------------------------------------------------
 * APPROACH: Simulated Binary Addition (Like Manual Addition)
 *
 * ------------------------------------------------------------
 * KEY OBSERVATIONS:
 *
 * 1️⃣ Binary addition rules:
 *
 *    0 + 0 = 0
 *    0 + 1 = 1
 *    1 + 1 = 0 (carry 1)
 *
 * 2️⃣ Just like decimal addition,
 *    we process from right → left.
 *
 * 3️⃣ Maintain a carry variable.
 *
 * ------------------------------------------------------------
 * STRATEGY:
 *
 * - Use two pointers:
 *     i → end of string a
 *     j → end of string b
 *
 * - While:
 *     i >= 0 OR j >= 0 OR carry exists
 *
 * - Add:
 *     carry
 *     + current digit from a (if valid)
 *     + current digit from b (if valid)
 *
 * - Append (sum % 2) to answer
 * - Update carry = sum / 2
 *
 * - Reverse the result at the end
 *
 * ------------------------------------------------------------
 * LOOP CONDITION:
 *
 * while(i >= 0 || j >= 0 || carry)
 *
 * Ensures:
 * - All digits processed
 * - Remaining carry handled
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * a = "1010"
 * b = "1011"
 *
 * Step-by-step:
 *
 *   0 + 1 = 1
 *   1 + 1 = 0 (carry 1)
 *   0 + 0 + 1 = 1
 *   1 + 1 = 0 (carry 1)
 *   leftover carry = 1
 *
 * Result = "10101"
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 * - O(max(n, m))
 *
 * Space Complexity:
 * - O(max(n, m)) for result string
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - Classic string simulation problem
 * - No need to convert to integers
 * - Handle carry carefully
 */

class Solution {
public:
    string addBinary(string a, string b) {

        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        string ans = "";

        // Process from right to left
        while (i >= 0 || j >= 0 || carry) {

            int sum = carry;

            if (i >= 0)
                sum += a[i--] - '0';

            if (j >= 0)
                sum += b[j--] - '0';

            // Append current bit
            ans.push_back((sum % 2) + '0');

            // Update carry
            carry = sum / 2;
        }

        // Reverse because we built from LSB → MSB
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

/*
 * Problem: 1108. Defanging an IP Address
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given a valid IPv4 address, return a defanged version of it.
 *
 * Defanging an IP address means replacing every '.'
 * with "[.]".
 *
 * ------------------------------------------------------------
 * EXAMPLE:
 *
 * Input:
 *   "1.1.1.1"
 *
 * Output:
 *   "1[.]1[.]1[.]1"
 *
 * ------------------------------------------------------------
 * WHY DEFANGING?
 *
 * Defanging an IP address is used in cybersecurity
 * and web content filtering to prevent automatic
 * hyperlink detection of IP addresses.
 *
 * ------------------------------------------------------------
 * APPROACH: Simple String Traversal
 *
 * ------------------------------------------------------------
 * CORE IDEA:
 *
 * Traverse the string character by character.
 *
 * If the character is '.'
 *      append "[.]"
 *
 * Otherwise
 *      append the character itself.
 *
 * ------------------------------------------------------------
 * ALGORITHM STEPS:
 *
 * 1️⃣ Initialize an empty string result.
 *
 * 2️⃣ Iterate through each character in the input string.
 *
 * 3️⃣ If character == '.'
 *        add "[.]"
 *
 *    Else
 *        add the character.
 *
 * 4️⃣ Return the constructed string.
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * address = "255.100.50.0"
 *
 * Process:
 *
 * '2' → "2"
 * '5' → "25"
 * '5' → "255"
 * '.' → "255[.]"
 * '1' → "255[.]1"
 * ...
 *
 * Final:
 * "255[.]100[.]50[.]0"
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 *   O(n)
 *   (single traversal of string)
 *
 * Space Complexity:
 *   O(n)
 *   (result string storage)
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - Very simple string manipulation problem.
 * - Often used as a warm-up problem.
 */

class Solution {
public:
    string defangIPaddr(string address) {

        string res = "";

        for (char c : address) {

            if (c == '.') {
                res += "[.]";
            }
            else {
                res += c;
            }
        }

        return res;
    }
};

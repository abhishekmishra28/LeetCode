/*
 * Problem: 13. Roman to Integer
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given a Roman numeral string s,
 * convert it to an integer.
 *
 * Roman numerals:
 *
 * I  → 1
 * V  → 5
 * X  → 10
 * L  → 50
 * C  → 100
 * D  → 500
 * M  → 1000
 *
 * ------------------------------------------------------------
 * SPECIAL RULE (Subtractive Notation):
 *
 * Normally:
 *   Larger value after smaller value → subtract.
 *
 * Examples:
 *   IV  = 5 - 1 = 4
 *   IX  = 10 - 1 = 9
 *   XL  = 50 - 10 = 40
 *   XC  = 100 - 10 = 90
 *   CD  = 500 - 100 = 400
 *   CM  = 1000 - 100 = 900
 *
 * ------------------------------------------------------------
 * APPROACH: Single Pass Traversal
 *
 * ------------------------------------------------------------
 * KEY OBSERVATIONS:
 *
 * 1️⃣ Traverse string from left → right.
 *
 * 2️⃣ If current value < next value:
 *      → subtract current value.
 *
 * 3️⃣ Otherwise:
 *      → add current value.
 *
 * ------------------------------------------------------------
 * WHY THIS WORKS:
 *
 * Example: "MCM"
 *
 * M (1000)
 * C (100) < M (1000) → subtract 100
 * M (1000)
 *
 * Result = 1000 - 100 + 1000 = 1900
 *
 * ------------------------------------------------------------
 * ALGORITHM:
 *
 * For each index i:
 *
 *   if (i + 1 exists AND value[i] < value[i+1])
 *       subtract value[i]
 *   else
 *       add value[i]
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * s = "MCMXCIV"
 *
 * M → +1000
 * C < M → -100
 * M → +1000
 * X < C → -10
 * C → +100
 * I < V → -1
 * V → +5
 *
 * Result = 1994
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
 * - Very common beginner problem.
 * - Can also solve by scanning right → left
 *   (compare with previous value).
 */

class Solution {
public:
    int romanToInt(string s) {

        unordered_map<char, int> roman = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int result = 0;

        for (int i = 0; i < s.size(); i++) {

            // If next value is greater, subtract current
            if (i + 1 < s.size() &&
                roman[s[i]] < roman[s[i + 1]]) {

                result -= roman[s[i]];
            }
            else {
                result += roman[s[i]];
            }
        }

        return result;
    }
};

/*
 * Problem: 190. Reverse Bits
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Reverse the bits of a given 32-bit unsigned integer.
 *
 * Example:
 *
 * Input : 00000010100101000001111010011100
 * Output: 00111001011110000010100101000000
 *
 * ------------------------------------------------------------
 * APPROACH: Bit Manipulation (Shift & Extract)
 *
 * ------------------------------------------------------------
 * KEY OBSERVATIONS:
 *
 * 1️⃣ A 32-bit integer has exactly 32 bits.
 *
 * 2️⃣ To reverse bits:
 *    - Extract the least significant bit (LSB) from n.
 *    - Append it to the result from left side.
 *
 * 3️⃣ We build the reversed number one bit at a time.
 *
 * ------------------------------------------------------------
 * STRATEGY:
 *
 * Initialize:
 *   res = 0
 *
 * Repeat 32 times:
 *
 *   1️⃣ Shift result left by 1
 *   2️⃣ Extract last bit of n → (n & 1)
 *   3️⃣ Add it to result using OR
 *   4️⃣ Shift n right by 1
 *
 * ------------------------------------------------------------
 * WHY THIS WORKS:
 *
 * Each iteration:
 *
 *   res <<= 1        → makes space for new bit
 *   res |= (n & 1)   → inserts extracted bit
 *   n >>= 1          → move to next bit
 *
 * After 32 steps:
 *   All bits reversed.
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * n = 5 (binary 000...0101)
 *
 * Iteration 1:
 *   extract 1 → res = 1
 *
 * Iteration 2:
 *   extract 0 → res = 10
 *
 * Iteration 3:
 *   extract 1 → res = 101
 *
 * Remaining bits are 0
 *
 * Final reversed value formed.
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 * - O(1)
 *   (Always 32 iterations)
 *
 * Space Complexity:
 * - O(1)
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - Classic bit manipulation problem
 * - Always iterate exactly 32 times
 * - Use unsigned int if dealing strictly with bit patterns
 */

class Solution {
public:
    int reverseBits(int n) {

        int res = 0;

        // Process all 32 bits
        for (int i = 0; i < 32; i++) {

            // Make space for next bit
            res <<= 1;

            // Add last bit of n
            res |= (n & 1);

            // Move to next bit
            n >>= 1;
        }

        return res;
    }
};

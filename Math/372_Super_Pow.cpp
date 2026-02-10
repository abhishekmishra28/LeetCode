/*
 * Problem: 372. Super Pow
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * You are given two integers:
 * - a (base)
 * - b (an array of digits representing a very large exponent)
 *
 * Compute:
 *      a^b % 1337
 *
 * where b is too large to be converted into a normal integer.
 *
 * ------------------------------------------------------------
 * APPROACH: Modular Arithmetic + Fast Exponentiation
 *
 * ------------------------------------------------------------
 * KEY OBSERVATIONS:
 *
 * 1️⃣ The exponent b is given as a digit array.
 *    - We cannot directly convert it to an integer.
 *
 * 2️⃣ Mathematical property used:
 *
 *    If b = [d1, d2, d3, ... dk], then:
 *
 *    a^(d1d2...dk)
 *    = (((a^d1)^10 * a^d2)^10 * a^d3 ... ) % M
 *
 * 3️⃣ This allows us to process digits one-by-one.
 *
 * ------------------------------------------------------------
 * CORE FORMULA USED:
 *
 * Let result store the current value:
 *
 * For each digit d in b:
 *   result = (result^10 % M) * (a^d % M) % M
 *
 * ------------------------------------------------------------
 * WHY FAST EXPONENTIATION?
 *
 * - Exponents can be large
 * - Binary exponentiation reduces power calculation
 *   from O(b) to O(log b)
 *
 * ------------------------------------------------------------
 * HELPER FUNCTION:
 *
 * findPow(a, b):
 * - Computes (a^b) % M using recursion
 * - Uses divide-and-conquer strategy
 *
 * ------------------------------------------------------------
 * ALGORITHM STEPS:
 *
 * 1️⃣ Initialize result = 1
 * 2️⃣ Reduce a modulo M
 * 3️⃣ For each digit in b:
 *    - result = result^10 % M
 *    - result = result * (a^digit % M) % M
 * 4️⃣ Return result
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * a = 2
 * b = [1, 0]
 *
 * Meaning: 2^10
 *
 * Step 1: result = 1
 * digit = 1:
 *   result = 1^10 * 2^1 = 2
 * digit = 0:
 *   result = 2^10 * 2^0 = 1024
 *
 * Final answer = 1024 % 1337 = 1024
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 * - O(len(b) * log 10)
 * - Effectively O(n), since log 10 is constant
 *
 * Space Complexity:
 * - O(log b) due to recursion stack in findPow
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - Key trick is processing exponent digit-by-digit
 * - Modulo arithmetic properties are essential
 * - Very common problem combining math + recursion
 */

class Solution {
private:
    static const int M = 1337;

    // Fast exponentiation: (a^b) % M
    long long findPow(long long a, long long b) {
        if (b == 0)
            return 1;

        long long half = findPow(a, b / 2);
        long long result = (half * half) % M;

        if (b % 2)
            result = (result * a) % M;

        return result;
    }

public:
    int superPow(int a, vector<int>& b) {

        int result = 1;
        a %= M;

        // Process exponent digit by digit
        for (int digit : b) {

            // Raise current result to power 10
            result = findPow(result, 10);

            // Multiply by a^digit
            result = (result * findPow(a, digit)) % M;
        }

        return result;
    }
};

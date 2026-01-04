/*
 * Problem: 1390. Four Divisors
 *
 * Statement:
 * You are given an integer array `nums`.
 * For each integer in the array, check whether it has EXACTLY four divisors.
 * If it does, add the SUM of those four divisors to the final answer.
 *
 * Return the total sum over all such integers.
 *
 * ------------------------------------------------------------
 * Key Observations:
 *
 * - Every positive integer has at least two divisors: 1 and itself
 * - We are ONLY interested in numbers having EXACTLY 4 divisors
 * - Divisors come in pairs: (d, n/d)
 *
 * ------------------------------------------------------------
 * Important Insight:
 *
 * If a number has exactly 4 divisors, then:
 * - It must be either:
 *   1) p³  (where p is a prime)
 *   OR
 *   2) p × q (where p and q are distinct primes)
 *
 * HOWEVER…
 * Instead of prime factorization, we directly COUNT divisors
 * while summing them (as done in your approach).
 *
 * ------------------------------------------------------------
 * Approach: Brute Force Divisor Counting (Optimized)
 *
 * For each number:
 * - Start with 2 divisors already counted: {1, number}
 * - Iterate from 2 to √number
 * - If j divides number:
 *     • j is a divisor
 *     • number/j is another divisor (if different)
 * - Count divisors and accumulate sum simultaneously
 * - Stop early if divisor count exceeds 4
 *
 * ------------------------------------------------------------
 * Why Early Break?
 *
 * - We only care about EXACTLY 4 divisors
 * - Once count exceeds 4, the number is invalid
 * - Early termination saves time
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm:
 *
 * For each nums[i]:
 *
 * 1. Initialize:
 *    cnt = 2        → counting divisors {1, nums[i]}
 *    sum = 1 + nums[i]
 *
 * 2. Loop j from 2 to √nums[i]:
 *    - If nums[i] % j == 0:
 *        • cnt++
 *        • sum += j
 *        • otherDiv = nums[i] / j
 *        • If j != otherDiv:
 *            cnt++
 *            sum += otherDiv
 *        • If cnt > 4 → break
 *
 * 3. After loop:
 *    - If cnt == 4 → add sum to total
 *
 * ------------------------------------------------------------
 * Example:
 *
 * nums = [21, 4, 7]
 *
 * For 21:
 * Divisors = {1, 3, 7, 21}
 * cnt = 4, sum = 32 → added
 *
 * For 4:
 * Divisors = {1, 2, 4}
 * cnt = 3 → ignored
 *
 * For 7:
 * Divisors = {1, 7}
 * cnt = 2 → ignored
 *
 * Output = 32
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Prime numbers → always ignored
 * - Perfect squares → careful with duplicate divisors
 * - Small numbers (≤ 3)
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n × √k)
 *   where k is the maximum number in nums
 *
 * Space Complexity:
 * - O(1)
 *   only constant extra variables
 *
 * ------------------------------------------------------------
 * Note:
 * This solution follows your exact logic:
 * - No prime factorization
 * - Divisor counting + summation together
 * - Early stopping optimization
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int total = 0;

        for (int i = 0; i < n; i++) {
            int cnt = 2;                  // 1 and the number itself
            int sum = 1 + nums[i];

            for (int j = 2; j * j <= nums[i]; j++) {
                // If j is a divisor
                if (nums[i] % j == 0) {
                    int otherDiv = nums[i] / j;

                    cnt++;
                    sum += j;

                    // Avoid double counting for perfect squares
                    if (j != otherDiv) {
                        cnt++;
                        sum += otherDiv;
                    }

                    // More than 4 divisors → invalid
                    if (cnt > 4) break;
                }
            }

            // Exactly 4 divisors → add sum
            if (cnt == 4) {
                total += sum;
            }
        }

        return total;
    }
};

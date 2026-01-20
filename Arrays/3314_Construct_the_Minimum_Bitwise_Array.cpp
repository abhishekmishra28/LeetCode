/*
 * Problem: 3314. Construct the Minimum Bitwise Array I
 *
 * Statement:
 * You are given an array `nums` of length n consisting of PRIME integers.
 *
 * You need to construct an array `ans` of the same length such that:
 *
 *   ans[i] OR (ans[i] + 1) == nums[i]
 *
 * Additionally:
 * - ans[i] should be MINIMIZED
 * - If no such value exists, set ans[i] = -1
 *
 * ------------------------------------------------------------
 * KEY OBSERVATION (Very Important):
 *
 * Consider the binary behavior of two consecutive numbers:
 *
 *   Let x be some integer.
 *   Then (x | (x + 1)) has a very specific structure.
 *
 * Example:
 *   x     =  0111
 *   x + 1 =  1000
 *   OR    =  1111
 *
 * General Rule:
 * - (x | (x + 1)) turns ALL trailing 1s of x into 1s
 * - And also turns the first 0 before them into 1
 *
 * ------------------------------------------------------------
 * CRITICAL PROPERTY:
 *
 * A number `nums[i]` is representable as:
 *
 *   nums[i] = x | (x + 1)
 *
 * IF AND ONLY IF:
 * - nums[i] is ODD
 *
 * Why?
 * - The least significant bit (LSB) of (x | (x+1)) is ALWAYS 1
 * - So any even number (ending in 0) is IMPOSSIBLE
 *
 * Since nums[i] are PRIME:
 * - The only EVEN prime is 2
 * - For nums[i] = 2 → answer is ALWAYS -1
 *
 * ------------------------------------------------------------
 * GOAL:
 *
 * For each nums[i], find the MINIMUM x such that:
 *
 *   x | (x + 1) == nums[i]
 *
 * ------------------------------------------------------------
 * APPROACH: Brute Force per Element (Accepted for Easy)
 *
 * Since constraints are small, we can safely brute force.
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm:
 *
 * 1. For each element nums[i]:
 *
 * 2. Try all values of x starting from 1 up to nums[i] - 1:
 *
 *      If (x | (x + 1)) == nums[i]:
 *          - This is the SMALLEST possible x (because we go in order)
 *          - Set ans[i] = x
 *          - Stop searching
 *
 * 3. If no such x is found:
 *      - Set ans[i] = -1
 *
 * ------------------------------------------------------------
 * Why This Guarantees Minimum ans[i]:
 *
 * - We iterate x in increasing order
 * - The first valid x encountered is the minimum
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * nums = [3, 5, 7, 2]
 *
 * nums[i] = 3:
 *   x = 1 → (1 | 2) = 3 ✔
 *   ans = 1
 *
 * nums[i] = 5:
 *   x = 1 → (1 | 2) = 3 ✘
 *   x = 2 → (2 | 3) = 3 ✘
 *   x = 3 → (3 | 4) = 7 ✘
 *   → no match → ans = -1
 *
 * nums[i] = 7:
 *   x = 3 → (3 | 4) = 7 ✔
 *   ans = 3
 *
 * nums[i] = 2:
 *   Even number → impossible → ans = -1
 *
 * Result:
 *   [1, -1, 3, -1]
 *
 * ------------------------------------------------------------
 * TIME COMPLEXITY:
 *
 * Let M = maximum value in nums
 *
 * - For each element:
 *     O(nums[i]) checks
 *
 * Worst case:
 * - O(n * M)
 *
 * This is acceptable because:
 * - Problem is Easy
 * - Input constraints are small
 *
 * ------------------------------------------------------------
 * SPACE COMPLEXITY:
 *
 * - O(1) extra space (in-place / output array only)
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTE (Optimization Insight):
 *
 * There exists an O(1) solution per element using bit tricks:
 *
 * - For odd nums[i], the answer is:
 *
 *     ans[i] = nums[i] - (lowest set bit of nums[i])
 *
 * But brute force is perfectly fine here and easier to reason about.
 *
 * ------------------------------------------------------------
 * PATTERN RECOGNITION:
 *
 * This problem tests:
 * - Understanding of bitwise OR
 * - Binary behavior of consecutive integers
 * - Constructive logic with minimization
 */

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int original = nums[i];
            bool found = false;

            for (int x = 1; x < nums[i]; x++) {
                if ((x | (x + 1)) == nums[i]) {
                    nums[i] = x;
                    found = true;
                    break;
                }
            }

            if (!found) nums[i] = -1;
        }
        return nums;
    }
};

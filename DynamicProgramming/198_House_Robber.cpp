/*
 * Problem: 198. House Robber
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * You are given an integer array nums where:
 *   nums[i] represents the amount of money in house i.
 *
 * You cannot rob two adjacent houses.
 *
 * Return the maximum amount of money you can rob.
 *
 * ------------------------------------------------------------
 * APPROACH: Dynamic Programming (Space Optimized)
 *
 * ------------------------------------------------------------
 * KEY OBSERVATIONS:
 *
 * 1️⃣ At each house i, we have two choices:
 *
 *    - Do NOT rob current house:
 *        profit = prev1
 *
 *    - Rob current house:
 *        profit = prev2 + nums[i]
 *
 * 2️⃣ So recurrence becomes:
 *
 *    dp[i] = max(dp[i-1], dp[i-2] + nums[i])
 *
 * 3️⃣ Instead of full dp array,
 *    we only need last two values.
 *
 * ------------------------------------------------------------
 * VARIABLES:
 *
 * prev1 → dp[i-1]
 * prev2 → dp[i-2]
 *
 * ------------------------------------------------------------
 * STRATEGY:
 *
 * Initialize:
 *   prev1 = 0
 *   prev2 = 0
 *
 * For each house:
 *
 *   temp = max(prev1, prev2 + nums[i])
 *   prev2 = prev1
 *   prev1 = temp
 *
 * Final answer = prev1
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * nums = [2,7,9,3,1]
 *
 * Step-by-step:
 *
 * i=0 → 2
 * i=1 → max(2,7)=7
 * i=2 → max(7,2+9=11)=11
 * i=3 → max(11,7+3=10)=11
 * i=4 → max(11,11+1=12)=12
 *
 * Answer = 12
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
 * - Classic 1D DP problem.
 * - Key idea: choose or skip.
 * - Extension: House Robber II (circular houses).
 */

class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();

        int prev1 = 0;  // dp[i-1]
        int prev2 = 0;  // dp[i-2]

        for (int i = 0; i < n; i++) {

            int temp = max(prev1,
                           prev2 + nums[i]);

            prev2 = prev1;
            prev1 = temp;
        }

        return prev1;
    }
};

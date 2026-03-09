/*
 * Problem: 213. House Robber II
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * You are given an integer array nums where:
 *      nums[i] = amount of money in house i.
 *
 * Houses are arranged in a CIRCLE.
 *
 * You cannot rob two adjacent houses.
 *
 * Return the maximum amount of money you can rob.
 *
 * ------------------------------------------------------------
 * KEY DIFFERENCE FROM HOUSE ROBBER I:
 *
 * In House Robber I, houses are in a straight line.
 *
 * Here houses form a circle, meaning:
 *
 *      house 0 and house n-1 are adjacent.
 *
 * So you cannot rob both of them together.
 *
 * ------------------------------------------------------------
 * CORE IDEA:
 *
 * Break the circular problem into two linear problems.
 *
 * Case 1:
 *      Rob houses from index 0 → n-2
 *      (exclude last house)
 *
 * Case 2:
 *      Rob houses from index 1 → n-1
 *      (exclude first house)
 *
 * Take the maximum of the two results.
 *
 * ------------------------------------------------------------
 * WHY THIS WORKS:
 *
 * Since house 0 and house n-1 cannot both be robbed,
 * every valid solution must fall into one of these cases:
 *
 *      • first house included → last excluded
 *      • last house included → first excluded
 *
 * ------------------------------------------------------------
 * SUBPROBLEM:
 *
 * Each case becomes the classic
 * "House Robber I" dynamic programming problem.
 *
 * Recurrence:
 *
 *      dp[i] = max(
 *                  dp[i-1],             // skip house
 *                  nums[i] + dp[i-2]    // rob house
 *                 )
 *
 * ------------------------------------------------------------
 * ALGORITHM STEPS:
 *
 * 1️⃣ Handle edge case:
 *      If only one house → return nums[0].
 *
 * 2️⃣ Solve two linear rob problems:
 *
 *      rob(0 → n-2)
 *      rob(1 → n-1)
 *
 * 3️⃣ Return the maximum.
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * nums = [2,3,2]
 *
 * Case 1:
 *      [2,3] → rob = 3
 *
 * Case 2:
 *      [3,2] → rob = 3
 *
 * Answer = 3
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
 * (can be optimized to O(1) space)
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * Very common follow-up to House Robber I.
 *
 * Key trick:
 *      Convert circular constraint
 *      into two linear DP problems.
 */

class Solution {
private:

    int houseRob(vector<int> &nums, int l, int r){

        if(l == r)
            return nums[l];

        vector<int> dp(r - l + 1);

        dp[0] = nums[l];
        dp[1] = max(nums[l + 1], nums[l]);

        for(int i = 2; i <= r - l; i++){

            dp[i] = max(
                        dp[i - 1],
                        nums[l + i] + dp[i - 2]
                      );
        }

        return dp[r - l];
    }

public:

    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1)
            return nums[0];

        return max(
                    houseRob(nums, 0, n - 2),
                    houseRob(nums, 1, n - 1)
                  );
    }
};

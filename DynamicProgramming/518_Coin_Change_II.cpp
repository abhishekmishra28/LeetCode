/*
 * Problem: 518. Coin Change II
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * You are given an integer array coins representing
 * different denominations of coins and an integer amount.
 *
 * Return the number of combinations that make up the amount.
 *
 * You may assume that you have an infinite number
 * of each kind of coin.
 *
 * If the amount cannot be made up by any combination
 * of the coins, return 0.
 *
 * ------------------------------------------------------------
 * EXAMPLE:
 *
 * coins = [1,2,5]
 * amount = 5
 *
 * Possible combinations:
 *
 * 1 + 1 + 1 + 1 + 1
 * 1 + 1 + 1 + 2
 * 1 + 2 + 2
 * 5
 *
 * Total combinations = 4
 *
 * ------------------------------------------------------------
 * CORE IDEA:
 *
 * This is an **Unbounded Knapsack counting problem**.
 *
 * Unlike Coin Change I (minimum coins),
 * here we must count the number of ways.
 *
 * ------------------------------------------------------------
 * STATE DEFINITION:
 *
 * Let:
 *
 *      dp[i][a] = number of ways to make amount 'a'
 *                 using first 'i' coins.
 *
 * ------------------------------------------------------------
 * BASE CASE:
 *
 * Amount = 0
 *
 * There is exactly one way:
 *
 *      choose nothing
 *
 * Therefore:
 *
 *      dp[i][0] = 1
 *
 * ------------------------------------------------------------
 * TRANSITIONS:
 *
 * For each coin we have two choices:
 *
 * 1️⃣ Not take the coin
 *
 *      dp[i-1][a]
 *
 * 2️⃣ Take the coin (unlimited times allowed)
 *
 *      dp[i][a - coins[i-1]]
 *
 * Therefore:
 *
 *      dp[i][a] = take + notTake
 *
 * ------------------------------------------------------------
 * IMPORTANT DIFFERENCE FROM 0/1 KNAPSACK:
 *
 * We use:
 *
 *      dp[i][a - coins[i-1]]
 *
 * instead of:
 *
 *      dp[i-1][...]
 *
 * because coins can be used multiple times.
 *
 * ------------------------------------------------------------
 * DRY RUN:
 *
 * coins = [1,2,5]
 * amount = 5
 *
 * dp eventually computes:
 *
 * ways = 4
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 *      O(n × amount)
 *
 * Space Complexity:
 *      O(n × amount)
 *
 * ------------------------------------------------------------
 * SPACE OPTIMIZATION:
 *
 * Can be optimized to:
 *
 *      O(amount)
 *
 * using a 1D DP array.
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * Classic Unbounded Knapsack variant:
 *
 *      Coin Change I → minimum coins
 *      Coin Change II → number of combinations
 */

class Solution {
public:
    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        vector<vector<unsigned long long>> dp(
            n+1,
            vector<unsigned long long>(amount+1,0)
        );

        // Base case
        for(int i=0;i<=n;i++)
            dp[i][0] = 1;

        for(int i=1;i<=n;i++){

            for(int a=1;a<=amount;a++){

                unsigned long long notTake =
                        dp[i-1][a];

                unsigned long long take = 0;

                if(coins[i-1] <= a)
                    take = dp[i][a - coins[i-1]];

                dp[i][a] = take + notTake;
            }
        }

        return dp[n][amount];
    }
};

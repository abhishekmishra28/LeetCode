/*
 * Problem: 322. Coin Change
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * You are given an array coins representing different
 * denominations and an integer amount.
 *
 * Return the minimum number of coins required to make
 * the given amount.
 *
 * If it is not possible to make the amount, return -1.
 *
 * You may use each coin unlimited times.
 *
 * ------------------------------------------------------------
 * EXAMPLE:
 *
 * coins = [1,2,5]
 * amount = 11
 *
 * Optimal combination:
 *
 *      5 + 5 + 1 = 11
 *
 * Number of coins = 3
 *
 * ------------------------------------------------------------
 * CORE IDEA:
 *
 * This is an **Unbounded Knapsack problem**.
 *
 * Each coin can be used multiple times.
 *
 * At each coin we have two choices:
 *
 *      1️⃣ Take the coin
 *      2️⃣ Skip the coin
 *
 * ------------------------------------------------------------
 * APPROACHES:
 *
 * 1️⃣ Recursion (Brute Force)
 * 2️⃣ Memoization (Top-Down DP)
 * 3️⃣ Tabulation (Bottom-Up DP) ← Used in final solution
 *
 * ------------------------------------------------------------
 * APPROACH 1: MEMOIZATION
 *
 * State:
 *
 *      solve(i, amount)
 *
 * Meaning:
 *
 *      Minimum coins needed to form "amount"
 *      using coins from index i onwards.
 *
 * Choices:
 *
 * Take coin:
 *
 *      solve(i, amount - coins[i]) + 1
 *
 * Not take coin:
 *
 *      solve(i + 1, amount)
 *
 * ------------------------------------------------------------
 * APPROACH 2: TABULATION
 *
 * Let:
 *
 *      dp[i][j] = minimum coins required to make
 *                 amount j using first i coins.
 *
 * Initialization:
 *
 *      dp[i][0] = 0
 *
 * Transition:
 *
 * Not take:
 *
 *      dp[i-1][j]
 *
 * Take:
 *
 *      1 + dp[i][j - coins[i-1]]
 *
 * (same row because coins are unlimited)
 *
 * ------------------------------------------------------------
 * FINAL ANSWER:
 *
 *      dp[n][amount]
 *
 * If dp[n][amount] remains very large
 * (infinite value), return -1.
 *
 * ------------------------------------------------------------
 * DRY RUN:
 *
 * coins = [1,2,5]
 * amount = 11
 *
 * DP eventually finds:
 *
 *      11 = 5 + 5 + 1
 *
 * Minimum coins = 3
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
 * INTERVIEW NOTES:
 *
 * Classic DP problem.
 *
 * Very similar to:
 *
 *      • Unbounded Knapsack
 *      • Minimum coins to make amount
 */

class Solution {
public:

    /*--------------------------------------------------
      MEMOIZATION (TOP-DOWN)
    --------------------------------------------------*/
    int solve(int i, vector<int>& coins, int amount,
              vector<vector<int>> &dp){

        if(amount == 0)
            return 0;

        if(i == coins.size())
            return INT_MAX;

        if(dp[i][amount] != -1)
            return dp[i][amount];

        int take = INT_MAX;

        if(coins[i] <= amount){

            int res = solve(i, coins,
                            amount - coins[i], dp);

            if(res != INT_MAX)
                take = 1 + res;
        }

        int notTake =
            solve(i + 1, coins, amount, dp);

        return dp[i][amount] = min(take, notTake);
    }


    /*--------------------------------------------------
      TABULATION (BOTTOM-UP)
    --------------------------------------------------*/
    int tabulation(vector<int>& coins, int amount) {

        int n = coins.size();

        vector<vector<int>> dp(
            n + 1, vector<int>(amount + 1, 1e9)
        );

        for(int i = 0; i <= n; i++)
            dp[i][0] = 0;

        for(int i = 1; i <= n; i++){

            for(int j = 1; j <= amount; j++){

                int take = 1e9;

                if(coins[i-1] <= j){
                    take =
                        1 + dp[i][j - coins[i-1]];
                }

                int notTake = dp[i-1][j];

                dp[i][j] = min(take, notTake);
            }
        }

        return (dp[n][amount] == 1e9)
               ? -1
               : dp[n][amount];
    }


public:

    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        /*-----------------------------------------
          MEMOIZATION VERSION
        -----------------------------------------*/

        // vector<vector<int>> dp(n+1,
        //      vector<int>(amount+1, -1));
        //
        // int res = solve(0, coins, amount, dp);
        // return (res != INT_MAX) ? res : -1;

        /*-----------------------------------------
          TABULATION VERSION
        -----------------------------------------*/

        return tabulation(coins, amount);
    }
};

/*
 * Problem: 983. Minimum Cost For Tickets
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * You are given:
 *
 *      days  → days when you will travel
 *      costs → cost of travel passes
 *
 * Available passes:
 *
 *      1-day pass
 *      7-day pass
 *      30-day pass
 *
 * A pass covers consecutive days starting from
 * the day you buy it.
 *
 * Return the minimum cost required to cover
 * all travel days.
 *
 * ------------------------------------------------------------
 * EXAMPLE:
 *
 * days  = [1,4,6,7,8,20]
 * costs = [2,7,15]
 *
 * Optimal:
 *
 * 1-day pass on day 1 → 2
 * 7-day pass on day 6 → 7
 * 1-day pass on day 20 → 2
 *
 * Total = 11
 *
 * ------------------------------------------------------------
 * CORE IDEA:
 *
 * At each travel day we have three choices:
 *
 * 1️⃣ Buy a 1-day pass
 * 2️⃣ Buy a 7-day pass
 * 3️⃣ Buy a 30-day pass
 *
 * We recursively compute the minimum cost
 * for the remaining travel days.
 *
 * ------------------------------------------------------------
 * STATE DEFINITION:
 *
 * Let:
 *
 *      dp[i] = minimum cost to cover travel
 *              starting from days[i]
 *
 * ------------------------------------------------------------
 * TRANSITIONS:
 *
 * Option 1:
 *
 *      1-day pass
 *      cost1 = costs[0] + solve(i+1)
 *
 * Option 2:
 *
 *      7-day pass
 *      find first index j where
 *      days[j] > days[i] + 6
 *
 *      cost7 = costs[1] + solve(j)
 *
 * Option 3:
 *
 *      30-day pass
 *      find first index j where
 *      days[j] > days[i] + 29
 *
 *      cost30 = costs[2] + solve(j)
 *
 * ------------------------------------------------------------
 * FINAL STATE:
 *
 *      dp[i] = min(cost1, cost7, cost30)
 *
 * ------------------------------------------------------------
 * APPROACHES:
 *
 * 1️⃣ Memoization (Top-Down DP)
 * 2️⃣ Tabulation (Bottom-Up DP) ← Used in final code
 *
 * ------------------------------------------------------------
 * TIME COMPLEXITY:
 *
 * O(n²) in worst case due to scanning forward
 * to find next valid travel day.
 *
 * ------------------------------------------------------------
 * SPACE COMPLEXITY:
 *
 * O(n)
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * This is a classic "DP on timeline" problem.
 *
 * Important pattern:
 *
 *      Jump DP (skip indices depending on duration)
 */

class Solution {
private:

    vector<int> dp;

    /*--------------------------------------------------
      MEMOIZATION (TOP-DOWN)
    --------------------------------------------------*/
    int solve(int i, vector<int>& days, vector<int>& costs) {

        if(i >= days.size())
            return 0;

        if(dp[i] != -1)
            return dp[i];

        // 1-day pass
        int cost1 = costs[0] + solve(i+1, days, costs);

        // 7-day pass
        int j = i;
        while(j < days.size() && days[j] <= days[i] + 6)
            j++;
        int cost7 = costs[1] + solve(j, days, costs);

        // 30-day pass
        j = i;
        while(j < days.size() && days[j] <= days[i] + 29)
            j++;
        int cost30 = costs[2] + solve(j, days, costs);

        return dp[i] = min({cost1, cost7, cost30});
    }

    /*--------------------------------------------------
      TABULATION (BOTTOM-UP)
    --------------------------------------------------*/
    int solveBU(vector<int>& days, vector<int>& costs){

        dp.clear();

        int n = days.size();

        dp.resize(n+1, 0);

        for(int i = n-1; i >= 0; i--){

            // 1-day pass
            int c1 = costs[0] + dp[i+1];

            // 7-day pass
            int j = i;
            while(j < n && days[j] <= days[i] + 6)
                j++;
            int c7 = costs[1] + dp[j];

            // 30-day pass
            j = i;
            while(j < n && days[j] <= days[i] + 29)
                j++;
            int c30 = costs[2] + dp[j];

            dp[i] = min({c1, c7, c30});
        }

        return dp[0];
    }

public:

    int mincostTickets(vector<int>& days, vector<int>& costs) {

        /*---------------------------------------------
          MEMOIZATION VERSION
        ---------------------------------------------*/
        // dp.assign(days.size(), -1);
        // return solve(0, days, costs);

        /*---------------------------------------------
          TABULATION VERSION
        ---------------------------------------------*/
        return solveBU(days, costs);
    }
};

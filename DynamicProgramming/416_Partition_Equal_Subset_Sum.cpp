/*
 * Problem: 416. Partition Equal Subset Sum
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given an integer array nums, determine whether the array
 * can be partitioned into two subsets such that the sum of
 * elements in both subsets is equal.
 *
 * ------------------------------------------------------------
 * EXAMPLE:
 *
 * nums = [1,5,11,5]
 *
 * Total sum = 22
 *
 * Possible partition:
 *
 *      [11]
 *      [1,5,5]
 *
 * Both subsets sum to 11 → return true
 *
 * ------------------------------------------------------------
 * KEY OBSERVATION:
 *
 * If the total sum of the array is odd,
 * it is impossible to split it into two equal parts.
 *
 * Let:
 *
 *      totalSum = sum(nums)
 *
 * We must check if a subset exists with sum:
 *
 *      target = totalSum / 2
 *
 * This reduces the problem to the classic:
 *
 *      SUBSET SUM problem
 *
 * ------------------------------------------------------------
 * APPROACHES:
 *
 * 1️⃣ Recursion
 * 2️⃣ Memoization (Top-Down DP)
 * 3️⃣ Tabulation (Bottom-Up DP)  ← Used in final solution
 *
 * ------------------------------------------------------------
 * APPROACH 1: MEMOIZATION
 *
 * State:
 *
 *      solve(i, target)
 *
 * Meaning:
 *      Can we make "target" using elements
 *      from index i → end.
 *
 * Choices:
 *
 *      take     → include nums[i]
 *      notTake  → skip nums[i]
 *
 * Recurrence:
 *
 *      solve(i,target) =
 *              solve(i+1,target-nums[i])  OR
 *              solve(i+1,target)
 *
 * ------------------------------------------------------------
 * APPROACH 2: TABULATION
 *
 * Let:
 *
 *      dp[i][j] = true if we can make sum j
 *                 using first i elements.
 *
 * Initialization:
 *
 *      dp[i][0] = true  (sum 0 always possible)
 *
 * Transition:
 *
 *      notTake = dp[i-1][j]
 *
 *      take = false
 *      if(nums[i-1] <= j)
 *          take = dp[i-1][j - nums[i-1]]
 *
 *      dp[i][j] = take OR notTake
 *
 * Final answer:
 *
 *      dp[n][target]
 *
 * ------------------------------------------------------------
 * DRY RUN:
 *
 * nums = [1,5,11,5]
 *
 * totalSum = 22
 * target = 11
 *
 * We check if subset with sum = 11 exists.
 *
 * Yes → [11]
 *
 * Return true.
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 *      O(n × target)
 *
 * Space Complexity:
 *      O(n × target)
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * This is a very famous DP pattern:
 *
 *      Subset Sum / 0-1 Knapsack variation
 *
 * Frequently asked in coding interviews.
 */

class Solution {
private:

    /*--------------------------------------------------
      MEMOIZATION (TOP-DOWN)
    --------------------------------------------------*/
    bool solve(int i, vector<int>& nums,
               int target, vector<vector<int>> &dp){

        if(target == 0)
            return true;

        if(i >= nums.size() || target < 0)
            return false;

        if(dp[i][target] != -1)
            return dp[i][target];

        bool take =
            solve(i+1, nums, target-nums[i], dp);

        bool notTake =
            solve(i+1, nums, target, dp);

        return dp[i][target] = take || notTake;
    }


    /*--------------------------------------------------
      TABULATION (BOTTOM-UP)
    --------------------------------------------------*/
    bool tabulation(vector<int>& nums, int tar){

        int n = nums.size();

        vector<vector<bool>> dp(
            n+1, vector<bool>(tar+1, false)
        );

        // Sum = 0 always possible
        for(int i=0;i<=n;i++)
            dp[i][0] = true;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=tar;j++){

                bool notTake = dp[i-1][j];

                bool take = false;

                if(nums[i-1] <= j){
                    take =
                        dp[i-1][j - nums[i-1]];
                }

                dp[i][j] = take || notTake;
            }
        }

        return dp[n][tar];
    }

public:

    bool canPartition(vector<int>& nums) {

        int sum = accumulate(
            nums.begin(), nums.end(), 0
        );

        // If sum is odd → impossible
        if(sum % 2)
            return false;

        int tar = sum / 2;

        /*-----------------------------------------
          MEMOIZATION VERSION
        -----------------------------------------*/

        // vector<vector<int>> dp(
        //      nums.size(), vector<int>(tar+1,-1));
        // return solve(0, nums, tar, dp);

        /*-----------------------------------------
          TABULATION VERSION
        -----------------------------------------*/

        return tabulation(nums, tar);
    }
};

/*
 * Problem: 45. Jump Game II
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * You are given an integer array nums where:
 *
 *      nums[i] = maximum jump length from index i
 *
 * Starting from index 0,
 * return the minimum number of jumps needed
 * to reach the last index.
 *
 * ------------------------------------------------------------
 * APPROACH 1: Dynamic Programming (Tabulation)
 *
 * ------------------------------------------------------------
 * CORE IDEA:
 *
 * dp[i] → minimum jumps required to reach index i.
 *
 * Initialize:
 *
 *      dp[0] = 0
 *
 * For each index i,
 * update all reachable positions from i.
 *
 * If we can jump from i to j:
 *
 *      dp[j] = min(dp[j], dp[i] + 1)
 *
 * ------------------------------------------------------------
 * TRANSITION:
 *
 * For index i:
 *
 *      reachable indices =
 *          i+1 → min(n-1, i + nums[i])
 *
 * Update dp values accordingly.
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * nums = [2,3,1,1,4]
 *
 * Start:
 *
 * dp = [0,∞,∞,∞,∞]
 *
 * i=0 (jump=2):
 * dp[1] = 1
 * dp[2] = 1
 *
 * i=1 (jump=3):
 * dp[2] = 1
 * dp[3] = 2
 * dp[4] = 2
 *
 * Answer = 2
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY (DP):
 *
 * Time Complexity:
 *      O(n²)
 *
 * Space Complexity:
 *      O(n)
 *
 * ------------------------------------------------------------
 * APPROACH 2: Greedy (Optimal Solution)
 *
 * ------------------------------------------------------------
 * CORE IDEA:
 *
 * Think of the array as BFS levels.
 *
 * Variables:
 *
 *      maxReach → farthest index reachable so far
 *      currEnd  → boundary of current jump
 *      jumps    → number of jumps taken
 *
 * When we reach currEnd,
 * we must make another jump.
 *
 * ------------------------------------------------------------
 * GREEDY ALGORITHM:
 *
 * 1️⃣ Track the farthest reachable index.
 *
 * 2️⃣ When current index reaches currEnd:
 *
 *        jump++
 *        currEnd = maxReach
 *
 * 3️⃣ Continue until the end.
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY (GREEDY):
 *
 * Time Complexity:
 *      O(n)
 *
 * Space Complexity:
 *      O(1)
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - Greedy solution is the optimal one.
 * - DP solution helps understand the transitions.
 */

class Solution {
public:
    int jump(vector<int>& nums) {

        int n = nums.size();

        // DP array
        vector<int> dp(n, INT_MAX);

        dp[0] = 0;

        for(int i = 0; i < n; i++){

            for(int j = i + 1;
                j <= min(n - 1, nums[i] + i);
                j++){

                dp[j] = min(dp[j], dp[i] + 1);
            }
        }

        return dp[n - 1];

        /*
        ----------- GREEDY SOLUTION (OPTIMAL) -----------

        int jumps = 0;
        int currEnd = 0;
        int maxReach = 0;

        for(int i = 0; i < nums.size() - 1; i++){

            maxReach = max(maxReach, i + nums[i]);

            if(i == currEnd){

                jumps++;
                currEnd = maxReach;
            }
        }

        return jumps;
        */
    }
};

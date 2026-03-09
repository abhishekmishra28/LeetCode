/*
 * Problem: 300. Longest Increasing Subsequence (LIS)
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given an integer array nums,
 * return the length of the longest strictly increasing
 * subsequence.
 *
 * A subsequence is derived from the array by deleting
 * some or no elements without changing the order.
 *
 * ------------------------------------------------------------
 * EXAMPLE:
 *
 * nums = [10,9,2,5,3,7,101,18]
 *
 * One LIS is:
 *
 *      [2,3,7,101]
 *
 * Length = 4
 *
 * ------------------------------------------------------------
 * APPROACH: Dynamic Programming (Tabulation)
 *
 * ------------------------------------------------------------
 * CORE IDEA:
 *
 * Let:
 *
 *      dp[i] = length of LIS ending at index i
 *
 * Each element by itself forms a subsequence,
 * so initialize:
 *
 *      dp[i] = 1
 *
 * ------------------------------------------------------------
 * TRANSITION:
 *
 * For each index i,
 * check all previous indices j < i.
 *
 * If:
 *
 *      nums[j] < nums[i]
 *
 * then we can extend the subsequence ending at j.
 *
 * So:
 *
 *      dp[i] = max(dp[i], dp[j] + 1)
 *
 * ------------------------------------------------------------
 * FINAL ANSWER:
 *
 * The LIS may end anywhere,
 * so return:
 *
 *      max(dp[i]) for all i
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * nums = [10,9,2,5,3,7,101,18]
 *
 * dp updates:
 *
 * i=0 → [1]
 * i=1 → [1,1]
 * i=2 → [1,1,1]
 * i=3 → [1,1,1,2]
 * i=4 → [1,1,1,2,2]
 * i=5 → [1,1,1,2,2,3]
 * i=6 → [1,1,1,2,2,3,4]
 * i=7 → [1,1,1,2,2,3,4,4]
 *
 * Result = 4
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 *      O(n²)
 *
 * Space Complexity:
 *      O(n)
 *
 * ------------------------------------------------------------
 * OPTIMIZED APPROACH (IMPORTANT):
 *
 * Using Binary Search + Greedy,
 * LIS can be solved in:
 *
 *      O(n log n)
 *
 * using the "Patience Sorting" technique.
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * This is one of the most important
 * Dynamic Programming problems.
 *
 * Frequently asked in interviews.
 */

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp(n, 1);

        for(int i = 0; i < n; i++){

            for(int j = 0; j < i; j++){

                if(nums[j] < nums[i]){

                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};

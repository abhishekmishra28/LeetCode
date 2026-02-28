/*
 * Problem: 53. Maximum Subarray
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given an integer array nums,
 * find the contiguous subarray (containing at least one number)
 * which has the largest sum and return its sum.
 *
 * ------------------------------------------------------------
 * APPROACH: Kadane’s Algorithm (Greedy + DP Insight)
 *
 * ------------------------------------------------------------
 * KEY OBSERVATIONS:
 *
 * 1️⃣ At each index i, we decide:
 *
 *    - Start a new subarray from nums[i]
 *    OR
 *    - Extend the previous subarray
 *
 * 2️⃣ Recurrence relation:
 *
 *    currSum =
 *        max(nums[i], currSum + nums[i])
 *
 * 3️⃣ Maintain global maximum:
 *
 *    maxSum = max(maxSum, currSum)
 *
 * ------------------------------------------------------------
 * WHY THIS WORKS:
 *
 * If previous sum becomes negative,
 * extending it will only reduce future sums.
 *
 * So we restart from current element.
 *
 * ------------------------------------------------------------
 * ALGORITHM STEPS:
 *
 * 1️⃣ Initialize:
 *       currSum = nums[0]
 *       maxSum  = nums[0]
 *
 * 2️⃣ For i = 1 → n-1:
 *       currSum = max(nums[i], currSum + nums[i])
 *       maxSum  = max(maxSum, currSum)
 *
 * 3️⃣ Return maxSum
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * nums = [-2,1,-3,4,-1,2,1,-5,4]
 *
 * Step-by-step:
 *
 * -2
 * 1
 * -2
 * 4
 * 3
 * 5
 * 6
 * 1
 * 5
 *
 * Maximum = 6
 * Subarray = [4,-1,2,1]
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
 * - Classic DP optimization problem.
 * - Can also track start/end indices.
 * - Frequently asked in interviews.
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n = nums.size();

        long long maxSum = nums[0];
        long long currSum = nums[0];

        for (int i = 1; i < n; i++) {

            // Either start new subarray
            // or extend previous
            currSum = max((long long)nums[i],
                          currSum + nums[i]);

            maxSum = max(maxSum, currSum);
        }

        return (int)maxSum;
    }
};

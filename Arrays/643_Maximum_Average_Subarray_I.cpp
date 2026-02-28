/*
 * Problem: 643. Maximum Average Subarray I
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given an integer array nums and an integer k,
 * find the contiguous subarray of length k
 * that has the maximum average value.
 *
 * Return the maximum average.
 *
 * ------------------------------------------------------------
 * CORE IDEA:
 *
 * Since the subarray size is FIXED (k),
 * this is a classic Fixed-Size Sliding Window problem.
 *
 * Instead of recalculating the sum of every subarray
 * in O(n * k), we maintain a running window sum
 * in O(n) time.
 *
 * ------------------------------------------------------------
 * WHY SLIDING WINDOW?
 *
 * Suppose current window is:
 *     [i - k + 1 ... i]
 *
 * When we move window one step right:
 *
 *   New sum =
 *       Old sum
 *       + nums[i]
 *       - nums[i - k]
 *
 * This avoids recomputing the entire sum.
 *
 * ------------------------------------------------------------
 * ALGORITHM STEPS:
 *
 * 1️⃣ Compute sum of first k elements.
 *    → This is the first window.
 *
 * 2️⃣ Store it as initial maximum.
 *
 * 3️⃣ Slide window from index k to n - 1:
 *
 *       currSum += nums[i]
 *       currSum -= nums[i - k]
 *
 *       Update maximum sum if needed.
 *
 * 4️⃣ Return maxSum / k.
 *
 * ------------------------------------------------------------
 * MATHEMATICAL INSIGHT:
 *
 * Since k is constant,
 * maximizing average is equivalent to
 * maximizing the sum.
 *
 * So we track maximum sum, not average directly.
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * nums = [1,12,-5,-6,50,3], k = 4
 *
 * First window:
 *   [1,12,-5,-6] → sum = 2
 *
 * Next window:
 *   [12,-5,-6,50] → sum = 51
 *
 * Next window:
 *   [-5,-6,50,3] → sum = 42
 *
 * Maximum sum = 51
 *
 * Maximum average = 51 / 4 = 12.75
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 * - O(n)
 *   (Single pass after first k elements)
 *
 * Space Complexity:
 * - O(1)
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - This is a fundamental sliding window pattern.
 * - Important difference:
 *     Fixed window → use running sum
 *     Variable window → use two pointers with conditions
 * - Be careful to use double to avoid precision loss.
 */

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int n = nums.size();

        // Step 1: Compute first window sum
        double currSum = 0;
        for (int i = 0; i < k; i++) {
            currSum += nums[i];
        }

        double result = currSum;

        // Step 2: Slide the window
        for (int i = k; i < n; i++) {

            currSum += nums[i];      // Add new element
            currSum -= nums[i - k];  // Remove old element

            result = max(result, currSum);
        }

        // Step 3: Return maximum average
        return result / k;
    }
};

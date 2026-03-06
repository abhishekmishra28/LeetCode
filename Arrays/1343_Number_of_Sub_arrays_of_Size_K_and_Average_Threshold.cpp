/*
 * Problem: 1343. Number of Sub-arrays of Size K and Average ≥ Threshold
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given an integer array nums, an integer k, and an integer threshold,
 * return the number of subarrays of size k whose average is
 * greater than or equal to threshold.
 *
 * ------------------------------------------------------------
 * MATHEMATICAL OBSERVATION:
 *
 * Instead of checking:
 *
 *      (sum / k) ≥ threshold
 *
 * We can multiply both sides by k:
 *
 *      sum ≥ threshold * k
 *
 * This avoids repeated division and floating-point operations.
 *
 * ------------------------------------------------------------
 * APPROACH: Fixed Size Sliding Window
 *
 * ------------------------------------------------------------
 * CORE IDEA:
 *
 * Since the subarray size is fixed (k),
 * we maintain a sliding window of size k
 * and track the sum of the window.
 *
 * For each window:
 *
 *      If windowSum / k ≥ threshold
 *      → valid subarray
 *
 * ------------------------------------------------------------
 * WINDOW MOVEMENT:
 *
 * Initial window:
 *      nums[0 ... k-1]
 *
 * When sliding forward:
 *
 *      currSum += nums[i]
 *      currSum -= nums[i-k]
 *
 * This efficiently updates the window sum
 * in constant time.
 *
 * ------------------------------------------------------------
 * ALGORITHM STEPS:
 *
 * 1️⃣ Compute sum of the first k elements.
 *
 * 2️⃣ Check if its average ≥ threshold.
 *
 * 3️⃣ Slide window from index k → n-1:
 *
 *      add nums[i]
 *      remove nums[i-k]
 *
 *      check condition again.
 *
 * 4️⃣ Count valid windows.
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * nums = [2,2,2,2,5,5,5,8]
 * k = 3
 * threshold = 4
 *
 * Window sums:
 *
 * [2,2,2] → 6  → avg = 2 → ❌
 * [2,2,2] → 6  → ❌
 * [2,2,5] → 9  → ❌
 * [2,5,5] → 12 → avg=4 → ✅
 * [5,5,5] → 15 → avg=5 → ✅
 * [5,5,8] → 18 → avg=6 → ✅
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
 *      O(1)
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - Classic fixed window sliding pattern.
 * - Often optimized using the condition:
 *
 *      sum ≥ threshold * k
 *
 *   instead of division.
 */

class Solution {
public:
    int numOfSubarrays(vector<int>& nums, int k, int threshold) {

        int n = nums.size();
        int cnt = 0;
        int currSum = 0;

        // First window
        for(int i = 0; i < k; i++){
            currSum += nums[i];
        }

        if(currSum / k >= threshold)
            cnt++;

        // Slide the window
        for(int i = k; i < n; i++){

            currSum += nums[i];
            currSum -= nums[i - k];

            if(currSum / k >= threshold)
                cnt++;
        }

        return cnt;
    }
};

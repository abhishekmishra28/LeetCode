/*
 * Problem: 1423. Maximum Points You Can Obtain from Cards
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * There are several cards arranged in a row.
 * Each card has an associated number of points.
 *
 * You can pick exactly k cards.
 *
 * Each time you can take a card either:
 *      • from the beginning
 *      • or from the end
 *
 * Return the maximum score you can obtain.
 *
 * ------------------------------------------------------------
 * KEY OBSERVATION:
 *
 * Instead of thinking about the k cards we TAKE,
 * think about the cards we DO NOT TAKE.
 *
 * If we take k cards from the ends,
 * the remaining cards in the middle form
 * a contiguous subarray of length:
 *
 *      n - k
 *
 * So the problem becomes:
 *
 *      Max score = Total Sum - Minimum Sum Subarray of size (n-k)
 *
 * ------------------------------------------------------------
 * WHY THIS WORKS:
 *
 * Taking k cards from ends is equivalent to
 * removing a continuous middle segment of size (n-k).
 *
 * If we remove the smallest possible middle segment,
 * the remaining score will be maximized.
 *
 * ------------------------------------------------------------
 * APPROACH: Sliding Window
 *
 * Steps:
 *
 * 1️⃣ Compute total sum of all cards.
 *
 * 2️⃣ Find the minimum sum subarray of length (n-k)
 *    using sliding window.
 *
 * 3️⃣ Subtract that minimum sum from the total.
 *
 *      result = totalSum - minWindowSum
 *
 * ------------------------------------------------------------
 * EDGE CASE:
 *
 * If k == n:
 *      we take all cards.
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * nums = [1,2,3,4,5,6,1]
 * k = 3
 *
 * n = 7
 * windowSize = n-k = 4
 *
 * totalSum = 22
 *
 * Windows of size 4:
 *
 * [1,2,3,4] → 10
 * [2,3,4,5] → 14
 * [3,4,5,6] → 18
 * [4,5,6,1] → 16
 *
 * Minimum = 10
 *
 * Result:
 *
 * 22 - 10 = 12
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
 * This is a classic trick problem:
 *
 *      "Pick from ends" → convert to
 *      "Remove minimum middle window"
 */

class Solution {
public:
    int maxScore(vector<int>& nums, int k) {

        int n = nums.size();

        int windowSize = n - k;

        // If we take all cards
        if(windowSize == 0)
            return accumulate(nums.begin(), nums.end(), 0);

        int total = accumulate(nums.begin(), nums.end(), 0);

        // Initial window
        int windowSum = 0;
        for(int i = 0; i < windowSize; i++){
            windowSum += nums[i];
        }

        int minWindow = windowSum;

        // Slide window
        for(int i = windowSize; i < n; i++){

            windowSum += nums[i];
            windowSum -= nums[i - windowSize];

            minWindow = min(minWindow, windowSum);
        }

        return total - minWindow;
    }
};

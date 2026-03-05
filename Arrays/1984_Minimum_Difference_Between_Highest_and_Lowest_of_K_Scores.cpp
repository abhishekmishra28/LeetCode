/*
 * Problem: 1984. Minimum Difference Between Highest and Lowest of K Scores
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * You are given an integer array nums representing scores
 * of students and an integer k.
 *
 * You must select k scores such that the difference between
 * the highest and lowest scores among them is minimized.
 *
 * Return the minimum possible difference.
 *
 * ------------------------------------------------------------
 * CORE IDEA:
 *
 * We want to choose k elements where:
 *
 *      max(selected) - min(selected)
 *
 * is as small as possible.
 *
 * ------------------------------------------------------------
 * KEY OBSERVATION:
 *
 * If the array is sorted,
 * the minimum difference among any group of k elements
 * will always occur among k consecutive elements.
 *
 * Why?
 *
 * Because any non-consecutive selection would only
 * increase the range.
 *
 * ------------------------------------------------------------
 * APPROACH: Sorting + Sliding Window
 *
 * Steps:
 *
 * 1️⃣ Sort the array.
 *
 * 2️⃣ Use a sliding window of size k.
 *
 * 3️⃣ For each window:
 *
 *      difference = nums[i + k - 1] - nums[i]
 *
 * 4️⃣ Track the minimum difference.
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * nums = [9,4,1,7]
 * k = 2
 *
 * Step 1: Sort
 * [1,4,7,9]
 *
 * Windows:
 *
 * [1,4] → diff = 3
 * [4,7] → diff = 3
 * [7,9] → diff = 2
 *
 * Minimum difference = 2
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 *   O(n log n)   (sorting)
 *
 * Space Complexity:
 *   O(1)
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - Sorting + sliding window pattern.
 * - Key insight: consecutive elements minimize range.
 */

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {

        int n = nums.size();

        // Sort the array
        sort(nums.begin(), nums.end());

        // Initial window difference
        int ans = nums[k - 1] - nums[0];

        // Sliding window of size k
        for (int i = 0; i + k <= n; i++) {

            ans = min(ans, nums[i + k - 1] - nums[i]);
        }

        return ans;
    }
};

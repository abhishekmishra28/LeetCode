/*
 * Problem: 1685. Sum of Absolute Differences in a Sorted Array
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given a sorted integer array nums,
 * return an array answer such that:
 *
 * answer[i] =
 *   Σ |nums[i] - nums[j]| for all j != i
 *
 * ------------------------------------------------------------
 * IMPORTANT CONDITION:
 *
 * nums is already SORTED.
 * This is the key to solving in O(n).
 *
 * ------------------------------------------------------------
 * BRUTE FORCE (NOT OPTIMAL):
 *
 * For each i:
 *   Compute absolute difference with all j
 *
 * Time = O(n²)
 *
 * ------------------------------------------------------------
 * OPTIMAL APPROACH: Prefix Sum Trick
 *
 * ------------------------------------------------------------
 * KEY OBSERVATIONS:
 *
 * Since nums is sorted:
 *
 * For index i:
 *
 * All elements on LEFT (0 → i-1)
 *     are ≤ nums[i]
 *
 * All elements on RIGHT (i+1 → n-1)
 *     are ≥ nums[i]
 *
 * So we can remove absolute value:
 *
 * Left Contribution:
 *   Σ (nums[i] - nums[j])
 *   = nums[i] * i - sumLeft
 *
 * Right Contribution:
 *   Σ (nums[j] - nums[i])
 *   = sumRight - nums[i] * (n - i - 1)
 *
 * ------------------------------------------------------------
 * FINAL FORMULA:
 *
 * ans[i] =
 *   nums[i] * i - left
 *   +
 *   right - nums[i] * (n - i - 1)
 *
 * ------------------------------------------------------------
 * VARIABLES:
 *
 * left  → sum of elements before index i
 * right → sum of elements after index i
 *
 * Initially:
 *   left = 0
 *   right = total sum of array
 *
 * ------------------------------------------------------------
 * ALGORITHM STEPS:
 *
 * 1️⃣ Compute total sum → right
 *
 * 2️⃣ For each index i:
 *       right -= nums[i]
 *
 *       ans[i] =
 *         nums[i] * i - left
 *         +
 *         right - nums[i] * (n - i - 1)
 *
 *       left += nums[i]
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * nums = [1,4,6,8,10]
 *
 * For i = 2 (value = 6):
 *
 * Left  = 1 + 4 = 5
 * Right = 8 + 10 = 18
 *
 * Left part:
 *   6*2 - 5 = 12 - 5 = 7
 *
 * Right part:
 *   18 - 6*2 = 18 - 12 = 6
 *
 * Total = 13
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 * - O(n)
 *
 * Space Complexity:
 * - O(1) extra (excluding output array)
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - Only works because array is sorted.
 * - Classic prefix-sum optimization trick.
 * - Very important pattern in range sum problems.
 */

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {

        int n = nums.size();

        // Sum of elements to the left
        int left = 0;

        // Sum of all elements initially
        int right = accumulate(nums.begin(),
                               nums.end(),
                               0);

        vector<int> ans(n);

        for (int i = 0; i < n; i++) {

            // Remove current element from right sum
            right -= nums[i];

            ans[i] =
                nums[i] * i - left
                +
                right - nums[i] * (n - i - 1);

            // Add current element to left sum
            left += nums[i];
        }

        return ans;
    }
};

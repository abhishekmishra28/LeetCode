/*
 * Problem: 2974. Minimum Cost to Make Array Equal (Minimum Cost)
 *
 * Statement:
 * You are given an integer array `nums`.
 *
 * You need to pick exactly THREE elements:
 *   - nums[0] (mandatory)
 *   - any TWO elements from indices [1 … n-1]
 *
 * Return the MINIMUM possible sum of these three chosen elements.
 *
 * ------------------------------------------------------------
 * APPROACH: Greedy – Track Two Minimums (Your Approach)
 *
 * Core Idea:
 *
 * - nums[0] is compulsory → it must be included
 * - From the remaining elements (index 1 to n-1),
 *   we must choose the TWO SMALLEST values
 *
 * - To do this efficiently:
 *     • Track the smallest and second smallest values
 *       while traversing the array once
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. Initialize:
 *
 *      min1 = 100   // smallest value found so far
 *      min2 = 100   // second smallest value found so far
 *
 *   (100 works because constraints ensure values ≤ 100)
 *
 * 2. Traverse the array from index 1 to end:
 *
 *      For each nums[i]:
 *
 *      a) If nums[i] < min1:
 *           min2 = min1
 *           min1 = nums[i]
 *
 *      b) Else if nums[i] < min2:
 *           min2 = nums[i]
 *
 * 3. Final answer:
 *
 *      nums[0] + min1 + min2
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - nums[0] is fixed and unavoidable
 * - Choosing the two smallest remaining values
 *   guarantees the minimum total sum
 *
 * - Greedy is optimal because:
 *     Any larger value would only increase the cost
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * nums = [5, 3, 2, 8]
 *
 * nums[0] = 5
 *
 * Traverse from index 1:
 *   min1 = 2
 *   min2 = 3
 *
 * Answer = 5 + 2 + 3 = 10
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Array size is always ≥ 3 (guaranteed)
 * - Duplicate minimum values are handled correctly
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - O(n)
 *   Single traversal of the array
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(1)
 *   Only constant extra variables used
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Pick K minimum elements using greedy scan"
 *
 * Seen in:
 * - Minimum sum problems
 * - Greedy selection tasks
 * - Optimization under fixed constraints
 */

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int min1 = 100;
        int min2 = 100;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < min1) {
                min2 = min1;
                min1 = nums[i];
            }
            else if (nums[i] < min2) {
                min2 = nums[i];
            }
        }
        return nums[0] + min1 + min2;
    }
};

/*
 * Problem: 1827. Minimum Operations to Make the Array Increasing
 *
 * Statement:
 * You are given an integer array `nums`.
 *
 * In one operation, you can increment any element of the array by 1.
 *
 * Return the MINIMUM number of operations required to make the array
 * STRICTLY INCREASING.
 *
 * A strictly increasing array satisfies:
 *     nums[i] < nums[i+1] for all valid i
 *
 * ------------------------------------------------------------
 * APPROACH: Greedy (Left-to-Right Fixing) — Your Approach
 *
 * Core Idea:
 *
 * - Traverse the array from LEFT to RIGHT
 * - At each position, ensure:
 *       nums[i+1] > nums[i]
 *
 * - If this condition is violated:
 *     • We must INCREASE nums[i+1]
 *     • The MINIMUM required increase is:
 *
 *           nums[i] - nums[i+1] + 1
 *
 * - Apply this increase and count the operations
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. Initialize:
 *      cnt = 0   // total number of operations
 *
 * 2. Traverse the array from index 0 to n-2:
 *
 *      For each i:
 *
 *      a) If nums[i] < nums[i+1]:
 *           → Already strictly increasing
 *           → Do nothing
 *
 *      b) Else (nums[i] >= nums[i+1]):
 *
 *           toAdd = nums[i] - nums[i+1] + 1
 *
 *           cnt += toAdd
 *
 *           nums[i+1] += toAdd
 *
 *           // Now nums[i+1] > nums[i]
 *
 * 3. Return cnt
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Greedy is optimal because:
 *     • Earlier elements cannot be reduced
 *     • Increasing nums[i+1] is the ONLY way to fix the order
 *
 * - Making nums[i+1] just ONE greater than nums[i]
 *   is the minimum required change
 *
 * - Fixing from left to right guarantees future comparisons
 *   are based on corrected values
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * nums = [1, 1, 1]
 *
 * i = 0:
 *   nums[0] >= nums[1]
 *   toAdd = 1 - 1 + 1 = 1
 *   nums → [1, 2, 1]
 *   cnt = 1
 *
 * i = 1:
 *   nums[1] >= nums[2]
 *   toAdd = 2 - 1 + 1 = 2
 *   nums → [1, 2, 3]
 *   cnt = 3
 *
 * Answer = 3
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Already strictly increasing → answer = 0
 * - Single element array → answer = 0
 * - Negative numbers handled naturally
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - O(n)
 *   Single pass through the array
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(1)
 *   In-place modification, constant extra space
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Greedy Adjustment / Array Fixing" problem
 *
 * Seen in:
 * - Making arrays monotonic
 * - Minimum operations problems
 * - Greedy validation tasks
 */

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] >= nums[i + 1]) {
                int toAdd = nums[i] - nums[i + 1] + 1;
                cnt += toAdd;
                nums[i + 1] += toAdd;
            }
        }
        return cnt;
    }
};

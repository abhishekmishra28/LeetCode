/*
 * Problem: 414. Third Maximum Number
 *
 * Statement:
 * Given an integer array `nums`, return the THIRD DISTINCT maximum number.
 * If the third distinct maximum does not exist, return the maximum number.
 *
 * ------------------------------------------------------------
 * APPROACH: Sorting + Distinct Count — Your Approach
 *
 * Core Idea:
 *
 * - Sort the array in descending order
 * - Traverse the sorted array
 * - Count DISTINCT values only
 * - As soon as the 3rd distinct value is found → return it
 * - If fewer than 3 distinct values exist → return the largest value
 *
 * ------------------------------------------------------------
 * Step-by-Step Explanation:
 *
 * 1. Sort the array in decreasing order
 *
 *      nums = [max, ..., min]
 *
 * 2. Initialize:
 *
 *      distCnt = 1   // first element is always the maximum (1st distinct)
 *
 * 3. Traverse from index 1 to end:
 *
 *      If nums[i] != nums[i-1]:
 *          → Found a new distinct number
 *          → Increment distCnt
 *
 *      If distCnt == 3:
 *          → nums[i] is the third distinct maximum
 *          → return nums[i]
 *
 * 4. If loop ends and third distinct is not found:
 *
 *      → Return nums[0] (the maximum element)
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Sorting brings numbers into decreasing order
 * - Comparing adjacent elements helps skip duplicates
 * - Distinct counter ensures we count UNIQUE values only
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * Input:
 *   nums = [2, 2, 3, 1]
 *
 * After sorting:
 *   nums = [3, 2, 2, 1]
 *
 * distCnt = 1  (3)
 *
 * i = 1:
 *   nums[1] = 2 ≠ 3 → distCnt = 2
 *
 * i = 2:
 *   nums[2] = 2 == 2 → skip
 *
 * i = 3:
 *   nums[3] = 1 ≠ 2 → distCnt = 3
 *   → return 1
 *
 * Output = 1
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - nums = [1, 2] → only 2 distinct → return max = 2
 * - nums = [3, 3, 3] → only 1 distinct → return 3
 * - nums = [1, 2, 3] → return 1
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - O(n log n) due to sorting
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(1) extra space (in-place sort)
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a:
 *   "Sorting + Distinct Element Tracking" problem
 *
 * Can be optimized further using:
 * - Set
 * - Three variables (one-pass, no sort)
 */

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());

        int distCnt = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                distCnt++;
                if (distCnt == 3) {
                    return nums[i];
                }
            }
        }

        // If third distinct does not exist
        return nums[0];
    }
};

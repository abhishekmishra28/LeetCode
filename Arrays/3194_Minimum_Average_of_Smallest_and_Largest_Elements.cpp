/*
 * Problem: 3194. Minimum Average of Smallest and Largest Elements
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * You are given an integer array nums.
 *
 * Repeat the following process until the array becomes empty:
 *
 *      • Take the smallest element
 *      • Take the largest element
 *      • Compute their average
 *      • Remove both elements
 *
 * Return the minimum average obtained across all steps.
 *
 * ------------------------------------------------------------
 * EXAMPLE:
 *
 * nums = [7,8,3,4,15,13,4,1]
 *
 * Sorted:
 * [1,3,4,4,7,8,13,15]
 *
 * Pairs:
 *
 * (1,15) → avg = 8
 * (3,13) → avg = 8
 * (4,8)  → avg = 6
 * (4,7)  → avg = 5.5
 *
 * Answer = 5.5
 *
 * ------------------------------------------------------------
 * CORE IDEA:
 *
 * Instead of repeatedly finding min and max
 * (which is expensive),
 * we sort the array once.
 *
 * Then use two pointers:
 *
 *      left  → smallest element
 *      right → largest element
 *
 * ------------------------------------------------------------
 * APPROACH: Sorting + Two Pointers
 *
 * ------------------------------------------------------------
 * ALGORITHM STEPS:
 *
 * 1️⃣ Sort the array.
 *
 * 2️⃣ Initialize:
 *
 *      left = 0
 *      right = n - 1
 *
 * 3️⃣ While left < right:
 *
 *      avg = (nums[left] + nums[right]) / 2.0
 *      update minimum
 *
 *      left++
 *      right--
 *
 * ------------------------------------------------------------
 * WHY THIS IS BETTER:
 *
 * Your approach:
 *      O(n²) due to repeated min/max + erase
 *
 * Optimized approach:
 *      O(n log n) due to sorting
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 *      O(n log n)
 *
 * Space Complexity:
 *      O(1)
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * Key improvement:
 *
 *      Replace repeated min/max operations
 *      with sorting + two pointers.
 */

class Solution {
public:
    double minimumAverage(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        int left = 0;
        int right = n - 1;

        double mini = DBL_MAX;

        while(left < right){

            double avg =
                (nums[left] + nums[right]) / 2.0;

            mini = min(mini, avg);

            left++;
            right--;
        }

        return mini;
    }
};

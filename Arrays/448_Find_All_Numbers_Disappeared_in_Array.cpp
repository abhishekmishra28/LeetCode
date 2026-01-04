/*
 * Problem: 448. Find All Numbers Disappeared in an Array
 *
 * Statement:
 * You are given an array `nums` of length n where:
 * - 1 ≤ nums[i] ≤ n
 * - Each number may appear once or twice
 *
 * Your task is to return all the numbers in the range [1, n]
 * that do NOT appear in the array.
 *
 * ------------------------------------------------------------
 * Key Observations:
 *
 * - The array size is n
 * - Valid values are strictly in range [1, n]
 * - Some numbers are missing, some may be duplicated
 *
 * ------------------------------------------------------------
 * APPROACH 1 (Commented in Code): Hash Map
 *
 * Idea:
 * - Count frequency of each number using a map
 * - Any number from 1 to n with frequency 0 is missing
 *
 * Drawbacks:
 * - Uses extra space O(n)
 * - Not optimal as per problem constraints
 *
 * ------------------------------------------------------------
 * APPROACH 2 (Used in Code): In-Place Marking (Optimal)
 *
 * Core Insight:
 *
 * Since:
 * - Values are in range [1, n]
 * - Indices are also [0, n-1]
 *
 * We can use the ARRAY ITSELF as a frequency marker.
 *
 * ------------------------------------------------------------
 * How In-Place Marking Works:
 *
 * For a number x in nums:
 * - It corresponds to index (x - 1)
 * - Mark nums[x - 1] as NEGATIVE to indicate presence of x
 *
 * Important:
 * - Use abs(nums[i]) because values may already be negative
 * - Never change the index mapping logic
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm:
 *
 * STEP 1: Mark Presence
 * - Iterate through nums
 * - For each nums[i]:
 *     idx = abs(nums[i]) - 1
 *     If nums[idx] is positive:
 *         make it negative
 *
 * STEP 2: Find Missing Numbers
 * - Iterate again through nums
 * - If nums[i] is STILL positive:
 *     → number (i + 1) was never marked
 *     → it is missing
 *
 * ------------------------------------------------------------
 * Example:
 *
 * Input:
 * nums = [4,3,2,7,8,2,3,1]
 *
 * After marking:
 * nums = [-4,-3,-2,-7,8,2,-3,-1]
 *
 * Positive indices:
 * index 4 → value 5 missing
 * index 5 → value 6 missing
 *
 * Output:
 * [5,6]
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - All numbers present → empty result
 * - All numbers same → many missing
 * - Single element array
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n)
 *   Two linear passes
 *
 * Space Complexity:
 * - O(1)
 *   No extra space (excluding output array)
 *
 * ------------------------------------------------------------
 * Why This Is Optimal:
 *
 * - Avoids extra data structures
 * - Leverages problem constraints intelligently
 * - Very common interview pattern
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Mark visited numbers using index mapping
        for (int i = 0; i < n; i++) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] > 0)
                nums[idx] = -nums[idx];
        }

        // Step 2: Collect missing numbers
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0)
                ans.push_back(i + 1);
        }

        return ans;
    }
};

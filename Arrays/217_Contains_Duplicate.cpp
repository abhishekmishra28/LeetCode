/*
 * Problem: 217. Contains Duplicate
 *
 * Statement:
 * You are given an integer array `nums`.
 * Your task is to determine whether the array contains
 * ANY duplicate element.
 *
 * Return:
 * - true  → if any value appears at least twice
 * - false → if all elements are distinct
 *
 * ------------------------------------------------------------
 * Key Observations:
 *
 * - We only care about FREQUENCY of elements
 * - The moment any element appears more than once,
 *   we can return true
 *
 * ------------------------------------------------------------
 * Approach: Frequency Counting using Map (Your Approach)
 *
 * Core Idea:
 * - Use a map to count how many times each number appears
 * - After counting, check if any number has frequency > 1
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Approach):
 *
 * 1. Initialize an empty map `mpp`
 *    - Key   → number
 *    - Value → frequency
 *
 * 2. Traverse the array:
 *    - For each element nums[i]:
 *        mpp[nums[i]]++
 *
 * 3. Traverse the map:
 *    - If any entry has frequency > 1:
 *        → duplicate exists
 *        → return true
 *
 * 4. If no duplicates found:
 *    - return false
 *
 * ------------------------------------------------------------
 * Example 1:
 *
 * Input:
 * nums = [1,2,3,1]
 *
 * Map contents:
 * 1 → 2
 * 2 → 1
 * 3 → 1
 *
 * Since 1 appears more than once → return true
 *
 * ------------------------------------------------------------
 * Example 2:
 *
 * Input:
 * nums = [1,2,3,4]
 *
 * Map contents:
 * All elements have frequency = 1
 *
 * Output:
 * false
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Empty array → no duplicates
 * - Array with one element → no duplicates
 * - All elements same
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n log n)
 *   Insertion into `map` takes O(log n) for each element
 *
 * Space Complexity:
 * - O(n)
 *   Extra space for storing frequencies
 *
 * ------------------------------------------------------------
 * Note:
 *
 * - This solution is clear and easy to understand
 * - Can be optimized to O(n) using:
 *     • unordered_map
 *     • unordered_set
 * - But this approach is perfectly valid and correct
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mpp;

        // Step 1: Count frequency
        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }

        // Step 2: Check for duplicates
        for (auto mp : mpp) {
            if (mp.second > 1) {
                return true;
            }
        }

        return false;
    }
};

/*
 * Problem: 169. Majority Element
 *
 * Statement:
 * You are given an integer array `nums` of size n.
 *
 * The MAJORITY element is the element that appears
 * MORE THAN ⌊n / 2⌋ times.
 *
 * It is guaranteed that a majority element ALWAYS exists.
 *
 * Your task is to return the majority element.
 *
 * ------------------------------------------------------------
 * APPROACH 1: Moore’s Voting Algorithm (Optimal)
 *
 * Core Insight:
 *
 * - Since a majority element appears more than n/2 times,
 *   it will ALWAYS survive pairwise cancellation.
 *
 * - Every time we see:
 *     • same element → increment count
 *     • different element → decrement count
 *
 * - When count becomes 0, we RESET the candidate.
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Approach 1):
 *
 * 1. Initialize:
 *    - cnt = 0   → counter
 *    - ele       → current candidate
 *
 * 2. Traverse the array:
 *
 *    a) If cnt == 0:
 *         - set ele = current number
 *
 *    b) If current number == ele:
 *         - cnt++
 *       else:
 *         - cnt--
 *
 * 3. After traversal, `ele` is guaranteed to be the majority element.
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Majority element frequency > sum of all others
 * - Cancellation cannot eliminate it completely
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n)
 *
 * Space Complexity:
 * - O(1)
 *
 * ------------------------------------------------------------
 * APPROACH 2: Frequency Map (Brute Force)
 *
 * Core Idea:
 *
 * - Count frequency of every element
 * - Return the element with frequency > n/2
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n log n)   (using map)
 *
 * Space Complexity:
 * - O(n)
 *
 * ------------------------------------------------------------
 * Comparison:
 *
 * | Approach | Time | Space | Interview Preferred |
 * |--------|------|-------|---------------------|
 * | Moore’s Voting | O(n) | O(1) | ✅ Yes |
 * | Map Counting | O(n log n) | O(n) | ❌ Backup |
 *
 * ------------------------------------------------------------
 * Example:
 *
 * Input:
 * nums = [2,2,1,1,1,2,2]
 *
 * Moore’s Algorithm:
 * - Candidate evolves → 2
 *
 * Output:
 * 2
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Array of size 1
 * - All elements same
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        // -----------------------------
        // Approach 1: Moore's Voting
        // -----------------------------
        int cnt = 0, ele = nums[0];

        for (int num : nums) {
            if (cnt == 0) {
                ele = num;
            }
            if (num == ele) {
                cnt++;
            } else {
                cnt--;
            }
        }
        return ele;

        // -----------------------------
        // Approach 2: Frequency Map
        // (Backup / Brute Force)
        // -----------------------------
        /*
        map<int,int> freq;
        for (int num : nums)
            freq[num]++;

        for (auto fr : freq) {
            if (fr.second > n / 2)
                return fr.first;
        }
        return -1;
        */
    }
};

/*
 * Problem: 1636. Sort Array by Increasing Frequency
 *
 * Statement:
 * You are given an integer array `nums`.
 *
 * Sort the array in INCREASING order based on the frequency of values.
 *
 * If multiple values have the SAME frequency:
 *   - Sort them in DECREASING order of value.
 *
 * Return the sorted array.
 *
 * ------------------------------------------------------------
 * APPROACH: Frequency Map + Custom Sorting (Your Approach)
 *
 * Core Idea:
 *
 * - First count how many times each number appears
 * - Then sort the array using a CUSTOM comparator:
 *     1) Lower frequency comes first
 *     2) If frequency is same → larger value comes first
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. Create an unordered_map `freq`
 *      freq[x] = number of occurrences of x in nums
 *
 * 2. Traverse `nums` and fill the frequency map
 *
 * 3. Sort the array using a custom comparator:
 *
 *      - If freq[a] != freq[b]:
 *            return freq[a] < freq[b]
 *
 *      - Else (same frequency):
 *            return a > b
 *
 * 4. Return the sorted array
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Hash map gives O(1) average-time frequency lookup
 * - Custom comparator enforces BOTH sorting rules
 * - Sorting directly on `nums` avoids extra arrays
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * nums = [1,1,2,2,2,3]
 *
 * Frequencies:
 *   1 → 2
 *   2 → 3
 *   3 → 1
 *
 * Sorted by rules:
 *   Frequency ascending:
 *     3 (1 time)
 *     1 (2 times)
 *     2 (3 times)
 *
 * Result:
 *   [3,1,1,2,2,2]
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - All elements unique → sorted in descending order
 * - All elements same → unchanged
 * - Negative numbers handled correctly
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - Building frequency map: O(n)
 * - Sorting array: O(n log n)
 *
 * Overall:
 *   O(n log n)
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(n)
 *   Hash map for frequencies
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Sort by Frequency with Tie-Breaker"
 *
 * Seen in:
 * - Frequency-based sorting problems
 * - Custom comparator questions
 * - Map + sort patterns
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;

        // Step 1: Count frequencies
        for (int x : nums) {
            freq[x]++;
        }

        // Step 2: Sort with custom comparator
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (freq[a] != freq[b])
                return freq[a] < freq[b];   // increasing frequency
            return a > b;                   // decreasing value
        });

        return nums;
    }
};

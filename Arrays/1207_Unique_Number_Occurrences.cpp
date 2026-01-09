/*
 * Problem: 1207. Unique Number of Occurrences
 *
 * Statement:
 * You are given an integer array `arr`.
 * Your task is to determine whether the number of occurrences
 * of each value in the array is UNIQUE.
 *
 * In other words:
 * - No two different numbers should have the same frequency
 *
 * Return:
 * - true  → if all frequencies are unique
 * - false → otherwise
 *
 * ------------------------------------------------------------
 * Key Observations:
 *
 * - The actual values do not matter
 * - Only the FREQUENCIES of values matter
 *
 * ------------------------------------------------------------
 * Approach: Frequency Map + Set Check (Your Approach)
 *
 * Core Idea:
 * - Count frequency of each number using a map
 * - Store frequencies in a set
 * - If a frequency is seen more than once → return false
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Approach):
 *
 * 1. Initialize a map `freq`
 *    - Key   → array value
 *    - Value → frequency of that value
 *
 * 2. Traverse the array:
 *    - For each number `num`:
 *        freq[num]++
 *
 * 3. Initialize an empty unordered_set `seen`
 *    - Stores frequencies already encountered
 *
 * 4. Traverse the frequency map:
 *    - For each (value, frequency) pair:
 *        a) If frequency already exists in `seen`:
 *            → duplicate frequency found
 *            → return false
 *        b) Otherwise:
 *            → insert frequency into `seen`
 *
 * 5. If all frequencies are unique:
 *    - return true
 *
 * ------------------------------------------------------------
 * Example 1:
 *
 * Input:
 * arr = [1,2,2,1,1,3]
 *
 * Frequencies:
 * 1 → 3
 * 2 → 2
 * 3 → 1
 *
 * All frequencies {3,2,1} are unique
 * Output = true
 *
 * ------------------------------------------------------------
 * Example 2:
 *
 * Input:
 * arr = [1,2]
 *
 * Frequencies:
 * 1 → 1
 * 2 → 1
 *
 * Duplicate frequency (1)
 * Output = false
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Empty array → trivially true
 * - Array with one element → true
 * - All elements same → true
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n)
 *   Counting + set insertion
 *
 * Space Complexity:
 * - O(n)
 *   Map + set
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Each frequency must be distinct
 * - Set ensures O(1) average-time uniqueness check
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Frequency Map + Uniqueness Check" problem
 *
 * Seen in:
 * - Anagram variations
 * - Histogram-based constraints
 * - Data validation problems
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> freq;

        // Step 1: Count frequency of each number
        for (int num : arr) {
            freq[num]++;
        }

        unordered_set<int> seen;

        // Step 2: Check uniqueness of frequencies
        for (auto fr : freq) {
            if (seen.find(fr.second) != seen.end())
                return false;

            seen.insert(fr.second);
        }

        return true;
    }
};

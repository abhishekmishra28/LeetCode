/*
 * Problem: 2404. Most Frequent Even Element
 *
 * Statement:
 * You are given an integer array `nums`.
 *
 * Your task is to find the EVEN element that appears MOST FREQUENTLY
 * in the array.
 *
 * Tie-breaking rule:
 * - If multiple even elements have the same highest frequency,
 *   return the SMALLEST even element.
 *
 * If there is NO even element, return -1.
 *
 * ------------------------------------------------------------
 * Key Observations:
 *
 * - Only EVEN numbers are relevant
 * - Frequency comparison decides the answer
 * - In case of a tie, the SMALLER value wins
 *
 * ------------------------------------------------------------
 * Approach: Frequency Counting with Ordered Map (Your Approach)
 *
 * Core Idea:
 * - Count frequencies of ONLY even numbers
 * - Track:
 *     • highest frequency seen so far
 *     • corresponding element (with tie-breaking)
 *
 * Using `map` helps because:
 * - Keys are sorted
 * - Tie-breaking by smallest value becomes straightforward
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Approach):
 *
 * 1. Initialize a map `freq`
 *    - Key   → even number
 *    - Value → frequency
 *
 * 2. Traverse the array:
 *    - If `num` is even:
 *        freq[num]++
 *
 * 3. If `freq` is empty:
 *    - No even numbers exist
 *    - Return -1
 *
 * 4. Initialize:
 *    - maxi = -∞  → maximum frequency found so far
 *    - ele = -1   → result element
 *
 * 5. Traverse the frequency map:
 *    - If:
 *        • current frequency > maxi
 *        OR
 *        • current frequency == maxi AND current element < ele
 *
 *      → Update:
 *           maxi = frequency
 *           ele = element
 *
 * 6. Return `ele`
 *
 * ------------------------------------------------------------
 * Example 1:
 *
 * Input:
 * nums = [0,1,2,2,4,4,1]
 *
 * Even frequencies:
 * 0 → 1
 * 2 → 2
 * 4 → 2
 *
 * Max frequency = 2
 * Tie between 2 and 4 → choose smaller = 2
 *
 * Output = 2
 *
 * ------------------------------------------------------------
 * Example 2:
 *
 * nums = [1,3,5]
 *
 * No even elements
 * Output = -1
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Array with only odd numbers
 * - Single even element
 * - Multiple evens with same frequency
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n log n)
 *   Map insertion takes log n time
 *
 * Space Complexity:
 * - O(n)
 *   Map stores frequencies of even numbers
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Frequency map guarantees correct counting
 * - Ordered traversal ensures correct tie-breaking
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Frequency Map + Conditional Tie-Breaking" problem
 *
 * Appears in:
 * - Most frequent element variants
 * - Mode with constraints
 * - Statistics-based problems
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int n = nums.size();
        map<int,int> freq;

        // Step 1: Count frequency of even numbers
        for (int num : nums) {
            if (num % 2 == 0) {
                freq[num]++;
            }
        }

        // Step 2: Handle no even elements
        if (freq.empty()) return -1;

        int maxi = INT_MIN;
        int ele = -1;

        // Step 3: Find most frequent even element
        for (auto fr : freq) {
            if (fr.second > maxi ||
               (fr.second == maxi && fr.first < ele)) {
                maxi = fr.second;
                ele = fr.first;
            }
        }

        return ele;
    }
};

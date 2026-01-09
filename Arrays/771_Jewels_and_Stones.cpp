/*
 * Problem: 771. Jewels and Stones
 *
 * Statement:
 * You are given two strings:
 * - `jewels` : characters representing different types of jewels
 * - `stones` : characters representing stones you have
 *
 * Each character in `jewels` is UNIQUE.
 * Characters are case-sensitive.
 *
 * Your task is to count how many stones are also jewels.
 *
 * ------------------------------------------------------------
 * Key Observations:
 *
 * - We only need to COUNT how many characters from `stones`
 *   appear in the set of `jewels`
 * - Duplicates in `stones` matter (each stone counts)
 * - Order does NOT matter
 *
 * ------------------------------------------------------------
 * Approach: Frequency Counting using Map (Your Approach)
 *
 * Core Idea:
 * - Count the frequency of each stone character
 * - For every jewel character:
 *     • If it exists in the stone frequency map,
 *       add its frequency to the answer
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Approach):
 *
 * 1. Initialize a map `freq`
 *    - Key   → stone character
 *    - Value → number of times it appears in `stones`
 *
 * 2. Traverse the `stones` string:
 *    - For each character stones[i]:
 *        freq[stones[i]]++
 *
 * 3. Initialize `cnt = 0`
 *
 * 4. Traverse the `jewels` string:
 *    - For each jewel character ch:
 *        If ch exists in `freq`:
 *            cnt += freq[ch]
 *
 * 5. Return `cnt`
 *
 * ------------------------------------------------------------
 * Example 1:
 *
 * Input:
 * jewels = "aA"
 * stones = "aAAbbbb"
 *
 * Frequency Map:
 * a → 1
 * A → 2
 * b → 4
 *
 * Jewels:
 * 'a' → add 1
 * 'A' → add 2
 *
 * Output = 3
 *
 * ------------------------------------------------------------
 * Example 2:
 *
 * Input:
 * jewels = "z"
 * stones = "ZZ"
 *
 * No matching characters
 * Output = 0
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - No jewels
 * - No stones
 * - Case sensitivity ('a' ≠ 'A')
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n + m)
 *   n = length of stones
 *   m = length of jewels
 *
 * Space Complexity:
 * - O(n)
 *   Map storing stone frequencies
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Frequency map avoids repeated scanning
 * - Each jewel contributes exactly the number of stones matching it
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Membership + Frequency Counting" problem
 *
 * Seen in:
 * - Anagram problems
 * - Inventory counting
 * - Set membership checks
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int n = stones.size();
        map<char,int> freq;

        // Step 1: Count frequency of stones
        for (int i = 0; i < n; i++) {
            freq[stones[i]]++;
        }

        int cnt = 0;

        // Step 2: Count jewels
        for (char ch : jewels) {
            if (freq.find(ch) != freq.end()) {
                cnt += freq[ch];
            }
        }

        return cnt;
    }
};

/*
 * Problem: 3803. Count Residue Prefixes
 *
 * Statement:
 * You are given a string `s` consisting of lowercase English letters.
 *
 * A PREFIX of the string is considered a **residue prefix** if:
 *
 *   (number of DISTINCT characters in the prefix)
 *        ==
 *   (length of the prefix) % 3
 *
 * Your task is to count how many prefixes of `s`
 * satisfy this condition.
 *
 * ------------------------------------------------------------
 * Key Observations:
 *
 * - We process prefixes incrementally from left to right
 * - For each prefix, we need:
 *     • Its length
 *     • The number of distinct characters in it
 * - `% 3` means we only care about remainder (0, 1, or 2)
 *
 * ------------------------------------------------------------
 * Approach: Prefix Traversal + Frequency Tracking (Your Approach)
 *
 * Core Idea:
 * - Maintain a frequency array of characters seen so far
 * - Maintain a counter `dist` for number of distinct characters
 * - For every prefix ending at index `i`:
 *     • length = i + 1
 *     • check if dist == (length % 3)
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Approach):
 *
 * 1. Initialize:
 *    - freq[26] = {0}  → frequency of each character
 *    - dist = 0        → number of distinct characters
 *    - cnt = 0         → count of valid residue prefixes
 *
 * 2. Traverse the string from left to right:
 *
 *    a) Let current character be s[i]
 *       idx = s[i] - 'a'
 *
 *    b) If freq[idx] == 0:
 *         → this is a NEW character
 *         → increment dist
 *
 *    c) Increment freq[idx]
 *
 *    d) Compute prefix length:
 *         len = i + 1
 *
 *    e) If dist == (len % 3):
 *         → this prefix is a residue prefix
 *         → increment cnt
 *
 * 3. After traversal, return cnt
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * s = "abc"
 *
 * Prefixes:
 *
 * i = 0 → "a"
 *   dist = 1, len = 1
 *   1 % 3 = 1 → valid
 *
 * i = 1 → "ab"
 *   dist = 2, len = 2
 *   2 % 3 = 2 → valid
 *
 * i = 2 → "abc"
 *   dist = 3, len = 3
 *   3 % 3 = 0 → invalid
 *
 * Result = 2
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Empty string → 0
 * - All characters same
 * - Long strings with repeating patterns
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n)
 *   Single pass through the string
 *
 * Space Complexity:
 * - O(1)
 *   Fixed-size frequency array of size 26
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Prefix-based problems naturally suit single-pass traversal
 * - Frequency array allows constant-time updates
 * - Modulo operation keeps checks lightweight
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Prefix Processing + Distinct Count" problem
 *
 * Seen in:
 * - Prefix property counting
 * - Sliding prefix frequency problems
 * - Modular prefix constraints
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int residuePrefixes(string s) {
        int n = s.size();

        vector<int> freq(26, 0);
        int dist = 0;   // number of distinct characters
        int cnt = 0;    // answer

        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';

            // New character encountered
            if (freq[idx] == 0)
                dist++;

            freq[idx]++;

            int len = i + 1;

            // Check residue condition
            if (dist == len % 3)
                cnt++;
        }

        return cnt;
    }
};

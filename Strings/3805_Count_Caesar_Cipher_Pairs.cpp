/*
 * Problem: 3805. Count Caesar Cipher Pairs
 *
 * Statement:
 * You are given an array of strings `words`.
 *
 * Two strings form a **Caesar Cipher Pair** if:
 * - One string can be transformed into the other
 * - By shifting ALL its characters by the SAME number
 *   of positions in the alphabet (cyclic, modulo 26)
 *
 * Your task is to count the total number of such valid pairs.
 *
 * ------------------------------------------------------------
 * Key Observations:
 *
 * - The absolute characters do NOT matter
 * - What matters is the RELATIVE SHIFT between characters
 *
 * Example:
 *   "abc" and "bcd" are Caesar pairs
 *   because every character is shifted by +1
 *
 *   "az" and "ba" are also Caesar pairs
 *   due to wrap-around (z → a)
 *
 * ------------------------------------------------------------
 * Core Insight:
 *
 * Any string can be NORMALIZED into a canonical form
 * by shifting it such that its FIRST character becomes 'a'.
 *
 * All strings that normalize to the SAME form
 * belong to the SAME Caesar Cipher group.
 *
 * ------------------------------------------------------------
 * APPROACH: Normalization + Hash Map (Your Approach)
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. Create an unordered_map `mpp`
 *    - Key   → normalized string
 *    - Value → frequency of that pattern
 *
 * 2. For each word in `words`:
 *
 *    a) Take the first character as BASE
 *       base = w[0] - 'a'
 *
 *    b) Build a normalized key:
 *       - For each character c in w:
 *           diff = (c - 'a' - base + 26) % 26
 *           append char(diff + 'a') to key
 *
 *    c) Increment mpp[key]
 *
 * 3. For each group in the map:
 *    - If frequency = k
 *    - Number of valid pairs = k * (k - 1) / 2
 *
 * 4. Sum over all groups and return result
 *
 * ------------------------------------------------------------
 * Why Normalization Works:
 *
 * Example:
 *
 * "abc":
 *   base = 'a'
 *   normalized = "abc"
 *
 * "bcd":
 *   base = 'b'
 *   normalized = "abc"
 *
 * "xyz":
 *   base = 'x'
 *   normalized = "abc"
 *
 * All belong to the SAME Caesar group
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * words = ["abc", "bcd", "xyz", "az", "ba"]
 *
 * Normalized forms:
 * "abc" → "abc"
 * "bcd" → "abc"
 * "xyz" → "abc"
 * "az"  → "az"
 * "ba"  → "az"
 *
 * Groups:
 * "abc" → 3 words → 3C2 = 3 pairs
 * "az"  → 2 words → 2C2 = 1 pair
 *
 * Total = 4
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Single-character strings
 * - Repeated identical strings
 * - Wrap-around shifts (z → a)
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - O(N * L)
 *   N = number of words
 *   L = average length of each word
 *
 * Space Complexity:
 *
 * - O(N * L)
 *   Storing normalized keys
 *
 * ------------------------------------------------------------
 * Why This Works Efficiently:
 *
 * - Each word is processed once
 * - Hash map groups equivalent Caesar strings
 * - Combination formula avoids pairwise comparison
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This problem uses:
 *   "String Normalization + Hashing + Combinatorics"
 *
 * Seen in:
 * - Group shifted strings
 * - Isomorphic string problems
 * - Canonical form hashing
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countPairs(vector<string>& words) {
        unordered_map<string,int> mpp;

        // Step 1: Normalize each word
        for (string &w : words) {
            string key = "";
            int base = w[0] - 'a';

            for (char c : w) {
                int diff = (c - 'a' - base + 26) % 26;
                key += char(diff + 'a');
            }
            mpp[key]++;
        }

        // Step 2: Count pairs in each group
        long long ans = 0;
        for (auto &p : mpp) {
            long long k = p.second;
            ans += k * (k - 1) / 2;
        }

        return ans;
    }
};

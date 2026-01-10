/*
 * Problem: 242. Valid Anagram
 *
 * Statement:
 * You are given two strings `s` and `t`.
 * Your task is to determine whether `t` is an ANAGRAM of `s`.
 *
 * An Anagram means:
 * - Both strings contain the SAME characters
 * - With the SAME frequencies
 * - Order of characters does NOT matter
 *
 * ------------------------------------------------------------
 * APPROACH 1: Frequency Map (Your Approach)
 *
 * Core Idea:
 * - Count frequency of each character in string `s`
 * - Decrease frequency using characters of string `t`
 * - If all frequencies become zero, strings are anagrams
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Approach 1):
 *
 * 1. If lengths of `s` and `t` are different:
 *      → return false
 *
 * 2. Create a map `freq`
 *    - Key   → character
 *    - Value → frequency in `s`
 *
 * 3. Traverse string `s`:
 *      freq[ch]++
 *
 * 4. Traverse string `t`:
 *    - If character exists in map:
 *         freq[ch]--
 *      Else:
 *         return false
 *
 * 5. Traverse the map:
 *    - If any frequency ≠ 0:
 *         return false
 *
 * 6. Return true
 *
 * ------------------------------------------------------------
 * Example:
 *
 * s = "anagram"
 * t = "nagaram"
 *
 * Frequency after s:
 * a→3, n→1, g→1, r→1, m→1
 *
 * After t subtraction:
 * All frequencies = 0
 *
 * Output = true
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n log n)
 *   (map operations)
 *
 * Space Complexity:
 * - O(n)
 *
 * ------------------------------------------------------------
 * APPROACH 2: Fixed-Size Frequency Array (Optimized)
 *
 * Core Insight:
 *
 * - Input contains only lowercase English letters
 * - There are only 26 possible characters
 *
 * So instead of a map, we can use a fixed-size array.
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Approach 2):
 *
 * 1. If lengths differ → return false
 *
 * 2. Create an array `cnt[26]` initialized to 0
 *
 * 3. Traverse string `s`:
 *      cnt[s[i] - 'a']++
 *
 * 4. Traverse string `t`:
 *      cnt[t[i] - 'a']--
 *
 * 5. If any value in cnt[] ≠ 0:
 *      return false
 *
 * 6. Otherwise return true
 *
 * ------------------------------------------------------------
 * Why Approach 2 Is Better:
 *
 * - O(n) time (no log factor)
 * - O(1) extra space
 * - Cleaner and faster
 *
 * ------------------------------------------------------------
 * Time & Space Comparison:
 *
 * | Approach | Time | Space | Recommended |
 * |--------|------|-------|-------------|
 * | Map    | O(n log n) | O(n) | ❌ |
 * | Array  | O(n) | O(1) | ✅ |
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Different lengths
 * - Empty strings
 * - Same strings
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Frequency Counting / Histogram Comparison" problem
 *
 * Seen in:
 * - Anagram checks
 * - Permutation matching
 * - String rearrangement problems
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // -----------------------------
    // Approach 1: Frequency Map
    // -----------------------------
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        map<char,int> freq;

        for (char ch : s) {
            freq[ch]++;
        }

        for (char ch : t) {
            if (freq.find(ch) != freq.end()) {
                freq[ch]--;
            } else {
                return false;
            }
        }

        for (auto fr : freq) {
            if (fr.second != 0)
                return false;
        }

        return true;
    }

    /*
    // -----------------------------
    // Approach 2: Frequency Array (Optimized)
    // -----------------------------
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        vector<int> cnt(26, 0);

        for (char ch : s)
            cnt[ch - 'a']++;

        for (char ch : t)
            cnt[ch - 'a']--;

        for (int x : cnt) {
            if (x != 0) return false;
        }

        return true;
    }
    */
};

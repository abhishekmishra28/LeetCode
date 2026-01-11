/*
 * Problem: 383. Ransom Note
 *
 * Statement:
 * You are given two strings:
 * - `ransomNote`
 * - `magazine`
 *
 * You need to determine whether you can construct `ransomNote`
 * using the letters from `magazine`.
 *
 * Rules:
 * - Each character in `magazine` can be used AT MOST ONCE
 * - Order of characters does NOT matter
 *
 * Return:
 * - true  → if ransomNote can be constructed
 * - false → otherwise
 *
 * ------------------------------------------------------------
 * APPROACH 1: Frequency Map (Your Approach)
 *
 * Core Idea:
 * - Count frequency of each character in `magazine`
 * - For each character in `ransomNote`:
 *     • Check if it is available
 *     • Decrease its frequency
 *
 * If at any point a character is unavailable,
 * construction is impossible.
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Approach 1):
 *
 * 1. Create an unordered_map `freq`
 *    - Key   → character
 *    - Value → frequency in `magazine`
 *
 * 2. Traverse `magazine`:
 *      freq[c]++
 *
 * 3. Traverse `ransomNote`:
 *    - If freq[s] > 0:
 *         freq[s]--
 *      Else:
 *         return false
 *
 * 4. If all characters are successfully matched:
 *      return true
 *
 * ------------------------------------------------------------
 * Example:
 *
 * ransomNote = "aa"
 * magazine   = "aab"
 *
 * Frequencies:
 * a → 2
 * b → 1
 *
 * Consume ransomNote:
 * a → ok (2→1)
 * a → ok (1→0)
 *
 * Output = true
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n + m)
 *   n = length of magazine
 *   m = length of ransomNote
 *
 * Space Complexity:
 * - O(n)
 *   Hash map for character frequencies
 *
 * ------------------------------------------------------------
 * APPROACH 2: Fixed-Size Frequency Array (Optimized)
 *
 * Core Insight:
 *
 * - Problem constraints specify ONLY lowercase English letters
 * - There are exactly 26 possible characters
 *
 * So instead of a hash map, we can use a fixed-size array.
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Approach 2):
 *
 * 1. Create an integer array `cnt[26]` initialized to 0
 *
 * 2. Traverse `magazine`:
 *      cnt[c - 'a']++
 *
 * 3. Traverse `ransomNote`:
 *    - If cnt[ch - 'a'] == 0:
 *         return false
 *    - Else:
 *         cnt[ch - 'a']--
 *
 * 4. Return true
 *
 * ------------------------------------------------------------
 * Why Approach 2 Is Better:
 *
 * - O(1) space
 * - Faster than hash map
 * - Cleaner and more interview-friendly
 *
 * ------------------------------------------------------------
 * Time & Space Comparison:
 *
 * | Approach | Time | Space | Recommended |
 * |--------|------|-------|-------------|
 * | Hash Map | O(n+m) | O(n) | ❌ |
 * | Array    | O(n+m) | O(1) | ✅ |
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - ransomNote longer than magazine
 * - Empty ransomNote → always true
 * - Repeated characters
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Frequency Consumption / Inventory Matching" problem
 *
 * Seen in:
 * - Anagram construction
 * - String build problems
 * - Resource allocation checks
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // -----------------------------
    // Approach 1: Frequency Map
    // -----------------------------
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> freq;

        // Count characters in magazine
        for (char c : magazine)
            freq[c]++;

        // Try to build ransomNote
        for (char s : ransomNote) {
            if (freq[s] > 0) {
                freq[s]--;
            } else {
                return false;
            }
        }

        return true;
    }

    /*
    // -----------------------------
    // Approach 2: Frequency Array (Optimized)
    // -----------------------------
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> cnt(26, 0);

        for (char c : magazine)
            cnt[c - 'a']++;

        for (char ch : ransomNote) {
            if (cnt[ch - 'a'] == 0)
                return false;
            cnt[ch - 'a']--;
        }

        return true;
    }
    */
};

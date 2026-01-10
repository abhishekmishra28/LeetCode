/*
 * Problem: 1832. Check if the Sentence Is Pangram
 *
 * Statement:
 * A sentence is called a PANGRAM if it contains
 * EVERY lowercase English letter at least once.
 *
 * You are given a string `sentence` consisting of
 * lowercase English letters.
 *
 * Return true if `sentence` is a pangram,
 * otherwise return false.
 *
 * ------------------------------------------------------------
 * APPROACH 1: Boolean Frequency Array (Your Approach)
 *
 * Core Idea:
 * - There are exactly 26 lowercase English letters
 * - Track whether each letter appears at least once
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Approach 1):
 *
 * 1. If sentence length < 26:
 *      → Impossible to contain all letters
 *      → return false
 *
 * 2. Create a boolean array `found[26]`
 *    - found[i] = true if letter (i + 'a') appears
 *
 * 3. Traverse the sentence:
 *      found[ch - 'a'] = true
 *
 * 4. Check the array:
 *    - If any index is false → return false
 *
 * 5. Otherwise → return true
 *
 * ------------------------------------------------------------
 * Example:
 *
 * sentence = "thequickbrownfoxjumpsoverthelazydog"
 *
 * All 26 letters appear → true
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n)
 *
 * Space Complexity:
 * - O(1)
 *   (Fixed size array of 26 elements)
 *
 * ------------------------------------------------------------
 * APPROACH 2: Bitmasking (More Compact & Elegant)
 *
 * Core Insight:
 *
 * - 26 letters can be represented using a 26-bit integer
 * - Each bit represents whether a letter has appeared
 *
 * ------------------------------------------------------------
 * How Bitmasking Works:
 *
 * - Start with mask = 0
 * - For each character ch:
 *      mask |= (1 << (ch - 'a'))
 *
 * - A pangram must have ALL 26 bits set
 *
 * Target mask:
 *      (1 << 26) - 1
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Approach 2):
 *
 * 1. Initialize mask = 0
 *
 * 2. Traverse sentence:
 *      mask |= (1 << (ch - 'a'))
 *
 * 3. If mask == (1 << 26) - 1:
 *      → return true
 *    Else:
 *      → return false
 *
 * ------------------------------------------------------------
 * Why Approach 2 Is Better:
 *
 * - Still O(n) time
 * - Uses only ONE integer instead of an array
 * - Very common in interviews for optimization discussion
 *
 * ------------------------------------------------------------
 * Time & Space Comparison:
 *
 * | Approach | Time | Space | Interview Value |
 * |--------|------|-------|-----------------|
 * | Boolean Array | O(n) | O(1) | ✅ |
 * | Bitmasking    | O(n) | O(1) | ⭐⭐ |
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Sentence shorter than 26 characters
 * - Repeated characters
 * - Exactly 26 characters
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Presence Check / Fixed Alphabet" problem
 *
 * Seen in:
 * - Pangram checks
 * - Character coverage problems
 * - Bitmask optimizations
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // -----------------------------
    // Approach 1: Boolean Array
    // -----------------------------
    bool checkIfPangram(string sentence) {
        if (sentence.size() < 26) return false;

        vector<bool> found(26, false);

        for (char ch : sentence) {
            found[ch - 'a'] = true;
        }

        for (int i = 0; i < 26; i++) {
            if (!found[i]) return false;
        }

        return true;
    }

    /*
    // -----------------------------
    // Approach 2: Bitmasking (Optimized)
    // -----------------------------
    bool checkIfPangram(string sentence) {
        int mask = 0;

        for (char ch : sentence) {
            mask |= (1 << (ch - 'a'));
        }

        return mask == ((1 << 26) - 1);
    }
    */
};

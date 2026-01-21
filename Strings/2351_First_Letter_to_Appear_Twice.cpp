/*
 * Problem: 2351. First Letter to Appear Twice
 *
 * Statement:
 * You are given a string `s` consisting of lowercase English letters.
 *
 * Return the FIRST letter that appears TWICE in the string.
 *
 * It is guaranteed that:
 * - At least one character appears twice
 * - The answer is unique
 *
 * ------------------------------------------------------------
 * APPROACH: Frequency Tracking with Early Exit (Your Approach)
 *
 * Core Idea:
 *
 * - Traverse the string from LEFT to RIGHT
 * - Keep track of characters already seen
 * - The first character encountered for the second time
 *   is the required answer
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. Create an array `seen` of size 26 (for 'a' to 'z'),
 *    initialized with 0
 *
 * 2. Traverse each character `ch` in string `s`:
 *
 *    a) Compute index:
 *         idx = ch - 'a'
 *
 *    b) If seen[idx] == 1:
 *         → This character has already appeared once
 *         → This is the FIRST repeated character
 *         → Return ch immediately
 *
 *    c) Otherwise:
 *         → Mark it as seen:
 *             seen[idx]++
 *
 * 3. The function will always return inside the loop
 *    because the problem guarantees a repeated character
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Left-to-right traversal ensures FIRST repetition is found
 * - Early exit avoids unnecessary processing
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * s = "abccba"
 *
 * a → seen[a] = 1
 * b → seen[b] = 1
 * c → seen[c] = 1
 * c → seen[c] == 1 → return 'c'
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - String length = 2
 * - Repetition occurs immediately
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n)
 *   Single traversal of the string
 *
 * Space Complexity:
 * - O(1)
 *   Fixed array of size 26
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "First Duplicate Detection"
 *
 * Seen in:
 * - First repeating character
 * - Duplicate detection problems
 * - Stream processing
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> seen(26, 0);

        for (char ch : s) {
            int idx = ch - 'a';

            if (seen[idx] == 1) {
                return ch;
            }
            seen[idx]++;
        }

        // Guaranteed to return earlier as per problem constraints
        return 'a';
    }
};

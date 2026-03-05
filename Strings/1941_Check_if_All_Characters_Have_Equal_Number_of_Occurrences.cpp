/*
 * Problem: 1941. Check if All Characters Have Equal Number of Occurrences
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given a string s, return true if all characters
 * in the string appear the same number of times.
 * Otherwise, return false.
 *
 * ------------------------------------------------------------
 * EXAMPLE:
 *
 * Input:
 *   s = "abacbc"
 *
 * Frequency:
 *   a → 2
 *   b → 2
 *   c → 2
 *
 * Output:
 *   true
 *
 * ------------------------------------------------------------
 * APPROACH: Frequency Counting
 *
 * ------------------------------------------------------------
 * CORE IDEA:
 *
 * 1️⃣ Count the frequency of every character
 *    in the string.
 *
 * 2️⃣ Store the frequency of the first character
 *    as the target frequency.
 *
 * 3️⃣ Compare all other character frequencies
 *    with this target value.
 *
 * 4️⃣ If any frequency differs → return false.
 *
 * 5️⃣ If all match → return true.
 *
 * ------------------------------------------------------------
 * ALGORITHM STEPS:
 *
 * Step 1:
 *   Use unordered_map<char,int> to count frequencies.
 *
 * Step 2:
 *   Set target frequency:
 *
 *        tar = freq[s[0]]
 *
 * Step 3:
 *   Traverse the map and compare each frequency
 *   with the target.
 *
 * Step 4:
 *   If mismatch found → return false.
 *
 * Step 5:
 *   Otherwise return true.
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * s = "aaabb"
 *
 * Frequency:
 *   a → 3
 *   b → 2
 *
 * Compare:
 *   3 != 2 → return false
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 *   O(n)
 *
 * Space Complexity:
 *   O(1)
 *   (since alphabet size is limited)
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - Can also solve using array of size 26
 *   instead of unordered_map.
 * - Useful when alphabet is limited.
 */

class Solution {
public:
    bool areOccurrencesEqual(string s) {

        unordered_map<char,int> freq;

        // Count frequency of each character
        for(char c : s){
            freq[c]++;
        }

        // Target frequency
        int tar = freq[s[0]];

        // Check if all frequencies match
        for(auto it : freq){
            if(it.second != tar)
                return false;
        }

        return true;
    }
};

/*
 * Problem: 316. Remove Duplicate Letters
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given a string s, remove duplicate letters so that every
 * letter appears once and only once.
 *
 * The result must be the smallest in lexicographical order
 * among all possible results.
 *
 * ------------------------------------------------------------
 * EXAMPLE:
 *
 * s = "bcabc"
 *
 * Result = "abc"
 *
 * ------------------------------------------------------------
 *
 * s = "cbacdcbc"
 *
 * Result = "acdb"
 *
 * ------------------------------------------------------------
 * CORE IDEA:
 *
 * We must:
 *
 * 1️⃣ Include every character exactly once
 * 2️⃣ Maintain the smallest lexicographical order
 *
 * This can be solved using a greedy + stack approach.
 *
 * ------------------------------------------------------------
 * KEY OBSERVATIONS:
 *
 * - If a character appears later again,
 *   we can remove it now and place it later.
 *
 * - If the current character is smaller than
 *   the top of the stack, we should remove
 *   the larger character to improve lexicographic order.
 *
 * ------------------------------------------------------------
 * DATA STRUCTURES USED:
 *
 * freq[26]
 *      Stores how many times each character still appears.
 *
 * vis[26]
 *      Tracks if a character is already used in the result.
 *
 * ans (string used as stack)
 *      Maintains the final sequence.
 *
 * ------------------------------------------------------------
 * ALGORITHM STEPS:
 *
 * 1️⃣ Count frequency of each character.
 *
 * 2️⃣ Traverse the string:
 *
 *      Decrease current character frequency.
 *
 * 3️⃣ If character already used → skip it.
 *
 * 4️⃣ Otherwise:
 *
 *      While stack is not empty AND
 *      top character is greater than current AND
 *      top character appears later again:
 *
 *              remove the top character
 *
 * 5️⃣ Push current character into stack.
 *
 * 6️⃣ Mark it as visited.
 *
 * ------------------------------------------------------------
 * DRY RUN:
 *
 * s = "cbacdcbc"
 *
 * Process:
 *
 * c → stack: c
 * b → pop c → stack: b
 * a → pop b → stack: a
 * c → stack: ac
 * d → stack: acd
 * c → skip
 * b → stack: acdb
 * c → skip
 *
 * Result = "acdb"
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 *      O(n)
 *
 * Space Complexity:
 *      O(1)
 *      (fixed alphabet size)
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * This is a classic greedy + monotonic stack problem.
 *
 * Similar pattern appears in:
 *
 *      • Smallest subsequence of distinct characters
 *      • Monotonic stack lexicographic problems
 */

class Solution {
public:
    string removeDuplicateLetters(string s) {

        vector<int> freq(26, 0);
        vector<bool> vis(26, false);

        // Count frequency
        for(char c : s)
            freq[c - 'a']++;

        string ans;

        for(char c : s){

            freq[c - 'a']--;

            // Skip if already in result
            if(vis[c - 'a'])
                continue;

            // Maintain lexicographic order
            while(!ans.empty() &&
                  ans.back() > c &&
                  freq[ans.back() - 'a'] > 0){

                vis[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans.push_back(c);
            vis[c - 'a'] = true;
        }

        return ans;
    }
};

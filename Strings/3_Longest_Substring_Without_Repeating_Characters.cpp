/*
 * Problem: 3. Longest Substring Without Repeating Characters
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given a string s,
 * find the length of the longest substring
 * without repeating characters.
 *
 * ------------------------------------------------------------
 * APPROACH: Sliding Window (Two Pointers)
 *
 * ------------------------------------------------------------
 * KEY OBSERVATIONS:
 *
 * 1️⃣ We need a substring (contiguous).
 *
 * 2️⃣ We must maintain uniqueness of characters
 *    inside the current window.
 *
 * 3️⃣ If a duplicate character appears:
 *    → Shrink window from the left
 *      until duplicate is removed.
 *
 * ------------------------------------------------------------
 * STRATEGY:
 *
 * Use:
 *   left  → start of window
 *   right → end of window
 *
 * Maintain:
 *   vis[128] → tracks ASCII character presence
 *
 * For each right:
 *   - While current character already exists:
 *         remove s[left] from window
 *         left++
 *
 *   - Mark current character visited
 *   - Update maximum length
 *
 * ------------------------------------------------------------
 * WINDOW INVARIANT:
 *
 * At every step:
 *   Substring s[left ... right]
 *   contains UNIQUE characters.
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * s = "abcabcbb"
 *
 * Window expands:
 * "abc" → length = 3
 *
 * When second 'a' appears:
 * Shrink until duplicate removed.
 *
 * Final answer = 3
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 * - O(n)
 *   (Each character visited at most twice)
 *
 * Space Complexity:
 * - O(1)
 *   (Fixed size array of 128)
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - Classic sliding window problem.
 * - Can also optimize using:
 *   unordered_map<char,int> to jump left pointer directly.
 * - Very frequently asked.
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.length();
        if (n == 0)
            return 0;

        int res = 0;

        // ASCII character tracking
        vector<bool> vis(128, false);

        int left = 0;

        for (int right = 0; right < n; right++) {

            // If duplicate found, shrink window
            while (vis[s[right]]) {
                vis[s[left]] = false;
                left++;
            }

            vis[s[right]] = true;

            // Update maximum length
            res = max(res, right - left + 1);
        }

        return res;
    }
};

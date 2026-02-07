/*
 * Problem: 1653. Minimum Deletions to Make String Balanced
 *
 * Statement:
 * You are given a string s consisting only of characters 'a' and 'b'.
 * A string is considered balanced if there is no index pair (i < j)
 * such that s[i] = 'b' and s[j] = 'a'.
 *
 * In other words:
 *   - All 'a's must appear before any 'b'
 *
 * You are allowed to delete characters.
 * Return the minimum number of deletions required to make s balanced.
 *
 * ------------------------------------------------------------
 * APPROACH: Greedy One-Pass (Your Approach)
 *
 * Core Idea:
 *
 * - Traverse the string from left to right
 * - Keep track of how many 'b's we have seen so far
 * - Whenever we see an 'a' after a 'b', the string becomes unbalanced
 *
 * At that point, we have two choices:
 *   1. Delete this 'a'
 *   2. Delete one of the previous 'b's
 *
 * Greedy Choice:
 *   - It is always optimal to delete the previous 'b'
 *   - Because future 'a's would cause even more conflicts
 *
 * ------------------------------------------------------------
 * Variables Used:
 *
 * cnt  → number of 'b's seen so far
 * ans  → minimum deletions required
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm:
 *
 * Initialize:
 *   cnt = 0   // count of 'b'
 *   ans = 0   // deletions
 *
 * Traverse string s from left to right:
 *
 * For each character:
 *
 * 1. If s[i] == 'b':
 *      cnt++
 *
 * 2. If s[i] == 'a' AND cnt > 0:
 *      - This 'a' appears after a 'b' → violation
 *      - Delete one previous 'b'
 *      - cnt--
 *      - ans++
 *
 * Return ans
 *
 * ------------------------------------------------------------
 * Why Deleting 'b' is Optimal:
 *
 * - Deleting the current 'a' would still leave earlier 'b's
 * - Those 'b's could cause issues with future 'a's
 * - Removing a 'b' reduces future conflicts
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * s = "aababbab"
 *
 * i   char   cnt(b)   ans
 * ------------------------
 * 0    a       0       0
 * 1    a       0       0
 * 2    b       1       0
 * 3    a       1 → 0   1
 * 4    b       1       1
 * 5    b       2       1
 * 6    a       2 → 1   2
 * 7    b       2       2
 *
 * Output: 2
 *
 * ------------------------------------------------------------
 * Key Observation:
 *
 * - cnt represents unresolved 'b's
 * - Each problematic 'a' forces exactly one deletion
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - O(n)
 *   Single pass through the string
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(1)
 *   Only constant extra variables used
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * - Greedy
 * - Prefix-based counting
 * - Conflict resolution during traversal
 */

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int cnt = 0;  // count of 'b'
        int ans = 0;  // deletions

        for(int i = 0; i < n; i++){
            if(s[i] == 'b')
                cnt++;
            else if(s[i] == 'a' && cnt > 0){
                cnt--;
                ans++;
            }
        }
        return ans;
    }
};

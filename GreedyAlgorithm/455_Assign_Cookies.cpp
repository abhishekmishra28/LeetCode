/*
 * Problem: 455. Assign Cookies
 *
 * Statement:
 * You are given:
 * - An array `g` where g[i] represents the GREED factor of the i-th child
 * - An array `s` where s[j] represents the SIZE of the j-th cookie
 *
 * Each child can get AT MOST one cookie.
 * A child is content if:
 *     cookie size >= child's greed
 *
 * Return the MAXIMUM number of content children.
 *
 * ------------------------------------------------------------
 * APPROACH: Greedy + Sorting + Two Pointers — Your Approach
 *
 * Core Greedy Insight:
 *
 * - To satisfy as many children as possible:
 *     • Always try to satisfy the child with the SMALLEST greed first
 *     • Use the SMALLEST cookie that can satisfy that child
 *
 * - This prevents wasting large cookies on small greed children
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. Sort the greed array `g` in ascending order
 * 2. Sort the cookie sizes array `s` in ascending order
 *
 * 3. Initialize pointers:
 *      i = 0  → points to children (greed array)
 *      j = 0  → points to cookies
 *
 * 4. Initialize:
 *      child = 0  → count of satisfied children
 *
 * 5. While both pointers are in range:
 *
 *    a) If current cookie can satisfy current child:
 *
 *         if (g[i] <= s[j]):
 *             → Assign cookie to child
 *             → child++
 *             → i++  (next child)
 *             → j++  (next cookie)
 *
 *    b) Else:
 *         → Cookie too small
 *         → Try next larger cookie:
 *             j++
 *
 * 6. Return `child`
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Sorting allows optimal matching
 * - Smallest greed matched with smallest sufficient cookie
 * - Greedy choice ensures global maximum satisfaction
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * g = [1,2,3]
 * s = [1,1]
 *
 * After sorting:
 * g = [1,2,3]
 * s = [1,1]
 *
 * Step-by-step:
 * - g[0]=1, s[0]=1 → satisfied → child=1
 * - g[1]=2, s[1]=1 → not satisfied → move cookie pointer
 *
 * Answer = 1
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - No cookies → return 0
 * - No children → return 0
 * - All cookies too small
 * - More cookies than children
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - Sorting: O(n log n + m log m)
 * - Two pointers: O(n + m)
 *
 * Overall:
 *   O(n log n + m log m)
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(1) extra space (ignoring sort stack)
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Greedy Matching with Two Pointers"
 *
 * Seen in:
 * - Job assignment problems
 * - Interval matching
 * - Resource allocation problems
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0;
        int child = 0;

        while (i < g.size() && j < s.size()) {
            if (g[i] <= s[j]) {
                child++;
                i++;
                j++;
            } else {
                j++;
            }
        }
        return child;
    }
};

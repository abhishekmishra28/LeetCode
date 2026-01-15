/*
 * Problem: 2943. Maximize Area of Square Hole in Grid
 *
 * Statement:
 * You are given an n × m grid formed by horizontal and vertical bars.
 *
 * - Some horizontal bars (hBars) are removed
 * - Some vertical bars (vBars) are removed
 *
 * Removing consecutive bars creates a larger continuous gap.
 *
 * Your task is to find the MAXIMUM AREA of a SQUARE hole
 * that can be formed after removing the given bars.
 *
 * ------------------------------------------------------------
 * Core Observation:
 *
 * - A square hole requires:
 *     • equal height and width
 *
 * - Height depends on:
 *     consecutive removed HORIZONTAL bars
 *
 * - Width depends on:
 *     consecutive removed VERTICAL bars
 *
 * - If k consecutive bars are removed,
 *   the actual gap length becomes (k + 1)
 *
 * ------------------------------------------------------------
 * APPROACH: Longest Consecutive Sequence (Your Approach)
 *
 * The problem reduces to:
 * - Find the longest consecutive sequence in hBars
 * - Find the longest consecutive sequence in vBars
 *
 * Then:
 *   maxHeight = longestH + 1
 *   maxWidth  = longestV + 1
 *
 * Since we want a SQUARE:
 *   side = min(maxHeight, maxWidth)
 *
 * Area = side × side
 *
 * ------------------------------------------------------------
 * Helper Function: longestSequence()
 *
 * Purpose:
 * - Finds the length of the longest consecutive sequence
 *   in a given array
 *
 * ------------------------------------------------------------
 * Step-by-Step for longestSequence():
 *
 * 1. Sort the array
 *
 * 2. Initialize:
 *      cnt = 1  → current consecutive count
 *      res = 1  → maximum found so far
 *
 * 3. Traverse from index 1:
 *
 *    a) If bars[i] == bars[i-1] + 1:
 *         → sequence continues
 *         → cnt++
 *
 *    b) Else:
 *         → sequence breaks
 *         → reset cnt = 1
 *
 *    c) Update:
 *         res = max(res, cnt)
 *
 * 4. Return res
 *
 * ------------------------------------------------------------
 * Why add +1?
 *
 * Example:
 * - Bars at positions [2, 3, 4] are removed
 * - That’s 3 consecutive bars
 *
 * Actual gap size becomes:
 *   3 bars removed → 4 units of space
 *
 * Hence:
 *   gap = longestSequence + 1
 *
 * ------------------------------------------------------------
 * Main Function Logic:
 *
 * 1. Compute:
 *      maxH = longestSequence(hBars) + 1
 *      maxV = longestSequence(vBars) + 1
 *
 * 2. The largest square side is:
 *      side = min(maxH, maxV)
 *
 * 3. Return:
 *      side × side
 *
 * ------------------------------------------------------------
 * Example:
 *
 * hBars = [2,3]
 * vBars = [1,2,3]
 *
 * longest horizontal = 2 → height = 3
 * longest vertical   = 3 → width  = 4
 *
 * square side = min(3,4) = 3
 * area = 9
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Only one bar removed → gap size = 2
 * - No bars removed → minimum gap = 1
 * - Unequal longest H and V gaps
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - Sorting bars:
 *     O(h log h + v log v)
 *
 * - Linear scan after sorting:
 *     O(h + v)
 *
 * Overall:
 *   O(h log h + v log v)
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(1) extra space (in-place sorting)
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Longest Consecutive Sequence after Sorting"
 *
 * Applied independently on two dimensions
 * and combined using a min() constraint.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSequence(vector<int> &bars){
        sort(bars.begin(), bars.end());

        int res = 1;
        int cnt = 1;

        for (int i = 1; i < (int)bars.size(); i++) {
            if (bars[i] == bars[i - 1] + 1) {
                cnt++;
            } else {
                cnt = 1;
            }
            res = max(res, cnt);
        }
        return res;
    }

    int maximizeSquareHoleArea(int n, int m,
                               vector<int>& hBars,
                               vector<int>& vBars) {

        int maxH = longestSequence(hBars) + 1;
        int maxV = longestSequence(vBars) + 1;

        int side = min(maxH, maxV);
        return side * side;
    }
};

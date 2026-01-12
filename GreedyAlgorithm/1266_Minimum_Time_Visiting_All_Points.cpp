/*
 * Problem: 1266. Minimum Time Visiting All Points
 *
 * Statement:
 * You are given a list of points on a 2D plane.
 * Each point is represented as [x, y].
 *
 * You need to visit all the points IN ORDER.
 *
 * In one second, you can:
 * - Move vertically (up/down)
 * - Move horizontally (left/right)
 * - Move diagonally
 *
 * Return the MINIMUM time required to visit all points.
 *
 * ------------------------------------------------------------
 * Key Observations:
 *
 * - You must move from points[i] → points[i+1] sequentially
 * - Diagonal movement allows you to reduce time
 * - In one diagonal move, both x and y change by 1
 *
 * ------------------------------------------------------------
 * Core Insight:
 *
 * To move from:
 *   (x1, y1) → (x2, y2)
 *
 * Let:
 *   dx = |x2 - x1|
 *   dy = |y2 - y1|
 *
 * Optimal strategy:
 * - Move diagonally as much as possible → min(dx, dy) steps
 * - Then move straight for remaining difference
 *
 * Total time required =
 *   max(dx, dy)
 *
 * ------------------------------------------------------------
 * APPROACH: Greedy Distance Calculation (Your Approach)
 *
 * Core Idea:
 * - For every consecutive pair of points:
 *     • Compute dx and dy
 *     • Add max(dx, dy) to total time
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Approach):
 *
 * 1. Initialize `cnt = 0` (total time)
 *
 * 2. Traverse the points array from i = 0 to n-2:
 *
 *    a) Compute:
 *         dx = |points[i][0] - points[i+1][0]|
 *         dy = |points[i][1] - points[i+1][1]|
 *
 *    b) Time to move between these two points:
 *         time = max(dx, dy)
 *
 *    c) Add time to `cnt`
 *
 * 3. Return `cnt`
 *
 * ------------------------------------------------------------
 * Example:
 *
 * points = [[1,1], [3,4], [-1,0]]
 *
 * Move 1:
 * (1,1) → (3,4)
 * dx = 2, dy = 3
 * time = max(2,3) = 3
 *
 * Move 2:
 * (3,4) → (-1,0)
 * dx = 4, dy = 4
 * time = max(4,4) = 4
 *
 * Total time = 3 + 4 = 7
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Diagonal moves are the most efficient
 * - Each diagonal move reduces both dx and dy
 * - Remaining distance is covered by straight moves
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Only one point → time = 0
 * - Points already aligned
 * - Large coordinates
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n)
 *   Single pass through the points array
 *
 * Space Complexity:
 * - O(1)
 *   No extra space used
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Greedy Geometry / Chebyshev Distance" problem
 *
 * Chebyshev Distance:
 *   dist = max(|dx|, |dy|)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int cnt = 0;

        for (int i = 0; i < n - 1; i++) {
            int dx = abs(points[i][0] - points[i+1][0]);
            int dy = abs(points[i][1] - points[i+1][1]);
            cnt += max(dx, dy);
        }

        return cnt;
    }
};

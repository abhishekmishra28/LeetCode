/*
 * Problem: 1765. Map of Highest Peak
 *
 * Statement:
 * You are given an m × n grid `isWater` where:
 * - isWater[i][j] = 1 represents a water cell
 * - isWater[i][j] = 0 represents a land cell
 *
 * You must assign a non-negative height to every cell such that:
 *
 * 1) Water cells MUST have height = 0
 * 2) Adjacent cells (up, down, left, right) differ in height by AT MOST 1
 * 3) The maximum height in the grid is as LARGE as possible
 *
 * Return the resulting height matrix.
 *
 * ------------------------------------------------------------
 * Key Observations:
 *
 * - All water cells have fixed height = 0
 * - Land cells should increase in height as we move away from water
 * - This is a MAXIMIZATION problem with LOCAL constraints
 *
 * ------------------------------------------------------------
 * Core Insight:
 *
 * To maximize heights while keeping adjacent difference ≤ 1,
 * each land cell should be as FAR as possible from the nearest water cell.
 *
 * That distance is exactly:
 * → the shortest distance to any water cell
 *
 * ------------------------------------------------------------
 * This becomes:
 *   MULTI-SOURCE BFS from all water cells
 *
 * ------------------------------------------------------------
 * Approach: Multi-Source BFS
 *
 * Idea:
 * - Treat all water cells as BFS sources
 * - Initialize their height = 0
 * - Expand outward, increasing height by 1 at each level
 *
 * BFS ensures:
 * - Each cell gets the MINIMUM distance to water
 * - Which results in the MAXIMUM possible valid height
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm:
 *
 * 1. Initialize:
 *    - `height` matrix with 0
 *    - `vis` matrix to mark visited cells
 *    - Queue for BFS
 *
 * 2. Push all water cells into the queue:
 *    - Mark them visited
 *    - Their height is already 0
 *
 * 3. Perform BFS:
 *    - Pop a cell (r, c)
 *    - For each of 4 neighbors:
 *        • If unvisited:
 *            - height[neighbor] = height[r][c] + 1
 *            - mark visited
 *            - push to queue
 *
 * 4. Continue until BFS completes
 *
 * ------------------------------------------------------------
 * Example:
 *
 * Input:
 * isWater =
 * [[0,1],
 *  [0,0]]
 *
 * BFS Levels:
 * Water → height 0
 * Adjacent land → height 1
 * Farthest land → height 2
 *
 * Output:
 * [[1,0],
 *  [2,1]]
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - All cells are water → all heights = 0
 * - Single water source
 * - Long narrow grids
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n * m)
 *   Each cell is processed once
 *
 * Space Complexity:
 * - O(n * m)
 *   Queue + visited + height matrix
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This problem is IDENTICAL in structure to:
 * - 542. 01 Matrix
 * - Walls and Gates
 *
 * Only interpretation differs:
 * - Distance = height
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Directions: up, down, left, right
    vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> height(n, vector<int>(m, 0));
        queue<pair<int,int>> q;

        // Step 1: Push all water cells into the queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isWater[i][j] == 1) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }

        // Step 2: Multi-source BFS
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];

                if (nr >= 0 && nc >= 0 && nr < n && nc < m && !vis[nr][nc]) {
                    vis[nr][nc] = 1;
                    height[nr][nc] = height[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return height;
    }
};

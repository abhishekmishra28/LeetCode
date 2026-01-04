/*
 * Problem: 542. 01 Matrix
 *
 * Statement:
 * You are given an m × n binary matrix `mat` consisting of only 0s and 1s.
 * For each cell, you need to find the distance to the nearest 0.
 *
 * The distance between two adjacent cells is 1.
 * Movement is allowed only in 4 directions:
 * - up, down, left, right
 *
 * Return a matrix `dist` where dist[i][j] is the distance of cell (i, j)
 * from the nearest 0.
 *
 * ------------------------------------------------------------
 * Key Observations:
 *
 * - Distance to nearest 0 → classic MULTI-SOURCE BFS problem
 * - All cells containing 0 are starting points
 * - BFS guarantees shortest distance in an unweighted grid
 *
 * ------------------------------------------------------------
 * Why NOT DFS or separate BFS from each 1?
 *
 * - DFS does not guarantee shortest distance
 * - BFS from each 1 → O((n*m)^2) ❌ TLE
 * - Multi-source BFS → O(n*m) ✅ optimal
 *
 * ------------------------------------------------------------
 * Approach: Multi-Source BFS
 *
 * Core Idea:
 * - Push ALL cells with value 0 into the queue initially
 * - Treat them as level-0 sources
 * - Expand BFS outward to fill distances for 1s
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm:
 *
 * 1. Initialize:
 *    - `vis` matrix to mark visited cells
 *    - `dist` matrix to store distance to nearest 0
 *    - Queue for BFS
 *
 * 2. Push all 0-cells into the queue:
 *    - Mark them as visited
 *    - Their distance is already 0
 *
 * 3. Perform BFS:
 *    - Pop a cell from the queue
 *    - Visit its 4 neighbors
 *    - If neighbor is unvisited:
 *        • dist[neighbor] = dist[current] + 1
 *        • mark visited
 *        • push into queue
 *
 * 4. Continue until queue is empty
 *
 * ------------------------------------------------------------
 * Example:
 *
 * Input:
 * mat =
 * [[0,0,0],
 *  [0,1,0],
 *  [1,1,1]]
 *
 * BFS layers:
 * Level 0 → all 0s
 * Level 1 → nearest 1s
 * Level 2 → farthest 1s
 *
 * Output:
 * [[0,0,0],
 *  [0,1,0],
 *  [1,2,1]]
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Matrix with all 0s → output same matrix
 * - Matrix with single 0
 * - Long narrow grids
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n * m)
 *   Each cell is visited once
 *
 * Space Complexity:
 * - O(n * m)
 *   Queue + visited + distance matrices
 *
 * ------------------------------------------------------------
 * Note:
 * This is the most efficient and standard solution.
 * This pattern appears frequently in grid problems.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Directions: up, down, left, right
    vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, 0));
        queue<pair<int,int>> q;

        // Step 1: Push all 0-cells into the queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
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
                    dist[nr][nc] = dist[r][c] + 1;
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }

        return dist;
    }
};

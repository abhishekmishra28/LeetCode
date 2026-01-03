/*
 * Problem: 934. Shortest Bridge
 *
 * Statement:
 * You are given an n × n binary grid where:
 * - 1 represents land
 * - 0 represents water
 *
 * There are exactly TWO islands in the grid.
 * An island is a group of 1s connected 4-directionally.
 *
 * You may flip 0s to 1s.
 *
 * Your task is to return the MINIMUM number of 0s that must be flipped
 * to connect the two islands.
 *
 * ------------------------------------------------------------
 * Key Observations:
 *
 * - There are exactly two islands
 * - We need the SHORTEST distance between them
 * - Flipping 0 → 1 is equivalent to crossing water
 *
 * ------------------------------------------------------------
 * Core Strategy:
 *
 * 1) Use DFS to find and mark the FIRST island
 * 2) Use BFS starting from ALL cells of the first island
 *    to reach the second island with minimum steps
 *
 * This is a classic:
 *   DFS + Multi-Source BFS hybrid problem
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - DFS helps capture the entire first island
 * - BFS guarantees shortest expansion across water
 * - Level-by-level BFS corresponds to number of flips
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm:
 *
 * STEP 1: Locate the first island
 * - Scan the grid
 * - When the first land cell is found, start DFS
 *
 * STEP 2: DFS to mark the entire first island
 * - Mark visited cells
 * - Push all island cells into a queue
 *
 * STEP 3: BFS expansion
 * - Each BFS level represents one flip
 * - Expand outward until second island is reached
 *
 * STEP 4: Return distance
 * - As soon as a land cell from the second island is reached
 *   return the current BFS level
 *
 * ------------------------------------------------------------
 * Example:
 *
 * Input:
 * [[0,1,0],
 *  [0,0,0],
 *  [0,0,1]]
 *
 * First island found at (0,1)
 * BFS expansion:
 * distance = 1 → water
 * distance = 2 → reaches second island
 *
 * Output: 2
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Islands touching diagonally (still separate)
 * - Islands at corners
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n * n)
 *   Each cell is visited at most once
 *
 * Space Complexity:
 * - O(n * n)
 *   Visited matrix + queue + recursion stack
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a TEXTBOOK example of:
 *   "DFS to mark + BFS to find shortest path"
 *
 * Appears in:
 * - Shortest bridge
 * - Number of enclaves (variation)
 * - Capture surrounded regions
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};

    /*
     * DFS to mark the first island
     * and push all its cells into the queue
     */
    void dfs(vector<vector<int>>& grid, int sr, int sc,
             vector<vector<int>>& vis,
             queue<pair<int,int>>& q) {

        int n = grid.size(), m = grid[0].size();

        // Boundary and invalid checks
        if (sr < 0 || sc < 0 || sr >= n || sc >= m) return;
        if (vis[sr][sc] || grid[sr][sc] == 0) return;

        vis[sr][sc] = 1;
        q.push({sr, sc});

        // Explore 4 directions
        for (int i = 0; i < 4; i++) {
            dfs(grid, sr + dir[i][0], sc + dir[i][1], vis, q);
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {

        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int,int>> q;

        // Step 1: Find and mark the first island
        bool found = false;
        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < m && !found; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, vis, q);
                    found = true;
                }
            }
        }

        // Step 2: BFS to find shortest bridge
        int dist = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [r, c] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int nr = r + dir[k][0];
                    int nc = c + dir[k][1];

                    if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
                    if (vis[nr][nc]) continue;

                    // Reached second island
                    if (grid[nr][nc] == 1)
                        return dist;

                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
            dist++;
        }

        return -1; // should never happen
    }
};

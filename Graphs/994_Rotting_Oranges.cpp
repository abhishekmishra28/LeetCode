/*
 * Problem: 994. Rotting Oranges
 *
 * Statement:
 * You are given an m x n grid where:
 *
 *   0 → empty cell
 *   1 → fresh orange
 *   2 → rotten orange
 *
 * Every minute, a rotten orange can rot its adjacent fresh oranges
 * (up, down, left, right).
 *
 * Return the minimum number of minutes needed until no fresh orange
 * remains. If impossible, return -1.
 *
 * ------------------------------------------------------------
 * APPROACH: Multi-Source BFS (Level Order Traversal) — Your Approach
 *
 * Core Idea:
 *
 * - All rotten oranges act as BFS SOURCES at time = 0
 * - Each BFS layer represents 1 minute of time
 * - Fresh oranges get infected level by level
 *
 * ------------------------------------------------------------
 * Why BFS?
 *
 * - Rot spreads simultaneously in all directions
 * - BFS naturally models "minimum time" propagation
 * - Using multiple starting points = Multi-Source BFS
 *
 * ------------------------------------------------------------
 * Data Structures Used:
 *
 * - Queue storing:
 *     ((row, col), time)
 *
 * - vis matrix to mark oranges already processed
 *
 * ------------------------------------------------------------
 * Step-by-Step Explanation:
 *
 * STEP 1: Initialization
 *
 * - Traverse the grid
 * - Push all initially rotten oranges into the queue with time = 0
 * - Mark them as visited
 *
 * STEP 2: BFS Traversal
 *
 * - Pop an element from the queue
 * - Update the maximum time encountered
 * - Try all 4 directions
 * - If a fresh orange is found and not visited:
 *     • Mark visited
 *     • Push into queue with time + 1
 *
 * STEP 3: Final Check
 *
 * - After BFS, scan the grid
 * - If any fresh orange remains unvisited → return -1
 *
 * STEP 4: Return the maximum time
 *
 * ------------------------------------------------------------
 * Direction Array:
 *
 * dir = {
 *   {0, 1},   // right
 *   {1, 0},   // down
 *   {-1, 0},  // up
 *   {0, -1}   // left
 * }
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * grid =
 * [
 *   [2,1,1],
 *   [1,1,0],
 *   [0,1,1]
 * ]
 *
 * Initial Queue:
 *   (0,0,0)
 *
 * Minute 1:
 *   (0,1), (1,0)
 *
 * Minute 2:
 *   (0,2), (1,1)
 *
 * Minute 3:
 *   (2,1)
 *
 * Minute 4:
 *   (2,2)
 *
 * Answer = 4
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - No fresh oranges → return 0
 * - Fresh oranges unreachable → return -1
 * - All oranges already rotten → return 0
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - O(n * m)
 *   Each cell is processed at most once
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(n * m)
 *   Queue + visited matrix
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Multi-Source BFS / Minimum Time Spread"
 *
 * Appears in:
 * - Rotting Oranges
 * - Zombie in Matrix
 * - Fire Spread
 * - Shortest path in grid with multiple sources
 */

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int time = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<pair<int,int>, int>> q;

        // Step 1: push all rotten oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = true;
                }
            }
        }

        int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};

        // Step 2: BFS
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();

            time = max(time, t);

            for (int i = 0; i < 4; i++) {
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];

                if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
                    !vis[nr][nc] && grid[nr][nc] == 1) {

                    vis[nr][nc] = true;
                    q.push({{nr, nc}, t + 1});
                }
            }
        }

        // Step 3: check if any fresh orange remains
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j])
                    return -1;
            }
        }

        return time;
    }
};

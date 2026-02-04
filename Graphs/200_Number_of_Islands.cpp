/*
 * Problem: 200. Number of Islands
 *
 * Statement:
 * You are given a 2D grid of characters where:
 *
 *   '1' represents LAND
 *   '0' represents WATER
 *
 * An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically.
 *
 * Return the number of islands in the grid.
 *
 * ------------------------------------------------------------
 * APPROACH: Depth First Search (DFS) Flood Fill — Your Approach
 *
 * Core Idea:
 *
 * - Treat the grid as a graph:
 *     • Each cell is a node
 *     • Adjacent land cells ('1') are connected
 *
 * - An ISLAND = one connected component of '1's
 *
 * - Strategy:
 *     • Traverse the grid
 *     • When a '1' is found → it starts a new island
 *     • Run DFS to mark the entire island as visited
 *     • Increment island count
 *
 * ------------------------------------------------------------
 * DFS Helper Function Explanation:
 *
 * dfs(r, c, grid)
 *
 * Purpose:
 * - Sink (remove) the entire island starting from cell (r, c)
 *
 * Steps:
 *
 * 1. Boundary / Base Case:
 *
 *      If:
 *        r or c is out of bounds
 *        OR grid[r][c] == '0'
 *      → return
 *
 * 2. Mark current land as visited:
 *
 *      grid[r][c] = '0'
 *
 * 3. Recursively explore all 4 directions:
 *
 *      dfs(r + 1, c)  // down
 *      dfs(r - 1, c)  // up
 *      dfs(r, c + 1)  // right
 *      dfs(r, c - 1)  // left
 *
 * ------------------------------------------------------------
 * Main Function Logic:
 *
 * 1. Initialize:
 *
 *      ans = 0   // number of islands
 *
 * 2. Traverse every cell in the grid:
 *
 *      If grid[i][j] == '1':
 *          - Found a new island
 *          - Increment ans
 *          - Call dfs(i, j) to remove the entire island
 *
 * 3. Return ans
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - DFS ensures all connected land cells are visited
 * - Marking visited cells as '0' prevents double counting
 * - Each DFS call corresponds to EXACTLY ONE island
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * grid =
 * [
 *   ['1','1','0','0'],
 *   ['1','1','0','0'],
 *   ['0','0','1','0'],
 *   ['0','0','0','1']
 * ]
 *
 * Start scanning:
 *
 * (0,0) → '1'
 *   → dfs removes entire first island
 *   → ans = 1
 *
 * (2,2) → '1'
 *   → dfs removes second island
 *   → ans = 2
 *
 * (3,3) → '1'
 *   → dfs removes third island
 *   → ans = 3
 *
 * Final Answer = 3
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Empty grid → 0 islands
 * - All water → 0 islands
 * - All land → 1 island
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - O(n * m)
 *   Each cell is visited at most once
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(n * m) in worst case (DFS recursion stack)
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Grid DFS / Flood Fill / Connected Components"
 *
 * Appears in:
 * - Number of Islands
 * - Flood Fill
 * - Surrounded Regions
 * - Max Area of Island
 */

class Solution {
public:
    void dfs(int r, int c, vector<vector<char>> &grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (r < 0 || r >= n || c < 0 || c >= m || grid[r][c] == '0')
            return;

        // mark as visited
        grid[r][c] = '0';

        // explore all directions
        dfs(r + 1, c, grid);
        dfs(r - 1, c, grid);
        dfs(r, c + 1, grid);
        dfs(r, c - 1, grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    ans++;          // new island
                    dfs(i, j, grid);
                }
            }
        }
        return ans;
    }
};

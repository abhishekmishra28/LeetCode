/*
 * Problem: 1034. Coloring A Border
 *
 * Statement:
 * You are given an m x n grid of integers where each cell represents a color.
 * Starting from a given cell (row, col), consider the connected component
 * of cells having the same color as grid[row][col] (4-directionally connected).
 *
 * Your task is to color ONLY the BORDER of this connected component with
 * a new given color, and return the resulting grid.
 *
 * A cell is considered a BORDER cell if:
 * 1) It lies on the boundary of the grid, OR
 * 2) At least one of its 4-directional neighbors has a DIFFERENT color
 *
 * ------------------------------------------------------------
 * Key Observations:
 * - We must NOT recolor the entire component
 * - Only the boundary cells of the component should change color
 * - Interior cells must remain unchanged
 * - DFS is ideal for traversing the connected component
 *
 * ------------------------------------------------------------
 * Approach 1: DFS + Mark Border Cells
 *
 * Idea:
 * - Traverse the connected component using DFS
 * - For each cell:
 *   - Check its 4 neighbors
 *   - If any neighbor is outside grid OR has a different color,
 *     mark the current cell as a BORDER cell
 * - Temporarily mark border cells using a special value (-1)
 * - After DFS, recolor all marked border cells with the new color
 *
 * Why use a temporary marker (-1)?
 * - Prevents interference while DFS is still running
 * - Avoids recoloring interior cells prematurely
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm:
 *
 * 1. Store the original color at (row, col) as `toCheck`
 * 2. Create a visited matrix to avoid revisiting cells
 * 3. Run DFS from (row, col)
 * 4. During DFS:
 *    - Assume current cell is NOT a border
 *    - For each of 4 directions:
 *        a) If neighbor is out of bounds → it's a border
 *        b) If neighbor has a different color → it's a border
 *        c) If neighbor is same color and unvisited → DFS
 *    - If marked as border → temporarily set grid[r][c] = -1
 * 5. After DFS completes:
 *    - Traverse the grid
 *    - Replace all -1 cells with the new color
 *
 * ------------------------------------------------------------
 * Example:
 *
 * Input:
 * grid = [[1,1,1],
 *         [1,1,1],
 *         [1,1,1]]
 * row = 1, col = 1, color = 2
 *
 * Border cells → outer ring of 1's
 * Result:
 * [[2,2,2],
 *  [2,1,2],
 *  [2,2,2]]
 *
 * ------------------------------------------------------------
 * Edge Cases:
 * - Starting cell itself is a border
 * - Entire component touches grid boundary
 * - Single-cell component
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n * m)
 *   Each cell is visited at most once
 *
 * Space Complexity:
 * - O(n * m)
 *   Visited matrix + recursion stack
 *
 * ------------------------------------------------------------
 * Note:
 * This approach ensures:
 * - Correct border detection
 * - No accidental recoloring
 * - Clean separation of traversal and recoloring
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};

    void dfs(vector<vector<int>>& grid, int r, int c, int toCheck,
             vector<vector<int>> &vis) {

        int n = grid.size();
        int m = grid[0].size();

        vis[r][c] = 1;
        bool isBorder = false;

        for (auto &d : dir) {
            int nr = r + d[0];
            int nc = c + d[1];

            // Out of bounds → border
            if (nr < 0 || nc < 0 || nr >= n || nc >= m)
                isBorder = true;

            // Neighbor has different color → border
            else if (grid[nr][nc] != toCheck && grid[nr][nc] != -1)
                isBorder = true;

            // Same color and not visited → DFS
            else if (!vis[nr][nc])
                dfs(grid, nr, nc, toCheck, vis);
        }

        // Temporarily mark border cells
        if (isBorder)
            grid[r][c] = -1;
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid,
                                    int row, int col, int color) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int toCheck = grid[row][col];

        // DFS to mark border cells
        dfs(grid, row, col, toCheck, vis);

        // Final recoloring step
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == -1)
                    grid[i][j] = color;

        return grid;
    }
};

/*
 * Problem: 733. Flood Fill
 *
 * Statement:
 * You are given an m x n image represented by a grid of integers.
 * Each integer represents the pixel color.
 *
 * Starting from pixel (sr, sc), replace the color of that pixel
 * and all 4-directionally connected pixels having the SAME original
 * color with the new given color.
 *
 * Return the modified image.
 *
 * ------------------------------------------------------------
 * APPROACH: DFS (Depth First Search) — Your Approach
 *
 * Core Idea:
 *
 * - Treat the image as a graph:
 *     • Each cell is a node
 *     • Adjacent cells (up, down, left, right) are connected
 *
 * - We start from (sr, sc) and:
 *     • Note its original color (ogColor)
 *     • Change all connected cells having ogColor to new color
 *
 * ------------------------------------------------------------
 * Important Optimization:
 *
 * If original color == new color:
 *   → No change needed
 *   → Return image immediately
 *
 * This prevents infinite recursion.
 *
 * ------------------------------------------------------------
 * DFS Helper Function:
 *
 * dfs(image, sr, sc, ogColor, color)
 *
 * Purpose:
 * - Recolor the current pixel
 * - Recursively recolor all valid neighboring pixels
 *
 * Base Conditions:
 *
 * 1. Out of bounds → return
 * 2. Current pixel color != original color → return
 *
 * Processing:
 *
 * - Change image[sr][sc] to new color
 * - Explore all 4 directions recursively
 *
 * ------------------------------------------------------------
 * Main Function Logic:
 *
 * 1. Store the original color:
 *
 *      ogColor = image[sr][sc]
 *
 * 2. If ogColor == color:
 *
 *      return image
 *
 * 3. Call DFS from (sr, sc)
 *
 * 4. Return updated image
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - DFS ensures all connected pixels of same color are visited
 * - Recoloring prevents revisiting the same pixel
 * - Only pixels matching the original color are changed
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * image =
 * [
 *   [1,1,1],
 *   [1,1,0],
 *   [1,0,1]
 * ]
 *
 * sr = 1, sc = 1, color = 2
 *
 * ogColor = 1
 *
 * DFS recolors all connected 1's starting from (1,1)
 *
 * Result =
 * [
 *   [2,2,2],
 *   [2,2,0],
 *   [2,0,1]
 * ]
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Starting pixel already has target color
 * - Single cell image
 * - Entire image same color
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - O(n * m)
 *   Each pixel is visited at most once
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(n * m) in worst case due to recursion stack
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "DFS Flood Fill / Graph Traversal on Grid"
 *
 * Appears in:
 * - Flood Fill
 * - Number of Islands
 * - Max Area of Island
 * - Surrounded Regions
 */

class Solution {
private:
    void dfs(vector<vector<int>>& image,
             int sr, int sc,
             int ogColor, int color) {

        int n = image.size();
        int m = image[0].size();

        // boundary + color check
        if (sr < 0 || sc < 0 || sr >= n || sc >= m)
            return;
        if (image[sr][sc] != ogColor)
            return;

        // recolor current pixel
        image[sr][sc] = color;

        // explore neighbors
        dfs(image, sr + 1, sc, ogColor, color);
        dfs(image, sr - 1, sc, ogColor, color);
        dfs(image, sr, sc + 1, ogColor, color);
        dfs(image, sr, sc - 1, ogColor, color);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc,
                                  int color) {

        int ogColor = image[sr][sc];

        // optimization: no change needed
        if (ogColor == color)
            return image;

        dfs(image, sr, sc, ogColor, color);
        return image;
    }
};

/*
 * Problem: 79. Word Search
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given an m x n grid of characters board and a string word,
 * return true if the word exists in the grid.
 *
 * The word can be constructed from letters of sequentially
 * adjacent cells (up, down, left, right).
 *
 * The same cell may NOT be used more than once.
 *
 * ------------------------------------------------------------
 * APPROACH: Backtracking (DFS on Grid)
 *
 * ------------------------------------------------------------
 * KEY OBSERVATIONS:
 *
 * 1️⃣ This is a classic grid DFS problem.
 *
 * 2️⃣ From each cell, we can move in 4 directions:
 *    - Up
 *    - Down
 *    - Left
 *    - Right
 *
 * 3️⃣ We must:
 *    - Match characters sequentially
 *    - Mark visited cells temporarily
 *    - Restore the cell after recursion (backtracking)
 *
 * ------------------------------------------------------------
 * STRATEGY:
 *
 * 1️⃣ Try starting DFS from every cell.
 *
 * 2️⃣ Recursive function:
 *
 *    solve(board, word, i, j, idx)
 *
 *    i, j → current position
 *    idx  → index of word we are matching
 *
 * ------------------------------------------------------------
 * BASE CASE:
 *
 * If idx == word.size():
 * → Entire word matched
 * → Return true
 *
 * ------------------------------------------------------------
 * INVALID CONDITIONS:
 *
 * - Out of bounds
 * - Character mismatch
 *
 * ------------------------------------------------------------
 * BACKTRACKING STEP:
 *
 * 1️⃣ Store current character
 * 2️⃣ Mark cell as visited (e.g., '#')
 * 3️⃣ Explore all 4 directions
 * 4️⃣ Restore original character
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * board =
 * [
 *  ['A','B','C','E'],
 *  ['S','F','C','S'],
 *  ['A','D','E','E']
 * ]
 *
 * word = "ABCCED"
 *
 * Path:
 * A → B → C → C → E → D
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 * - O(m * n * 4^L)
 *   where L = length of word
 *
 * Space Complexity:
 * - O(L) recursion depth
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - Classic DFS + Backtracking grid problem
 * - Mark and restore technique is crucial
 * - Avoid using extra visited matrix (in-place marking works)
 */

class Solution {
private:
    bool solve(vector<vector<char>>& board,
               string& word,
               int i,
               int j,
               int idx) {

        // All characters matched
        if (idx == word.size())
            return true;

        // Out of bounds or mismatch
        if (i < 0 || i >= board.size() ||
            j < 0 || j >= board[0].size() ||
            board[i][j] != word[idx])
            return false;

        // Store original character
        char temp = board[i][j];

        // Mark as visited
        board[i][j] = '#';

        // Explore all 4 directions
        bool found =
            solve(board, word, i + 1, j, idx + 1) ||
            solve(board, word, i - 1, j, idx + 1) ||
            solve(board, word, i, j + 1, idx + 1) ||
            solve(board, word, i, j - 1, idx + 1);

        // Restore original character (backtrack)
        board[i][j] = temp;

        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {

        int n = board.size();
        int m = board[0].size();

        // Try starting from each cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (solve(board, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};

/*
 * Problem: 37. Sudoku Solver
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Write a program to solve a Sudoku puzzle by filling
 * the empty cells.
 *
 * A Sudoku solution must satisfy:
 *
 * 1️⃣ Each digit 1-9 must appear exactly once in each row.
 * 2️⃣ Each digit 1-9 must appear exactly once in each column.
 * 3️⃣ Each digit 1-9 must appear exactly once in each 3x3 sub-box.
 *
 * The input board contains '.' for empty cells.
 *
 * ------------------------------------------------------------
 * APPROACH: Backtracking (DFS + Constraint Checking)
 *
 * ------------------------------------------------------------
 * KEY OBSERVATIONS:
 *
 * 1️⃣ This is a constraint satisfaction problem.
 *
 * 2️⃣ For every empty cell:
 *    - Try digits '1' to '9'
 *    - Place digit only if valid
 *    - Recursively solve the rest
 *
 * 3️⃣ If placing a digit leads to failure,
 *    undo the placement (backtrack).
 *
 * ------------------------------------------------------------
 * VALIDITY CHECK:
 *
 * isValid(board, r, c, ch)
 *
 * We check:
 *
 * 1️⃣ Entire row r
 * 2️⃣ Entire column c
 * 3️⃣ 3×3 subgrid:
 *
 *    boxRow = 3 * (r / 3) + i / 3
 *    boxCol = 3 * (c / 3) + i % 3
 *
 * This iterates over all 9 cells in the box.
 *
 * ------------------------------------------------------------
 * BACKTRACKING STRATEGY:
 *
 * 1️⃣ Traverse board cell-by-cell.
 *
 * 2️⃣ If an empty cell '.' is found:
 *     - Try digits '1' to '9'
 *     - If valid:
 *         - Place digit
 *         - Recurse
 *         - If recursion succeeds → return true
 *         - Else undo and try next digit
 *
 * 3️⃣ If no digit works → return false
 *
 * 4️⃣ If entire board filled → return true
 *
 * ------------------------------------------------------------
 * BASE CASE:
 *
 * If no empty cell is left:
 * → Puzzle solved
 * → Return true
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 * - Worst case exponential
 * - Roughly O(9^(empty_cells))
 *
 * Space Complexity:
 * - O(1) extra space (board modified in-place)
 * - O(depth) recursion stack
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - Classic backtracking problem
 * - Validity checking is critical
 * - Can be optimized using:
 *     row[9][9]
 *     col[9][9]
 *     box[9][9]
 *   for O(1) validity checks
 */

class Solution {
private:
    bool isValid(vector<vector<char>>& board,
                 int r,
                 int c,
                 char ch) {

        for (int i = 0; i < 9; i++) {

            // Check row
            if (board[r][i] == ch)
                return false;

            // Check column
            if (board[i][c] == ch)
                return false;

            // Check 3x3 box
            int boxR = 3 * (r / 3) + i / 3;
            int boxC = 3 * (c / 3) + i % 3;

            if (board[boxR][boxC] == ch)
                return false;
        }

        return true;
    }

    bool backtrack(vector<vector<char>>& board) {

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                // Find empty cell
                if (board[i][j] == '.') {

                    // Try digits 1 to 9
                    for (char c = '1'; c <= '9'; c++) {

                        if (isValid(board, i, j, c)) {

                            board[i][j] = c;

                            if (backtrack(board))
                                return true;

                            // Backtrack
                            board[i][j] = '.';
                        }
                    }

                    // No valid digit found
                    return false;
                }
            }
        }

        // All cells filled
        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }
};

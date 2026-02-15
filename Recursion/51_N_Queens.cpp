/*
 * Problem: 51. N-Queens
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * The n-queens puzzle is the problem of placing n queens
 * on an n × n chessboard such that:
 *
 * - No two queens attack each other.
 *
 * Queens attack:
 * - Same row
 * - Same column
 * - Same diagonal
 *
 * Return all distinct solutions.
 *
 * ------------------------------------------------------------
 * APPROACH: Backtracking (Column-by-Column Placement)
 *
 * ------------------------------------------------------------
 * KEY OBSERVATIONS:
 *
 * 1️⃣ Place one queen per column.
 *    → This automatically avoids column conflicts.
 *
 * 2️⃣ Before placing a queen at (row, col),
 *    we must check:
 *       - Left row
 *       - Upper-left diagonal
 *       - Lower-left diagonal
 *
 * 3️⃣ We only check LEFT side because:
 *    - We place queens from left → right.
 *
 * ------------------------------------------------------------
 * SAFETY CHECK (isSafe):
 *
 * For position (r, c):
 *
 * 1️⃣ Check upper-left diagonal
 * 2️⃣ Check left row
 * 3️⃣ Check lower-left diagonal
 *
 * If any queen found → not safe.
 *
 * ------------------------------------------------------------
 * RECURSION STRATEGY:
 *
 * solve(col):
 *
 * If col == n:
 *    → Valid configuration found
 *    → Store board
 *
 * Otherwise:
 *    For each row in current column:
 *        - If safe:
 *            - Place queen
 *            - Recurse for next column
 *            - Backtrack
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * n = 4
 *
 * One solution:
 *
 * . Q . .
 * . . . Q
 * Q . . .
 * . . Q .
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 * - O(n!)
 *   (Backtracking with branching)
 *
 * Space Complexity:
 * - O(n) recursion stack
 * - O(n²) board storage
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - Classic hard backtracking problem
 * - Optimize safety check using hash arrays for:
 *     row
 *     upper diagonal
 *     lower diagonal
 *   → reduces checking from O(n) to O(1)
 */

class Solution {
private:
    bool isSafe(int r, int c, vector<string> board, int n) {

        int rCopy = r;
        int cCopy = c;

        // Check upper-left diagonal (North-West)
        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q')
                return false;
            r--;
            c--;
        }

        r = rCopy;
        c = cCopy;

        // Check left row
        while (c >= 0) {
            if (board[r][c] == 'Q')
                return false;
            c--;
        }

        r = rCopy;
        c = cCopy;

        // Check lower-left diagonal (South-West)
        while (r < n && c >= 0) {
            if (board[r][c] == 'Q')
                return false;
            r++;
            c--;
        }

        return true;
    }

    void solve(int col,
               vector<string>& board,
               vector<vector<string>>& result,
               int n) {

        // All queens placed
        if (col == n) {
            result.push_back(board);
            return;
        }

        // Try placing queen in each row of current column
        for (int row = 0; row < n; row++) {

            if (isSafe(row, col, board, n)) {

                board[row][col] = 'Q';

                solve(col + 1, board, result, n);

                // Backtrack
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> result;

        // Initialize empty board
        vector<string> board(n);
        string rowString(n, '.');

        for (int i = 0; i < n; i++) {
            board[i] = rowString;
        }

        solve(0, board, result, n);

        return result;
    }
};

/*
 * Problem: 52. N-Queens II
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * The n-queens puzzle is the problem of placing n queens
 * on an n × n chessboard such that:
 *
 * - No two queens attack each other.
 *
 * Return the total number of distinct solutions.
 *
 * ------------------------------------------------------------
 * DIFFERENCE FROM N-Queens I:
 *
 * - Instead of returning all board configurations,
 *   we only need to return the COUNT of valid solutions.
 *
 * ------------------------------------------------------------
 * APPROACH: Backtracking (Column-by-Column Placement)
 *
 * ------------------------------------------------------------
 * KEY OBSERVATIONS:
 *
 * 1️⃣ Place one queen per column.
 *    → This avoids column conflicts automatically.
 *
 * 2️⃣ Before placing a queen at (row, col),
 *    check:
 *       - Left row
 *       - Upper-left diagonal
 *       - Lower-left diagonal
 *
 * 3️⃣ Only LEFT side needs checking because
 *    queens are placed from left → right.
 *
 * ------------------------------------------------------------
 * SAFETY CHECK:
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
 *    → One valid arrangement found
 *    → Increment counter
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
 * Total valid solutions = 2
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 * - O(n!)
 *
 * Space Complexity:
 * - O(n) recursion stack
 * - O(n²) board representation
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - Same logic as N-Queens I
 * - Only counting instead of storing boards
 * - Can be optimized using hash arrays:
 *     row[]
 *     upperDiag[]
 *     lowerDiag[]
 *   → O(1) safety check
 */

class Solution {
private:
    bool isSafe(int r, int c, vector<string> board, int n) {

        int rCopy = r;
        int cCopy = c;

        // Check upper-left diagonal
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

        // Check lower-left diagonal
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
               int& cnt,
               int n) {

        // All queens placed
        if (col == n) {
            cnt++;
            return;
        }

        // Try placing queen in each row
        for (int row = 0; row < n; row++) {

            if (isSafe(row, col, board, n)) {

                board[row][col] = 'Q';

                solve(col + 1, board, cnt, n);

                // Backtrack
                board[row][col] = '.';
            }
        }
    }

public:
    int totalNQueens(int n) {

        int cnt = 0;

        // Initialize empty board
        vector<string> board(n);
        string rowString(n, '.');

        for (int i = 0; i < n; i++) {
            board[i] = rowString;
        }

        solve(0, board, cnt, n);

        return cnt;
    }
};

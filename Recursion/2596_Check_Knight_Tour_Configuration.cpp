/*
 * Problem: 2596. Check Knight Tour Configuration
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * You are given an n x n grid where each cell contains
 * a number from 0 to n²-1 representing the order of moves
 * in a knight's tour.
 *
 * A knight starts from the top-left corner (0,0).
 *
 * The grid represents a valid knight tour if:
 *
 * 1️⃣ The first move starts at grid[0][0] = 0.
 * 2️⃣ Each next number represents the next valid
 *    knight move.
 * 3️⃣ All numbers from 0 → n²-1 appear exactly once.
 *
 * Return true if the configuration represents a valid
 * knight tour, otherwise return false.
 *
 * ------------------------------------------------------------
 * KNIGHT MOVES:
 *
 * A knight in chess moves in an "L" shape:
 *
 *      (±2, ±1)
 *      (±1, ±2)
 *
 * Possible moves from (r,c):
 *
 *      (r-2, c+1)
 *      (r-1, c+2)
 *      (r-2, c-1)
 *      (r-1, c-2)
 *      (r+1, c-2)
 *      (r+2, c-1)
 *      (r+2, c+1)
 *      (r+1, c+2)
 *
 * ------------------------------------------------------------
 * APPROACH: DFS Simulation
 *
 * ------------------------------------------------------------
 * CORE IDEA:
 *
 * We simulate the knight's movement using recursion.
 *
 * Starting from position (0,0) with expected move = 0:
 *
 * - Verify the current cell has the correct number.
 * - Recursively check all 8 knight moves for the next move.
 *
 * If we reach move number (n² - 1),
 * the entire sequence is valid.
 *
 * ------------------------------------------------------------
 * BASE CONDITIONS:
 *
 * 1️⃣ If position is outside grid → invalid.
 * 2️⃣ If grid value ≠ expected move → invalid.
 * 3️⃣ If expected move == n²-1 → valid tour completed.
 *
 * ------------------------------------------------------------
 * ALGORITHM STEPS:
 *
 * 1️⃣ Start DFS from (0,0) expecting move 0.
 *
 * 2️⃣ Check if current cell matches expected move.
 *
 * 3️⃣ Recursively explore all 8 possible knight moves
 *    with expectedMove + 1.
 *
 * 4️⃣ If any recursive path succeeds → return true.
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * grid =
 *
 * 0  11 16  5 20
 * 17  4 19 10 15
 * 12  1  8 21  6
 * 3  18 23 14  9
 * 24 13  2  7 22
 *
 * Starting from (0,0) → 0
 * Next move should be 1
 * Continue checking valid knight transitions.
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 *      O(n²)
 *
 * Space Complexity:
 *      O(n²) recursion depth in worst case
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - This is a simulation problem.
 * - Instead of searching for the knight path,
 *   we only validate the given path.
 * - Often asked to test understanding of
 *   knight movement patterns.
 */

class Solution {
private:

    bool isValid(vector<vector<int>> &grid,
                 int r, int c,
                 int n,
                 int expMove){

        // Out of bounds or wrong move number
        if(r < 0 || r >= n || c < 0 || c >= n ||
           grid[r][c] != expMove)
            return false;

        // All moves completed
        if(expMove == (n*n - 1))
            return true;

        bool a1 = isValid(grid, r-2, c+1, n, expMove+1);
        bool a2 = isValid(grid, r-1, c+2, n, expMove+1);
        bool a3 = isValid(grid, r-2, c-1, n, expMove+1);
        bool a4 = isValid(grid, r-1, c-2, n, expMove+1);
        bool a5 = isValid(grid, r+1, c-2, n, expMove+1);
        bool a6 = isValid(grid, r+2, c-1, n, expMove+1);
        bool a7 = isValid(grid, r+2, c+1, n, expMove+1);
        bool a8 = isValid(grid, r+1, c+2, n, expMove+1);

        return a1 || a2 || a3 || a4 ||
               a5 || a6 || a7 || a8;
    }

public:

    bool checkValidGrid(vector<vector<int>>& grid) {

        int n = grid.size();

        return isValid(grid, 0, 0, n, 0);
    }
};

/*
 * Problem: 216. Combination Sum III
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Find all valid combinations of k numbers that add up to n
 * such that:
 *
 *      • Only numbers from 1 to 9 are used.
 *      • Each number can be used at most once.
 *
 * Return all possible valid combinations.
 *
 * ------------------------------------------------------------
 * EXAMPLE:
 *
 * k = 3
 * n = 7
 *
 * Output:
 *
 * [1,2,4]
 *
 * ------------------------------------------------------------
 *
 * k = 3
 * n = 9
 *
 * Output:
 *
 * [1,2,6]
 * [1,3,5]
 * [2,3,4]
 *
 * ------------------------------------------------------------
 * APPROACH: Backtracking
 *
 * ------------------------------------------------------------
 * CORE IDEA:
 *
 * We generate combinations using numbers 1 → 9.
 *
 * At each step we decide whether to include a number
 * in the current combination.
 *
 * We keep track of:
 *
 *      curr → current combination
 *      k    → remaining numbers to pick
 *      n    → remaining sum
 *
 * ------------------------------------------------------------
 * BASE CASES:
 *
 * 1️⃣ If k == 0 and n == 0
 *
 *      We found a valid combination.
 *
 * 2️⃣ If k == 0 or n < 0
 *
 *      Invalid path → stop recursion.
 *
 * ------------------------------------------------------------
 * RECURSION STEP:
 *
 * Try every number from:
 *
 *      start → 9
 *
 * Add it to the current combination and
 * recursively explore the remaining possibilities.
 *
 * After recursion we backtrack by removing
 * the last added number.
 *
 * ------------------------------------------------------------
 * DRY RUN:
 *
 * k = 3
 * n = 9
 *
 * Start with:
 *
 * []
 *
 * Try:
 *
 * [1] → remaining sum = 8
 * [1,2] → remaining sum = 6
 * [1,2,6] → valid
 *
 * Continue exploring all possibilities.
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 *      O(9 choose k)
 *
 * Space Complexity:
 *      O(k) recursion depth
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * Classic backtracking problem similar to:
 *
 *      • Combination Sum
 *      • Subsets
 *      • Permutations
 */

class Solution {
private:

    void backtrack(int start,
                   int k,
                   int n,
                   vector<int> &curr,
                   vector<vector<int>> &ans) {

        if(k == 0 && n == 0) {
            ans.push_back(curr);
            return;
        }

        if(k == 0 || n < 0)
            return;

        for(int i = start; i <= 9; i++) {

            curr.push_back(i);

            backtrack(i + 1,
                      k - 1,
                      n - i,
                      curr,
                      ans);

            curr.pop_back(); // backtrack
        }
    }

public:

    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<int>> ans;
        vector<int> curr;

        backtrack(1, k, n, curr, ans);

        return ans;
    }
};

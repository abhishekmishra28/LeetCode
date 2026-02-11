/*
 * Problem: 77. Combinations
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given two integers n and k,
 * return all possible combinations of k numbers chosen
 * from the range [1, n].
 *
 * You may return the answer in any order.
 *
 * ------------------------------------------------------------
 * APPROACH: Backtracking (Combination Generation)
 *
 * ------------------------------------------------------------
 * KEY OBSERVATIONS:
 *
 * 1️⃣ We must choose exactly k numbers from 1 to n.
 *
 * 2️⃣ Order does NOT matter in combinations.
 *    [1,2] and [2,1] are the same combination.
 *
 * 3️⃣ To avoid duplicates:
 *    - Always move forward in the number range.
 *
 * ------------------------------------------------------------
 * STRATEGY:
 *
 * - Use backtracking
 * - At each step:
 *   → Pick a number from current start to n
 *   → Recurse with next start = i + 1
 * - Stop when current combination size == k
 *
 * ------------------------------------------------------------
 * RECURSIVE FUNCTION PARAMETERS:
 *
 * helper(start, n, k, ans, curr)
 *
 * start → next number we are allowed to pick
 * n     → upper limit
 * k     → required size
 * ans   → stores final combinations
 * curr  → current combination being built
 *
 * ------------------------------------------------------------
 * BASE CASE:
 *
 * If curr.size() == k:
 * → Valid combination formed
 * → Add to answer
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * n = 4, k = 2
 *
 * Output:
 * [1,2]
 * [1,3]
 * [1,4]
 * [2,3]
 * [2,4]
 * [3,4]
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 * - O(C(n, k))
 *   (Total combinations generated)
 *
 * Space Complexity:
 * - O(k) recursion stack
 * - O(C(n, k)) to store results
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - Classic backtracking problem
 * - Forward-only selection prevents duplicates
 * - Can be optimized with pruning:
 *   Loop upper bound can be:
 *   i <= n - (k - curr.size()) + 1
 */

class Solution {
private:
    void helper(int start,
                int n,
                int k,
                vector<vector<int>>& ans,
                vector<int>& curr) {

        // Base case: combination of size k formed
        if (curr.size() == k) {
            ans.push_back(curr);
            return;
        }

        // Try all possible next numbers
        for (int i = start; i <= n; i++) {

            // Choose number i
            curr.push_back(i);

            // Recurse with next start
            helper(i + 1, n, k, ans, curr);

            // Backtrack
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>> ans;
        vector<int> curr;

        // Start from 1
        helper(1, n, k, ans, curr);

        return ans;
    }
};

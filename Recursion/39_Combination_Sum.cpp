/*
 * Problem: 39. Combination Sum
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given an array of distinct integers `candidates`
 * and an integer `target`,
 * return all unique combinations of candidates where
 * the chosen numbers sum to `target`.
 *
 * You may use the SAME element unlimited times.
 *
 * The solution set must not contain duplicate combinations.
 *
 * ------------------------------------------------------------
 * APPROACH: Backtracking (Pick / Not-Pick Strategy)
 *
 * ------------------------------------------------------------
 * KEY OBSERVATIONS:
 *
 * 1️⃣ We can use the same element multiple times.
 *
 * 2️⃣ Order does NOT matter in combinations.
 *    [2,3] and [3,2] are the same.
 *
 * 3️⃣ To avoid duplicates:
 *    - We never go backwards.
 *    - Once we move to next index, we don't revisit previous ones.
 *
 * ------------------------------------------------------------
 * STRATEGY:
 *
 * At index i, we have TWO choices:
 *
 * 1️⃣ PICK the element:
 *    - Only if candidates[i] <= target
 *    - Reduce target
 *    - Stay at same index (since unlimited reuse allowed)
 *
 * 2️⃣ NOT PICK:
 *    - Move to next index (i + 1)
 *
 * ------------------------------------------------------------
 * RECURSIVE FUNCTION PARAMETERS:
 *
 * findCombination(i, target, candidates, ans, ds)
 *
 * i           → current index
 * target      → remaining sum
 * candidates  → input array
 * ans         → stores valid combinations
 * ds          → current combination
 *
 * ------------------------------------------------------------
 * BASE CASE:
 *
 * If i == candidates.size():
 *    - If target == 0 → valid combination → store
 *    - Else → discard
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * candidates = [2,3,6,7]
 * target = 7
 *
 * Possible combinations:
 * [2,2,3]
 * [7]
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 * - Exponential (backtracking)
 * - Roughly O(2^n) in worst case
 *
 * Space Complexity:
 * - O(target) recursion depth
 * - O(k) for storing current combination
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - Classic backtracking problem
 * - Key trick: stay at same index after picking
 * - Very common variation in coding interviews
 */

class Solution {
public:
    void findCombination(int i,
                         int target,
                         vector<int>& candidates,
                         vector<vector<int>>& ans,
                         vector<int>& ds) {

        // Base case: reached end of array
        if (i == candidates.size()) {
            if (target == 0) {
                ans.push_back(ds);
            }
            return;
        }

        // PICK the current element (if possible)
        if (candidates[i] <= target) {

            ds.push_back(candidates[i]);

            // Stay at same index (unlimited usage allowed)
            findCombination(i,
                            target - candidates[i],
                            candidates,
                            ans,
                            ds);

            // Backtrack
            ds.pop_back();
        }

        // NOT PICK the current element
        findCombination(i + 1,
                        target,
                        candidates,
                        ans,
                        ds);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates,
                                       int target) {

        vector<vector<int>> ans;
        vector<int> ds;

        findCombination(0, target, candidates, ans, ds);

        return ans;
    }
};

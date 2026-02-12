/*
 * Problem: 40. Combination Sum II
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given a collection of candidate numbers (candidates)
 * and a target number (target),
 * return all unique combinations in candidates where
 * the candidate numbers sum to target.
 *
 * Each number may be used AT MOST ONCE.
 *
 * The solution set must NOT contain duplicate combinations.
 *
 * ------------------------------------------------------------
 * APPROACH: Backtracking + Sorting + Pruning
 *
 * ------------------------------------------------------------
 * KEY DIFFERENCE FROM Combination Sum I:
 *
 * 1️⃣ Each element can be used ONLY ONCE.
 * 2️⃣ Input may contain duplicates.
 * 3️⃣ We must avoid duplicate combinations.
 *
 * ------------------------------------------------------------
 * KEY OBSERVATIONS:
 *
 * 1️⃣ Sorting is mandatory:
 *    - Groups duplicates together
 *    - Enables skipping duplicates
 *    - Allows early pruning
 *
 * 2️⃣ Duplicate Skipping Logic:
 *
 *    if (i > start && candidates[i] == candidates[i - 1])
 *        continue;
 *
 *    Meaning:
 *    - If same number appears again at same recursion level,
 *      skip it to avoid duplicate combinations.
 *
 * 3️⃣ Early Pruning:
 *
 *    if (candidates[i] > target)
 *        break;
 *
 *    Since array is sorted, no need to check further.
 *
 * ------------------------------------------------------------
 * STRATEGY:
 *
 * - Sort the array
 * - Use backtracking
 * - At each step:
 *   → Pick current element
 *   → Move to next index (i + 1) since reuse not allowed
 *   → Reduce target
 *
 * ------------------------------------------------------------
 * RECURSIVE FUNCTION PARAMETERS:
 *
 * findCombination(start, target, candidates, ans, ds)
 *
 * start      → index from where selection is allowed
 * target     → remaining sum
 * candidates → sorted input array
 * ans        → stores valid combinations
 * ds         → current combination
 *
 * ------------------------------------------------------------
 * BASE CASE:
 *
 * If target == 0:
 * → Valid combination formed
 * → Add to answer
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * candidates = [10,1,2,7,6,1,5]
 * target = 8
 *
 * After sorting:
 * [1,1,2,5,6,7,10]
 *
 * Output:
 * [1,1,6]
 * [1,2,5]
 * [1,7]
 * [2,6]
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 * - Exponential in worst case (backtracking)
 *
 * Space Complexity:
 * - O(target) recursion depth
 * - O(k) for storing combination
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - Sorting + duplicate skipping is the key idea
 * - Early pruning improves performance significantly
 * - Very common interview problem
 */

class Solution {
public:
    void findCombination(int start,
                         int target,
                         vector<int>& candidates,
                         vector<vector<int>>& ans,
                         vector<int>& ds) {

        // Base case: valid combination found
        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        // Try picking elements starting from 'start'
        for (int i = start; i < candidates.size(); i++) {

            // Skip duplicates at the same recursion level
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            // Early pruning: stop if current element exceeds target
            if (candidates[i] > target)
                break;

            // Choose current element
            ds.push_back(candidates[i]);

            // Move to next index (each element can be used once)
            findCombination(i + 1,
                            target - candidates[i],
                            candidates,
                            ans,
                            ds);

            // Backtrack
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                        int target) {

        // Sort to handle duplicates and pruning
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> ds;

        findCombination(0, target, candidates, ans, ds);

        return ans;
    }
};

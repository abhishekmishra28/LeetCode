/*
 * Problem: 40. Combination Sum II
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given an array nums (may contain duplicates) and an integer target,
 * return all unique combinations where:
 *
 * - Each number is used AT MOST once.
 * - The chosen numbers sum to target.
 * - The solution set must not contain duplicate combinations.
 *
 * ------------------------------------------------------------
 * APPROACH: Backtracking + Sorting + Duplicate Skipping
 *
 * ------------------------------------------------------------
 * KEY DIFFERENCE FROM Combination Sum I:
 *
 * 1️⃣ Each element can be used only once.
 * 2️⃣ Input may contain duplicates.
 * 3️⃣ We must carefully skip duplicates to avoid repeated combinations.
 *
 * ------------------------------------------------------------
 * KEY OBSERVATIONS:
 *
 * 1️⃣ Sorting is mandatory.
 *    - Groups duplicates together.
 *    - Enables early pruning.
 *    - Makes duplicate skipping easy.
 *
 * 2️⃣ Duplicate Skipping Condition:
 *
 *    if (i > idx && nums[i] == nums[i - 1])
 *        continue;
 *
 *    Meaning:
 *    - If same number appears again at the same recursion level,
 *      skip it to prevent duplicate combinations.
 *
 * 3️⃣ Early Pruning:
 *
 *    if (nums[i] > target)
 *        break;
 *
 *    Since array is sorted, further elements will also exceed target.
 *
 * ------------------------------------------------------------
 * STRATEGY:
 *
 * backtrack(idx, nums, target, curr, result)
 *
 * idx    → starting index for selection
 * target → remaining sum
 * curr   → current combination
 * result → stores valid combinations
 *
 * ------------------------------------------------------------
 * BASE CASE:
 *
 * If target == 0:
 * → Valid combination found
 * → Add to result
 *
 * ------------------------------------------------------------
 * RECURSION FLOW:
 *
 * For each index i from idx to n-1:
 *
 *   1️⃣ Skip duplicates at same level
 *   2️⃣ Stop if nums[i] > target
 *   3️⃣ Choose nums[i]
 *   4️⃣ Recurse with i + 1 (since reuse not allowed)
 *   5️⃣ Backtrack
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * nums = [10,1,2,7,6,1,5]
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
 * - Exponential (backtracking)
 *
 * Space Complexity:
 * - O(target) recursion depth (worst case)
 * - O(k) for storing current combination
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - Sorting + duplicate skipping is the core trick
 * - Early pruning significantly reduces recursion
 * - Very common backtracking interview problem
 */

class Solution {
private:
    void backtrack(int idx,
                   vector<int>& nums,
                   int target,
                   vector<int>& curr,
                   vector<vector<int>>& result) {

        // Valid combination found
        if (target == 0) {
            result.push_back(curr);
            return;
        }

        // Explore choices starting from idx
        for (int i = idx; i < nums.size(); i++) {

            // Skip duplicates at the same recursion level
            if (i > idx && nums[i] == nums[i - 1])
                continue;

            // Early pruning
            if (nums[i] > target)
                break;

            // Choose current element
            curr.push_back(nums[i]);

            // Move to next index (no reuse allowed)
            backtrack(i + 1,
                      nums,
                      target - nums[i],
                      curr,
                      result);

            // Backtrack
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& nums,
                                        int target) {

        // Sort to handle duplicates and pruning
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        vector<int> curr;

        backtrack(0, nums, target, curr, result);

        return result;
    }
};

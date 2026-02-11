/*
 * Problem: 46. Permutations
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given an array nums of distinct integers,
 * return all possible permutations.
 *
 * You may return the answer in any order.
 *
 * ------------------------------------------------------------
 * APPROACH: Backtracking (Swap-Based Permutation Generation)
 *
 * ------------------------------------------------------------
 * KEY OBSERVATIONS:
 *
 * 1️⃣ A permutation means arranging elements in all possible orders.
 *
 * 2️⃣ At index `idx`, we can choose any element from
 *    idx → n-1 to place at position `idx`.
 *
 * 3️⃣ After fixing one element at position `idx`,
 *    we recursively permute the remaining elements.
 *
 * 4️⃣ Swapping allows in-place generation
 *    → no extra visited array needed.
 *
 * ------------------------------------------------------------
 * STRATEGY:
 *
 * - Fix one position at a time
 * - Swap current index with all possible choices
 * - Recurse for next index
 * - Backtrack (swap back) to restore original state
 *
 * ------------------------------------------------------------
 * RECURSION TREE IDEA:
 *
 * For nums = [1,2,3]
 *
 * idx = 0:
 *   swap(0,0) → [1,2,3]
 *   swap(0,1) → [2,1,3]
 *   swap(0,2) → [3,2,1]
 *
 * Each branch recursively permutes remaining elements.
 *
 * ------------------------------------------------------------
 * BASE CASE:
 *
 * If idx == nums.size():
 * → One full permutation is formed
 * → Push into answer
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * nums = [1,2]
 *
 * idx = 0:
 *   swap(0,0) → [1,2]
 *     idx = 1:
 *       swap(1,1) → [1,2]
 *       → push
 *
 *   swap(0,1) → [2,1]
 *     idx = 1:
 *       swap(1,1) → [2,1]
 *       → push
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 * - O(n!)
 *   (Total permutations)
 *
 * Space Complexity:
 * - O(n) recursion stack
 * - O(n!) for storing results
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - Swap-based approach is memory efficient
 * - No extra visited array required
 * - Very common backtracking pattern
 */

class Solution {
private:
    void backtrack(int idx,
                   vector<int>& nums,
                   vector<vector<int>>& ans) {

        // Base case: one permutation formed
        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }

        // Try placing every element at position idx
        for (int i = idx; i < nums.size(); i++) {

            // Choose element for current position
            swap(nums[i], nums[idx]);

            // Recurse for next index
            backtrack(idx + 1, nums, ans);

            // Backtrack: restore original order
            swap(nums[i], nums[idx]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;

        // Start permutation generation from index 0
        backtrack(0, nums, ans);

        return ans;
    }
};

/*
 * Problem: 47. Permutations II
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given a collection of numbers nums, that might contain duplicates,
 * return all possible unique permutations.
 *
 * You may return the answer in any order.
 *
 * ------------------------------------------------------------
 * APPROACH: Backtracking (Swap-Based) + Duplicate Pruning
 *
 * ------------------------------------------------------------
 * KEY OBSERVATIONS:
 *
 * 1️⃣ This is similar to the classic Permutations problem,
 *    but nums may contain duplicate elements.
 *
 * 2️⃣ If we generate permutations normally,
 *    duplicate permutations will appear.
 *
 * 3️⃣ To avoid duplicates:
 *    - At each recursion level (fixed index),
 *      do not place the same value twice.
 *
 * ------------------------------------------------------------
 * CORE IDEA:
 *
 * At index `idx`, we try placing every element from
 * idx → n-1 at position `idx`.
 *
 * But before swapping:
 *   - Check whether the same value has already been used
 *     in this position during this recursion level.
 *
 * ------------------------------------------------------------
 * DUPLICATE CHECK LOGIC:
 *
 * bool alreadyUsed = false;
 * for (int j = idx; j < i; j++)
 *     if (nums[j] == nums[i])
 *         alreadyUsed = true;
 *
 * Meaning:
 * - If the same value already appeared between idx and i-1,
 *   skip it to prevent duplicate permutations.
 *
 * ------------------------------------------------------------
 * WHY SORTING?
 *
 * Sorting groups duplicates together.
 * Though this implementation uses manual checking,
 * sorting ensures consistent ordering and correctness.
 *
 * ------------------------------------------------------------
 * BASE CASE:
 *
 * If idx == nums.size():
 * → A complete permutation is formed
 * → Add it to answer
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * nums = [1,1,2]
 *
 * idx = 0:
 *   i = 0 → use first 1
 *   i = 1 → skip (duplicate 1 already used at this level)
 *   i = 2 → use 2
 *
 * Final unique permutations:
 * [1,1,2]
 * [1,2,1]
 * [2,1,1]
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 * - O(n! * n)
 *   (Permutation generation + duplicate checking)
 *
 * Space Complexity:
 * - O(n) recursion stack
 * - O(n!) for storing results
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - Very common backtracking variation
 * - Key insight: avoid using same value twice at same depth
 * - Swap-based method avoids extra visited array
 */

class Solution {
private:
    void helper(int idx,
                vector<int>& nums,
                vector<vector<int>>& ans) {

        // Base case: full permutation formed
        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }

        // Try placing elements at position idx
        for (int i = idx; i < nums.size(); i++) {

            // Check if this value was already used at this level
            bool alreadyUsed = false;
            for (int j = idx; j < i; j++) {
                if (nums[j] == nums[i]) {
                    alreadyUsed = true;
                    break;
                }
            }

            if (alreadyUsed)
                continue;

            // Choose element
            swap(nums[i], nums[idx]);

            // Recurse for next position
            helper(idx + 1, nums, ans);

            // Backtrack
            swap(nums[i], nums[idx]);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        // Sorting helps maintain consistent ordering
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        helper(0, nums, ans);

        return ans;
    }
};

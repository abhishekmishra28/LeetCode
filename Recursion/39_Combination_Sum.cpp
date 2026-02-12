/*
 * Problem: Combination Sum (Unbounded Version – Pick / Not Pick Style)
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given an array of integers nums and an integer k (target),
 * return all possible combinations where:
 *
 * - The chosen numbers sum to k
 * - Each number may be used unlimited times
 *
 * The solution set must not contain duplicate combinations.
 *
 * ------------------------------------------------------------
 * APPROACH: Backtracking (Pick / Skip Strategy)
 *
 * ------------------------------------------------------------
 * KEY OBSERVATIONS:
 *
 * 1️⃣ We can reuse the same element multiple times.
 *
 * 2️⃣ At every index i, we have TWO choices:
 *    - Take nums[i]
 *    - Skip nums[i]
 *
 * 3️⃣ If we take the element:
 *    - Reduce target by nums[i]
 *    - Stay at same index (since reuse allowed)
 *
 * 4️⃣ If we skip:
 *    - Move to next index
 *
 * ------------------------------------------------------------
 * STRATEGY:
 *
 * Recursive function:
 *
 * combSum(i, nums, k, comb, ans)
 *
 * i    → current index
 * k    → remaining target
 * comb → current combination
 * ans  → stores final results
 *
 * ------------------------------------------------------------
 * BASE CASES:
 *
 * 1️⃣ If k == 0:
 *    → Valid combination found
 *    → Add to answer
 *
 * 2️⃣ If i == nums.size() OR k < 0:
 *    → No valid solution from here
 *    → Return
 *
 * ------------------------------------------------------------
 * RECURSION TREE IDEA:
 *
 * At each step:
 *
 *         (i, k)
 *        /       \
 *   Take nums[i]   Skip nums[i]
 *     (i, k-x)      (i+1, k)
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * nums = [2,3]
 * k = 6
 *
 * Possible combinations:
 * [2,2,2]
 * [3,3]
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 * - Exponential (backtracking)
 *
 * Space Complexity:
 * - O(k) recursion depth (in worst case)
 * - O(k) for current combination storage
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - Classic pick / not-pick recursion pattern
 * - Staying at same index enables unlimited reuse
 * - Often asked as base version before introducing duplicates
 */

class Solution {
private:
    void combSum(int i,
                 vector<int>& nums,
                 int k,
                 vector<int>& comb,
                 vector<vector<int>>& ans) {

        // Valid combination found
        if (k == 0) {
            ans.push_back(comb);
            return;
        }

        // Out of bounds or negative target
        if (i == nums.size() || k < 0)
            return;

        // TAKE current element (stay at same index)
        comb.push_back(nums[i]);
        combSum(i, nums, k - nums[i], comb, ans);
        comb.pop_back();

        // SKIP current element
        combSum(i + 1, nums, k, comb, ans);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int k) {

        vector<vector<int>> ans;
        vector<int> comb;

        combSum(0, nums, k, comb, ans);

        return ans;
    }
};

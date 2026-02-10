/*
 * Problem: 90. Subsets II
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given an integer array nums that may contain duplicates,
 * return all possible subsets (the power set).
 *
 * The solution set must NOT contain duplicate subsets.
 * You may return the solution in any order.
 *
 * ------------------------------------------------------------
 * APPROACH: Backtracking + Sorting
 *
 * ------------------------------------------------------------
 * KEY OBSERVATIONS:
 *
 * 1️⃣ This is similar to the classic Subsets problem,
 *    BUT duplicates are allowed in the input.
 *
 * 2️⃣ To avoid duplicate subsets:
 *    - We must ensure the same number at the same recursive level
 *      is not chosen more than once.
 *
 * 3️⃣ Sorting is essential.
 *    - It groups equal elements together
 *    - Makes it easy to skip duplicates
 *
 * ------------------------------------------------------------
 * STRATEGY:
 *
 * - Sort the input array
 * - Use backtracking to generate subsets
 * - Skip duplicate elements at the same recursion level
 *
 * ------------------------------------------------------------
 * DUPLICATE SKIPPING LOGIC:
 *
 * if (i != start && nums[i] == nums[i - 1]) continue;
 *
 * Meaning:
 * - If current element is the same as the previous one
 * - AND we are at the same recursion level
 * - Then skip it to avoid duplicate subsets
 *
 * ------------------------------------------------------------
 * RECURSIVE FUNCTION PARAMETERS:
 *
 * backtrack(start, nums, curr, ans)
 *
 * start → index from where elements can be picked
 * nums  → sorted input array
 * curr  → current subset
 * ans   → stores all unique subsets
 *
 * ------------------------------------------------------------
 * ALGORITHM STEPS:
 *
 * 1️⃣ Sort nums
 * 2️⃣ Start backtracking from index 0
 * 3️⃣ Add current subset to answer
 * 4️⃣ Loop from index = start to n-1:
 *    - Skip duplicates at same recursion level
 *    - Pick nums[i]
 *    - Recurse with i + 1
 *    - Backtrack by removing last element
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * nums = [1, 2, 2]
 *
 * Subsets generated:
 * []
 * [1]
 * [1, 2]
 * [1, 2, 2]
 * [2]
 * [2, 2]
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 * - O(2^n)
 *   (All possible subsets)
 *
 * Space Complexity:
 * - O(n) recursion stack
 * - O(2^n) to store subsets
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - Sorting is mandatory to handle duplicates
 * - The skip condition is the key insight
 * - Very common backtracking interview problem
 */

class Solution {
public:
    void backtrack(int start,
                   vector<int>& nums,
                   vector<int>& curr,
                   vector<vector<int>>& ans) {

        // Current subset is valid → add to answer
        ans.push_back(curr);

        // Try picking elements starting from index 'start'
        for (int i = start; i < nums.size(); i++) {

            // Skip duplicates at the same recursion level
            if (i != start && nums[i] == nums[i - 1])
                continue;

            // Choose current element
            curr.push_back(nums[i]);

            // Recurse for the next index
            backtrack(i + 1, nums, curr, ans);

            // Backtrack: remove last element
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        // Sort to group duplicates together
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> curr;

        // Start backtracking
        backtrack(0, nums, curr, ans);

        return ans;
    }
};

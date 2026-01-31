/*
 * Problem: 113. Path Sum II
 *
 * Statement:
 * Given the root of a binary tree and an integer `targetSum`,
 * return ALL root-to-leaf paths where the sum of the node values
 * in the path equals `targetSum`.
 *
 * A path:
 * - Starts at the root
 * - Ends at a LEAF node
 * - Goes only downward (parent → child)
 *
 * ------------------------------------------------------------
 * APPROACH: DFS + Backtracking — Your Approach
 *
 * Core Idea:
 *
 * - Explore all root-to-leaf paths using DFS
 * - Maintain:
 *     • `path`  → current path from root to current node
 *     • `targetSum` → remaining sum needed
 *
 * - When we reach a leaf:
 *     • If remaining sum == 0 → valid path found
 *
 * ------------------------------------------------------------
 * Why DFS + Backtracking?
 *
 * - DFS naturally explores root-to-leaf paths
 * - Backtracking allows us to:
 *     • Try all possibilities
 *     • Revert changes when returning from recursion
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. Use a helper DFS function:
 *
 *      dfs(node, targetSum, path)
 *
 * 2. Base Case:
 *      If node == nullptr:
 *          → return
 *
 * 3. Include current node in path:
 *
 *      path.push_back(node->val)
 *      targetSum -= node->val
 *
 * 4. Check leaf condition:
 *
 *      If node is a LEAF
 *      AND targetSum == 0:
 *          → store `path` in result
 *
 * 5. Recurse on children:
 *
 *      dfs(node->left,  targetSum, path)
 *      dfs(node->right, targetSum, path)
 *
 * 6. Backtrack:
 *
 *      path.pop_back()
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Each DFS call represents a unique path prefix
 * - `targetSum` tracks remaining required sum
 * - Backtracking ensures path correctness when returning
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * Tree:
 *          5
 *         / \
 *        4   8
 *       /   / \
 *      11  13  4
 *     /  \      \
 *    7    2      1
 *
 * targetSum = 22
 *
 * Valid Paths:
 *   [5, 4, 11, 2]
 *   [5, 8, 4, 5]   (if present)
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Empty tree → return empty list
 * - No valid path → return empty list
 * - Single-node tree equal to targetSum
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - O(n)
 *   Every node is visited once
 *
 * (In worst case, copying path takes O(h) per valid path)
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(h)
 *   Recursion stack + path vector
 *   (h = height of tree)
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Root-to-Leaf DFS + Backtracking"
 *
 * Seen in:
 * - Combination generation
 * - Tree path problems
 * - Constraint-based DFS
 */

class Solution {
private:
    vector<vector<int>> result;

    void dfs(TreeNode* node, int targetSum, vector<int> &path) {
        if (!node) return;

        path.push_back(node->val);
        targetSum -= node->val;

        if (!node->left && !node->right && targetSum == 0)
            result.push_back(path);

        dfs(node->left,  targetSum, path);
        dfs(node->right, targetSum, path);

        // backtrack
        path.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfs(root, targetSum, path);
        return result;
    }
};

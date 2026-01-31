/*
 * Problem: 1026. Maximum Difference Between Node and Ancestor
 *
 * Statement:
 * Given the root of a binary tree, find the maximum value:
 *
 *      |ancestor.val - node.val|
 *
 * where `ancestor` is any ancestor of `node`
 * (a node can be an ancestor of itself).
 *
 * ------------------------------------------------------------
 * APPROACH: DFS with Path Min / Max Tracking — Your Approach
 *
 * Core Idea:
 *
 * - While traversing from root to leaves,
 *   keep track of:
 *       • maximum value seen so far on the path
 *       • minimum value seen so far on the path
 *
 * - At each node:
 *       The maximum possible difference involving this node
 *       is simply:
 *
 *           current_max - current_min
 *
 * - Update the global answer using this value
 *
 * ------------------------------------------------------------
 * Why DFS?
 *
 * - DFS naturally explores all root-to-node paths
 * - Each recursion carries path-specific information (min & max)
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. Maintain a global variable:
 *
 *      ans → stores the maximum difference found so far
 *
 * 2. Define DFS function:
 *
 *      dfs(node, maxi, mini)
 *
 *      where:
 *          maxi = maximum value on current root-to-node path
 *          mini = minimum value on current root-to-node path
 *
 * 3. Base Case:
 *
 *      If node == nullptr:
 *          → return
 *
 * 4. Update path extremes:
 *
 *      maxi = max(maxi, node->val)
 *      mini = min(mini, node->val)
 *
 * 5. Update answer:
 *
 *      ans = max(ans, maxi - mini)
 *
 * 6. Recurse on children:
 *
 *      dfs(node->left,  maxi, mini)
 *      dfs(node->right, maxi, mini)
 *
 * 7. Initial Call:
 *
 *      dfs(root, INT_MIN, INT_MAX)
 *
 * 8. Return ans
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - For any node, the largest ancestor difference
 *   must involve either:
 *       • the maximum ancestor value
 *       • or the minimum ancestor value
 *
 * - Tracking only min & max is sufficient
 * - No need to compare with every ancestor individually
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * Tree:
 *          8
 *         / \
 *        3  10
 *       / \   \
 *      1   6   14
 *
 * Path: 8 → 3 → 1
 *   min = 1, max = 8
 *   diff = 7
 *
 * Path: 8 → 10 → 14
 *   min = 8, max = 14
 *   diff = 6
 *
 * Answer = 7
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Single node → answer = 0
 * - Skewed tree → handled naturally
 * - Large value differences → safe with int range
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - O(n)
 *   Each node is visited exactly once
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(h)
 *   Recursion stack (h = height of tree)
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "DFS with State Propagation"
 *
 * Seen in:
 * - Path-based tree problems
 * - Min/Max tracking
 * - Ancestor-descendant relationship problems
 */

class Solution {
private:
    int ans = 0;

public:
    void dfs(TreeNode* node, int maxi, int mini) {
        if (!node) return;

        // update path extremes
        maxi = max(maxi, node->val);
        mini = min(mini, node->val);

        // update answer
        ans = max(ans, maxi - mini);

        dfs(node->left,  maxi, mini);
        dfs(node->right, maxi, mini);
    }

    int maxAncestorDiff(TreeNode* root) {
        dfs(root, INT_MIN, INT_MAX);
        return ans;
    }
};

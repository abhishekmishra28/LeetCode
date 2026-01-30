/*
 * Problem: 814. Binary Tree Pruning
 *
 * Statement:
 * Given the root of a binary tree, remove every subtree
 * that does NOT contain a node with value 1.
 *
 * Return the pruned tree’s root.
 *
 * ------------------------------------------------------------
 * APPROACH: Postorder DFS (Bottom-Up Pruning) — Your Approach
 *
 * Core Idea:
 *
 * - A node should be REMOVED if:
 *     • its value is 0
 *     • AND both its left and right subtrees are NULL
 *
 * - To know whether a subtree contains a `1`,
 *   we MUST process children FIRST.
 *
 * → This makes POSTORDER traversal the perfect choice.
 *
 * ------------------------------------------------------------
 * Why Postorder?
 *
 * - Children decide whether the parent survives
 * - If both children are pruned away and value is 0,
 *   the current node must also be pruned
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. Base Case:
 *      If root == nullptr:
 *          → return nullptr
 *
 * 2. Recursively prune left and right subtrees:
 *
 *      root->left  = pruneTree(root->left)
 *      root->right = pruneTree(root->right)
 *
 * 3. Decide whether to keep or delete current node:
 *
 *      If:
 *        root->val == 0
 *        AND root->left == nullptr
 *        AND root->right == nullptr
 *
 *      → return nullptr   // prune this node
 *
 * 4. Otherwise:
 *      → return root      // keep this node
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Any subtree containing at least one `1`
 *   will survive upward
 *
 * - Subtrees containing only `0`s collapse bottom-up
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * Tree:
 *        1
 *       / \
 *      0   1
 *     / \
 *    0   0
 *
 * - Leaves with 0 → pruned
 * - Parent 0 with no children → pruned
 * - Node 1 survives
 *
 * Result:
 *        1
 *         \
 *          1
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Entire tree contains only 0 → return nullptr
 * - Single node with value 1 → unchanged
 * - Single node with value 0 → pruned
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - O(n)
 *   Each node visited once
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
 *   "Tree Pruning using Postorder DFS"
 *
 * Seen in:
 * - Conditional deletion in trees
 * - Tree cleanup problems
 * - Bottom-up recursion patterns
 */

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (!root) return nullptr;

        root->left  = pruneTree(root->left);
        root->right = pruneTree(root->right);

        if (root->val == 0 && !root->left && !root->right)
            return nullptr;

        return root;
    }
};

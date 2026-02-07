/*
 * Problem: 235. Lowest Common Ancestor of a Binary Search Tree
 *
 * Statement:
 * Given a Binary Search Tree (BST), find the lowest common ancestor (LCA)
 * of two given nodes p and q.
 *
 * The LCA is defined as the lowest node in the tree that has both p and q
 * as descendants (where we allow a node to be a descendant of itself).
 *
 * ------------------------------------------------------------
 * APPROACH: Iterative BST Property Exploitation (Your Approach)
 *
 * Core Idea:
 *
 * - A Binary Search Tree has the property:
 *     • Left subtree  → values < root
 *     • Right subtree → values > root
 *
 * - Using this property, we can decide in which direction to move
 *   without exploring the entire tree.
 *
 * ------------------------------------------------------------
 * Key Observations:
 *
 * 1. If both p and q are greater than root:
 *      → LCA lies in the RIGHT subtree
 *
 * 2. If both p and q are smaller than root:
 *      → LCA lies in the LEFT subtree
 *
 * 3. Otherwise:
 *      → root is the SPLIT point → LCA found
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - The first node where paths to p and q diverge
 *   is the lowest common ancestor
 *
 * ------------------------------------------------------------
 * Algorithm Steps:
 *
 * Start from root:
 *
 * While root is not null:
 *
 *   1. If p->val > root->val AND q->val > root->val:
 *         Move to root->right
 *
 *   2. Else if p->val < root->val AND q->val < root->val:
 *         Move to root->left
 *
 *   3. Else:
 *         Current root is the LCA → return it
 *
 * If traversal ends, return nullptr
 *
 * ------------------------------------------------------------
 * Example:
 *
 * BST:
 *        6
 *       / \
 *      2   8
 *     / \ / \
 *    0  4 7  9
 *
 * p = 2, q = 8
 *
 * - 2 < 6 and 8 > 6 → split occurs → LCA = 6
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - One node is ancestor of the other
 * - p or q is the root itself
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - O(h)
 *   where h is the height of the BST
 *
 *   Best Case: O(log n) (balanced BST)
 *   Worst Case: O(n) (skewed BST)
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(1)
 *   No recursion or extra memory used
 *
 * ------------------------------------------------------------
 * Comparison with Binary Tree LCA:
 *
 * - Binary Tree LCA → DFS → O(n)
 * - BST LCA → Directional search → O(h)
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * - BST property based navigation
 * - Iterative traversal
 * - Lowest split point logic
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            if (p->val > root->val && q->val > root->val) {
                root = root->right;
            } else if (p->val < root->val && q->val < root->val) {
                root = root->left;
            } else {
                // This is the split point
                return root;
            }
        }
        return nullptr;
    }
};

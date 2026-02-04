/*
 * Problem: 700. Search in a Binary Search Tree
 *
 * Statement:
 * You are given the root of a Binary Search Tree (BST) and an integer `val`.
 * Return the subtree rooted at the node whose value equals `val`.
 * If such a node does not exist, return nullptr.
 *
 * ------------------------------------------------------------
 * APPROACH: Recursive Search using BST Property
 *
 * Core Observation:
 *
 * A Binary Search Tree follows a strict ordering rule:
 *
 *   • All values in LEFT subtree  < root->val
 *   • All values in RIGHT subtree > root->val
 *
 * This property allows us to decide the search direction
 * at every node instead of traversing the entire tree.
 *
 * ------------------------------------------------------------
 * Recursive Logic Breakdown:
 *
 * searchBST(root, val)
 *
 * 1. Base Case:
 *
 *    If root == nullptr
 *      → Tree exhausted, value not found
 *      → return nullptr
 *
 * 2. If root->val == val
 *
 *      → Target node found
 *      → return current root
 *
 * 3. If val < root->val
 *
 *      → Target must lie in LEFT subtree
 *      → Recur on root->left
 *
 * 4. Else (val > root->val)
 *
 *      → Target must lie in RIGHT subtree
 *      → Recur on root->right
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - At each step, we eliminate half of the remaining tree
 * - No unnecessary traversal
 * - Efficient due to BST ordering
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * BST:
 *           4
 *         /   \
 *        2     7
 *       / \
 *      1   3
 *
 * Search val = 3
 *
 * Step 1: root = 4
 *   3 < 4 → go left
 *
 * Step 2: root = 2
 *   3 > 2 → go right
 *
 * Step 3: root = 3
 *   3 == 3 → found → return this node
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Empty tree → return nullptr
 * - Value not present → return nullptr
 * - Root node matches → return root
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - O(h)
 *   where h is height of the tree
 *
 *   • Balanced BST → O(log n)
 *   • Skewed BST   → O(n)
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(h) due to recursion stack
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This problem uses:
 *   "Guided Tree Traversal using BST Properties"
 *
 * Similar problems:
 * - Insert into BST
 * - Delete from BST
 * - LCA in BST
 */

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {

        // Base case: tree exhausted
        if (!root) return nullptr;

        // Found the value
        if (val == root->val) return root;

        // Search left subtree
        if (val < root->val)
            return searchBST(root->left, val);

        // Search right subtree
        return searchBST(root->right, val);
    }
};

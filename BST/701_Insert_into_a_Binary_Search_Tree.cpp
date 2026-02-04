/*
 * Problem: 701. Insert into a Binary Search Tree
 *
 * Statement:
 * You are given the root of a Binary Search Tree (BST) and an integer `val`.
 * Insert `val` into the BST and return the root of the tree.
 *
 * It is guaranteed that:
 *   - `val` does NOT already exist in the BST
 *   - Multiple valid BSTs are acceptable after insertion
 *
 * ------------------------------------------------------------
 * APPROACH: Recursive BST Insertion (Top-Down) — Your Approach
 *
 * Core BST Property:
 *
 *   • All values in LEFT subtree  < root->val
 *   • All values in RIGHT subtree > root->val
 *
 * This property uniquely determines where the new value must go.
 *
 * ------------------------------------------------------------
 * Intuition:
 *
 * - Start from the root
 * - Compare `val` with current node
 * - Move left or right accordingly
 * - When you hit a NULL position → insert the new node there
 *
 * ------------------------------------------------------------
 * Recursive Logic Breakdown:
 *
 * insert(root, val)
 *
 * 1. Base Case:
 *
 *    If root == nullptr:
 *        → We have found the correct position
 *        → Create a new node with value `val`
 *        → Return this node
 *
 * 2. Recursive Cases:
 *
 *    If val < root->val:
 *        → Insert into LEFT subtree
 *
 *    Else (val > root->val):
 *        → Insert into RIGHT subtree
 *
 * 3. Return root:
 *    → Ensures tree links remain intact
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - BST ordering guides the traversal
 * - Only one path is followed from root to leaf
 * - Guaranteed no duplicates, so no conflict cases
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * Insert val = 5
 *
 * Initial BST:
 *           8
 *         /   \
 *        3     10
 *         \
 *          6
 *
 * Step-by-step:
 *
 * root = 8 → 5 < 8 → go left
 * root = 3 → 5 > 3 → go right
 * root = 6 → 5 < 6 → go left
 * root = nullptr → insert 5
 *
 * Final BST:
 *           8
 *         /   \
 *        3     10
 *         \
 *          6
 *         /
 *        5
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Empty tree → new node becomes root
 * - Insert value smaller than all nodes
 * - Insert value larger than all nodes
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - O(h)
 *   where h is the height of the BST
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
 * This is a classic:
 *   "BST Guided Recursion"
 *
 * Appears in:
 * - Search in BST
 * - Insert in BST
 * - Delete in BST
 */

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        // Base case: found insertion point
        if (!root)
            return new TreeNode(val);

        // Insert into left subtree
        if (val < root->val)
            root->left = insertIntoBST(root->left, val);

        // Insert into right subtree
        else
            root->right = insertIntoBST(root->right, val);

        return root;
    }
};

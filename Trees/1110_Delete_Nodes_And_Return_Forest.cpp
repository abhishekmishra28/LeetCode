/*
 * Problem: 1110. Delete Nodes And Return Forest
 *
 * Statement:
 * You are given the root of a binary tree and an array `to_delete`
 * containing distinct values of nodes to be deleted.
 *
 * After deleting all these nodes, return the ROOTS of the remaining
 * trees (the forest).
 *
 * ------------------------------------------------------------
 * APPROACH: Postorder DFS (Bottom-Up Deletion) — Your Approach
 *
 * Core Idea:
 *
 * - Use DFS in POSTORDER (left → right → root)
 * - Decide whether to delete the current node AFTER processing children
 * - If a node is deleted:
 *      • Its non-null children become new roots in the forest
 *
 * ------------------------------------------------------------
 * Why Postorder?
 *
 * - Children must be processed FIRST
 * - Because deleting a parent affects how children are handled
 *
 * ------------------------------------------------------------
 * Helper Function:
 *
 * delHelper(root, deleteSet, result)
 *
 * Returns:
 * - The current node if it should stay
 * - nullptr if it should be deleted
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. Base Case:
 *      If root == nullptr:
 *          → return nullptr
 *
 * 2. Recursively process children:
 *
 *      root->left  = delHelper(root->left,  st, result)
 *      root->right = delHelper(root->right, st, result)
 *
 * 3. Check if current node needs to be deleted:
 *
 *      If root->val exists in delete set:
 *
 *          a) If root->left is not null:
 *                → add root->left to result (new tree root)
 *
 *          b) If root->right is not null:
 *                → add root->right to result (new tree root)
 *
 *          c) Return nullptr (delete this node)
 *
 * 4. If current node is NOT deleted:
 *      → return root
 *
 * ------------------------------------------------------------
 * Main Function Logic:
 *
 * 1. Convert `to_delete` array into an unordered_set for O(1) lookup
 *
 * 2. Call delHelper(root, st, result)
 *
 * 3. After recursion:
 *
 *      If root itself was NOT deleted:
 *          → add root to result
 *
 * 4. Return result
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Postorder ensures children are already finalized
 * - Deleted nodes correctly split the tree
 * - Remaining subtrees are captured as new roots
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * Tree:
 *        1
 *       / \
 *      2   3
 *     /   / \
 *    4   5   6
 *
 * to_delete = [3]
 *
 * - Node 3 is deleted
 * - Its children (5 and 6) become new roots
 *
 * Result Forest Roots:
 *   [1, 5, 6]
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Root itself is deleted
 * - All nodes deleted → result empty
 * - No nodes deleted → result contains original root
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
 * - O(n)
 *   Recursion stack + delete set + result list
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Tree Modification using Postorder DFS"
 *
 * Seen in:
 * - Tree pruning problems
 * - Conditional deletion in trees
 * - Forest construction problems
 */

class Solution {
public:
    TreeNode* delHelper(TreeNode* root,
                        unordered_set<int> &st,
                        vector<TreeNode*> &result) {

        if (!root) return nullptr;

        root->left  = delHelper(root->left,  st, result);
        root->right = delHelper(root->right, st, result);

        if (st.count(root->val)) {
            if (root->left)  result.push_back(root->left);
            if (root->right) result.push_back(root->right);
            return nullptr;  // delete current node
        }

        return root; // keep node
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> result;
        unordered_set<int> st(to_delete.begin(), to_delete.end());

        root = delHelper(root, st, result);

        // If root itself is not deleted, add it to result
        if (root) result.push_back(root);

        return result;
    }
};

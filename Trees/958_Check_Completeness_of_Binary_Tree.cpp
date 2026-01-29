/*
 * Problem: 958. Check Completeness of a Binary Tree
 *
 * Statement:
 * Given the root of a binary tree, determine whether it is a
 * COMPLETE binary tree.
 *
 * A complete binary tree is defined as:
 * - All levels are completely filled except possibly the last level
 * - In the last level, nodes are filled from LEFT to RIGHT
 *
 * ------------------------------------------------------------
 * APPROACH: Level Order Traversal (BFS) — Your Approach
 *
 * Core Idea:
 *
 * - Perform a level-order traversal (BFS)
 * - Once a NULL node is encountered, all following nodes
 *   must also be NULL for the tree to be complete
 *
 * ------------------------------------------------------------
 * Key Observation:
 *
 * In a complete binary tree:
 * - After the first missing child (NULL),
 *   NO valid node should appear later in BFS order
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. If root is NULL:
 *      → Tree is trivially complete
 *
 * 2. Initialize:
 *      queue<TreeNode*> q
 *      bool seenNull = false
 *
 * 3. Push root into the queue
 *
 * 4. While queue is not empty:
 *
 *      a) Pop the front node
 *
 *      b) If node == NULL:
 *           → Mark seenNull = true
 *
 *      c) Else (node is not NULL):
 *
 *           If seenNull is already true:
 *               → A valid node appeared after NULL
 *               → Tree is NOT complete → return false
 *
 *           Push node->left into queue
 *           Push node->right into queue
 *
 * 5. If traversal finishes without violation:
 *      → Tree is complete → return true
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - BFS ensures nodes are checked level by level
 * - The moment a NULL appears, the tree must not have
 *   any further non-NULL nodes afterward
 *
 * ------------------------------------------------------------
 * Example (Valid Complete Tree):
 *
 *        1
 *       / \
 *      2   3
 *     / \  /
 *    4  5 6
 *
 * BFS order:
 * 1, 2, 3, 4, 5, 6, NULL, NULL, NULL...
 *
 * NULLs only appear at the end → VALID
 *
 * ------------------------------------------------------------
 * Example (Invalid Complete Tree):
 *
 *        1
 *       / \
 *      2   3
 *       \
 *        5
 *
 * BFS order:
 * 1, 2, 3, NULL, 5
 *
 * Non-NULL (5) after NULL → INVALID
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Empty tree → complete
 * - Single node → complete
 * - Missing left child but present right child → not complete
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - O(n)
 *   Each node is visited once
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(n)
 *   Queue storage in worst case
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Level Order Traversal with State Tracking"
 *
 * Seen in:
 * - Binary tree validation problems
 * - Heap property checks
 * - Tree structure verification
 */

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;

        queue<TreeNode*> q;
        q.push(root);

        bool seenNull = false;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node == nullptr) {
                seenNull = true;
            } else {
                if (seenNull) return false;
                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
    }
};

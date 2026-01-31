/*
 * Problem: 1609. Even Odd Tree
 *
 * Statement:
 * Given the root of a binary tree, determine whether it is an
 * EVEN-ODD TREE.
 *
 * Rules:
 *
 * - Level 0, 2, 4, ... (EVEN levels):
 *     • All node values must be ODD
 *     • Values must be STRICTLY INCREASING from left to right
 *
 * - Level 1, 3, 5, ... (ODD levels):
 *     • All node values must be EVEN
 *     • Values must be STRICTLY DECREASING from left to right
 *
 * ------------------------------------------------------------
 * APPROACH: Level Order Traversal (BFS) — Your Approach
 *
 * Core Idea:
 *
 * - Traverse the tree level by level using BFS
 * - For each level:
 *     • Check parity (odd / even) of node values
 *     • Check strict ordering using a `prev` variable
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. Edge Case:
 *      If root == NULL:
 *          → return true
 *
 * 2. Initialize:
 *      queue<TreeNode*> q
 *      q.push(root)
 *      level = 0
 *
 * 3. While queue is not empty:
 *
 *      a) Get number of nodes at current level:
 *           n = q.size()
 *
 *      b) Initialize `prev`:
 *
 *           If level is EVEN:
 *               prev = INT_MIN
 *           Else (level is ODD):
 *               prev = INT_MAX
 *
 *      c) Process all nodes at this level:
 *
 *           For each node:
 *
 *           EVEN LEVEL (level % 2 == 0):
 *               - node->val must be ODD
 *               - node->val must be > prev
 *
 *           ODD LEVEL (level % 2 == 1):
 *               - node->val must be EVEN
 *               - node->val must be < prev
 *
 *           If any rule is violated:
 *               → return false
 *
 *           Update:
 *               prev = node->val
 *
 *           Push children into queue
 *
 *      d) Increment level
 *
 * 4. If all levels satisfy conditions:
 *      → return true
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - BFS guarantees left-to-right order per level
 * - `prev` ensures strict ordering
 * - Level number decides parity and comparison logic
 *
 * ------------------------------------------------------------
 * Example (Valid Even-Odd Tree):
 *
 *            1
 *          /   \
 *         10    4
 *        / \   / \
 *       3  7  9  11
 *
 * Level 0 (even): [1]        → odd, increasing ✔
 * Level 1 (odd) : [10, 4]    → even, decreasing ✔
 * Level 2 (even): [3,7,9,11] → odd, increasing ✔
 *
 * ------------------------------------------------------------
 * Example (Invalid Case):
 *
 * Level 1 values: [4, 10]
 * - Not strictly decreasing → INVALID
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Single node → valid
 * - Wrong parity at any level → invalid
 * - Equal or unordered values → invalid
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
 * - O(n)
 *   Queue used for level-order traversal
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Level Order Traversal with Conditional Validation"
 *
 * Seen in:
 * - Tree level constraints
 * - BFS validation problems
 * - Structured binary tree checks
 */

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if (!root) return true;

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while (!q.empty()) {
            int n = q.size();
            int prev = (level % 2 == 0) ? INT_MIN : INT_MAX;

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (level % 2 == 0) {
                    // Even level: odd values, strictly increasing
                    if (node->val % 2 == 0 || node->val <= prev)
                        return false;
                } else {
                    // Odd level: even values, strictly decreasing
                    if (node->val % 2 == 1 || node->val >= prev)
                        return false;
                }

                prev = node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            level++;
        }
        return true;
    }
};

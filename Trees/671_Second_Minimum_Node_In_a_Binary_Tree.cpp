/*
 * Problem: 671. Second Minimum Node In a Binary Tree
 *
 * Statement:
 * You are given a special binary tree where:
 *
 *   - Every node has either 0 or 2 children
 *   - For every non-leaf node:
 *         node->val = min(node->left->val, node->right->val)
 *
 * Return the SECOND MINIMUM value among all node values in the tree.
 * If no such value exists, return -1.
 *
 * ------------------------------------------------------------
 * APPROACH: Level Order Traversal (BFS) — Your Approach
 *
 * Core Observation:
 *
 * - Because of the special property:
 *     • The ROOT always contains the MINIMUM value
 *     • Any value greater than root->val is a candidate
 *       for the second minimum
 *
 * - We need the smallest value STRICTLY GREATER than root->val
 *
 * ------------------------------------------------------------
 * High-Level Strategy:
 *
 * 1. Store root->val as the minimum value (minVal)
 * 2. Traverse the entire tree using BFS
 * 3. Track the smallest value > minVal
 * 4. If found, return it; otherwise return -1
 *
 * ------------------------------------------------------------
 * Variables Used:
 *
 * - minVal      → root->val (global minimum)
 * - secMinVal   → candidate for second minimum (initialized to INT_MAX)
 * - found       → indicates whether a valid second minimum exists
 *
 * ------------------------------------------------------------
 * Step-by-Step Explanation:
 *
 * STEP 1: Edge Case
 *
 *   If root is null → return -1
 *
 * STEP 2: Initialization
 *
 *   minVal = root->val
 *   secMinVal = INT_MAX
 *   found = false
 *
 * STEP 3: BFS Traversal
 *
 *   - Push root into queue
 *   - While queue is not empty:
 *
 *       • Pop current node
 *       • If it has children:
 *           - Push both children into queue
 *
 *           - If left->val != minVal:
 *                 secMinVal = min(secMinVal, left->val)
 *                 found = true
 *
 *           - If right->val != minVal:
 *                 secMinVal = min(secMinVal, right->val)
 *                 found = true
 *
 * STEP 4: Final Answer
 *
 *   - If found == true → return secMinVal
 *   - Else → return -1
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Root holds the smallest value by definition
 * - We only care about values strictly greater than root->val
 * - BFS ensures all nodes are checked
 * - Taking the minimum among valid candidates gives second minimum
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * Tree:
 *          2
 *        /   \
 *       2     5
 *            / \
 *           5   7
 *
 * minVal = 2
 *
 * BFS traversal:
 *   - left child = 2 → ignore
 *   - right child = 5 → candidate → secMinVal = 5
 *   - next level: 5, 7 → both > 2
 *       secMinVal remains 5
 *
 * Output = 5
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - All nodes have the same value → return -1
 * - Tree with only one unique value → return -1
 * - Root with no children → return -1
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - O(n)
 *   Every node is visited once
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(n)
 *   Queue used for BFS traversal
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a:
 *   "Tree Traversal + Conditional Minimum Tracking"
 *
 * Seen in:
 * - Second minimum / second largest problems
 * - Special property binary trees
 */

class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;

        queue<TreeNode*> q;
        q.push(root);

        int minVal = root->val;
        int secMinVal = INT_MAX;
        bool found = false;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left) {
                q.push(node->left);
                q.push(node->right);

                if (node->left->val != minVal) {
                    secMinVal = min(secMinVal, node->left->val);
                    found = true;
                }
                if (node->right->val != minVal) {
                    secMinVal = min(secMinVal, node->right->val);
                    found = true;
                }
            }
        }
        return found ? secMinVal : -1;
    }
};

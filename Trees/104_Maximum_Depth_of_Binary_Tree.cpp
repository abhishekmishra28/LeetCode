/*
 * Problem: 104. Maximum Depth of Binary Tree
 *
 * Statement:
 * You are given the root of a binary tree.
 * Your task is to find the MAXIMUM DEPTH (height) of the tree.
 *
 * Depth of a node:
 * - Number of nodes along the longest path
 *   from the root down to the farthest leaf node.
 *
 * ------------------------------------------------------------
 * APPROACH 1: DFS (Recursive) — Depth First Search
 *
 * Core Idea:
 * - The depth of a tree is:
 *     1 + max(depth of left subtree, depth of right subtree)
 *
 * - We recursively compute depth for left and right children
 * - The recursion naturally explores the tree depth-wise
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (DFS):
 *
 * 1. If root is NULL:
 *      → depth = 0
 *
 * 2. Recursively compute:
 *      leftDepth  = maxDepth(root->left)
 *      rightDepth = maxDepth(root->right)
 *
 * 3. Return:
 *      1 + max(leftDepth, rightDepth)
 *
 * ------------------------------------------------------------
 * Example:
 *
 *        3
 *       / \
 *      9  20
 *         / \
 *        15  7
 *
 * maxDepth(3):
 *   = 1 + max(1, 2)
 *   = 3
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n)
 *   Every node is visited once
 *
 * Space Complexity:
 * - O(h)
 *   h = height of tree (recursion stack)
 *   Worst case: O(n) for skewed tree
 *
 * ------------------------------------------------------------
 * APPROACH 2: BFS (Level Order Traversal) — Your Implemented Approach
 *
 * Core Idea:
 * - Traverse the tree level by level
 * - Each level represents one unit of depth
 * - Count how many levels exist
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (BFS):
 *
 * 1. If root is NULL:
 *      → return 0
 *
 * 2. Initialize:
 *      - queue q
 *      - height h = 0
 *
 * 3. Push root into the queue
 *
 * 4. While queue is not empty:
 *
 *    a) Let sz = number of nodes at current level
 *
 *    b) Process exactly `sz` nodes:
 *        - Pop each node
 *        - Push its left and right children (if they exist)
 *
 *    c) After finishing the level:
 *        - Increment height (h++)
 *
 * 5. Return h
 *
 * ------------------------------------------------------------
 * Why BFS Works:
 *
 * - Each iteration of the outer loop processes ONE FULL LEVEL
 * - Counting levels directly gives the tree depth
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n)
 *   Every node is enqueued and dequeued once
 *
 * Space Complexity:
 * - O(n)
 *   Queue may store up to an entire level of nodes
 *
 * ------------------------------------------------------------
 * Comparison of Approaches:
 *
 * | Approach | Time | Space | Notes |
 * |--------|------|-------|------|
 * | DFS (Recursion) | O(n) | O(h) | Elegant & common |
 * | BFS (Level Order) | O(n) | O(n) | Level-based intuition |
 *
 * ------------------------------------------------------------
 * When to Use What:
 *
 * - DFS:
 *     • Cleaner
 *     • Shorter code
 *     • Default interview choice
 *
 * - BFS:
 *     • When level-wise information is needed
 *     • Easier to visualize depth incrementally
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Tree Height / Depth Calculation" problem
 *
 * Appears in:
 * - Balanced tree checks
 * - Diameter of tree
 * - Level-based tree problems
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {

        // -----------------------------
        // Approach 1: DFS (Recursive)
        // -----------------------------
        /*
        if (!root) return 0;
        return 1 + max(maxDepth(root->left),
                       maxDepth(root->right));
        */

        // -----------------------------
        // Approach 2: BFS (Level Order)
        // -----------------------------
        if (!root) return 0;

        int h = 0;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            h++; // completed one level
        }
        return h;
    }
};

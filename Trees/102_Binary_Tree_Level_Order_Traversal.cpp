/*
 * Problem: 102. Binary Tree Level Order Traversal
 *
 * Statement:
 * You are given the root of a binary tree.
 * Your task is to return the LEVEL ORDER traversal of its nodes’ values.
 *
 * Level Order Traversal means:
 * - Traverse the tree level by level
 * - From left to right at each level
 *
 * The result should be a 2D array where:
 * - Each inner vector contains values of nodes at the same depth
 *
 * ------------------------------------------------------------
 * APPROACH: BFS (Breadth-First Search) / Level Order Traversal
 *
 * Core Idea:
 * - BFS naturally processes nodes level by level
 * - A queue helps maintain the order of traversal
 * - At each step, we process exactly ONE level
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Approach):
 *
 * 1. Initialize an empty 2D vector `ans`
 *    - This will store the final level order traversal
 *
 * 2. If root is NULL:
 *    - Return empty result
 *
 * 3. Create a queue and push the root node into it
 *
 * 4. While the queue is not empty:
 *
 *    a) Let `sz` = number of nodes currently in the queue
 *       - This represents the number of nodes at the current level
 *
 *    b) Create a temporary vector `temp`
 *       - To store values of nodes at this level
 *
 *    c) Process exactly `sz` nodes:
 *        - Pop front node from queue
 *        - Add its value to `temp`
 *        - Push its left child (if exists)
 *        - Push its right child (if exists)
 *
 *    d) After processing the level:
 *        - Push `temp` into `ans`
 *
 * 5. After traversal, return `ans`
 *
 * ------------------------------------------------------------
 * Example:
 *
 * Tree:
 *         3
 *        / \
 *       9  20
 *          / \
 *         15  7
 *
 * Level-wise traversal:
 * Level 0 → [3]
 * Level 1 → [9, 20]
 * Level 2 → [15, 7]
 *
 * Output:
 * [[3], [9, 20], [15, 7]]
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Queue ensures FIFO order
 * - Capturing queue size ensures strict level separation
 * - Children are added only after parent is processed
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Empty tree → return []
 * - Single node tree → [[root->val]]
 * - Skewed tree (all left or all right)
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n)
 *   Each node is visited exactly once
 *
 * Space Complexity:
 * - O(n)
 *   Queue + output storage
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Level Order Traversal using BFS"
 *
 * Appears in:
 * - Tree height / depth problems
 * - Zigzag traversal
 * - Average of levels
 * - Right / Left view of tree
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            vector<int> temp;

            while (sz--) {
                TreeNode* node = q.front();
                q.pop();

                temp.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};

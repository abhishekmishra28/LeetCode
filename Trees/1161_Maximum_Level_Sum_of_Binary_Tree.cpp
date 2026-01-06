/*
 * Problem: 1161. Maximum Level Sum of a Binary Tree
 *
 * Statement:
 * You are given the root of a binary tree.
 * The level of the root is considered level 1.
 *
 * Your task is to return the LEVEL number (1-indexed)
 * that has the MAXIMUM sum of node values.
 *
 * If multiple levels have the same maximum sum,
 * return the SMALLEST level number.
 *
 * ------------------------------------------------------------
 * Key Observations:
 *
 * - Nodes at the same depth belong to the same level
 * - We need to compute the sum of values level by level
 * - Breadth-First Search (BFS) naturally processes trees by levels
 *
 * ------------------------------------------------------------
 * Approach: Level-Order Traversal (BFS)
 *
 * Core Idea:
 * - Traverse the tree level by level using a queue
 * - For each level:
 *     • Calculate the sum of all node values
 *     • Compare it with the maximum sum found so far
 *     • Update the answer if current level sum is larger
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Approach):
 *
 * 1. Initialize:
 *    - maxSum = -∞ → stores maximum level sum seen so far
 *    - ans = 0     → level with maximum sum
 *    - level = 0   → current level counter
 *    - Queue for BFS
 *
 * 2. Push the root node into the queue
 *
 * 3. While the queue is not empty:
 *
 *    a) Increment level count
 *
 *    b) Initialize currLevelSum = 0
 *
 *    c) Process all nodes at the current level:
 *       - Loop `q.size()` times
 *       - Pop each node
 *       - Add node->val to currLevelSum
 *       - Push its children (if any) into the queue
 *
 *    d) Compare currLevelSum with maxSum:
 *       - If currLevelSum > maxSum:
 *           → update maxSum
 *           → update ans = current level
 *
 * 4. After traversal, return ans
 *
 * ------------------------------------------------------------
 * Example:
 *
 * Input Tree:
 *         1
 *       /   \
 *      7     0
 *     / \
 *    7  -8
 *
 * Level 1 sum = 1
 * Level 2 sum = 7 + 0 = 7
 * Level 3 sum = 7 + (-8) = -1
 *
 * Answer = 2
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Tree with only one node
 * - Tree with negative values
 * - Multiple levels having same sum (smallest level returned)
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n)
 *   Each node is visited once
 *
 * Space Complexity:
 * - O(n)
 *   Queue can store up to one full level
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Level-order traversal + aggregation" problem
 *
 * Appears in:
 * - Level average
 * - Level max / min
 * - Zigzag traversal
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
    int maxLevelSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int ans = 0;
        int level = 0;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            level++;
            int currLevelSum = 0;
            int sz = q.size();

            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();

                currLevelSum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            if (currLevelSum > maxSum) {
                maxSum = currLevelSum;
                ans = level;
            }
        }

        return ans;
    }
};

/*
 * Problem: 103. Binary Tree Zigzag Level Order Traversal
 *
 * Statement:
 * You are given the root of a binary tree.
 *
 * Return the ZIGZAG level order traversal of its nodes' values.
 *
 * Zigzag traversal means:
 * - Level 0 → Left to Right
 * - Level 1 → Right to Left
 * - Level 2 → Left to Right
 * - and so on...
 *
 * ------------------------------------------------------------
 * APPROACH: BFS (Level Order Traversal) with Direction Control
 *
 * Core Idea:
 *
 * - Perform a normal level-order traversal using a queue
 * - Use a boolean flag to decide the direction of insertion
 * - Instead of reversing the level array, directly place
 *   elements at correct indices
 *
 * ------------------------------------------------------------
 * Key Variables:
 *
 * - queue<TreeNode*> q
 *     → for standard BFS traversal
 *
 * - bool flag
 *     → true  = left to right
 *     → false = right to left
 *
 * - vector<int> level(n)
 *     → pre-sized array for current level
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. If root is NULL:
 *      → return empty result
 *
 * 2. Push root into queue
 *
 * 3. Initialize flag = true
 *      (first level is left to right)
 *
 * 4. While queue is not empty:
 *
 *    a) Let n = queue.size()
 *       (number of nodes at current level)
 *
 *    b) Create vector<int> level of size n
 *
 *    c) Process all nodes of current level:
 *
 *         For i = 0 to n-1:
 *           - Pop node from queue
 *
 *           - Decide index:
 *                if flag == true:
 *                    idx = i
 *                else:
 *                    idx = n - i - 1
 *
 *           - Place node->val at level[idx]
 *
 *           - Push left child (if exists)
 *           - Push right child (if exists)
 *
 *    d) Toggle direction:
 *         flag = !flag
 *
 *    e) Push `level` into answer
 *
 * 5. Return the final answer
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - BFS guarantees level-by-level traversal
 * - Using index mapping avoids reversing arrays
 * - Direction alternates cleanly using a boolean flag
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * Tree:
 *        3
 *       / \
 *      9  20
 *         / \
 *        15  7
 *
 * Level 0 (flag = true):
 *   → [3]
 *
 * Level 1 (flag = false):
 *   → [20, 9]
 *
 * Level 2 (flag = true):
 *   → [15, 7]
 *
 * Output:
 * [[3], [20, 9], [15, 7]]
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Empty tree → []
 * - Single node tree → [[root->val]]
 * - Skewed tree (left or right)
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n)
 *   Each node is visited once
 *
 * Space Complexity:
 * - O(n)
 *   Queue + output storage
 *
 * ------------------------------------------------------------
 * Alternative Approach (Mention in Interview):
 *
 * - Use deque and push_front / push_back
 * - Or reverse the level vector on alternate levels
 *
 * Your approach is more OPTIMAL
 * (avoids extra reverse operation)
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Level Order Traversal with Direction Toggle"
 *
 * Seen in:
 * - Zigzag traversal
 * - Spiral traversal
 * - Tree level manipulation problems
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;

        queue<TreeNode*> q;
        q.push(root);

        bool flag = true; // true = left to right

        while (!q.empty()) {
            int n = q.size();
            vector<int> level(n);

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                int idx = flag ? i : (n - i - 1);
                level[idx] = node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            flag = !flag; // toggle direction
            ans.push_back(level);
        }
        return ans;
    }
};

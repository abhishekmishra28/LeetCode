/*
 * Problem: 112. Path Sum
 *
 * Statement:
 * You are given the root of a binary tree and an integer `targetSum`.
 *
 * Return true if the tree has a ROOT-TO-LEAF path such that
 * the sum of the values along the path equals `targetSum`.
 * Otherwise, return false.
 *
 * A leaf is a node with NO children.
 *
 * ------------------------------------------------------------
 * APPROACH: DFS (Recursive Depth-First Search) — Your Approach
 *
 * Core Idea:
 *
 * - We traverse the tree from root to leaves
 * - At each node:
 *     • Subtract node->val from targetSum
 *     • Pass the remaining sum to children
 *
 * - If we reach a LEAF node and:
 *     remainingSum == node->val
 *   → a valid path exists
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. Base Case:
 *    - If root is NULL:
 *         → No path exists → return false
 *
 * 2. Leaf Node Check:
 *    - If root has NO left and right child
 *    - And root->val == targetSum
 *         → Found a valid root-to-leaf path
 *         → return true
 *
 * 3. Recursive Calls:
 *    - Recur on left subtree with:
 *         targetSum - root->val
 *
 *    - Recur on right subtree with:
 *         targetSum - root->val
 *
 * 4. If either subtree returns true:
 *      → return true
 *    Else:
 *      → return false
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Every root-to-leaf path is explored
 * - Subtracting values ensures we track the remaining sum
 * - Leaf condition guarantees path completeness
 *
 * ------------------------------------------------------------
 * Example:
 *
 * Tree:
 *        5
 *       / \
 *      4   8
 *     /   / \
 *    11  13  4
 *   /  \       \
 *  7    2       1
 *
 * targetSum = 22
 *
 * Path:
 * 5 → 4 → 11 → 2
 *
 * Remaining sums:
 * 22 → 17 → 13 → 2 ✔
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Empty tree → false
 * - Single node tree:
 *     root->val == targetSum → true
 * - Negative values in tree
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n)
 *   Every node is visited once in the worst case
 *
 * Space Complexity:
 * - O(h)
 *   h = height of the tree (recursion stack)
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Root-to-Leaf Path DFS" problem
 *
 * Seen in:
 * - Path Sum II
 * - Binary Tree Paths
 * - Sum-based DFS tree problems
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        // Leaf node condition
        if (!root->left && !root->right && root->val == targetSum)
            return true;

        // Check left and right subtrees
        bool left  = hasPathSum(root->left,  targetSum - root->val);
        bool right = hasPathSum(root->right, targetSum - root->val);

        return left || right;
    }
};

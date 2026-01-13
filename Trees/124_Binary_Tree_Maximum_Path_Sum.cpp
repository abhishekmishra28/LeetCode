/*
 * Problem: 124. Binary Tree Maximum Path Sum
 *
 * Statement:
 * You are given the root of a binary tree.
 *
 * A PATH is defined as:
 * - Any sequence of nodes where each pair of adjacent nodes
 *   has a parent-child relationship.
 * - The path does NOT need to pass through the root.
 * - The path must contain at least ONE node.
 *
 * The PATH SUM is the sum of values of all nodes in the path.
 *
 * Your task is to return the MAXIMUM path sum.
 *
 * ------------------------------------------------------------
 * APPROACH: Optimized DFS (Bottom-Up Tree DP) — Your Approach
 *
 * Core Insight:
 *
 * - At every node, there are two different concepts:
 *
 *   1) The BEST path that PASSES THROUGH this node
 *      (can include both left and right child)
 *
 *   2) The BEST path that can be EXTENDED to the parent
 *      (can include ONLY ONE side)
 *
 * ------------------------------------------------------------
 * Helper Function Role:
 *
 * helper(root, ans):
 * - Returns the maximum path sum starting at `root`
 *   and extending DOWNWARD to one side (left or right)
 *
 * - Updates `ans` with the maximum path sum found anywhere
 *   in the tree
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. Base Case:
 *    - If root is NULL → return 0
 *
 * 2. Recursively compute:
 *    - left  = max(0, helper(root->left, ans))
 *    - right = max(0, helper(root->right, ans))
 *
 *    Why max(0, …)?
 *    - Negative paths REDUCE the sum
 *    - It is better to IGNORE them
 *
 * 3. Compute the BEST path passing THROUGH current node:
 *
 *        root->val + left + right
 *
 *    This path:
 *    - Starts in left subtree
 *    - Passes through root
 *    - Ends in right subtree
 *
 * 4. Update global answer:
 *
 *        ans = max(ans, root->val + left + right)
 *
 * 5. Return the best EXTENDABLE path:
 *
 *        root->val + max(left, right)
 *
 *    Why only one side?
 *    - A path going to parent cannot split into two branches
 *
 * ------------------------------------------------------------
 * Main Function Logic:
 *
 * - Initialize ans = -∞
 * - Call helper(root, ans)
 * - Return ans
 *
 * ------------------------------------------------------------
 * Example:
 *
 * Tree:
 *        -10
 *        /  \
 *       9   20
 *          /  \
 *         15   7
 *
 * Best path:
 *   15 → 20 → 7
 *
 * Path sum = 15 + 20 + 7 = 42
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Every node is treated as a possible "turning point"
 * - Negative contributions are discarded early
 * - One DFS pass computes the answer
 *
 * ------------------------------------------------------------
 * Important Clarifications:
 *
 * - Path does NOT need to include root
 * - Path does NOT need to go from leaf to leaf
 * - Single node path is allowed
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n)
 *   Each node is visited once
 *
 * Space Complexity:
 * - O(h)
 *   h = height of the tree (recursion stack)
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Tree DP with Global Answer Tracking"
 *
 * Seen in:
 * - Diameter of Binary Tree
 * - Maximum path problems
 * - Bottom-up DFS optimizations
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
    int helper(TreeNode* root, int &ans) {
        if (!root) return 0;

        // Ignore negative paths
        int left  = max(0, helper(root->left, ans));
        int right = max(0, helper(root->right, ans));

        // Best path passing through this node
        ans = max(ans, root->val + left + right);

        // Return best extendable path
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        helper(root, ans);
        return ans;
    }
};

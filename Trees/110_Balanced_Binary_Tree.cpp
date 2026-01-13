/*
 * Problem: 110. Balanced Binary Tree
 *
 * Statement:
 * You are given the root of a binary tree.
 *
 * A binary tree is called HEIGHT-BALANCED if:
 * - For every node in the tree,
 *   the height difference between its left and right subtrees
 *   is at most 1.
 *
 * Return true if the tree is balanced, otherwise false.
 *
 * ------------------------------------------------------------
 * APPROACH 1: Brute Force using Height Calculation (Your Approach)
 *
 * Core Idea:
 * - For every node:
 *     1) Compute height of left subtree
 *     2) Compute height of right subtree
 *     3) Check height difference ≤ 1
 *     4) Recursively ensure left and right subtrees are balanced
 *
 * ------------------------------------------------------------
 * Helper Function:
 *
 * height(root):
 * - Returns height of the tree rooted at `root`
 * - Height = 1 + max(left height, right height)
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Approach 1):
 *
 * 1. If root is NULL:
 *      → tree is balanced → return true
 *
 * 2. Compute:
 *      lh = height(root->left)
 *      rh = height(root->right)
 *
 * 3. If |lh - rh| > 1:
 *      → tree is NOT balanced → return false
 *
 * 4. Recursively check:
 *      left subtree is balanced
 *      right subtree is balanced
 *
 * 5. If both are balanced:
 *      → return true
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Height difference condition is checked at EVERY node
 * - Recursion ensures condition holds for entire tree
 *
 * ------------------------------------------------------------
 * Drawback of Approach 1:
 *
 * - Height is recomputed again and again
 * - Leads to repeated work
 *
 * Worst Case (skewed tree):
 * - height() takes O(n)
 * - called for each node
 *
 * Time Complexity: O(n²)
 *
 * ------------------------------------------------------------
 * APPROACH 2: Optimized DFS (Bottom-Up) ⭐ (Interview Preferred)
 *
 * Core Insight:
 *
 * - Combine height calculation AND balance check in ONE DFS
 * - Return:
 *     • height if subtree is balanced
 *     • -1 if subtree is NOT balanced
 *
 * ------------------------------------------------------------
 * Optimized DFS Logic:
 *
 * dfs(root):
 *   if root == NULL → return 0
 *
 *   leftHeight = dfs(root->left)
 *   if leftHeight == -1 → return -1
 *
 *   rightHeight = dfs(root->right)
 *   if rightHeight == -1 → return -1
 *
 *   if |leftHeight - rightHeight| > 1:
 *       return -1
 *
 *   return 1 + max(leftHeight, rightHeight)
 *
 * Tree is balanced if dfs(root) != -1
 *
 * ------------------------------------------------------------
 * Time & Space Comparison:
 *
 * | Approach | Time | Space | Recommended |
 * |--------|------|-------|-------------|
 * | Brute Force (Height) | O(n²) | O(h) | ❌ |
 * | Optimized DFS | O(n) | O(h) | ✅ |
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
 * Heights differ by ≤ 1 at every node → balanced
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Bottom-Up Tree DP" problem
 *
 * Seen in:
 * - Diameter of tree
 * - Balanced tree checks
 * - Tree height problems
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
    // -----------------------------
    // Approach 1: Brute Force (Your Code)
    // -----------------------------
    int height(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    bool isBalanced(TreeNode* root) {
        if (!root) return true;

        int lh = height(root->left);
        int rh = height(root->right);

        if (abs(lh - rh) > 1) return false;

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        return left && right;
    }

    /*
    // -----------------------------
    // Approach 2: Optimized DFS (Recommended)
    // -----------------------------
    int dfs(TreeNode* root) {
        if (!root) return 0;

        int lh = dfs(root->left);
        if (lh == -1) return -1;

        int rh = dfs(root->right);
        if (rh == -1) return -1;

        if (abs(lh - rh) > 1) return -1;

        return 1 + max(lh, rh);
    }

    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }
    */
};

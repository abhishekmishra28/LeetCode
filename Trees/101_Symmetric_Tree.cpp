/*
 * Problem: 101. Symmetric Tree
 *
 * Statement:
 * You are given the root of a binary tree.
 *
 * A binary tree is SYMMETRIC if it is a mirror of itself
 * (i.e., symmetric around its center).
 *
 * Return true if the tree is symmetric, otherwise false.
 *
 * ------------------------------------------------------------
 * APPROACH: Recursive Mirror Comparison (DFS) — Your Approach
 *
 * Core Idea:
 *
 * - A tree is symmetric if:
 *     • Left subtree is a mirror of the right subtree
 *
 * - Two trees are MIRRORS if:
 *     1) Their root values are equal
 *     2) Left child of one equals right child of the other
 *     3) Right child of one equals left child of the other
 *
 * ------------------------------------------------------------
 * Helper Function: isMirror(p, q)
 *
 * Purpose:
 * - Checks whether two trees `p` and `q` are mirror images
 *   of each other
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. Base Case 1:
 *    - If both p and q are NULL:
 *         → Trees are mirrors at this level
 *         → return true
 *
 * 2. Base Case 2:
 *    - If ONLY one of p or q is NULL:
 *         → Structure mismatch
 *         → return false
 *
 * 3. Value Check:
 *    - If p->val != q->val:
 *         → Values differ
 *         → return false
 *
 * 4. Recursive Mirror Check:
 *    - Compare:
 *         p->left  with q->right
 *         p->right with q->left
 *
 *    - Both must be true
 *
 * ------------------------------------------------------------
 * Main Function Logic: isSymmetric(root)
 *
 * 1. If root is NULL:
 *      → Empty tree is symmetric → return true
 *
 * 2. If root has no children:
 *      → Single node tree is symmetric → return true
 *
 * 3. Otherwise:
 *      → Check mirror condition between:
 *           root->left and root->right
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - DFS explores both subtrees simultaneously
 * - Cross-comparison enforces mirror structure
 * - Any asymmetry is caught immediately
 *
 * ------------------------------------------------------------
 * Example:
 *
 * Symmetric Tree:
 *
 *        1
 *       / \
 *      2   2
 *     / \ / \
 *    3  4 4  3
 *
 * isMirror(left, right) → true
 *
 * ------------------------------------------------------------
 * Counter Example:
 *
 *        1
 *       / \
 *      2   2
 *       \   \
 *        3   3
 *
 * Structure mismatch → false
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n)
 *   Every node is visited once
 *
 * ------------------------------------------------------------
 * Space Complexity:
 * - O(h)
 *   h = height of the tree (recursion stack)
 *
 * ------------------------------------------------------------
 * Alternative Approach (Interview Mention):
 *
 * - Iterative BFS using a queue
 * - Push nodes in mirror order and compare
 *
 * Recursive approach is cleaner and preferred.
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Mirror Tree Comparison" problem
 *
 * Related Problems:
 * - Same Tree
 * - Subtree of Another Tree
 * - Invert Binary Tree
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
    bool isMirror(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;

        return isMirror(p->left, q->right) &&
               isMirror(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        if (!root->left && !root->right) return true;

        return isMirror(root->left, root->right);
    }
};

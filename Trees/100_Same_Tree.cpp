/*
 * Problem: 100. Same Tree
 *
 * Statement:
 * You are given the roots of two binary trees `p` and `q`.
 *
 * Two binary trees are considered the SAME if:
 * - They have the same structure
 * - Corresponding nodes have the same values
 *
 * Return true if the two trees are the same, otherwise false.
 *
 * ------------------------------------------------------------
 * APPROACH: Recursive DFS (Tree Comparison) — Your Approach
 *
 * Core Idea:
 *
 * - Compare both trees SIMULTANEOUSLY
 * - At every step, check:
 *     1) Structure (presence / absence of nodes)
 *     2) Node values
 * - Recursively verify left and right subtrees
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. Base Case 1:
 *    - If both nodes are NULL:
 *         → Trees match at this position
 *         → return true
 *
 * 2. Base Case 2:
 *    - If ONLY one of them is NULL:
 *         → Structure mismatch
 *         → return false
 *
 * 3. Value Check:
 *    - If p->val != q->val:
 *         → Node values differ
 *         → return false
 *
 * 4. Recursive Check:
 *    - Check left subtrees:
 *         isSameTree(p->left, q->left)
 *
 *    - Check right subtrees:
 *         isSameTree(p->right, q->right)
 *
 * 5. Return true only if BOTH recursive calls return true
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - DFS ensures we visit corresponding nodes together
 * - Structural mismatches are caught immediately
 * - Value mismatches stop recursion early
 *
 * ------------------------------------------------------------
 * Example:
 *
 * Tree p:        Tree q:
 *     1              1
 *    / \            / \
 *   2   3          2   3
 *
 * → Same structure + same values → true
 *
 * ------------------------------------------------------------
 * Counter Example:
 *
 * Tree p:        Tree q:
 *     1              1
 *    /                \
 *   2                  2
 *
 * → Structure differs → false
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - O(n)
 *   Where n = number of nodes in the smaller tree
 *   Each node is visited once
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(h)
 *   h = height of the tree (recursion stack)
 *   Worst case (skewed tree): O(n)
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Simultaneous Tree Traversal" problem
 *
 * Seen in:
 * - Symmetric Tree
 * - Subtree of Another Tree
 * - Identical Binary Trees
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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // Case 1: both nodes are NULL
        if (!p && !q) return true;

        // Case 2: one is NULL, the other is not
        if (!p || !q) return false;

        // Case 3: values differ
        if (p->val != q->val) return false;

        // Case 4: recursively check left and right subtrees
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};

/*
 * Problem: 236. Lowest Common Ancestor of a Binary Tree
 *
 * Statement:
 * Given a binary tree and two nodes `p` and `q`,
 * return their LOWEST COMMON ANCESTOR (LCA).
 *
 * The LCA of two nodes p and q is defined as the
 * lowest node in the tree that has both p and q
 * as descendants (a node can be a descendant of itself).
 *
 * ------------------------------------------------------------
 * APPROACH: Recursive DFS (Bottom-Up) — Your Approach
 *
 * Core Idea:
 *
 * - Traverse the tree using DFS
 * - If the current node is either `p` or `q`,
 *   return it upwards
 *
 * - From left and right subtrees:
 *     • If both sides return non-null → current node is LCA
 *     • Else return the non-null side
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. Base Case:
 *      If root == NULL:
 *          → return nullptr
 *
 * 2. If current node is p or q:
 *      → return current node
 *
 * 3. Recurse on left and right subtrees:
 *
 *      leftN  = LCA(root->left,  p, q)
 *      rightN = LCA(root->right, p, q)
 *
 * 4. Analyze results:
 *
 *      - If both leftN and rightN are non-null:
 *            → p and q found in different subtrees
 *            → current root is the LCA
 *
 *      - If only one is non-null:
 *            → propagate that node upward
 *
 *      - If both are null:
 *            → return nullptr
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - DFS ensures both p and q are searched in all subtrees
 * - The first node where p and q split is the LCA
 * - Works for ANY binary tree (not necessarily BST)
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 *        3
 *       / \
 *      5   1
 *     / \ / \
 *    6  2 0  8
 *      / \
 *     7   4
 *
 * p = 5, q = 1
 *
 * → left subtree returns 5
 * → right subtree returns 1
 * → root 3 is LCA
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - p == q → that node is LCA
 * - One node is ancestor of the other
 * - Tree with only one node
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - O(n)
 *   Each node is visited once
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(h)
 *   Recursion stack (h = height of tree)
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Postorder DFS + Information Propagation"
 *
 * Seen in:
 * - LCA problems
 * - Tree path queries
 * - Binary tree recursion problems
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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;

        if (root == p || root == q)
            return root;

        TreeNode* leftN  = lowestCommonAncestor(root->left,  p, q);
        TreeNode* rightN = lowestCommonAncestor(root->right, p, q);

        if (leftN && rightN)
            return root;

        return leftN ? leftN : rightN;
    }
};

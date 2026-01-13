/*
 * Problem: 
 *
 * Statement:
 * You are given the root of a binary tree.
 *
 * The DIAMETER of a binary tree is defined as:
 * - The length of the LONGEST path between any two nodes
 * - This path may or may NOT pass through the root
 *
 * Length is measured in:
 * - NUMBER OF EDGES (not nodes)
 *
 * Your task is to return the diameter of the binary tree.
 *
 * ------------------------------------------------------------
 * APPROACH: Optimized DFS (Single Traversal) — Your Approach
 *
 * Core Insight:
 *
 * - The longest path through a node is:
 *       height(left subtree) + height(right subtree)
 *
 * - While computing height, we can simultaneously update
 *   the maximum diameter seen so far
 *
 * ------------------------------------------------------------
 * Helper Function:
 *
 * helper(root, maxi):
 * - Returns HEIGHT of the subtree rooted at `root`
 * - Updates `maxi` with the best diameter found
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. If current node is NULL:
 *      → height = 0
 *
 * 2. Recursively compute:
 *      lh = height of left subtree
 *      rh = height of right subtree
 *
 * 3. Diameter passing through this node:
 *      lh + rh
 *
 * 4. Update global maximum:
 *      maxi = max(maxi, lh + rh)
 *
 * 5. Return height of current subtree:
 *      1 + max(lh, rh)
 *
 * ------------------------------------------------------------
 * Main Function Logic:
 *
 * - Initialize maxi = 0
 * - Call helper(root, maxi)
 * - Return maxi
 *
 * ------------------------------------------------------------
 * Example:
 *
 *        1
 *       / \
 *      2   3
 *     / \
 *    4   5
 *
 * Heights:
 * - At node 2: lh = 1, rh = 1 → diameter = 2
 * - At node 1: lh = 2, rh = 1 → diameter = 3
 *
 * Output = 3
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Every node is considered as a potential "center"
 *   of the diameter
 * - Single DFS avoids recomputation
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n)
 *   Each node is visited once
 *
 * Space Complexity:
 * - O(h)
 *   h = height of tree (recursion stack)
 *
 * ------------------------------------------------------------
 * Important Clarification:
 *
 * - Height is counted in NODES
 * - Diameter is counted in EDGES
 *
 * This is why:
 *   diameter = lh + rh
 *   (not +1)
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Tree DP / Bottom-Up DFS" problem
 *
 * Seen in:
 * - Balanced Binary Tree
 * - Maximum Path Sum
 * - Tree height related problems
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
    // Helper function to compute height and update diameter
    int helper(TreeNode* root, int &maxi) {
        if (!root) return 0;

        int lh = helper(root->left, maxi);
        int rh = helper(root->right, maxi);

        // Update diameter (edges count)
        maxi = max(maxi, lh + rh);

        // Return height of current subtree
        return 1 + max(lh, rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        if (!root) return 0;

        helper(root, maxi);
        return maxi;
    }
};

/*
 * Problem: 1339. Maximum Product of Splitted Binary Tree
 *
 * Statement:
 * You are given the root of a binary tree.
 * You are allowed to split the tree by removing exactly ONE edge.
 *
 * After splitting:
 * - The tree becomes two non-empty subtrees
 * - Let the sum of values of the two subtrees be S1 and S2
 *
 * Your task is to return the MAXIMUM possible product:
 *
 *        S1 × S2
 *
 * Since the result can be large, return it modulo (1e9 + 7).
 *
 * ------------------------------------------------------------
 * Key Observations:
 *
 * - Removing one edge separates the tree into:
 *     • One subtree
 *     • The rest of the tree
 *
 * - If we know:
 *     • total sum of the entire tree = TOTAL
 *     • sum of a subtree = subtree_sum
 *
 *   Then the other part has sum:
 *     TOTAL - subtree_sum
 *
 *   Product = subtree_sum × (TOTAL - subtree_sum)
 *
 * ------------------------------------------------------------
 * Core Strategy:
 *
 * 1) First compute the TOTAL sum of the tree
 * 2) Then try every possible subtree as one part of the split
 * 3) Track the maximum product obtained
 *
 * ------------------------------------------------------------
 * Why DFS?
 *
 * - DFS naturally computes subtree sums
 * - At every node, we can consider "cutting" the edge above it
 * - This gives one valid split
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Approach):
 *
 * STEP 1: Compute total sum of the tree
 *
 * - Use BFS (level-order traversal)
 * - Accumulate values of all nodes into `total`
 *
 * STEP 2: DFS to compute subtree sums and products
 *
 * For each node:
 * - Compute left subtree sum
 * - Compute right subtree sum
 * - subtree_sum = node->val + left + right
 *
 * - If we split here:
 *     S1 = subtree_sum
 *     S2 = total - subtree_sum
 *
 * - Product = S1 × S2
 * - Update global maximum product
 *
 * STEP 3: Return maximum product modulo 1e9+7
 *
 * ------------------------------------------------------------
 * Example:
 *
 * Tree:
 *        1
 *       / \
 *      2   3
 *
 * TOTAL = 6
 *
 * Possible splits:
 * - Cut edge above node 2:
 *     subtree_sum = 2
 *     product = 2 × 4 = 8
 *
 * - Cut edge above node 3:
 *     subtree_sum = 3
 *     product = 3 × 3 = 9  ← maximum
 *
 * Answer = 9
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Tree with only two nodes
 * - Highly skewed tree
 * - Large node values
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - O(n)
 *   • BFS to compute total sum
 *   • DFS to compute subtree sums
 *
 * Space Complexity:
 *
 * - O(n)
 *   • Queue for BFS
 *   • Recursion stack for DFS
 *
 * ------------------------------------------------------------
 * Important Note:
 *
 * - We use `long long` for product to avoid overflow
 * - Modulo is applied ONLY at the end
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Tree DP + Subtree Sum" problem
 *
 * Similar ideas appear in:
 * - Split tree problems
 * - Maximum sum / product partitions on trees
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
    long long MOD = 1e9 + 7;

    /*
     * DFS function:
     * - returns subtree sum of current node
     * - updates maximum product by trying split at this node
     */
    int dfs(TreeNode* node, int total, long long &maxProd) {
        if (!node) return 0;

        int left = dfs(node->left, total, maxProd);
        int right = dfs(node->right, total, maxProd);

        int subtree_sum = node->val + left + right;

        long long prod = 1LL * subtree_sum * (total - subtree_sum);
        maxProd = max(maxProd, prod);

        return subtree_sum;
    }

    int maxProduct(TreeNode* root) {

        // Step 1: Compute total sum of tree (BFS)
        int total = 0;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            total += node->val;

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        // Step 2: DFS to compute max product
        long long maxProd = 0;
        dfs(root, total, maxProd);

        // Step 3: Return result modulo
        return maxProd % MOD;
    }
};

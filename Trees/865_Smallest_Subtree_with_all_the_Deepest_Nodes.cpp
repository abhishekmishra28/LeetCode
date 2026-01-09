/*
 * Problem: 865. Smallest Subtree with all the Deepest Nodes
 *
 * Statement:
 * You are given the root of a binary tree.
 *
 * The DEPTH of a node is the number of edges from the root to that node.
 * The DEEPEST nodes are those having the maximum depth.
 *
 * Your task is to return the ROOT of the SMALLEST subtree
 * that contains ALL the deepest nodes.
 *
 * ------------------------------------------------------------
 * APPROACH 1: Brute Force + BFS + DFS (Your Approach)
 *
 * This approach directly follows the problem statement:
 * 1) First find ALL the deepest nodes
 * 2) Then find the smallest subtree that contains ALL of them
 *
 * ------------------------------------------------------------
 * High-Level Idea:
 *
 * - Use BFS to identify the deepest level of the tree
 * - Store all nodes present at that deepest level
 * - For every node in the tree:
 *     • Check if its subtree contains ALL deepest nodes
 *     • Track the subtree with MINIMUM size
 *
 * ------------------------------------------------------------
 * Step 1: Find all deepest nodes (BFS)
 *
 * - Perform level-order traversal (BFS)
 * - At each level, store nodes of that level
 * - The LAST level processed will contain all deepest nodes
 *
 * Result:
 * - A set `deepestNodes` containing pointers to all deepest nodes
 *
 * ------------------------------------------------------------
 * Step 2: Traverse all nodes as potential subtree roots
 *
 * - For every node in the tree, assume it as a subtree root
 * - Check:
 *     • Does its subtree contain ALL deepest nodes?
 *     • What is the size of this subtree?
 *
 * ------------------------------------------------------------
 * Step 3: Subtree checking logic
 *
 * The helper function `check()`:
 * - Traverses the subtree rooted at current node
 * - Counts:
 *     • `sz`  → total nodes in this subtree
 *     • `cnt` → how many deepest nodes are found inside it
 *
 * If:
 *     cnt == deepestNodes.size()
 * → This subtree contains ALL deepest nodes
 *
 * ------------------------------------------------------------
 * Step 4: Maintain the smallest valid subtree
 *
 * - Keep global variables:
 *     • `mini` → minimum subtree size found so far
 *     • `ans`  → root of the smallest valid subtree
 *
 * - Update them whenever a smaller valid subtree is found
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Any subtree containing all deepest nodes is a valid candidate
 * - Among all such subtrees, the one with minimum size
 *   is exactly the required answer
 *
 * ------------------------------------------------------------
 * Example:
 *
 * Tree:
 *         3
 *        / \
 *       5   1
 *      / \   \
 *     6   2   8
 *        / \
 *       7   4
 *
 * Deepest nodes = {7, 4}
 *
 * Smallest subtree containing both = rooted at node 2
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - BFS to find deepest nodes: O(n)
 * - For each node, subtree traversal: O(n)
 *
 * Total: O(n²)
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(n) for recursion + queue + sets
 *
 * ------------------------------------------------------------
 * Drawback:
 *
 * - This is NOT the optimal solution
 * - Exists a clean O(n) DFS-based solution
 * - However, this approach is very intuitive
 *   and follows the problem statement literally
 *
 * ------------------------------------------------------------
 * NOTE:
 * This is marked as **Approach 1** intentionally.
 * A more optimal approach can be discussed as Approach 2.
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
    int mini;
    TreeNode* ans;

    /*
     * Traverses the subtree rooted at `root`
     * - sz  → counts total nodes in subtree
     * - cnt → counts how many deepest nodes are found
     */
    void check(TreeNode* root, set<TreeNode*> &node,
               int &sz, int &cnt) {

        if (!root) return;

        if (node.find(root) != node.end())
            cnt++;

        sz++;

        if (root->left)
            check(root->left, node, sz, cnt);
        if (root->right)
            check(root->right, node, sz, cnt);
    }

    /*
     * Try every node as subtree root
     */
    void traverse(TreeNode* root, set<TreeNode*> &nodes) {
        if (!root) return;

        int sz = 0;
        int cnt = 0;

        check(root, nodes, sz, cnt);

        if (cnt == nodes.size()) {
            if (mini > sz) {
                mini = sz;
                ans = root;
            }
        }

        traverse(root->left, nodes);
        traverse(root->right, nodes);
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        mini = INT_MAX;
        ans = NULL;

        // Step 1: BFS to find deepest nodes
        queue<TreeNode*> q;
        q.push(root);

        set<TreeNode*> deepestNodes;

        while (!q.empty()) {
            int sz = q.size();
            set<TreeNode*> temp;

            while (sz--) {
                TreeNode* node = q.front();
                q.pop();

                temp.insert(node);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            deepestNodes = temp; // overwrite with current level
        }

        // Step 2: Try all subtrees
        traverse(root, deepestNodes);

        return ans;
    }
};

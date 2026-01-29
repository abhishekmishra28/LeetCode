/*
 * Problem: 105. Construct Binary Tree from Preorder and Inorder Traversal
 *
 * Statement:
 * You are given two integer arrays:
 *   - preorder: preorder traversal of a binary tree
 *   - inorder:  inorder traversal of the same tree
 *
 * Construct and return the binary tree.
 *
 * ------------------------------------------------------------
 * APPROACH: Recursive Construction using Traversal Properties
 *           (DFS + Index Tracking) — Your Approach
 *
 * Core Observations:
 *
 * 1. Preorder Traversal:  Root → Left → Right
 *    → The FIRST unused element in preorder is always the ROOT.
 *
 * 2. Inorder Traversal:   Left → Root → Right
 *    → Elements LEFT of root belong to left subtree
 *    → Elements RIGHT of root belong to right subtree
 *
 * ------------------------------------------------------------
 * High-Level Idea:
 *
 * - Use an index `idx` to track the current root in preorder.
 * - Pick preorder[idx] as root.
 * - Find this root in inorder array to split left & right subtrees.
 * - Recursively build left and right subtrees.
 *
 * ------------------------------------------------------------
 * Helper Function:
 *
 * helper(preorder, inorder, s, e, idx)
 *
 * Parameters:
 * - s, e : current range in inorder array
 * - idx  : reference index for preorder traversal
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. Base Case:
 *      If s > e:
 *          → no elements to form subtree
 *          → return nullptr
 *
 * 2. Root Selection:
 *      rootVal = preorder[idx]
 *
 * 3. Find rootVal in inorder[s … e]:
 *      This splits inorder into:
 *        - Left subtree  → s to i-1
 *        - Right subtree → i+1 to e
 *
 * 4. Increment preorder index:
 *      idx++
 *
 * 5. Create root node:
 *      TreeNode* root = new TreeNode(rootVal)
 *
 * 6. Recursively build:
 *      root->left  = helper(preorder, inorder, s, i-1, idx)
 *      root->right = helper(preorder, inorder, i+1, e, idx)
 *
 * 7. Return root
 *
 * ------------------------------------------------------------
 * Main Function Logic:
 *
 * 1. Initialize preorder index idx = 0
 * 2. Call helper on full inorder range [0 … n-1]
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Preorder guarantees correct root order
 * - Inorder guarantees correct subtree partition
 * - Recursive DFS builds tree top-down
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * preorder = [3, 9, 20, 15, 7]
 * inorder  = [9, 3, 15, 20, 7]
 *
 * Root = 3
 * inorder split:
 *   left  = [9]
 *   right = [15, 20, 7]
 *
 * Recursively construct subtrees the same way.
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - Worst case: O(n²)
 *   (Each recursive call does a linear search in inorder)
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(n) recursion stack (skewed tree)
 *
 * ------------------------------------------------------------
 * 🔧 Optimization Note (Interview Important):
 *
 * If we use a HASH MAP to store inorder indices:
 *
 *   unordered_map<int, int> pos;
 *
 * Then:
 * - Finding root position becomes O(1)
 * - Overall Time Complexity → O(n)
 *
 * This is the OPTIMAL solution expected in interviews.
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Tree Construction from Traversals"
 *
 * Seen in:
 * - Preorder + Inorder
 * - Inorder + Postorder
 */

class Solution {
public:
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,
                     int s, int e, int &idx) {

        if (s > e) return nullptr;

        int rootVal = preorder[idx];
        int i = s;

        // find root in inorder
        for (; i <= e; i++) {
            if (inorder[i] == rootVal) break;
        }

        idx++;
        TreeNode* root = new TreeNode(rootVal);

        root->left  = helper(preorder, inorder, s, i - 1, idx);
        root->right = helper(preorder, inorder, i + 1, e, idx);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        return helper(preorder, inorder, 0, preorder.size() - 1, idx);
    }
};

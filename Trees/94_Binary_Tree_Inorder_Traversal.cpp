/*
 * Problem: 94. Binary Tree Inorder Traversal
 *
 * Statement:
 * Given the root of a binary tree, return the inorder traversal
 * of its nodes' values.
 *
 * Inorder Traversal Order:
 *      LEFT → ROOT → RIGHT
 *
 * ------------------------------------------------------------
 * APPROACH 1: Recursive Inorder Traversal — Your Final Approach
 *
 * Core Idea:
 *
 * - Inorder traversal naturally fits recursion
 * - For every node:
 *     1) Traverse left subtree
 *     2) Process current node
 *     3) Traverse right subtree
 *
 * ------------------------------------------------------------
 * Helper Function Explanation:
 *
 * inorder(node, ans)
 *
 * Purpose:
 * - Perform inorder traversal starting from `node`
 * - Store result in vector `ans`
 *
 * Base Case:
 * - If node == nullptr → return
 *
 * Recursive Steps:
 * - inorder(node->left)
 * - ans.push_back(node->val)
 * - inorder(node->right)
 *
 * ------------------------------------------------------------
 * Main Function Logic:
 *
 * 1. Create an empty result vector `ans`
 * 2. Call inorder(root, ans)
 * 3. Return ans
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Recursion automatically maintains traversal order
 * - Call stack keeps track of parent nodes
 * - Clean and readable solution
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * Tree:
 *          1
 *           \
 *            2
 *           /
 *          3
 *
 * Inorder Traversal:
 *
 *   left of 1 → null
 *   visit 1
 *   go right → 2
 *       left of 2 → 3
 *           visit 3
 *       visit 2
 *
 * Output = [1, 3, 2]
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - O(n)
 *   Each node is visited exactly once
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(h)
 *   where h = height of the tree (recursion stack)
 *
 *   • Balanced tree → O(log n)
 *   • Skewed tree   → O(n)
 *
 * ------------------------------------------------------------
 * APPROACH 2: Iterative Inorder Traversal (Stack) — Commented
 *
 * Idea:
 *
 * - Simulate recursion using an explicit stack
 * - Move left until null
 * - Process node
 * - Move right
 *
 * This avoids recursion and is useful when stack overflow is a concern.
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Tree Traversal (DFS)"
 *
 * Variants:
 * - Preorder (ROOT → LEFT → RIGHT)
 * - Postorder (LEFT → RIGHT → ROOT)
 */

class Solution {
private:
    void inorder(TreeNode* node, vector<int> &ans) {
        if (!node) return;

        inorder(node->left, ans);      // LEFT
        ans.push_back(node->val);      // ROOT
        inorder(node->right, ans);     // RIGHT
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {

        // ---------- Iterative Approach (Commented) ----------
        /*
        stack<TreeNode*> st;
        vector<int> inorder;
        TreeNode* node = root;

        while (true) {
            if (node) {
                st.push(node);
                node = node->left;
            } else {
                if (st.empty()) break;
                node = st.top();
                st.pop();
                inorder.push_back(node->val);
                node = node->right;
            }
        }
        return inorder;
        */

        // ---------- Recursive Approach ----------
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};

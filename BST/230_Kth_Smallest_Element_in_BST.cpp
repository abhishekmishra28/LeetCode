/*
 * Problem: 230. Kth Smallest Element in a BST
 *
 * Statement:
 * You are given the root of a Binary Search Tree (BST) and an integer k.
 * Return the k-th SMALLEST element in the BST.
 *
 * ------------------------------------------------------------
 * APPROACH: Inorder Traversal (DFS) — Your Approach
 *
 * Core Observation:
 *
 * - Inorder traversal of a BST gives nodes in
 *   SORTED (increasing) order.
 *
 *     Inorder (BST) → LEFT → ROOT → RIGHT
 *
 * - So, the k-th element visited during inorder traversal
 *   is exactly the k-th smallest element.
 *
 * ------------------------------------------------------------
 * Helper Function Explanation:
 *
 * helper(root, k, cnt, res)
 *
 * Parameters:
 * - root → current node
 * - k    → target index (k-th smallest)
 * - cnt  → counts how many nodes have been visited so far
 * - res  → stores the answer once cnt == k
 *
 * ------------------------------------------------------------
 * Recursive Logic:
 *
 * 1. Base Case:
 *
 *      If root == nullptr → return
 *
 * 2. Traverse LEFT subtree
 *
 * 3. Visit current node:
 *
 *      cnt++
 *      If cnt == k:
 *          res = root->val
 *          return
 *
 * 4. Traverse RIGHT subtree
 *
 * ------------------------------------------------------------
 * Main Function Logic:
 *
 * 1. Initialize:
 *
 *      cnt = 0
 *      res = (uninitialized, will be set when cnt == k)
 *
 * 2. Call helper(root, k, cnt, res)
 *
 * 3. Return res
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - BST inorder traversal visits nodes in ascending order
 * - Counting visits gives direct access to k-th smallest
 * - No need to store all values in a list
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * BST:
 *           5
 *         /   \
 *        3     6
 *       / \
 *      2   4
 *     /
 *    1
 *
 * k = 3
 *
 * Inorder Traversal Order:
 *   1 (cnt=1)
 *   2 (cnt=2)
 *   3 (cnt=3)  ← answer
 *
 * Output = 3
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - k = 1 → smallest element
 * - k = number of nodes → largest element
 * - Skewed BST
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - O(n) in worst case
 *   (when k is large or tree is skewed)
 *
 * - Average:
 *   O(h + k), where h = tree height
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(h) due to recursion stack
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "BST + Inorder Traversal + Counter"
 *
 * Related problems:
 * - Kth Largest in BST
 * - Validate BST
 * - Inorder Traversal
 */

class Solution {
private:
    void helper(TreeNode* root, int k, int &cnt, int &res) {
        if (!root) return;

        // Left subtree
        helper(root->left, k, cnt, res);

        // Visit current node
        cnt++;
        if (cnt == k) {
            res = root->val;
            return;
        }

        // Right subtree
        helper(root->right, k, cnt, res);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        int res = -1;
        helper(root, k, cnt, res);
        return res;
    }
};

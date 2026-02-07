/*
 * Problem: 653. Two Sum IV - Input is a BST
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given the root of a Binary Search Tree (BST) and an integer k,
 * return true if there exist two elements in the BST such that
 * their sum equals k.
 *
 * ------------------------------------------------------------
 * APPROACH 1: Inorder Traversal + Two Pointers
 *
 * Idea:
 * - Inorder traversal of a BST gives a sorted array
 * - Apply two-pointer technique on the sorted array
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * ------------------------------------------------------------
 * APPROACH 2: DFS + HashSet (More Efficient / Early Exit)
 *
 * Idea:
 * - Traverse the tree once using DFS
 * - For each node value x, check if (k - x) already exists
 * - If yes → pair found
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * ------------------------------------------------------------
 * NOTE:
 * - Approach 1 uses BST property explicitly
 * - Approach 2 works for any binary tree and can exit early
 */

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
private:
    /* ========== APPROACH 1 HELPERS ========== */
    vector<int> inorderArr;

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        inorderArr.push_back(root->val);
        inorder(root->right);
    }

    /* ========== APPROACH 2 HELPERS ========== */
    unordered_set<int> seen;

    bool dfs(TreeNode* root, int k) {
        if (!root) return false;

        if (seen.count(k - root->val))
            return true;

        seen.insert(root->val);
        return dfs(root->left, k) || dfs(root->right, k);
    }

public:
    bool findTarget(TreeNode* root, int k) {

        /* ---------- APPROACH 1: Inorder + Two Pointers ---------- */
        /*
        inorderArr.clear();
        inorder(root);

        int i = 0, j = inorderArr.size() - 1;
        while (i < j) {
            int sum = inorderArr[i] + inorderArr[j];
            if (sum == k) return true;
            else if (sum < k) i++;
            else j--;
        }
        return false;
        */

        /* ---------- APPROACH 2: DFS + HashSet (Efficient) ---------- */
        seen.clear();
        return dfs(root, k);
    }
};

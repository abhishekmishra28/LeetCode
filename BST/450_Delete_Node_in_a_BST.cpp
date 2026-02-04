/*
 * Problem: 450. Delete Node in a BST
 *
 * Statement:
 * You are given the root of a Binary Search Tree (BST) and a key.
 * Delete the node with value equal to `key` and return the updated root.
 *
 * The deletion must maintain BST properties.
 *
 * ------------------------------------------------------------
 * APPROACH: Recursive BST Deletion — Your Approach
 *
 * Core BST Property:
 *
 *   • Left subtree  → values < root->val
 *   • Right subtree → values > root->val
 *
 * This property helps us locate the node to delete efficiently.
 *
 * ------------------------------------------------------------
 * High-Level Strategy:
 *
 * 1. Traverse the BST to FIND the node with value = key
 * 2. Once found, handle deletion based on number of children:
 *
 *      Case 1: Node is a LEAF
 *      Case 2: Node has ONE child
 *      Case 3: Node has TWO children
 *
 * ------------------------------------------------------------
 * Helper Function: findMin(node)
 *
 * Purpose:
 * - Find the inorder successor of a node
 * - In a BST, the inorder successor is:
 *     → the smallest value in the RIGHT subtree
 *
 * Implementation:
 * - Keep moving left until node->left == nullptr
 *
 * ------------------------------------------------------------
 * deleteNode(root, key) — Step-by-Step
 *
 * STEP 1: Base Case
 *
 *   If root == nullptr
 *     → key not found
 *     → return nullptr
 *
 * STEP 2: Locate the Node
 *
 *   If key < root->val
 *     → search LEFT subtree
 *
 *   If key > root->val
 *     → search RIGHT subtree
 *
 * STEP 3: Node Found (root->val == key)
 *
 *   Now handle deletion cases:
 *
 * ------------------------------------------------------------
 * Case 1: Leaf Node (No children)
 *
 *   if (!root->left && !root->right)
 *     → delete node
 *     → return nullptr
 *
 * ------------------------------------------------------------
 * Case 2: One Child
 *
 *   a) Only RIGHT child exists
 *        - Store root->right
 *        - Delete root
 *        - Return right child
 *
 *   b) Only LEFT child exists
 *        - Store root->left
 *        - Delete root
 *        - Return left child
 *
 * ------------------------------------------------------------
 * Case 3: Two Children
 *
 *   - Find inorder successor (smallest node in right subtree)
 *   - Copy successor's value into current node
 *   - Recursively delete successor from right subtree
 *
 *   Why this works:
 *     - Inorder successor preserves BST ordering
 *     - Actual deletion happens lower in the tree
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - BST properties guide traversal
 * - All structural changes preserve BST rules
 * - Recursive returns rebuild the tree correctly
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * Delete key = 3
 *
 * Initial BST:
 *          5
 *        /   \
 *       3     6
 *      / \
 *     2   4
 *
 * Node 3 has TWO children
 *
 * Inorder successor = 4
 *
 * Replace 3 → 4
 * Delete 4 from right subtree
 *
 * Final BST:
 *          5
 *        /   \
 *       4     6
 *      /
 *     2
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Deleting root node
 * - Tree with one node
 * - Key not present
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - O(h)
 *   where h = height of the BST
 *
 *   • Balanced BST → O(log n)
 *   • Skewed BST   → O(n)
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(h) due to recursion stack
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This problem is a classic:
 *   "BST Modification with Structural Cases"
 *
 * Related problems:
 * - Insert into BST
 * - Search in BST
 * - Validate BST
 */

class Solution {
private:
    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        // Step 1: Find the node
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {
            // Step 2: Node found

            // Case 1: Leaf node
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            }

            // Case 2: One child
            if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Two children
            TreeNode* temp = findMin(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }

        return root;
    }
};

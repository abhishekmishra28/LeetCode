/*
 * Problem: 1382. Balance a Binary Search Tree
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given the root of a Binary Search Tree (BST),
 * return a balanced BST with the same node values.
 *
 * A BST is balanced if for every node, the height difference
 * between left and right subtrees is at most 1.
 *
 * ------------------------------------------------------------
 * APPROACH: Inorder Traversal + Build Balanced BST
 *
 * Key Observation:
 * - Inorder traversal of a BST gives nodes in SORTED order.
 * - A balanced BST can be constructed from a sorted array
 *   by always choosing the middle element as root.
 *
 * ------------------------------------------------------------
 * STEP-BY-STEP EXPLANATION:
 *
 * 1️⃣ Perform Inorder Traversal
 *    - Traverse the BST in inorder (Left → Root → Right)
 *    - Store all node values in a vector
 *    - Resulting vector is sorted
 *
 * 2️⃣ Build Balanced BST from Sorted Array
 *    - Choose middle element as root
 *    - Recursively build left subtree from left half
 *    - Recursively build right subtree from right half
 *
 * 3️⃣ Return the new root
 *
 * ------------------------------------------------------------
 * EXAMPLE:
 *
 * Input BST (Unbalanced):
 *        1
 *         \
 *          2
 *           \
 *            3
 *             \
 *              4
 *
 * Inorder Traversal:
 *   [1, 2, 3, 4]
 *
 * Balanced BST:
 *         2
 *       /   \
 *      1     3
 *             \
 *              4
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 * - O(n)
 *   - Inorder traversal: O(n)
 *   - Building BST: O(n)
 *
 * Space Complexity:
 * - O(n)
 *   - Inorder array storage
 *   - Recursion stack
 *
 * ------------------------------------------------------------
 * WHY THIS APPROACH WORKS:
 *
 * ✅ Preserves BST property
 * ✅ Guarantees minimum height
 * ✅ Clean divide-and-conquer strategy
 * ✅ Very common interview solution
 *
 * ------------------------------------------------------------
 * IMPORTANT NOTE:
 * - This builds a NEW balanced BST
 * - Node values are reused, not original node pointers
 */

class Solution {
private:
    vector<int> inorder;

    // Step 1: Inorder traversal to get sorted values
    void helper(TreeNode* root, vector<int> &inorder) {
        if (!root) return;
        helper(root->left, inorder);
        inorder.push_back(root->val);
        helper(root->right, inorder);
    }

    // Step 2: Build balanced BST from sorted array
    TreeNode* buildBST(int left, int right) {
        if (left > right) return nullptr;

        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(inorder[mid]);

        root->left  = buildBST(left, mid - 1);
        root->right = buildBST(mid + 1, right);

        return root;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {

        // Step 1: Store inorder traversal
        helper(root, inorder);

        // Step 2: Build balanced BST
        return buildBST(0, inorder.size() - 1);
    }
};

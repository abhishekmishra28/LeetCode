/*
 * Problem: 98. Validate Binary Search Tree
 *
 * Statement:
 * Given the root of a binary tree, determine if it is a valid
 * Binary Search Tree (BST).
 *
 * A valid BST must satisfy:
 *   - All values in the LEFT subtree < node->val
 *   - All values in the RIGHT subtree > node->val
 *   - Both subtrees must also be valid BSTs
 *
 * ------------------------------------------------------------
 * APPROACH: DFS with Range Validation — Your Approach
 *
 * Core Insight:
 *
 * - Checking only immediate children is NOT sufficient
 * - Every node must satisfy constraints imposed by ALL its ancestors
 *
 * So instead of checking:
 *   left < root < right
 *
 * We check:
 *   mini < node->val < maxi
 *
 * where:
 *   - mini = lower bound allowed for this node
 *   - maxi = upper bound allowed for this node
 *
 * ------------------------------------------------------------
 * Helper Function Explanation:
 *
 * valid(node, mini, maxi)
 *
 * Parameters:
 * - node → current tree node
 * - mini → minimum allowed value for node->val
 * - maxi → maximum allowed value for node->val
 *
 * ------------------------------------------------------------
 * Recursive Logic:
 *
 * 1. Base Case:
 *
 *    If node == nullptr
 *        → empty tree is a valid BST
 *        → return true
 *
 * 2. Value Check:
 *
 *    If node->val <= mini OR node->val >= maxi
 *        → violates BST property
 *        → return false
 *
 * 3. Recurse:
 *
 *    - LEFT subtree:
 *        valid(node->left, mini, node->val)
 *
 *    - RIGHT subtree:
 *        valid(node->right, node->val, maxi)
 *
 * 4. Return true only if BOTH subtrees are valid
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Bounds propagate ancestor constraints correctly
 * - Prevents invalid cases like:
 *
 *        10
 *       /  \
 *      5    15
 *          /
 *         6   ❌ (6 < 10 but in right subtree)
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * Tree:
 *        5
 *       / \
 *      3   7
 *
 * Initial call:
 *   valid(5, -∞, +∞)
 *
 * Left:
 *   valid(3, -∞, 5) ✔
 *
 * Right:
 *   valid(7, 5, +∞) ✔
 *
 * Result → valid BST
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Duplicate values → INVALID BST
 * - Single node → valid BST
 * - Empty tree → valid BST
 *
 * ------------------------------------------------------------
 * Why LONG_MIN and LONG_MAX:
 *
 * - Node values can be as small as INT_MIN or as large as INT_MAX
 * - Using long avoids overflow issues during comparison
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - O(n)
 *   Every node is visited exactly once
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(h)
 *   Recursion stack where h = height of the tree
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Tree DFS with Valid Range Propagation"
 *
 * Seen in:
 * - Validate BST
 * - Serialize / Deserialize BST
 * - BST boundary problems
 */

class Solution {
private:
    bool valid(TreeNode* node, long mini, long maxi) {
        if (!node) return true;

        if (node->val <= mini || node->val >= maxi)
            return false;

        return valid(node->left, mini, node->val) &&
               valid(node->right, node->val, maxi);
    }

public:
    bool isValidBST(TreeNode* root) {
        return valid(root, LONG_MIN, LONG_MAX);
    }
};

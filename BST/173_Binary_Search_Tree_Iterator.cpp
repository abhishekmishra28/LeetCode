/*
 * Problem: 173. Binary Search Tree Iterator
 *
 * Statement:
 * Implement an iterator over a Binary Search Tree (BST).
 * The iterator should return the next smallest number.
 *
 * You must implement:
 *   - BSTIterator(root)
 *   - next()
 *   - hasNext()
 *
 * Constraints:
 * - next() and hasNext() should run in average O(1) time
 * - Space complexity should be O(h), where h is the height of the tree
 *
 * ------------------------------------------------------------
 * APPROACH: Controlled Inorder Traversal using Stack (Your Approach)
 *
 * Core Idea:
 *
 * - Inorder traversal of a BST gives values in ascending order
 * - Instead of doing full inorder traversal upfront,
 *   we simulate it lazily using a stack
 *
 * ------------------------------------------------------------
 * Why Stack?
 *
 * - Recursion uses implicit stack
 * - Here, we use an explicit stack to:
 *     • Pause traversal
 *     • Resume exactly where we left off
 *
 * ------------------------------------------------------------
 * Data Structure Used:
 *
 * stack<TreeNode*> st
 *   - Stores nodes whose left subtree has been processed
 *   - Top of stack is always the next smallest element
 *
 * ------------------------------------------------------------
 * Helper Function: pushall(node)
 *
 * Purpose:
 *   Push the node and all its left descendants onto the stack
 *
 * Why?
 *   - Leftmost node is always the smallest in BST
 *
 * Implementation:
 *
 *   while(node != NULL):
 *       push node
 *       node = node->left
 *
 * ------------------------------------------------------------
 * Constructor: BSTIterator(root)
 *
 * Goal:
 *   Prepare iterator so that next() returns the smallest element
 *
 * Steps:
 *
 * 1. Call pushall(root)
 * 2. Stack now contains path from root to smallest element
 *
 * ------------------------------------------------------------
 * next():
 *
 * Goal:
 *   Return the next smallest element
 *
 * Steps:
 *
 * 1. Pop the top node from stack → this is current smallest
 * 2. If popped node has a right child:
 *      - Call pushall(node->right)
 *      - This ensures next smallest elements are prepared
 * 3. Return popped node’s value
 *
 * ------------------------------------------------------------
 * hasNext():
 *
 * Goal:
 *   Check if more elements are available
 *
 * Logic:
 *
 * - If stack is not empty → elements still remain
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * BST:
 *        7
 *       / \
 *      3   15
 *         /  \
 *        9   20
 *
 * Initialization:
 *   pushall(7) → stack = [7,3]
 *
 * next() → pop 3 → return 3
 *
 * next() → pop 7 → pushall(15) → stack = [15,9]
 *
 * next() → pop 9 → return 9
 *
 * next() → pop 15 → pushall(20)
 *
 * next() → pop 20
 *
 * hasNext() → false
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Stack always maintains the path to the next inorder node
 * - Each node is:
 *     • Pushed once
 *     • Popped once
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - next(): Amortized O(1)
 * - hasNext(): O(1)
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(h), where h is height of BST
 * - Worst case: O(n) for skewed tree
 *
 * ------------------------------------------------------------
 * Comparison:
 *
 * Full inorder traversal:
 *   - Time: O(n)
 *   - Space: O(n)
 *
 * This iterator:
 *   - Time: O(1) amortized per operation
 *   - Space: O(h)
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * - BST + Inorder Traversal
 * - Lazy traversal using stack
 * - Iterator design pattern
 */

class BSTIterator {
private:
    stack<TreeNode*> st;

    // Push current node and all left descendants
    void pushall(TreeNode* node) {
        for (; node != NULL; st.push(node), node = node->left);
    }

public:
    // Constructor
    BSTIterator(TreeNode* root) {
        pushall(root);
    }

    // Return next smallest element
    int next() {
        TreeNode* tempNode = st.top();
        st.pop();
        pushall(tempNode->right);
        return tempNode->val;
    }

    // Check if iterator has next element
    bool hasNext() {
        return !st.empty();
    }
};

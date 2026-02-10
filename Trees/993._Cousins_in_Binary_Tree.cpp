/*
 * Problem: 993. Cousins in Binary Tree
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given the root of a binary tree and two integers x and y,
 * return true if the nodes with values x and y are cousins.
 *
 * Two nodes are cousins if:
 * - They are on the same level (same depth)
 * - They have different parents
 *
 * ------------------------------------------------------------
 * APPROACH: Level Order Traversal (BFS)
 *
 * ------------------------------------------------------------
 * KEY OBSERVATIONS:
 *
 * 1️⃣ Cousins must be at the SAME depth.
 * 2️⃣ Cousins must NOT share the same parent.
 * 3️⃣ Level order traversal naturally processes nodes
 *    level-by-level → perfect fit for this problem.
 *
 * ------------------------------------------------------------
 * STRATEGY:
 *
 * - Use BFS with a queue
 * - At each level:
 *   → Check if x and y are present
 *   → Ensure they are not siblings
 *
 * ------------------------------------------------------------
 * SIBLING CHECK LOGIC:
 *
 * If a node has both left and right children:
 * - If one child is x and the other is y → siblings → NOT cousins
 *
 * ------------------------------------------------------------
 * ALGORITHM STEPS:
 *
 * 1️⃣ Push root into queue
 * 2️⃣ While queue is not empty:
 *    - Process one level at a time
 *    - Track if x and y are found at current level
 *    - Check sibling condition
 * 3️⃣ If both found at same level → return true
 * 4️⃣ If only one found → return false
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * Tree:
 *        1
 *       / \
 *      2   3
 *       \
 *        4
 *
 * x = 4, y = 3
 *
 * - 4 is at level 2
 * - 3 is at level 1
 * → Not cousins → false
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 * - O(n) (each node visited once)
 *
 * Space Complexity:
 * - O(n) (queue for BFS)
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - BFS is more intuitive than DFS here
 * - Level-based checks are crucial
 * - Early sibling detection avoids extra work
 */

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {

        // Edge case: empty tree
        if (!root)
            return false;

        queue<TreeNode*> q;
        q.push(root);

        // Perform level order traversal
        while (!q.empty()) {

            int n = q.size();
            bool foundX = false, foundY = false;

            // Process all nodes at current level
            for (int i = 0; i < n; i++) {

                TreeNode* curr = q.front();
                q.pop();

                // Check if current node matches x or y
                if (curr->val == x)
                    foundX = true;
                if (curr->val == y)
                    foundY = true;

                // Check if x and y are siblings
                if (curr->left && curr->right) {
                    int l = curr->left->val;
                    int r = curr->right->val;

                    if ((l == x && r == y) || (l == y && r == x))
                        return false;
                }

                // Push children for next level
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }

            // If both found at same level and not siblings
            if (foundX && foundY)
                return true;
        }

        return false;
    }
};

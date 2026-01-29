/*
 * Problem: 199. Binary Tree Right Side View
 *
 * Statement:
 * Given the root of a binary tree, imagine yourself standing
 * on the RIGHT side of it.
 *
 * Return the values of the nodes you can see,
 * ordered from top to bottom.
 *
 * ------------------------------------------------------------
 * APPROACH 1: BFS (Level Order Traversal) — Your Approach
 *
 * Core Idea:
 *
 * - Perform level-order traversal (BFS)
 * - For each level, the RIGHTMOST node is visible
 * - Store the last node of every level
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (BFS):
 *
 * 1. If root is NULL → return empty answer
 *
 * 2. Push root into a queue
 *
 * 3. While queue is not empty:
 *
 *      a) Let n = queue size (nodes at current level)
 *
 *      b) Traverse all n nodes:
 *            - Pop node
 *            - Push its children (left first, then right)
 *
 *      c) After processing the level,
 *         the LAST processed node is the rightmost one
 *         → add it to answer
 *
 * 4. Return answer
 *
 * ------------------------------------------------------------
 * Why BFS Works:
 *
 * - BFS processes tree level by level
 * - Rightmost node of each level is visible from the right side
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n)  (each node visited once)
 *
 * Space Complexity:
 * - O(n)  (queue in worst case)
 *
 * ------------------------------------------------------------
 * BFS CODE (Cleaned Version of Your Logic)
 */

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            TreeNode* node = nullptr;

            for (int i = 0; i < n; i++) {
                node = q.front();
                q.pop();

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // last node of this level
            ans.push_back(node->val);
        }
        return ans;
    }
};


/*
 * ------------------------------------------------------------
 * APPROACH 2: DFS (Right-First Preorder Traversal)
 *
 * Core Idea:
 *
 * - Traverse the tree using DFS
 * - Visit RIGHT child before LEFT child
 * - The FIRST node we encounter at each depth
 *   is the rightmost node
 *
 * ------------------------------------------------------------
 * DFS Strategy:
 *
 * - Maintain current depth
 * - If depth == ans.size():
 *       → first time visiting this level
 *       → add node value to ans
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (DFS):
 *
 * 1. Start DFS from root at depth = 0
 *
 * 2. At each node:
 *      a) If node is NULL → return
 *
 *      b) If depth == ans.size():
 *           → add node->val to ans
 *
 *      c) Recurse RIGHT child first
 *      d) Recurse LEFT child
 *
 * 3. Return ans
 *
 * ------------------------------------------------------------
 * Why DFS Works:
 *
 * - Right-first traversal ensures rightmost nodes
 *   are visited before others at the same level
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n)
 *
 * Space Complexity:
 * - O(h) where h = height of tree (recursion stack)
 *
 * ------------------------------------------------------------
 * DFS CODE (Separate as Requested)
 */

class SolutionDFS {
public:
    void dfs(TreeNode* root, int depth, vector<int>& ans) {
        if (!root) return;

        if (depth == ans.size()) {
            ans.push_back(root->val);
        }

        dfs(root->right, depth + 1, ans);
        dfs(root->left, depth + 1, ans);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        dfs(root, 0, ans);
        return ans;
    }
};

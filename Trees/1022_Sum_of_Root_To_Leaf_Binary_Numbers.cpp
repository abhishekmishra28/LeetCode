/*
 * Problem: 1022. Sum of Root To Leaf Binary Numbers
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * You are given a binary tree where each node has value 0 or 1.
 *
 * Each root-to-leaf path represents a binary number.
 *
 * Return the sum of all root-to-leaf binary numbers.
 *
 * ------------------------------------------------------------
 * EXPLANATION:
 *
 * Example:
 *
 *        1
 *       / \
 *      0   1
 *     / \   \
 *    0   1   1
 *
 * Root-to-leaf paths:
 *
 * 100 → 4
 * 101 → 5
 * 111 → 7
 *
 * Total = 4 + 5 + 7 = 16
 *
 * ------------------------------------------------------------
 * APPROACH: DFS + Path Construction
 *
 * ------------------------------------------------------------
 * KEY OBSERVATIONS:
 *
 * 1️⃣ Each path forms a binary number.
 *
 * 2️⃣ When we reach a leaf:
 *    - Convert binary string to integer.
 *
 * 3️⃣ Add values from left and right subtrees.
 *
 * ------------------------------------------------------------
 * STRATEGY:
 *
 * 1️⃣ Use DFS traversal.
 *
 * 2️⃣ Maintain current binary path as string.
 *
 * 3️⃣ At leaf:
 *      Convert binary string → integer.
 *
 * 4️⃣ Return sum of left and right subtree values.
 *
 * ------------------------------------------------------------
 * HELPER FUNCTION: binaryToInt
 *
 * Converts binary string to integer using:
 *
 *   result += 2^position (for each '1')
 *
 * ------------------------------------------------------------
 * DFS LOGIC:
 *
 * dfs(node, path):
 *
 *   If node is null → return 0
 *
 *   Append node value to path
 *
 *   If leaf:
 *       return binaryToInt(path)
 *
 *   return dfs(left) + dfs(right)
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 * - O(N * H)
 *   N = nodes
 *   H = height (string conversion cost)
 *
 * Space Complexity:
 * - O(H) recursion stack
 * - O(H) path string
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTE:
 *
 * - This solution works,
 *   but can be optimized by avoiding string + pow().
 *
 *   Better approach:
 *     currentValue = currentValue * 2 + node->val
 *
 *   (More efficient and recommended.)
 */

class Solution {
private:

    int binaryToInt(string s) {

        int res = 0;
        int n = s.length();
        int expo = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1') {
                res += pow(2, expo);
            }
            expo++;
        }

        return res;
    }

    int dfs(TreeNode* node, string path) {

        if (!node)
            return 0;

        // Append current node value
        path.push_back(node->val + '0');

        // If leaf node
        if (!node->left && !node->right) {
            return binaryToInt(path);
        }

        // Recurse left and right
        return dfs(node->left, path) +
               dfs(node->right, path);
    }

public:
    int sumRootToLeaf(TreeNode* root) {

        return dfs(root, "");
    }
};

/*
 * Problem: 129. Sum Root to Leaf Numbers
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * You are given the root of a binary tree where each node
 * contains a digit from 0–9.
 *
 * Each root-to-leaf path represents a number formed by
 * concatenating the digits along the path.
 *
 * Return the total sum of all root-to-leaf numbers.
 *
 * ------------------------------------------------------------
 * EXAMPLE:
 *
 * Tree:
 *
 *       1
 *      / \
 *     2   3
 *
 * Paths:
 *
 * 1 → 2  → "12" → 12
 * 1 → 3  → "13" → 13
 *
 * Result:
 *
 * 12 + 13 = 25
 *
 * ------------------------------------------------------------
 * APPROACH: DFS + Backtracking
 *
 * ------------------------------------------------------------
 * CORE IDEA:
 *
 * We perform a Depth-First Search from the root to all leaves.
 *
 * While traversing the tree we maintain a string that
 * represents the current path number.
 *
 * When we reach a leaf node:
 *
 *      convert the path string into an integer
 *      and add it to the result list.
 *
 * Finally, sum all collected numbers.
 *
 * ------------------------------------------------------------
 * ALGORITHM STEPS:
 *
 * 1️⃣ Start DFS from the root.
 *
 * 2️⃣ Append current node value to the path string.
 *
 * 3️⃣ If the node is a leaf:
 *
 *      convert path → integer
 *      store in result vector.
 *
 * 4️⃣ Otherwise recursively explore:
 *
 *      left subtree
 *      right subtree
 *
 * 5️⃣ Backtrack by removing the last digit
 *    from the path.
 *
 * ------------------------------------------------------------
 * DRY RUN:
 *
 * Tree:
 *
 *      4
 *     / \
 *    9   0
 *   / \
 *  5   1
 *
 * Paths:
 *
 * 4 → 9 → 5 → 495
 * 4 → 9 → 1 → 491
 * 4 → 0 → 40
 *
 * Sum = 495 + 491 + 40 = 1026
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 *      O(N)
 *      Each node is visited once.
 *
 * Space Complexity:
 *      O(H)
 *      Recursion stack where H is tree height.
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * Instead of storing strings, an optimized approach
 * directly builds numbers using:
 *
 *      current = current * 10 + node->val
 *
 * which avoids string conversions.
 */

class Solution {
private:

    void getPath(TreeNode* root, string path, vector<int> &ans){

        if(!root) return;

        path += to_string(root->val);

        // Leaf node
        if(!root->left && !root->right){

            ans.push_back(stoi(path));

        } else {

            getPath(root->left, path, ans);
            getPath(root->right, path, ans);
        }

        // Backtracking
        path.pop_back();
    }

public:

    int sumNumbers(TreeNode* root) {

        vector<int> ans;

        getPath(root, "", ans);

        return accumulate(ans.begin(), ans.end(), 0);
    }
};

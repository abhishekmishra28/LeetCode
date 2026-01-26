/*
 * Problem: 386. Lexicographical Numbers
 *
 * Statement:
 * Given an integer `n`, return all the numbers from 1 to n
 * in LEXICOGRAPHICAL (dictionary) order.
 *
 * You must achieve this WITHOUT converting numbers to strings.
 *
 * ------------------------------------------------------------
 * APPROACH: DFS (Lexicographical Traversal) — Your Approach
 *
 * Core Idea:
 *
 * - Think of numbers as nodes in a tree:
 *
 *          1
 *       / / \ \
 *     10 11 12 ... 19
 *     |
 *    100
 *
 * - Lexicographical order is exactly a PREORDER DFS
 *   traversal of this implicit tree.
 *
 * ------------------------------------------------------------
 * Helper Function: lexo(curr, n, result)
 *
 * Purpose:
 * - Generate numbers starting from `curr`
 * - Explore all valid numbers by appending digits 0–9
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. Base Case:
 *      If curr > n:
 *          → Stop recursion
 *
 * 2. Add current number:
 *      result.push_back(curr)
 *
 * 3. Try appending digits 0 to 9:
 *
 *      for i = 0 to 9:
 *          next = curr * 10 + i
 *
 *          If next > n:
 *              break (further digits will only increase value)
 *
 *          Recurse:
 *              lexo(next, n, result)
 *
 * ------------------------------------------------------------
 * Main Function Logic: lexicalOrder(n)
 *
 * 1. Initialize empty result array
 *
 * 2. Start DFS from digits 1 to 9:
 *
 *      for i = 1 to 9:
 *          lexo(i, n, result)
 *
 *    (Because numbers cannot start with 0)
 *
 * 3. Return result
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - DFS preorder ensures lexicographical ordering
 * - No string conversion is needed
 * - Early stopping prevents unnecessary recursion
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * n = 13
 *
 * Start:
 * 1 → 10 → 11 → 12 → 13
 * 2
 * 3
 * ...
 * 9
 *
 * Output:
 * [1,10,11,12,13,2,3,4,5,6,7,8,9]
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - n < 10 → simple sequential output
 * - n = 1 → [1]
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n)
 *   Every number from 1 to n is visited exactly once
 *
 * Space Complexity:
 * - O(n)
 *   Output storage + recursion stack
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "DFS on Implicit Tree"
 *
 * Seen in:
 * - Lexicographical ordering
 * - Trie traversal
 * - Number generation problems
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void lexo(int curr, int n, vector<int> &result) {
        if (curr > n) return;

        result.push_back(curr);

        for (int i = 0; i <= 9; i++) {
            int next = curr * 10 + i;
            if (next > n) break;
            lexo(next, n, result);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> result;

        for (int i = 1; i <= 9; i++) {
            lexo(i, n, result);
        }
        return result;
    }
};

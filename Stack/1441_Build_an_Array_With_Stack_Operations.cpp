/*
 * Problem: 1441. Build an Array With Stack Operations
 *
 * Statement:
 * You are given an integer array `target` and an integer `n`.
 *
 * You have an empty stack and an integer `idx = 1`.
 * You can perform the following operations:
 *
 *  - "Push": Push `idx` onto the stack and increment `idx`
 *  - "Pop" : Pop the top element from the stack
 *
 * You must build the array `target` using numbers from 1 to n
 * and return the sequence of operations.
 *
 * ------------------------------------------------------------
 * APPROACH: Simulation using Greedy Logic — Your Approach
 *
 * Core Idea:
 *
 * - We simulate reading numbers from 1 to n (using `idx`)
 * - For each value in `target`:
 *     • If current number matches target value → keep it
 *     • Otherwise → push and immediately pop until match
 *
 * - This ensures we only keep elements that are needed
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. Initialize:
 *
 *      idx = 1                // current number to read
 *      ans = empty list       // operations result
 *
 * 2. Iterate over target array:
 *
 *      For each target[i]:
 *
 *      a) If target[i] == idx:
 *
 *           - "Push"
 *           - idx++
 *
 *      b) Else (target[i] > idx):
 *
 *           - "Push"
 *           - "Pop"
 *           - idx++
 *           - i--  // recheck same target value
 *
 * 3. Continue until all target elements are processed
 *
 * 4. Return ans
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Numbers must be read in increasing order
 * - Any number not in `target` must be discarded immediately
 * - Greedy simulation ensures minimum operations
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * Input:
 *   target = [1,3]
 *   n = 3
 *
 * idx = 1:
 *   target[0] == 1 → Push
 *
 * idx = 2:
 *   target[1] != 2 → Push, Pop
 *
 * idx = 3:
 *   target[1] == 3 → Push
 *
 * Output:
 *   ["Push","Push","Pop","Push"]
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - target already equals [1,2,3,...]
 * - target contains only large numbers
 * - n > last element of target (ignored safely)
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - O(n)
 *   Each number is pushed at most once
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(target.size())
 *   Stores operations
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Simulation + Greedy Stack Operations"
 *
 * Seen in:
 * - Stack simulation problems
 * - Controlled sequence construction
 */

class Solution {
public:
    vector<string> ans;

    vector<string> buildArray(vector<int>& target, int n) {
        int sz = target.size();
        int idx = 1;

        for (int i = 0; i < sz; i++) {
            if (target[i] == idx) {
                ans.push_back("Push");
                idx++;
            } else {
                ans.push_back("Push");
                ans.push_back("Pop");
                idx++;
                i--;  // retry same target element
            }
        }
        return ans;
    }
};

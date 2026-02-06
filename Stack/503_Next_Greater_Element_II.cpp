/*
 * Problem: 503. Next Greater Element II (Circular Array)
 *
 * Statement:
 * Given a circular integer array nums, return the next greater element
 * for every element in nums.
 *
 * The next greater element of nums[i] is the first element to the right
 * of nums[i] in the circular traversal that is strictly greater than it.
 * If no such element exists, return -1.
 *
 * ------------------------------------------------------------
 * APPROACH: Monotonic Stack + Circular Traversal (Your Approach)
 *
 * Core Idea:
 *
 * - Treat the array as circular by iterating from 0 → 2*n - 1
 * - Use a monotonic decreasing stack of indices
 * - Each element gets a chance to find its next greater element
 *
 * ------------------------------------------------------------
 * Why Circular Traversal?
 *
 * - In a circular array, elements at the end can find their next
 *   greater element at the beginning
 * - Simulate circular behavior using index modulo (i % n)
 *
 * ------------------------------------------------------------
 * Data Structures Used:
 *
 * - stack<int> st
 *     → Stores indices of elements whose NGE is not yet found
 *
 * - vector<int> res
 *     → Stores the next greater element for each index
 *     → Initialized with -1
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm:
 *
 * Let n = nums.size()
 *
 * Loop i from 0 to 2*n - 1:
 *
 * 1. curr = i % n
 *    → Maps index into circular range
 *
 * 2. While stack is not empty AND:
 *        nums[st.top()] < nums[curr]
 *
 *    - nums[curr] is the next greater element
 *    - Update result for index st.top()
 *    - Pop from stack
 *
 * 3. Push curr index into stack
 *
 * ------------------------------------------------------------
 * Important Detail:
 *
 * - We push indices even during second pass
 * - Result array prevents overwriting already resolved values
 * - Stack ensures each index is processed efficiently
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * nums = [1,2,1]
 *
 * i = 0 → curr = 0 → push 0
 * i = 1 → curr = 1 → pop 0 → res[0] = 2 → push 1
 * i = 2 → curr = 2 → push 2
 *
 * i = 3 → curr = 0 → nothing pops
 * i = 4 → curr = 1 → pop 2 → res[2] = 2
 * i = 5 → curr = 2 → no pop
 *
 * Result = [2, -1, 2]
 *
 * ------------------------------------------------------------
 * Why Monotonic Stack Works:
 *
 * - Stack maintains indices of elements in decreasing order
 * - Once a greater element is found, it's final
 * - Each index is pushed and popped at most once
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - O(n)
 *   Each element is pushed and popped once
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(n)
 *   Stack + result array
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * - Circular Next Greater Element
 * - Monotonic Stack (Decreasing)
 * - Index-based stack
 */

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> res(n, -1);

        // Circular traversal
        for(int i = 0; i < 2 * n; i++) {
            int curr = i % n;

            while(!st.empty() && nums[st.top()] < nums[curr]) {
                res[st.top()] = nums[curr];
                st.pop();
            }

            st.push(curr);
        }
        return res;
    }
};

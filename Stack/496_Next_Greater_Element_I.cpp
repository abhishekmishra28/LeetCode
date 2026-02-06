/*
 * Problem: 496. Next Greater Element I
 *
 * Statement:
 * You are given two integer arrays nums1 and nums2 where nums1 is a subset of nums2.
 * For each element in nums1, find the next greater element in nums2.
 *
 * The next greater element of x in nums2 is the first element to the right of x
 * that is strictly greater than x. If no such element exists, return -1.
 *
 * ------------------------------------------------------------
 * APPROACH: Monotonic Stack + Hash Map (Your Approach)
 *
 * Core Idea:
 *
 * - Preprocess nums2 to find the Next Greater Element (NGE) for every value
 * - Store the result in a hash map
 * - Answer queries for nums1 in O(1) time using the map
 *
 * ------------------------------------------------------------
 * Key Observations:
 *
 * - nums1 is a subset of nums2 → we only need to compute NGE for nums2 once
 * - Next Greater Element problems are best solved using a Monotonic Stack
 *
 * ------------------------------------------------------------
 * Data Structures Used:
 *
 * - stack<int> st
 *     → Maintains a decreasing monotonic stack
 *
 * - unordered_map<int,int> mpp
 *     → Maps each value in nums2 to its next greater element
 *
 * ------------------------------------------------------------
 * Step 1: Process nums2 from RIGHT to LEFT
 *
 * Why right to left?
 * - Because the "next" greater element lies on the right side
 *
 * For each nums2[i]:
 *
 * 1. Pop elements from stack while:
 *        stack.top() ≤ nums2[i]
 *    (They can never be the NGE for nums2[i])
 *
 * 2. If stack is empty:
 *        → No greater element exists → NGE = -1
 *
 * 3. Else:
 *        → stack.top() is the next greater element
 *
 * 4. Store result in map:
 *        mpp[nums2[i]] = NGE
 *
 * 5. Push nums2[i] onto stack
 *
 * ------------------------------------------------------------
 * Step 2: Build result for nums1
 *
 * For each element in nums1:
 * - Fetch its precomputed NGE from the map
 * - Store it in the result array
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * nums1 = [4,1,2]
 * nums2 = [1,3,4,2]
 *
 * Processing nums2:
 *
 * i = 3 → 2 → stack empty → NGE = -1
 * i = 2 → 4 → pop 2 → stack empty → NGE = -1
 * i = 1 → 3 → top = 4 → NGE = 4
 * i = 0 → 1 → top = 3 → NGE = 3
 *
 * Map:
 *   1 → 3
 *   3 → 4
 *   4 → -1
 *   2 → -1
 *
 * Result for nums1:
 *   [ -1, 3, -1 ]
 *
 * ------------------------------------------------------------
 * Why Monotonic Stack Works:
 *
 * - Stack maintains elements in strictly decreasing order
 * - Ensures nearest greater element is found efficiently
 * - Each element is pushed and popped at most once
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - Processing nums2: O(n)
 * - Processing nums1: O(m)
 *
 * Overall: O(n + m)
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - Stack: O(n)
 * - Hash map: O(n)
 *
 * Overall: O(n)
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * - Classic "Next Greater Element"
 * - Monotonic Stack (Decreasing)
 * - Hashing for fast lookups
 */

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> mpp;

        // Step 1: Compute NGE for nums2
        for(int i = nums2.size() - 1; i >= 0; i--) {
            while(!st.empty() && nums2[i] > st.top())
                st.pop();

            mpp[nums2[i]] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }

        // Step 2: Build result for nums1
        vector<int> sol(nums1.size());
        for(int i = 0; i < nums1.size(); i++) {
            sol[i] = mpp[nums1[i]];
        }

        return sol;
    }
};

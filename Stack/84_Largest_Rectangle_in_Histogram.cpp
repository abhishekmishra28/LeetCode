/*
 * Problem: 84. Largest Rectangle in Histogram
 *
 * Statement:
 * You are given an array `heights` where each element represents
 * the height of a histogram bar with width = 1.
 *
 * Find the area of the LARGEST rectangle that can be formed
 * inside the histogram.
 *
 * ------------------------------------------------------------
 * APPROACH: Monotonic Stack (Previous Smaller + Next Smaller)
 *           — Your Approach
 *
 * Core Idea:
 *
 * - For every bar `i`, consider it as the HEIGHT of the rectangle
 * - Expand left and right until a smaller bar is found
 *
 * Rectangle width for bar `i`:
 *
 *      width = (index of next smaller) - (index of prev smaller) - 1
 *
 * Area:
 *
 *      area = heights[i] * width
 *
 * To compute this efficiently, we use a MONOTONIC INCREASING STACK.
 *
 * ------------------------------------------------------------
 * Step 1: Previous Smaller Element (PSE)
 *
 * Meaning:
 * - For each index `i`, find the closest index to the LEFT
 *   such that heights[pse[i]] < heights[i]
 *
 * Algorithm:
 *
 * - Traverse from LEFT → RIGHT
 * - Maintain a stack of indices with increasing heights
 *
 * For each `i`:
 *   - Pop indices while heights[st.top()] >= heights[i]
 *   - If stack is empty → pse[i] = -1
 *   - Else → pse[i] = st.top()
 *   - Push i into stack
 *
 * ------------------------------------------------------------
 * Step 2: Next Smaller Element (NSE)
 *
 * Meaning:
 * - For each index `i`, find the closest index to the RIGHT
 *   such that heights[nse[i]] < heights[i]
 *
 * Algorithm:
 *
 * - Traverse from RIGHT → LEFT
 * - Use the same monotonic increasing stack
 *
 * For each `i`:
 *   - Pop indices while heights[st.top()] >= heights[i]
 *   - If stack is empty → nse[i] = n
 *   - Else → nse[i] = st.top()
 *   - Push i into stack
 *
 * ------------------------------------------------------------
 * Step 3: Calculate Maximum Area
 *
 * For each bar `i`:
 *
 *      width = nse[i] - pse[i] - 1
 *      area  = heights[i] * width
 *
 * Update the maximum area.
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - PSE tells how far we can extend LEFT
 * - NSE tells how far we can extend RIGHT
 * - Using a monotonic stack ensures O(n) time
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * heights = [2,1,5,6,2,3]
 *
 * i = 2 (height = 5):
 *   pse = 1
 *   nse = 4
 *   width = 4 - 1 - 1 = 2
 *   area = 5 * 2 = 10
 *
 * Maximum area = 10
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Single bar → area = height
 * - All bars same height
 * - Strictly increasing / decreasing histogram
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - O(n)
 *   Each index is pushed and popped at most once
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(n)
 *   For stack + PSE + NSE arrays
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a CLASSIC:
 *   "Monotonic Stack + Range Expansion" problem
 *
 * Seen in:
 * - Histogram problems
 * - Stock span
 * - Next/Previous greater/smaller problems
 */

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> pse(n), nse(n);
        stack<int> st;

        // 1. Previous Smaller Element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // clear stack
        while (!st.empty()) st.pop();

        // 2. Next Smaller Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // 3. Compute maximum area
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = nse[i] - pse[i] - 1;
            maxArea = max(maxArea, heights[i] * width);
        }

        return maxArea;
    }
};

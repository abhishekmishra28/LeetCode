/*
 * Problem: 155. Min Stack
 *
 * Statement:
 * Design a stack that supports the following operations in O(1) time:
 *
 *  - push(x): Push element x onto stack
 *  - pop(): Remove the element on top of the stack
 *  - top(): Get the top element
 *  - getMin(): Retrieve the minimum element in the stack
 *
 * ------------------------------------------------------------
 * APPROACH: Stack of Pairs (Value + Current Minimum) — Your Approach
 *
 * Core Idea:
 *
 * - Along with each value, store the MINIMUM value of the stack
 *   up to that point.
 *
 * - This way:
 *     • getMin() becomes O(1)
 *     • No extra stack or traversal is needed
 *
 * ------------------------------------------------------------
 * Data Structure Used:
 *
 * stack<pair<int,int>> st
 *
 * Each stack element stores:
 *   - first  → actual value pushed
 *   - second → minimum value in the stack at this level
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. push(val):
 *
 *      If stack is empty:
 *          push {val, val}
 *          // current value is also the minimum
 *
 *      Else:
 *          push {val, min(val, st.top().second)}
 *          // store updated minimum so far
 *
 * 2. pop():
 *
 *      Simply pop the top element
 *
 * 3. top():
 *
 *      Return st.top().first
 *
 * 4. getMin():
 *
 *      Return st.top().second
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Every stack level knows the minimum up to itself
 * - When popping, the previous minimum is automatically restored
 * - No recomputation is required
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * Operations:
 *
 *   push(5) → stack: [(5,5)]
 *   push(3) → stack: [(5,5),(3,3)]
 *   push(7) → stack: [(5,5),(3,3),(7,3)]
 *
 * getMin() → 3
 *
 * pop() → removes (7,3)
 *
 * getMin() → 3
 *
 * pop() → removes (3,3)
 *
 * getMin() → 5
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Stack is empty → top() returns -1 (as per your code)
 * - Duplicate minimum values are handled correctly
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - push(): O(1)
 * - pop(): O(1)
 * - top(): O(1)
 * - getMin(): O(1)
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(n)
 *   One pair stored per element
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Augmented Stack" problem
 *
 * Seen in:
 * - Min/Max stack variants
 * - Sliding window minimum
 * - Stack with extra metadata
 */

class MinStack {
private:
    // pair<value, minimum_so_far>
    stack<pair<int,int>> st;

public:
    MinStack() {}

    void push(int val) {
        if (st.empty()) {
            st.push({val, val});
        } else {
            st.push({val, min(val, st.top().second)});
        }
    }

    void pop() {
        st.pop();
    }

    int top() {
        if (st.empty()) return -1;
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};

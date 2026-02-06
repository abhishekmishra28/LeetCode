/*
 * Problem: 225. Implement Stack using Queues
 *
 * Statement:
 * Implement a Last-In-First-Out (LIFO) stack using only two queues.
 * You must support the following operations:
 *
 *   - push(x)
 *   - pop()
 *   - top()
 *   - empty()
 *
 * ------------------------------------------------------------
 * APPROACH: Costly Push using Two Queues — Your Approach
 *
 * Core Idea:
 *
 * - Always maintain the stack TOP at the FRONT of q1
 * - Make push() costly so that pop() and top() become O(1)
 *
 * ------------------------------------------------------------
 * Data Structures Used:
 *
 * - q1 → Main queue (acts like the stack)
 * - q2 → Helper queue (used during push operation)
 *
 * ------------------------------------------------------------
 * Invariant Maintained:
 *
 * After every push operation:
 *   - q1.front() is ALWAYS the top of the stack
 *
 * ------------------------------------------------------------
 * push(x) — Step-by-Step:
 *
 * 1. Push x into q2
 * 2. Move all elements from q1 to q2
 *      (this places x in front of all previous elements)
 * 3. Swap q1 and q2
 *
 * Result:
 *   q1 order becomes: [x, top-1, top-2, ..., bottom]
 *
 * Time Complexity: O(n)
 *
 * ------------------------------------------------------------
 * pop() — Step-by-Step:
 *
 * 1. Remove and return q1.front()
 *
 * Since q1.front() is always the stack top,
 * pop works in O(1) time.
 *
 * ------------------------------------------------------------
 * top() — Step-by-Step:
 *
 * 1. Return q1.front()
 *
 * Time Complexity: O(1)
 *
 * ------------------------------------------------------------
 * empty() — Step-by-Step:
 *
 * 1. Check if q1 is empty
 *
 * Time Complexity: O(1)
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * Operations:
 *
 *   push(1)
 *     q1 = [1]
 *
 *   push(2)
 *     q2 = [2]
 *     move q1 → q2 → [2,1]
 *     swap → q1 = [2,1]
 *
 *   top() → 2
 *
 *   pop()
 *     remove 2
 *     q1 = [1]
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Stack requires LIFO order
 * - Queue is FIFO
 * - By reordering elements during push,
 *   we simulate stack behavior
 *
 * ------------------------------------------------------------
 * Trade-Off:
 *
 * - push() is O(n)
 * - pop(), top(), empty() are O(1)
 *
 * This is ideal when:
 *   - Many pop/top operations
 *   - Fewer push operations
 *
 * ------------------------------------------------------------
 * Time Complexity Summary:
 *
 *   push()  → O(n)
 *   pop()   → O(1)
 *   top()   → O(1)
 *   empty() → O(1)
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(n) for storing elements in queues
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Simulate Stack using Queue"
 *
 * Variants:
 * - Costly push (this approach)
 * - Costly pop (alternative)
 */

class MyStack {
private:
    queue<int> q1;
    queue<int> q2;

public:
    MyStack() {}

    void push(int x) {
        // Step 1: push new element to q2
        q2.push(x);

        // Step 2: move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Step 3: swap q1 and q2
        swap(q1, q2);
    }

    int pop() {
        int out = q1.front();
        q1.pop();
        return out;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

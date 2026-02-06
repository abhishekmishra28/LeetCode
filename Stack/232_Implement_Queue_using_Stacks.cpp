/*
 * Problem: 232. Implement Queue using Stacks
 *
 * Statement:
 * Implement a First-In-First-Out (FIFO) queue using only two stacks.
 * You must support the following operations:
 *
 *   - push(x)
 *   - pop()
 *   - peek()
 *   - empty()
 *
 * ------------------------------------------------------------
 * APPROACH: Costly Push using Two Stacks — Your Approach
 *
 * Core Idea:
 *
 * - Always maintain the FRONT of the queue at the TOP of st1
 * - Make push() costly so that pop() and peek() are O(1)
 *
 * ------------------------------------------------------------
 * Data Structures Used:
 *
 * - st1 → Main stack (represents the queue)
 * - st2 → Helper stack (used temporarily during push)
 *
 * ------------------------------------------------------------
 * Invariant Maintained:
 *
 * After every push operation:
 *   - st1.top() is ALWAYS the front of the queue
 *
 * ------------------------------------------------------------
 * push(x) — Step-by-Step:
 *
 * Goal:
 *   Insert element x at the BOTTOM of the queue
 *
 * Steps:
 *
 * 1. Move all elements from st1 to st2
 *      (reverses the order temporarily)
 *
 * 2. Push x into st1
 *
 * 3. Move all elements back from st2 to st1
 *
 * Result:
 *   st1 stack order (top → bottom):
 *     front, ..., last, x
 *
 * Time Complexity: O(n)
 *
 * ------------------------------------------------------------
 * pop() — Step-by-Step:
 *
 * 1. Remove and return st1.top()
 *
 * Since st1.top() is always the queue FRONT,
 * pop works in O(1) time.
 *
 * ------------------------------------------------------------
 * peek() — Step-by-Step:
 *
 * 1. Return st1.top()
 *
 * Time Complexity: O(1)
 *
 * ------------------------------------------------------------
 * empty() — Step-by-Step:
 *
 * 1. Check if both stacks are empty
 *
 * Time Complexity: O(1)
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * Operations:
 *
 *   push(1)
 *     st1 = [1]
 *
 *   push(2)
 *     move st1 → st2 → [1]
 *     push 2 into st1 → [2]
 *     move st2 → st1 → [2,1]
 *
 *   peek() → 1
 *
 *   pop()
 *     remove 1
 *     st1 = [2]
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Queue requires FIFO order
 * - Stack is LIFO
 * - By reversing elements during push,
 *   we maintain correct queue order
 *
 * ------------------------------------------------------------
 * Trade-Off:
 *
 * - push() is O(n)
 * - pop(), peek(), empty() are O(1)
 *
 * This approach is ideal when:
 *   - Many pop / peek operations
 *   - Fewer push operations
 *
 * ------------------------------------------------------------
 * Time Complexity Summary:
 *
 *   push()  → O(n)
 *   pop()   → O(1)
 *   peek()  → O(1)
 *   empty() → O(1)
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(n) for stack storage
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Simulate Queue using Stacks"
 *
 * Variants:
 * - Costly push (this approach)
 * - Costly pop (amortized O(1))
 */

class MyQueue {
private:
    stack<int> st1;
    stack<int> st2;

public:
    MyQueue() {}

    void push(int x) {
        // Step 1: move all elements from st1 to st2
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }

        // Step 2: push new element
        st1.push(x);

        // Step 3: move everything back to st1
        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
    }

    int pop() {
        int out = st1.top();
        st1.pop();
        return out;
    }

    int peek() {
        return st1.top();
    }

    bool empty() {
        return st1.empty() && st2.empty();
    }
};

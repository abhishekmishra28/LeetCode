/*
 * Problem: 622. Design Circular Queue
 *
 * Statement:
 * Design a circular queue with a fixed size k.
 * Implement the following operations:
 *
 *   - enQueue(value)
 *   - deQueue()
 *   - Front()
 *   - Rear()
 *   - isEmpty()
 *   - isFull()
 *
 * ------------------------------------------------------------
 * APPROACH: Doubly Linked List + Size Tracking (Your Approach)
 *
 * Core Idea:
 *
 * - Use a Doubly Linked List to represent the queue
 * - Maintain:
 *     • head → front of the queue
 *     • tail → rear of the queue
 *     • size → current number of elements
 *     • capacity → maximum allowed elements
 *
 * Even though the problem says “circular queue”,
 * circular behavior is logically enforced using size & capacity,
 * not by physically linking tail back to head.
 *
 * ------------------------------------------------------------
 * Data Structures Used:
 *
 * struct List
 *   - val  → stores data
 *   - next → pointer to next node
 *   - prev → pointer to previous node
 *
 * Class Variables:
 *
 *   capacity → maximum queue size
 *   size     → current number of elements
 *   head     → front pointer
 *   tail     → rear pointer
 *
 * ------------------------------------------------------------
 * Constructor:
 *
 * MyCircularQueue(int k):
 *   - Set capacity = k
 *   - Initialize size = 0
 *   - head = tail = nullptr
 *
 * ------------------------------------------------------------
 * enQueue(value):
 *
 * Goal:
 *   Insert value at the rear of the queue
 *
 * Steps:
 *
 * 1. If queue is full → return false
 *
 * 2. Create a new node
 *
 * 3. If queue is empty:
 *      head = tail = new node
 *
 * 4. Else:
 *      tail->next = node
 *      node->prev = tail
 *      tail = node
 *
 * 5. Increment size
 *
 * Time Complexity: O(1)
 *
 * ------------------------------------------------------------
 * deQueue():
 *
 * Goal:
 *   Remove the front element of the queue
 *
 * Steps:
 *
 * 1. If queue is empty → return false
 *
 * 2. Store current head
 *
 * 3. If size == 1:
 *      head = tail = nullptr
 *
 * 4. Else:
 *      head = head->next
 *      head->prev = nullptr
 *
 * 5. Decrement size
 *
 * Time Complexity: O(1)
 *
 * ------------------------------------------------------------
 * Front():
 *
 * - If empty → return -1
 * - Else return head->val
 *
 * Time Complexity: O(1)
 *
 * ------------------------------------------------------------
 * Rear():
 *
 * - If empty → return -1
 * - Else return tail->val
 *
 * Time Complexity: O(1)
 *
 * ------------------------------------------------------------
 * isEmpty():
 *
 * - Returns true if size == 0
 *
 * Time Complexity: O(1)
 *
 * ------------------------------------------------------------
 * isFull():
 *
 * - Returns true if size == capacity
 *
 * Time Complexity: O(1)
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * capacity = 3
 *
 * enQueue(10) → [10]
 * enQueue(20) → [10,20]
 * enQueue(30) → [10,20,30]
 *
 * isFull() → true
 *
 * deQueue() → removes 10 → [20,30]
 *
 * Front() → 20
 * Rear()  → 30
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Doubly linked list allows O(1) insertion & deletion
 * - size variable enforces circular queue constraints
 * - No array shifting required
 *
 * ------------------------------------------------------------
 * Time Complexity Summary:
 *
 * enQueue() → O(1)
 * deQueue() → O(1)
 * Front()   → O(1)
 * Rear()    → O(1)
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(k) for k nodes in the linked list
 *
 * ------------------------------------------------------------
 * Interview Notes:
 *
 * - Even without physically circular links,
 *   logical circular behavior is achieved via capacity control
 * - Clean separation of concerns using head & tail pointers
 */

struct List {
    int val;
    List* next;
    List* prev;
    List(int x) {
        val = x;
        next = nullptr;
        prev = nullptr;
    }
};

class MyCircularQueue {
private:
    int capacity;
    int size;
    List* head;
    List* tail;

public:
    MyCircularQueue(int k) {
        capacity = k;
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    bool enQueue(int value) {
        if (isFull()) return false;

        List* node = new List(value);

        if (isEmpty()) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }

        size++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;

        if (size == 1) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }

        size--;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return head->val;
    }

    int Rear() {
        if (isEmpty()) return -1;
        return tail->val;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};

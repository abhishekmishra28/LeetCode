/*
 * Problem: 641. Design Circular Deque
 *
 * Statement:
 * Design a circular double-ended queue (deque) with a fixed capacity k.
 * Implement the following operations:
 *
 *   - insertFront(value)
 *   - insertLast(value)
 *   - deleteFront()
 *   - deleteLast()
 *   - getFront()
 *   - getRear()
 *   - isEmpty()
 *   - isFull()
 *
 * ------------------------------------------------------------
 * APPROACH: Doubly Linked List + Size & Capacity Tracking
 * (Your Approach)
 *
 * Core Idea:
 *
 * - Use a Doubly Linked List to allow O(1) insertion and deletion
 *   from both the front and the rear.
 * - Maintain:
 *     • head → front of deque
 *     • tail → rear of deque
 *     • size → current number of elements
 *     • capacity → maximum allowed elements
 *
 * Even though the problem says "circular deque",
 * circular behavior is logically enforced using:
 *     size == capacity
 * not by physically connecting tail->next to head.
 *
 * ------------------------------------------------------------
 * Data Structures Used:
 *
 * struct List
 *   - val  → value of the node
 *   - next → pointer to next node
 *   - prev → pointer to previous node
 *
 * Class Members:
 *
 *   capacity → maximum number of elements allowed
 *   size     → current size of deque
 *   head     → pointer to front
 *   tail     → pointer to rear
 *
 * ------------------------------------------------------------
 * Constructor:
 *
 * MyCircularDeque(int k):
 *   - capacity = k
 *   - size = 0
 *   - head = tail = nullptr
 *
 * ------------------------------------------------------------
 * insertFront(value):
 *
 * Goal:
 *   Insert value at the FRONT of the deque
 *
 * Steps:
 *
 * 1. If deque is full → return false
 *
 * 2. Create a new node
 *
 * 3. If deque is empty:
 *      head = tail = node
 *
 * 4. Else:
 *      node->next = head
 *      head->prev = node
 *      head = node
 *
 * 5. Increment size
 *
 * Time Complexity: O(1)
 *
 * ------------------------------------------------------------
 * insertLast(value):
 *
 * Goal:
 *   Insert value at the REAR of the deque
 *
 * Steps:
 *
 * 1. If deque is full → return false
 *
 * 2. Create a new node
 *
 * 3. If deque is empty:
 *      head = tail = node
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
 * deleteFront():
 *
 * Goal:
 *   Remove element from the FRONT
 *
 * Steps:
 *
 * 1. If deque is empty → return false
 *
 * 2. Store current head
 *
 * 3. If only one element exists:
 *      head = tail = nullptr
 *
 * 4. Else:
 *      head = head->next
 *      head->prev = nullptr
 *
 * 5. Delete old head
 * 6. Decrement size
 *
 * Time Complexity: O(1)
 *
 * ------------------------------------------------------------
 * deleteLast():
 *
 * Goal:
 *   Remove element from the REAR
 *
 * Steps:
 *
 * 1. If deque is empty → return false
 *
 * 2. Store current tail
 *
 * 3. If only one element exists:
 *      head = tail = nullptr
 *
 * 4. Else:
 *      tail = tail->prev
 *      tail->next = nullptr
 *
 * 5. Delete old tail
 * 6. Decrement size
 *
 * Time Complexity: O(1)
 *
 * ------------------------------------------------------------
 * getFront():
 *
 * - If empty → return -1
 * - Else return head->val
 *
 * Time Complexity: O(1)
 *
 * ------------------------------------------------------------
 * getRear():
 *
 * - If empty → return -1
 * - Else return tail->val
 *
 * Time Complexity: O(1)
 *
 * ------------------------------------------------------------
 * isEmpty():
 *
 * - Return true if size == 0
 *
 * Time Complexity: O(1)
 *
 * ------------------------------------------------------------
 * isFull():
 *
 * - Return true if size == capacity
 *
 * Time Complexity: O(1)
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * capacity = 3
 *
 * insertLast(10) → [10]
 * insertFront(20) → [20,10]
 * insertLast(30) → [20,10,30]
 *
 * isFull() → true
 *
 * deleteFront() → removes 20 → [10,30]
 * getFront() → 10
 * getRear()  → 30
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Doubly linked list allows O(1) access from both ends
 * - Size counter enforces circular constraints
 * - No shifting or resizing required
 *
 * ------------------------------------------------------------
 * Time Complexity Summary:
 *
 * insertFront  → O(1)
 * insertLast   → O(1)
 * deleteFront  → O(1)
 * deleteLast   → O(1)
 * getFront     → O(1)
 * getRear      → O(1)
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(k) where k is capacity (linked list nodes)
 *
 * ------------------------------------------------------------
 * Interview Notes:
 *
 * - Circular deque does NOT require physical circular links
 * - Logical circularity using size & capacity is sufficient
 * - Clean, readable, and interview-safe implementation
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

class MyCircularDeque {
private:
    int capacity;
    int size;
    List* head;
    List* tail;

public:
    MyCircularDeque(int k) {
        capacity = k;
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    bool insertFront(int value) {
        if (isFull()) return false;
        List* node = new List(value);

        if (isEmpty()) {
            head = tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }

        size++;
        return true;
    }

    bool insertLast(int value) {
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

    bool deleteFront() {
        if (isEmpty()) return false;

        List* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }

        delete temp;
        size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;

        List* node = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }

        delete node;
        size--;
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return head->val;
    }

    int getRear() {
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

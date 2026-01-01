/*
Problem: 146. LRU Cache

Design a data structure that supports:

1. LRUCache(int capacity)
   Initialize the cache with a positive capacity.

2. int get(int key)
   Return the value associated with the key if present,
   otherwise return -1. Accessing a key makes it the
   most recently used.

3. void put(int key, int value)
   Insert or update (key, value).
   If the cache exceeds capacity, evict the
   least recently used key.

Both get() and put() must run in O(1) average time.

We achieve this using:
- A doubly linked list to store nodes in recency order
  (front = most recent, back = least recent)
- An unordered_map<int, Node*> for O(1) key lookup
*/

class Node {
public:
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int k, int v) {
        key = k;
        val = v;
        next = prev = nullptr;
    }
};

class LRUCache {
public:
    unordered_map<int, Node*> mpp;   // key -> node pointer
    int capacity;
    Node* head;   // dummy head (before most recent)
    Node* tail;   // dummy tail (after least recent)

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    // Removes a node from the linked list
    void deleteNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Inserts a node right after head (most recently used position)
    void insertAtHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    // Returns value if present, otherwise -1.
    // Also moves accessed node to the MRU position.
    int get(int key) {
        if (!mpp.count(key)) return -1;

        Node* node = mpp[key];
        deleteNode(node);
        insertAtHead(node);

        return node->val;
    }

    /*
      put(key, value):

      Case 1 — key exists:
          Update value and move node to MRU.

      Case 2 — key does not exist and cache is full:
          Remove the LRU node (node before tail),
          erase it from map, then insert new node.

      Case 3 — key does not exist and cache has space:
          Simply insert new node at MRU.
    */
    void put(int key, int value) {

        // Key already exists → update + move to head
        if (mpp.count(key)) {
            Node* node = mpp[key];
            node->val = value;

            deleteNode(node);
            insertAtHead(node);
            return;
        }

        // Cache full → evict LRU
        if (mpp.size() == capacity) {
            Node* lru = tail->prev;
            deleteNode(lru);
            mpp.erase(lru->key);
            delete lru;
        }

        // Insert new key
        Node* node = new Node(key, value);
        insertAtHead(node);
        mpp[key] = node;
    }
};

/**
 * Example usage:
 * LRUCache* obj = new LRUCache(capacity);
 * int value = obj->get(key);
 * obj->put(key, value);
 */

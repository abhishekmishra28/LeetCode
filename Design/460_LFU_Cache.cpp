
/*
 * Problem: LFU Cache
 *
 * Design a data structure that supports:
 *
 * get(key)
 *   - Return value if key exists, else -1
 *   - Increase key's frequency
 *
 * put(key, value)
 *   - Insert or update (key, value)
 *   - If cache exceeds capacity, evict:
 *       -> key with lowest frequency
 *       -> if tie, evict least recently used among them
 *
 * Both operations should run in O(1) average time.
 *
 * Core idea:
 * ----------
 * 1) Map key -> node   (O(1) lookups)
 * 2) Map freq -> doubly linked list of nodes
 *      - Front = most recently used at that frequency
 *      - Back  = least recently used at that frequency
 * 3) Track current min frequency
 */

#include <bits/stdc++.h>
using namespace std;

class LFUCache {
private:
    struct Node {
        int key, value, freq;
        Node(int k, int v) : key(k), value(v), freq(1) {}
    };

    int capacity;
    int minFreq;

    unordered_map<int, Node*> keyMap;               // key -> node
    unordered_map<int, list<Node*>> freqMap;        // freq -> list of nodes
    unordered_map<int, list<Node*>::iterator> pos;  // key -> iterator in list

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    // Move node to next frequency bucket
    void update(Node* node) {
        int f = node->freq;

        // Remove from current frequency list
        freqMap[f].erase(pos[node->key]);

        // If this was the last node in the lowest freq list
        if (freqMap[f].empty()) {
            freqMap.erase(f);
            if (minFreq == f) minFreq++;
        }

        // Add node to freq+1 list (most recent at front)
        node->freq++;
        freqMap[node->freq].push_front(node);
        pos[node->key] = freqMap[node->freq].begin();
    }

    int get(int key) {
        if (!capacity || !keyMap.count(key)) return -1;

        Node* node = keyMap[key];
        update(node);
        return node->value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        // Case 1: key already exists -> update value + freq
        if (keyMap.count(key)) {
            Node* node = keyMap[key];
            node->value = value;
            update(node);
            return;
        }

        // Case 2: cache full -> evict LFU
        if (keyMap.size() == capacity) {
            Node* victim = freqMap[minFreq].back();   // LRU within min freq
            freqMap[minFreq].pop_back();

            if (freqMap[minFreq].empty())
                freqMap.erase(minFreq);

            keyMap.erase(victim->key);
            pos.erase(victim->key);
            delete victim;
        }

        // Case 3: insert new node
        Node* node = new Node(key, value);
        minFreq = 1;

        freqMap[1].push_front(node);
        pos[key] = freqMap[1].begin();
        keyMap[key] = node;
    }
};

int main() {
    LFUCache cache(2);

    cache.put(1, 10);
    cache.put(2, 20);
    cout << cache.get(1) << endl;   // 10 (freq of key1 becomes 2)

    cache.put(3, 30);               // key 2 evicted (freq1 < freq2)
    cout << cache.get(2) << endl;   // -1
    cout << cache.get(3) << endl;   // 30

    cache.put(4, 40);               // key 1 evicted (freq2 tie, LRU removed)
    cout << cache.get(1) << endl;   // -1
    cout << cache.get(3) << endl;   // 30
    cout << cache.get(4) << endl;   // 40
}

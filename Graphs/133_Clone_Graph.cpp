/*
 * Problem: 133. Clone Graph
 *
 * Statement:
 * Given a reference of a node in a connected undirected graph,
 * return a deep copy (clone) of the graph.
 *
 * Each node in the graph contains:
 * - an integer value `val`
 * - a list of neighbors `neighbors`
 *
 * The graph is represented using adjacency lists.
 *
 * ------------------------------------------------------------
 * Important Clarifications:
 * - The graph may contain cycles
 * - The graph is connected
 * - Node values are unique
 * - You must create NEW nodes (deep copy), not reuse old ones
 *
 * ------------------------------------------------------------
 * Key Challenge:
 * - If the graph contains cycles, naive DFS/BFS will loop forever
 * - We must remember already cloned nodes
 *
 * ------------------------------------------------------------
 * Approach 1: DFS + Hash Map (Most Intuitive)
 *
 * Idea:
 * - Traverse the graph using DFS
 * - For each node:
 *   - Create its clone
 *   - Store mapping: original node → cloned node
 * - If a node is visited again, return the already created clone
 *
 * Data Structure Used:
 * - unordered_map<Node*, Node*> to store mapping
 *
 * Why this works:
 * - Prevents infinite recursion due to cycles
 * - Ensures each node is cloned exactly once
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm:
 *
 * 1. If input node is NULL → return NULL
 * 2. If current node already exists in map → return its clone
 * 3. Create a new node with same value as current node
 * 4. Store it in the map
 * 5. Recursively clone all neighbors and attach them
 * 6. Return the cloned node
 *
 * ------------------------------------------------------------
 * Example:
 *
 * Graph:
 * 1 -- 2
 * |    |
 * 4 -- 3
 *
 * DFS Order:
 * clone(1)
 *  ├─ clone(2)
 *  │   └─ clone(3)
 *  │       └─ clone(4)
 *
 * Mapping ensures already visited nodes are reused
 *
 * ------------------------------------------------------------
 * Edge Cases:
 * - Single node graph
 * - Graph with cycles
 * - Graph with self-loop
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(V + E)
 *   where V = number of vertices, E = number of edges
 *
 * Space Complexity:
 * - O(V)
 *   for hash map + recursion stack
 *
 * ------------------------------------------------------------
 * Note:
 * This is the most commonly expected solution in interviews.
 * BFS solution is also valid and equivalent.
 */

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Map to store original node -> cloned node
    unordered_map<Node*, Node*> cloned;

    Node* cloneGraph(Node* node) {
        // Base case
        if (node == NULL)
            return NULL;

        // If already cloned, return it
        if (cloned.find(node) != cloned.end())
            return cloned[node];

        // Create a clone of current node
        Node* copy = new Node(node->val);

        // Store mapping
        cloned[node] = copy;

        // Clone all neighbors
        for (Node* neigh : node->neighbors) {
            copy->neighbors.push_back(cloneGraph(neigh));
        }

        return copy;
    }
};

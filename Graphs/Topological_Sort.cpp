/*
 * Problem: Topological Sort (DFS-based)
 *
 * Statement:
 * You are given a Directed Acyclic Graph (DAG) with:
 * - V vertices labeled from 0 to V-1
 * - E directed edges, where each edge is represented as [u, v]
 *   meaning there is a directed edge u → v
 *
 * Your task is to return a TOPOLOGICAL ORDERING of the graph.
 *
 * A Topological Sort is a linear ordering of vertices such that:
 * For every directed edge u → v,
 * vertex u appears BEFORE vertex v in the ordering.
 *
 * NOTE:
 * - The graph is guaranteed to be a DAG
 * - Multiple valid topological orders may exist
 * - You may return ANY valid one
 *
 * ------------------------------------------------------------
 * Key Observations:
 *
 * - Topological sort is only possible for DAGs
 * - If a cycle exists, topological ordering is impossible
 * - DFS finishing times naturally give topological order
 *
 * ------------------------------------------------------------
 * Approach: DFS + Stack (Classic Topological Sort)
 *
 * Core Idea:
 * - Perform DFS on the graph
 * - Push a node into a stack ONLY AFTER all its neighbors
 *   have been fully processed
 *
 * This ensures:
 * - A node appears AFTER all nodes it points to
 * - Reversing this order gives a valid topological ordering
 *
 * ------------------------------------------------------------
 * Why DFS Works Here:
 *
 * - DFS explores dependencies first
 * - When a node finishes (post-order), all nodes dependent on it
 *   are already placed in the stack
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm:
 *
 * 1. Build adjacency list from the given edge list
 *
 * 2. Initialize:
 *    - visited array `vis` of size V
 *    - empty stack `st`
 *
 * 3. For every vertex from 0 to V-1:
 *    - If not visited, start DFS
 *
 * 4. In DFS:
 *    - Mark current node as visited
 *    - DFS on all unvisited neighbors
 *    - Push current node into stack AFTER exploring neighbors
 *
 * 5. After DFS of all nodes:
 *    - Pop elements from stack
 *    - This gives the topological order
 *
 * ------------------------------------------------------------
 * Example:
 *
 * V = 6
 * edges = [[5,2],[5,0],[4,0],[4,1],[2,3],[3,1]]
 *
 * One valid topological order:
 * [5, 4, 2, 3, 1, 0]
 *
 * (Many answers are possible)
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Graph with multiple disconnected components
 * - Graph with single node
 * - Graph with no edges
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(V + E)
 *   Each vertex and edge is visited once
 *
 * Space Complexity:
 * - O(V + E)
 *   Adjacency list + recursion stack + explicit stack
 *
 * ------------------------------------------------------------
 * Note:
 * This is the MOST COMMONLY ASKED topological sort approach.
 * Interviewers expect you to explain it using DFS finishing times.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    /*
     * DFS helper function
     * Pushes node into stack after exploring all neighbors
     */
    void dfs(int node, vector<int>& vis,
             vector<vector<int>>& adj,
             stack<int>& st) {

        vis[node] = 1;

        // Visit all outgoing edges
        for (auto nxt : adj[node]) {
            if (!vis[nxt]) {
                dfs(nxt, vis, adj, st);
            }
        }

        // Post-order insertion
        st.push(node);
    }

public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {

        // Step 1: Build adjacency list
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }

        vector<int> vis(V, 0);
        stack<int> st;

        // Step 2: Run DFS for all components
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, adj, st);
            }
        }

        // Step 3: Pop stack to get topological order
        vector<int> topo;
        while (!st.empty()) {
            topo.push_back(st.top());
            st.pop();
        }

        return topo;
    }
};

/*
 * Problem: 3650. Minimum Cost Path with Edge Reversals
 *
 * Statement:
 * You are given a directed, weighted graph with `n` nodes (0 to n-1).
 * Each edge is given as:
 *      edges[i] = [u, v, w]
 * meaning there is a directed edge u -> v with cost w.
 *
 * Special Rule (Switch Mechanism):
 * - Each node u has a SWITCH that can be used AT MOST ONCE.
 * - When you arrive at node u, you may:
 *      • pick ONE incoming edge (v -> u),
 *      • temporarily reverse it to (u -> v),
 *      • traverse it immediately with cost = 2 * w.
 * - This reversal is valid for ONLY that single move.
 *
 * Task:
 * - Find the MINIMUM cost to go from node 0 to node n-1.
 * - If not possible, return -1.
 *
 * ------------------------------------------------------------
 * KEY INSIGHT:
 *
 * The "edge reversal" with cost 2*w is NOT persistent.
 * It is equivalent to saying:
 *
 *   From v -> u (cost w),
 *   we ALSO have a virtual edge u -> v with cost 2*w,
 *   but usable only once per node.
 *
 * However, since the switch can be used at most once per node,
 * the simplest and correct modeling (used here) is:
 *
 * - Build a graph where:
 *     u -> v with cost w        (original edge)
 *     v -> u with cost 2*w      (simulating reversal)
 *
 * Then run Dijkstra.
 *
 * Why this works:
 * - Any reversed edge is used immediately and only once.
 * - Dijkstra will naturally choose the cheapest combination.
 * - Using a reversed edge twice would be more expensive and
 *   never optimal.
 *
 * ------------------------------------------------------------
 * APPROACH: Dijkstra on Modified Graph (Greedy)
 *
 * Since:
 * - All costs are NON-NEGATIVE
 * - We need shortest path
 *
 * → Dijkstra’s algorithm is optimal.
 *
 * ------------------------------------------------------------
 * GRAPH CONSTRUCTION:
 *
 * For each edge [u, v, w]:
 *   - Add edge u -> v with cost w
 *   - Add edge v -> u with cost 2*w
 *
 * This converts the problem into a standard shortest path problem.
 *
 * ------------------------------------------------------------
 * DIJKSTRA IMPLEMENTATION DETAILS:
 *
 * - dist[i]: shortest distance to node i
 * - vis[i]: whether node i is finalized
 * - Priority queue stores (distance, node)
 *   (implemented as max-heap with negative distances)
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm:
 *
 * 1. Build adjacency list G with modified edges
 *
 * 2. Initialize:
 *      dist[0] = 0
 *      dist[others] = INF
 *
 * 3. Push (0, 0) into priority queue
 *
 * 4. While queue is not empty:
 *
 *    a) Extract node u with smallest distance
 *    b) If u already visited → continue
 *    c) Mark u visited
 *    d) Relax all edges from u:
 *
 *         for each (v, w):
 *             if dist[u] + w < dist[v]:
 *                 dist[v] = dist[u] + w
 *                 push into queue
 *
 * 5. If dist[n-1] == INF → return -1
 *    Else return dist[n-1]
 *
 * ------------------------------------------------------------
 * Example:
 *
 * n = 4
 * edges = [[0,1,3],[3,1,1],[2,3,4],[0,2,2]]
 *
 * Graph edges:
 *   0 -> 1 (3)
 *   1 -> 0 (6)
 *   3 -> 1 (1)
 *   1 -> 3 (2)
 *   2 -> 3 (4)
 *   3 -> 2 (8)
 *   0 -> 2 (2)
 *   2 -> 0 (4)
 *
 * Optimal path:
 *   0 -> 2 (2)
 *   2 -> 3 (4)
 *   3 -> 1 (1)
 *   1 -> 3 (2) [reverse]
 *
 * Total = 5
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - Graph construction: O(E)
 * - Dijkstra: O((V + E) log V)
 *
 * ------------------------------------------------------------
 * Space Complexity:
 * - O(V + E)
 *
 * ------------------------------------------------------------
 * PATTERN RECOGNITION:
 *
 * This is a classic:
 *   "Graph with Special Moves → Expand State Space or Edges"
 *
 * Similar to:
 * - Shortest path with discounts
 * - Graph with teleport edges
 * - One-time power usage problems
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<pair<int,int>>> G;

    int dijkstra(int n) {
        vector<int> dist(n, 1e9);
        vector<bool> vis(n, false);

        priority_queue<pair<int,int>> pq;
        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (vis[u]) continue;
            vis[u] = true;

            for (auto [v, w] : G[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({-dist[v], v});
                }
            }
        }

        return (dist[n-1] == 1e9 ? -1 : dist[n-1]);
    }

    int minCost(int n, vector<vector<int>>& edges) {
        G.assign(n, {});

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            G[u].push_back({v, w});        // normal edge
            G[v].push_back({u, 2 * w});    // reversed edge (switch)
        }

        return dijkstra(n);
    }
};

/*
 * Problem: 1971. Find if Path Exists in Graph
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * There is an undirected graph with n nodes labeled from 0 to n-1.
 *
 * You are given:
 *   - edges → list of undirected edges
 *   - source
 *   - destination
 *
 * Return true if there is a valid path from source to destination.
 *
 * ------------------------------------------------------------
 * APPROACH: Breadth-First Search (BFS)
 *
 * ------------------------------------------------------------
 * KEY OBSERVATIONS:
 *
 * 1️⃣ The graph is undirected.
 *
 * 2️⃣ We only need to check reachability.
 *
 * 3️⃣ This is a classic graph traversal problem.
 *
 * 4️⃣ BFS guarantees we explore level by level.
 *
 * ------------------------------------------------------------
 * STRATEGY:
 *
 * 1️⃣ Build adjacency list from edges.
 *
 * 2️⃣ Use a visited array to avoid revisiting nodes.
 *
 * 3️⃣ Start BFS from source.
 *
 * 4️⃣ If we reach destination → return true.
 *
 * 5️⃣ If BFS finishes without reaching destination
 *    → return false.
 *
 * ------------------------------------------------------------
 * ALGORITHM STEPS:
 *
 * Step 1: Create adjacency list:
 *
 *   adj[a].push_back(b);
 *   adj[b].push_back(a);
 *
 * Step 2: Initialize:
 *
 *   queue<int> q;
 *   vector<bool> vis(n, false);
 *
 * Step 3: BFS:
 *
 *   - Push source
 *   - While queue not empty:
 *       - Pop node
 *       - If node == dest → return true
 *       - Visit all unvisited neighbors
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * n = 3
 * edges = [[0,1],[1,2]]
 * source = 0
 * dest = 2
 *
 * BFS:
 * 0 → 1 → 2 → Found
 *
 * Return true.
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 * - O(n + e)
 *   n = nodes
 *   e = edges
 *
 * Space Complexity:
 * - O(n + e) adjacency list
 * - O(n) visited + queue
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - Can also be solved using:
 *     - DFS
 *     - Union-Find (Disjoint Set)
 *
 * - BFS is simplest and cleanest approach.
 */

class Solution {
public:
    bool validPath(int n,
                   vector<vector<int>>& edges,
                   int source,
                   int dest) {

        // Build adjacency list
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            int a = e[0];
            int b = e[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        // Visited array
        vector<bool> vis(n, false);

        queue<int> q;
        q.push(source);
        vis[source] = true;

        // BFS traversal
        while (!q.empty()) {

            int node = q.front();
            q.pop();

            // If destination found
            if (node == dest)
                return true;

            // Explore neighbors
            for (int neigh : adj[node]) {
                if (!vis[neigh]) {
                    vis[neigh] = true;
                    q.push(neigh);
                }
            }
        }

        return false;
    }
};

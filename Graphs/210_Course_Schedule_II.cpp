/*
 * Problem: 210. Course Schedule II
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * There are n courses labeled from 0 to n - 1.
 *
 * You are given prerequisites where:
 *   prereq[i] = [a, b]
 *   → To take course a, you must first take course b.
 *
 * Return an ordering of courses you should take
 * to finish all courses.
 *
 * If it is impossible (cycle exists), return empty array.
 *
 * ------------------------------------------------------------
 * CORE IDEA:
 *
 * This is a Topological Sorting problem.
 *
 * If the directed graph contains a cycle →
 *     No valid ordering exists.
 *
 * If no cycle →
 *     Topological order is the answer.
 *
 * ------------------------------------------------------------
 * APPROACH: DFS + Cycle Detection + Stack
 *
 * ------------------------------------------------------------
 * KEY OBSERVATIONS:
 *
 * 1️⃣ Build directed graph:
 *       b → a
 *
 * 2️⃣ Use DFS to:
 *       - Detect cycle
 *       - Generate topological order
 *
 * 3️⃣ Maintain:
 *       vis[]     → permanently visited
 *       pathVis[] → currently in recursion stack
 *
 * 4️⃣ If we revisit a node in pathVis →
 *       Cycle detected.
 *
 * ------------------------------------------------------------
 * DFS LOGIC:
 *
 * dfs(node):
 *
 *   vis[node] = true
 *   pathVis[node] = true
 *
 *   For each neighbor:
 *       If not visited → dfs(neighbor)
 *       If pathVis[neighbor] == true → cycle
 *
 *   After exploring:
 *       push node into stack
 *       pathVis[node] = false
 *
 * ------------------------------------------------------------
 * WHY STACK?
 *
 * Nodes are pushed AFTER exploring dependencies.
 * So popping gives valid topological order.
 *
 * ------------------------------------------------------------
 * ALGORITHM STEPS:
 *
 * 1️⃣ Build adjacency list.
 *
 * 2️⃣ For each node:
 *       If not visited:
 *           If dfs detects cycle → return {}
 *
 * 3️⃣ Pop stack into result.
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * n = 4
 * prereq = [[1,0],[2,0],[3,1],[3,2]]
 *
 * Graph:
 * 0 → 1
 * 0 → 2
 * 1 → 3
 * 2 → 3
 *
 * Valid order:
 * 0 2 1 3
 * (or 0 1 2 3)
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 * - O(V + E)
 *
 * Space Complexity:
 * - O(V + E)
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - Can also be solved using Kahn's Algorithm (BFS).
 * - DFS method requires careful cycle detection.
 * - Very common interview problem.
 */

class Solution {
private:
    bool dfs(int i,
             vector<vector<int>>& adj,
             stack<int>& st,
             vector<bool>& vis,
             vector<bool>& pathVis) {

        vis[i] = true;
        pathVis[i] = true;

        for (auto& e : adj[i]) {

            if (!vis[e]) {
                if (dfs(e, adj, st, vis, pathVis))
                    return true;
            }
            else if (pathVis[e])
                return true;  // cycle detected
        }

        // Push after exploring dependencies
        st.push(i);

        pathVis[i] = false;

        return false;
    }

public:
    vector<int> findOrder(int n,
                          vector<vector<int>>& prereq) {

        vector<int> result;
        stack<int> st;

        vector<bool> vis(n, false);
        vector<bool> pathVis(n, false);

        vector<vector<int>> adj(n);

        // Build graph
        for (auto& e : prereq) {
            adj[e[1]].push_back(e[0]);
        }

        // DFS traversal
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, st, vis, pathVis))
                    return {};  // cycle found
            }
        }

        // Extract topological order
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        return result;
    }
};

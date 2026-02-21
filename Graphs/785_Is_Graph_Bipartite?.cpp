/*
 * Problem: 785. Is Graph Bipartite?
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given an undirected graph represented as an adjacency list,
 * determine whether it is bipartite.
 *
 * A graph is bipartite if:
 *   - Its vertices can be divided into two groups such that
 *   - No two adjacent vertices belong to the same group.
 *
 * ------------------------------------------------------------
 * DEFINITION:
 *
 * A graph is bipartite ⇔
 * It can be colored using 2 colors
 * such that no adjacent nodes share the same color.
 *
 * ------------------------------------------------------------
 * APPROACH: BFS + Graph Coloring
 *
 * ------------------------------------------------------------
 * KEY OBSERVATIONS:
 *
 * 1️⃣ If graph contains an odd-length cycle →
 *    It is NOT bipartite.
 *
 * 2️⃣ We attempt to color the graph using 2 colors:
 *       0 and 1.
 *
 * 3️⃣ If at any point two adjacent nodes
 *    have the same color → return false.
 *
 * 4️⃣ Graph may be disconnected.
 *    So we must check all components.
 *
 * ------------------------------------------------------------
 * STRATEGY:
 *
 * 1️⃣ Create color array:
 *       -1 → uncolored
 *        0 → color A
 *        1 → color B
 *
 * 2️⃣ For each node:
 *       If uncolored:
 *           - Start BFS
 *           - Assign color 0
 *           - Color neighbors with alternate color
 *
 * 3️⃣ If conflict detected → return false.
 *
 * 4️⃣ If traversal finishes → return true.
 *
 * ------------------------------------------------------------
 * ALGORITHM STEPS:
 *
 * For each node i:
 *   If color[i] == -1:
 *       - color[i] = 0
 *       - BFS from i
 *       - For each neighbor:
 *            If uncolored → assign opposite color
 *            Else if same color → return false
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * Graph:
 * 0 — 1
 * |    |
 * 3 — 2
 *
 * Coloring:
 * 0 → 0
 * 1 → 1
 * 2 → 0
 * 3 → 1
 *
 * Valid bipartite → return true
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 * - O(V + E)
 *
 * Space Complexity:
 * - O(V)
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - Can also solve using DFS.
 * - Bipartite ⇔ No odd-length cycle.
 * - Frequently asked in graph interviews.
 */

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();

        // -1 means uncolored
        vector<int> color(n, -1);

        queue<pair<int, int>> q;

        // Handle disconnected components
        for (int i = 0; i < n; i++) {

            if (color[i] == -1) {

                // Start BFS
                color[i] = 0;
                q.push({i, 0});

                while (!q.empty()) {

                    int node = q.front().first;
                    int currColor = q.front().second;
                    q.pop();

                    for (auto it : graph[node]) {

                        // If not colored yet
                        if (color[it] == -1) {

                            color[it] = 1 - currColor;
                            q.push({it, 1 - currColor});
                        }
                        // Conflict detected
                        else if (color[it] == color[node]) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};

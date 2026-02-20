/*
 * Problem: 207. Course Schedule
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * There are numCourses courses labeled from 0 to numCourses - 1.
 *
 * You are given prerequisites array pre where:
 *   pre[i] = [a, b]
 *   → To take course a, you must first take course b.
 *
 * Return true if you can finish all courses.
 *
 * ------------------------------------------------------------
 * CORE IDEA:
 *
 * This is a cycle detection problem in a Directed Graph.
 *
 * If the graph contains a cycle →
 *     It is impossible to finish all courses.
 *
 * If no cycle →
 *     All courses can be completed.
 *
 * ------------------------------------------------------------
 * APPROACH: Topological Sort (Kahn's Algorithm - BFS)
 *
 * ------------------------------------------------------------
 * KEY OBSERVATIONS:
 *
 * 1️⃣ Build adjacency list:
 *       b → a
 *
 * 2️⃣ Maintain indegree array:
 *       indegree[a]++
 *
 * 3️⃣ Start with all nodes having indegree 0
 *       (courses with no prerequisites).
 *
 * 4️⃣ Perform BFS:
 *       - Remove course
 *       - Reduce indegree of neighbors
 *       - Push new zero-indegree nodes
 *
 * 5️⃣ If total processed courses == numCourses
 *       → No cycle
 *       → return true
 *
 *    Otherwise:
 *       → Cycle exists
 *       → return false
 *
 * ------------------------------------------------------------
 * ALGORITHM STEPS:
 *
 * 1️⃣ Build graph and indegree array.
 *
 * 2️⃣ Push all nodes with indegree == 0 into queue.
 *
 * 3️⃣ While queue not empty:
 *       - Pop node
 *       - Increment completed counter
 *       - Reduce indegree of neighbors
 *       - Push new zero-indegree nodes
 *
 * 4️⃣ Check:
 *       completed == numCourses ?
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * numCourses = 2
 * pre = [[1,0]]
 *
 * Graph:
 * 0 → 1
 *
 * indegree:
 * 0 → 0
 * 1 → 1
 *
 * Process:
 * Take 0 → reduce indegree[1] → 0
 * Take 1
 *
 * completed = 2 → return true
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
 * - Classic Topological Sort problem.
 * - Can also solve using DFS cycle detection.
 * - Very frequently asked in interviews.
 */

class Solution {
public:
    bool canFinish(int numCourses,
                   vector<vector<int>>& pre) {

        // Adjacency list
        vector<vector<int>> adj(numCourses);

        // Indegree array
        vector<int> indegree(numCourses, 0);

        // Build graph
        for (auto& p : pre) {
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        // Queue for courses with no prerequisites
        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        int completed = 0;

        // Kahn's Algorithm (BFS)
        while (!q.empty()) {

            int curr = q.front();
            q.pop();

            completed++;

            for (auto next : adj[curr]) {

                indegree[next]--;

                if (indegree[next] == 0)
                    q.push(next);
            }
        }

        // If all courses processed → no cycle
        return completed == numCourses;
    }
};

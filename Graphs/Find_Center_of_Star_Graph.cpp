/*
 * Problem: 1791. Find Center of Star Graph
 *
 * Statement:
 * You are given the edges of a star graph with n nodes.
 * A star graph is a graph where:
 * - One central node is connected to all other nodes
 * - All other nodes are connected ONLY to the center
 *
 * The graph is given as an edge list `edges`,
 * where edges[i] = [ui, vi] represents an undirected edge.
 *
 * Your task is to find and return the center node of the star graph.
 *
 * ------------------------------------------------------------
 * Key Observations:
 * - In a star graph with n nodes, there are exactly n - 1 edges.
 * - The center node appears in EVERY edge.
 * - Any two edges MUST share the center node.
 *
 * ------------------------------------------------------------
 * Approach 1: Compare First Two Edges (O(1) Solution)
 *
 * Idea:
 * - Take the first two edges only.
 * - Since the center appears in all edges, it MUST be common
 *   between these two edges.
 *
 * Steps:
 * 1. Extract the two nodes from edge[0] → (a, b)
 * 2. Extract the two nodes from edge[1] → (c, d)
 * 3. Compare:
 *    - If `a` matches either `c` or `d`, then `a` is the center
 *    - Otherwise, `b` must be the center
 *
 * Why this works:
 * - In a star graph, every edge contains the center.
 * - Checking only the first two edges is sufficient.
 *
 * ------------------------------------------------------------
 * Example:
 *
 * edges = [[1,2], [2,3], [2,4]]
 *
 * First edge:  (1, 2)
 * Second edge: (2, 3)
 *
 * Common node = 2 → Center
 *
 * ------------------------------------------------------------
 * Edge Cases:
 * - Minimum valid star graph has 3 nodes and 2 edges
 * - Node labels are arbitrary (not necessarily sorted)
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(1) → constant time
 *
 * Space Complexity:
 * - O(1) → no extra space used
 *
 * ------------------------------------------------------------
 * Note:
 * This is the most optimal and cleanest solution for this problem.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // Nodes of the first edge
        int a = edges[0][0];
        int b = edges[0][1];

        // Nodes of the second edge
        int c = edges[1][0];
        int d = edges[1][1];

        // The node common to both edges is the center
        return (a == c || a == d) ? a : b;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> edges = {{1, 2}, {2, 3}, {2, 4}};
    int center = sol.findCenter(edges);

    cout << "Center of the Star Graph: " << center << endl;

    return 0;
}

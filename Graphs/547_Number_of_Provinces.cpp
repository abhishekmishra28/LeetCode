/*
 * Problem: 547. Number of Provinces
 *
 * Statement:
 * You are given an n x n adjacency matrix `isConnected`,
 * where:
 *   isConnected[i][j] == 1 → city i is directly connected to city j
 *
 * A province is a group of directly or indirectly connected cities.
 *
 * Return the TOTAL number of provinces.
 *
 * ------------------------------------------------------------
 * APPROACH: Depth First Search (DFS) — Your Approach
 *
 * Core Idea:
 *
 * - Treat each city as a node in a graph
 * - An edge exists between city i and j if isConnected[i][j] == 1
 *
 * - A PROVINCE = one CONNECTED COMPONENT in the graph
 *
 * - Strategy:
 *     • Traverse all cities
 *     • If a city is not visited → start DFS from it
 *     • DFS will mark all cities in that province
 *     • Increment province count
 *
 * ------------------------------------------------------------
 * DFS Helper Function Explanation:
 *
 * dfs(curr, isConnected, visited)
 *
 * Purpose:
 * - Visit the current city
 * - Recursively visit all cities directly or indirectly connected to it
 *
 * Steps:
 *
 * 1. Mark current city as visited
 *
 * 2. Traverse all cities from 0 to n-1:
 *      If city `i` is NOT visited
 *      AND isConnected[curr][i] == 1
 *          → city i belongs to the same province
 *          → recursively call dfs(i)
 *
 * ------------------------------------------------------------
 * Main Function Logic:
 *
 * 1. Initialize:
 *      visited array of size n (all false)
 *      ans = 0   // province count
 *
 * 2. Traverse each city i from 0 to n-1:
 *
 *      If city i is NOT visited:
 *          - Start DFS from city i
 *          - DFS will mark the entire province
 *          - Increment ans
 *
 * 3. Return ans
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - DFS explores all cities reachable from a starting city
 * - Once visited, a city is never counted again
 * - Each DFS call corresponds to EXACTLY ONE province
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * isConnected =
 * [
 *   [1,1,0],
 *   [1,1,0],
 *   [0,0,1]
 * ]
 *
 * visited = [false,false,false]
 *
 * i = 0:
 *   visited[0] == false
 *   → dfs(0) visits 0 and 1
 *   → ans = 1
 *
 * i = 1:
 *   visited[1] == true → skip
 *
 * i = 2:
 *   visited[2] == false
 *   → dfs(2) visits 2
 *   → ans = 2
 *
 * Output = 2 provinces
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - All cities disconnected → n provinces
 * - All cities connected → 1 province
 * - Single city → 1 province
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - O(n²)
 *   Because adjacency matrix is scanned for each DFS call
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(n)
 *   visited array + recursion stack
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Connected Components using DFS"
 *
 * Appears in:
 * - Number of Provinces
 * - Number of Islands
 * - Friend Circles
 * - Graph traversal problems
 */

class Solution {
private:
    void dfs(int curr,
             vector<vector<int>> isConnected,
             vector<bool> &visited) {

        visited[curr] = true;
        int n = isConnected.size();

        for (int i = 0; i < n; i++) {
            if (!visited[i] && isConnected[curr][i] == 1) {
                dfs(i, isConnected, visited);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int ans = 0;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, isConnected, visited);
                ans++;   // found a new province
            }
        }
        return ans;
    }
};

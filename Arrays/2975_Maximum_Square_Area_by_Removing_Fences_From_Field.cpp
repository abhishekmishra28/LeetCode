/*
 * Problem: 2975. Maximum Square Area by Removing Fences From a Field
 *
 * Statement:
 * You are given a rectangular grid of size m × n.
 *
 * - Some horizontal fences are removed (hFences)
 * - Some vertical fences are removed (vFences)
 *
 * Fences exist at positions 0 and m (horizontal),
 * and 0 and n (vertical) by default.
 *
 * Removing fences creates gaps. A SQUARE hole can be formed
 * only if a horizontal gap length equals a vertical gap length.
 *
 * Your task is to return the MAXIMUM possible area of such a square.
 * If no square can be formed, return -1.
 *
 * Answer should be returned modulo 1e9 + 7.
 *
 * ------------------------------------------------------------
 * APPROACH: Brute-Force Gap Matching using Hash Set (Your Approach)
 *
 * Core Idea:
 *
 * - A square requires:
 *     height gap == width gap
 *
 * - So:
 *     1) Compute ALL possible horizontal gaps
 *     2) Compute ALL possible vertical gaps
 *     3) Find the LARGEST gap common to both
 *
 * ------------------------------------------------------------
 * Why Add Boundaries (0 and m / n)?
 *
 * - Fences at the boundary always exist
 * - Gaps can be formed between:
 *     • two removed fences
 *     • boundary fence and a removed fence
 *
 * Without adding boundaries, edge gaps would be missed.
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. Add boundary fences:
 *      hFences → add 0 and m
 *      vFences → add 0 and n
 *
 * 2. Sort both fence arrays
 *
 * 3. Compute ALL possible horizontal gaps:
 *
 *    - For every pair (i, j), i < j:
 *         gap = hFences[j] - hFences[i]
 *    - Store each gap in a hash set `heightGaps`
 *
 * 4. Traverse all vertical gaps:
 *
 *    - For every pair (i, j), i < j:
 *         gap = vFences[j] - vFences[i]
 *
 *    - If this gap exists in `heightGaps`:
 *         → a square of side = gap is possible
 *         → update best = max(best, gap)
 *
 * 5. If no common gap found:
 *      → return -1
 *
 * 6. Otherwise:
 *      → return (best × best) % MOD
 *
 * ------------------------------------------------------------
 * Example:
 *
 * m = 5, n = 4
 * hFences = [1,2]
 * vFences = [1,3]
 *
 * After adding boundaries:
 * hFences = [0,1,2,5]
 * vFences = [0,1,3,4]
 *
 * Horizontal gaps:
 * {1,2,3,4,5}
 *
 * Vertical gaps:
 * {1,2,3,4}
 *
 * Largest common gap = 4
 * Area = 4 × 4 = 16
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Any square must be bounded by two horizontal and two vertical fences
 * - Enumerating all pairs guarantees no valid square is missed
 * - Hash set enables fast O(1) lookup
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * Let:
 *   H = number of horizontal fences
 *   V = number of vertical fences
 *
 * - Horizontal gap computation: O(H²)
 * - Vertical gap computation:   O(V²)
 *
 * Total:
 *   O(H² + V²)
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(H²) in worst case (storing all horizontal gaps)
 *
 * ------------------------------------------------------------
 * Trade-offs:
 *
 * ✅ Simple and intuitive
 * ✅ Correct for all cases
 * ❌ Quadratic complexity (acceptable due to constraints)
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This follows the pattern:
 *   "All-Pairs Difference + Set Intersection"
 *
 * Seen in:
 * - Grid gap problems
 * - Geometry with constraints
 * - Matching distances across dimensions
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximizeSquareArea(int m, int n,
                           vector<int>& hFences,
                           vector<int>& vFences) {

        const long long MOD = 1e9 + 7;

        // Step 1: Add boundaries
        hFences.push_back(0);
        hFences.push_back(m);
        vFences.push_back(0);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        // Step 2: Store all horizontal gaps
        unordered_set<int> heightGaps;
        int H = hFences.size();
        for (int i = 0; i < H; i++) {
            for (int j = i + 1; j < H; j++) {
                heightGaps.insert(hFences[j] - hFences[i]);
            }
        }

        // Step 3: Check vertical gaps and find best square
        long long best = -1;
        int V = vFences.size();
        for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++) {
                int gap = vFences[j] - vFences[i];
                if (heightGaps.count(gap)) {
                    best = max(best, (long long)gap);
                }
            }
        }

        // Step 4: Return result
        if (best == -1) return -1;
        return (best * best) % MOD;
    }
};

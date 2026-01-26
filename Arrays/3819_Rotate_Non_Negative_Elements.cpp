/*
 * Problem: 3819. Rotate Non-Negative Elements
 *
 * Statement:
 * You are given an integer array `nums` and an integer `k`.
 *
 * You need to:
 * - Rotate ONLY the non-negative elements of the array
 * - Rotation is to the LEFT by `k` positions (cyclic)
 * - All negative elements must:
 *      • stay at their original indices
 *      • never move
 *
 * After rotation:
 * - Place the rotated non-negative elements back
 * - Only fill positions that originally had non-negative values
 *
 * Return the resulting array.
 *
 * ------------------------------------------------------------
 * APPROACH: Extract → Rotate → Reinsert (Your Approach)
 *
 * Core Idea:
 *
 * - Negative elements act like "blocked positions"
 * - We temporarily REMOVE all non-negative elements
 * - Rotate them independently
 * - Put them back ONLY in non-negative positions
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. Traverse `nums` and extract all non-negative elements
 *    into a separate array `pos`
 *
 * 2. Let:
 *      m = pos.size()   // count of non-negative elements
 *
 *    If m == 0:
 *      → No rotation needed
 *      → Return nums as-is
 *
 * 3. Normalize rotation:
 *      k = k % m
 *
 * 4. Perform LEFT rotation on `pos`:
 *
 *      rotated[i] = pos[(i + k) % m]
 *
 * 5. Reinsert rotated elements back into `nums`:
 *
 *    - Traverse original array
 *    - Whenever nums[i] >= 0:
 *         nums[i] = rotated[j]
 *         j++
 *
 *    - Negative elements are skipped automatically
 *
 * 6. Return the modified `nums`
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Relative order of negative elements is preserved
 * - Only non-negative values are rotated
 * - Rotation logic is isolated and simple
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * nums = [1, -2, 3, 4, -5, 6]
 * k = 2
 *
 * Step 1: Extract non-negative elements
 *   pos = [1, 3, 4, 6]
 *
 * Step 2: Rotate left by 2
 *   rotated = [4, 6, 1, 3]
 *
 * Step 3: Reinsert
 *
 *   index 0 → 4
 *   index 1 → -2 (unchanged)
 *   index 2 → 6
 *   index 3 → 1
 *   index 4 → -5 (unchanged)
 *   index 5 → 3
 *
 * Result:
 *   [4, -2, 6, 1, -5, 3]
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - All elements are negative → no change
 * - All elements are non-negative → normal left rotation
 * - k >= number of non-negative elements
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n)
 *   One pass to extract + one pass to reinsert
 *
 * Space Complexity:
 * - O(m)
 *   Extra space for non-negative elements
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This follows the:
 *   "Selective Rotation with Fixed Positions" pattern
 *
 * Seen in:
 * - Filter + transform problems
 * - Stable index problems
 * - Conditional array rotations
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pos;

        // Step 1: Extract non-negative elements
        for (int num : nums) {
            if (num >= 0) pos.push_back(num);
        }

        int m = pos.size();
        if (m == 0) return nums;

        // Step 2: Normalize k
        k %= m;

        // Step 3: Rotate left by k
        vector<int> rotated(m);
        for (int i = 0; i < m; i++) {
            rotated[i] = pos[(i + k) % m];
        }

        // Step 4: Reinsert into original array
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] >= 0) {
                nums[i] = rotated[j++];
            }
        }

        return nums;
    }
};

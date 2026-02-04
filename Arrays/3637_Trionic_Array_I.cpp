/*
 * Problem: 3637. Trionic Array I
 *
 * Statement:
 * You are given an integer array `nums` of length `n`.
 *
 * An array is called TRIONIC if there exist indices:
 *
 *      0 < p < q < n - 1
 *
 * such that:
 *
 *   1) nums[0 ... p]     is STRICTLY INCREASING
 *   2) nums[p ... q]     is STRICTLY DECREASING
 *   3) nums[q ... n - 1] is STRICTLY INCREASING
 *
 * Return true if `nums` is trionic, otherwise return false.
 *
 * ------------------------------------------------------------
 * APPROACH: Single Pass with Three Monotonic Phases
 *
 * Core Idea:
 *
 * - Traverse the array once using an index `i`
 * - Explicitly move through three required phases:
 *
 *      Phase 1 → strictly increasing
 *      Phase 2 → strictly decreasing
 *      Phase 3 → strictly increasing
 *
 * - At each phase boundary, ensure:
 *      • The phase actually occurred
 *      • Indices satisfy 0 < p < q < n - 1
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm:
 *
 * Let:
 *   n = nums.size()
 *   i = 0   // traversal pointer
 *
 * -------------------------
 * Phase 1: STRICTLY INCREASING
 * -------------------------
 *
 *   while (i + 1 < n && nums[i] < nums[i + 1])
 *       i++;
 *
 *   If i == 0:
 *       → No increasing step
 *       → return false
 *
 *   If i == n - 1:
 *       → Array ended too early
 *       → return false
 *
 *   Set:
 *       p = i
 *
 * -------------------------
 * Phase 2: STRICTLY DECREASING
 * -------------------------
 *
 *   while (i + 1 < n && nums[i] > nums[i + 1])
 *       i++;
 *
 *   If i == p:
 *       → No decreasing step
 *       → return false
 *
 *   If i == n - 1:
 *       → No space for final increase
 *       → return false
 *
 *   Set:
 *       q = i
 *
 * -------------------------
 * Phase 3: STRICTLY INCREASING
 * -------------------------
 *
 *   while (i + 1 < n && nums[i] < nums[i + 1])
 *       i++;
 *
 * -------------------------
 * Final Check:
 * -------------------------
 *
 *   If i == n - 1:
 *       → All elements consumed correctly
 *       → return true
 *   Else:
 *       → return false
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Each phase is validated independently
 * - Strict comparisons ensure no equal adjacent values
 * - Single pointer guarantees O(n) time
 * - Boundary checks enforce:
 *       0 < p < q < n - 1
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * nums = [1, 3, 5, 4, 2, 6, 8]
 *
 * Phase 1 (up):
 *   1 < 3 < 5   → p = 2
 *
 * Phase 2 (down):
 *   5 > 4 > 2   → q = 4
 *
 * Phase 3 (up):
 *   2 < 6 < 8   → end reached
 *
 * ✔ Trionic → true
 *
 * ------------------------------------------------------------
 * Invalid Examples:
 *
 * [1, 2, 3, 4]
 *   → Missing decreasing phase
 *
 * [5, 4, 3, 2]
 *   → Missing increasing phases
 *
 * [1, 3, 2, 4, 3]
 *   → Extra decrease after final increase
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - n < 4 → impossible to form three phases
 * - Equal adjacent elements → invalid
 * - Any phase skipped → invalid
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - O(n)
 *   Single linear traversal
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(1)
 *   Constant extra space
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Multi-phase Monotonic Array Validation"
 *
 * Related to:
 * - Mountain Array problems
 * - Trend / pattern detection
 * - Sequence phase validation
 */

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size(), i = 0;

        // Phase 1: strictly increasing
        while (i + 1 < n && nums[i] < nums[i + 1]) i++;
        if (i == 0 || i == n - 1) return false;

        int p = i;

        // Phase 2: strictly decreasing
        while (i + 1 < n && nums[i] > nums[i + 1]) i++;
        if (i == p || i == n - 1) return false;

        // Phase 3: strictly increasing
        while (i + 1 < n && nums[i] < nums[i + 1]) i++;

        return i == n - 1;
    }
};

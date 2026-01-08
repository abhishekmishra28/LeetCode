/*
 * Problem: 1629. Slowest Key
 *
 * Statement:
 * You are given:
 * - an integer array `releaseTimes`
 * - a string `keysPressed`
 *
 * `releaseTimes[i]` denotes the time at which the i-th key was released.
 * The i-th key pressed is `keysPressed[i]`.
 *
 * The PRESS DURATION of the i-th key is:
 *   - releaseTimes[0]                     (for i = 0)
 *   - releaseTimes[i] - releaseTimes[i-1] (for i > 0)
 *
 * Your task is to return the key that had the LONGEST press duration.
 *
 * Tie-breaking rule:
 * - If multiple keys have the same maximum duration,
 *   return the lexicographically LARGEST key.
 *
 * ------------------------------------------------------------
 * Key Observations:
 *
 * - Durations are derived from differences in release times
 * - We only need to track the maximum duration seen so far
 * - Tie-breaking is handled during comparison
 *
 * ------------------------------------------------------------
 * Approach: Single Pass Greedy
 *
 * Core Idea:
 * - Compute duration for each key
 * - Track:
 *     • maximum duration so far
 *     • index of the key producing that duration
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Approach):
 *
 * 1. Initialize:
 *    - maxDuration = releaseTimes[0]
 *    - idx = 0   → index of slowest key so far
 *
 * 2. Traverse keys from index 1 to n-1:
 *
 *    a) duration = releaseTimes[i] - releaseTimes[i-1]
 *
 *    b) If:
 *       - duration > maxDuration
 *         OR
 *       - duration == maxDuration AND
 *         keysPressed[i] > keysPressed[idx]
 *
 *       → update:
 *           maxDuration = duration
 *           idx = i
 *
 * 3. Return keysPressed[idx]
 *
 * ------------------------------------------------------------
 * Example:
 *
 * Input:
 * releaseTimes = [9,29,49,50]
 * keysPressed  = "cbcd"
 *
 * Durations:
 * c → 9
 * b → 20
 * c → 20
 * d → 1
 *
 * Max duration = 20
 * Tie between 'b' and 'c'
 * Lexicographically larger = 'c'
 *
 * Output = 'c'
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Only one key
 * - All durations same
 * - Keys in random order
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n)
 *   Single traversal
 *
 * Space Complexity:
 * - O(1)
 *   Constant extra space
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Greedy comparison at each step ensures optimal result
 * - Tie-breaking is handled inline
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int n = releaseTimes.size();

        int maxDuration = releaseTimes[0];
        int idx = 0;

        for (int i = 1; i < n; i++) {
            int duration = releaseTimes[i] - releaseTimes[i - 1];

            if (duration > maxDuration ||
               (duration == maxDuration &&
                keysPressed[i] > keysPressed[idx])) {

                maxDuration = duration;
                idx = i;
            }
        }

        return keysPressed[idx];
    }
};

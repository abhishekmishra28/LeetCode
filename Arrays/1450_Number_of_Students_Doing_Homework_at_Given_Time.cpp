/*
 * Problem: 1450. Number of Students Doing Homework at a Given Time
 *
 * Statement:
 * You are given two integer arrays:
 *   - startTime[i]: time when the i-th student starts homework
 *   - endTime[i]:   time when the i-th student finishes homework
 *
 * You are also given an integer `queryTime`.
 *
 * A student is considered BUSY at `queryTime` if:
 *     startTime[i] ≤ queryTime ≤ endTime[i]
 *
 * Return the number of students busy at `queryTime`.
 *
 * ------------------------------------------------------------
 * APPROACH: Direct Counting (Brute-Force but Optimal) — Your Approach
 *
 * Core Idea:
 *
 * - For each student, check whether `queryTime` lies within
 *   their homework interval.
 *
 * - Count how many such intervals contain `queryTime`.
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. Initialize:
 *      cnt = 0
 *
 * 2. Traverse all students (i = 0 to n-1):
 *
 *      If:
 *         startTime[i] ≤ queryTime
 *         AND
 *         endTime[i] ≥ queryTime
 *
 *      Then:
 *         cnt++
 *
 * 3. Return cnt
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Each student’s interval is independent
 * - Only one query time is given
 * - Linear scan is sufficient and optimal
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * startTime = [1, 2, 3]
 * endTime   = [3, 2, 7]
 * queryTime = 4
 *
 * Student 0: [1,3] → not busy
 * Student 1: [2,2] → not busy
 * Student 2: [3,7] → busy
 *
 * Answer = 1
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - startTime[i] == queryTime
 * - endTime[i] == queryTime
 * - No students busy → return 0
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - O(n)
 *   Single pass through the arrays
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
 *   "Interval Containment Check"
 *
 * Seen in:
 * - Scheduling problems
 * - Time-window queries
 * - Simple range counting
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int n = startTime.size();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (startTime[i] <= queryTime && endTime[i] >= queryTime) {
                cnt++;
            }
        }
        return cnt;
    }
};

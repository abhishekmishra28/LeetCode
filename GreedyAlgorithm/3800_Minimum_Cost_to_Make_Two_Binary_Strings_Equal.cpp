/*
 * Problem: 3800. Minimum Cost to Make Two Binary Strings Equal
 *
 * Statement:
 * You are given two binary strings `s` and `t` of equal length `n`,
 * along with three operation costs:
 *
 * - flipCost  : cost to flip a single bit in either string
 * - swapCost  : cost to swap two positions within the SAME string
 * - crossCost : cost to swap characters at the SAME index between s and t
 *
 * Allowed operations (any number of times, any order):
 * 1) Flip s[i] or t[i] (0 ↔ 1) → cost = flipCost
 * 2) Swap s[i] with s[j] OR t[i] with t[j] → cost = swapCost
 * 3) Swap s[i] with t[i] → cost = crossCost
 *
 * Goal:
 * Make strings s and t EXACTLY equal with MINIMUM total cost.
 *
 * ------------------------------------------------------------
 * Key Observations:
 *
 * - We only care about positions where s[i] != t[i]
 * - There are only two types of mismatches:
 *
 *   Type A: s[i] = 0, t[i] = 1
 *   Type B: s[i] = 1, t[i] = 0
 *
 * - Let:
 *     a = count of Type A mismatches
 *     b = count of Type B mismatches
 *
 * ------------------------------------------------------------
 * Core Insight:
 *
 * Any valid operation sequence must eventually FIX all mismatches.
 * We want to fix them as cheaply as possible by pairing operations
 * whenever beneficial.
 *
 * ------------------------------------------------------------
 * Strategy Breakdown:
 *
 * STEP 1: Count mismatches
 * - Traverse both strings
 * - Count how many (0→1) mismatches → a
 * - Count how many (1→0) mismatches → b
 *
 * ------------------------------------------------------------
 * STEP 2: Pair opposite mismatches (a with b)
 *
 * One Type A + One Type B can be fixed by:
 * - Swapping positions within a string (swapCost)
 * OR
 * - Flipping both bits individually (2 * flipCost)
 *
 * We choose the cheaper option:
 *   min(swapCost, 2 * flipCost)
 *
 * Number of such pairs = min(a, b)
 *
 * ------------------------------------------------------------
 * STEP 3: Handle remaining mismatches
 *
 * After pairing:
 *   a -= pairs
 *   b -= pairs
 *
 * Remaining mismatches are of ONE TYPE only.
 *
 * Let:
 *   rem = a + b
 *
 * To fix TWO remaining mismatches, options are:
 * - Flip both bits → cost = 2 * flipCost
 * - Cross swap + one internal swap → cost = crossCost + swapCost
 *
 * Choose cheaper:
 *   cost2 = min(2 * flipCost, crossCost + swapCost)
 *
 * Apply this to (rem / 2) pairs.
 *
 * ------------------------------------------------------------
 * STEP 4: Handle odd leftover mismatch
 *
 * If rem is odd:
 * - Only one mismatch left
 * - Only possible fix is a single flip
 * - Cost = flipCost
 *
 * ------------------------------------------------------------
 * Example:
 *
 * s = "0101"
 * t = "1010"
 *
 * a = 2, b = 2
 * pairs = 2
 * cost = 2 * min(swapCost, 2 * flipCost)
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n)
 *   Single pass over strings
 *
 * Space Complexity:
 * - O(1)
 *   Constant extra variables
 *
 * ------------------------------------------------------------
 * Why This Greedy Works:
 *
 * - Pairing opposite mismatches is always optimal
 * - Remaining mismatches are independent
 * - Every step locally minimizes cost without affecting future choices
 *
 * ------------------------------------------------------------
 * This solution is:
 * - Optimal
 * - Clean
 * - Interview-grade
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumCost(string s, string t,
                          int flipCost, int swapCost, int crossCost) {

        long long a = 0, b = 0;

        // Step 1: Count mismatch types
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0' && t[i] == '1') a++;
            else if (s[i] == '1' && t[i] == '0') b++;
        }

        long long ans = 0;

        // Step 2: Pair opposite mismatches
        long long pairs = min(a, b);
        ans += pairs * min((long long)swapCost, 2LL * flipCost);

        a -= pairs;
        b -= pairs;

        // Step 3: Handle remaining mismatches
        long long rem = a + b;
        long long cost2 = min(2LL * flipCost,
                               (long long)crossCost + swapCost);

        ans += (rem / 2) * cost2;

        // Step 4: Handle odd leftover
        if (rem % 2 == 1) {
            ans += flipCost;
        }

        return ans;
    }
};

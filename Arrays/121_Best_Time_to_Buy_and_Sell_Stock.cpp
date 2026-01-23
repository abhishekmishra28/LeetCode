/*
 * Problem: 121. Best Time to Buy and Sell Stock
 *
 * Statement:
 * You are given an array `prices` where prices[i] is the price of a given stock
 * on the i-th day.
 *
 * You want to maximize your profit by choosing:
 *   - one day to BUY
 *   - a different later day to SELL
 *
 * Return the maximum profit you can achieve.
 * If no profit is possible, return 0.
 *
 * ------------------------------------------------------------
 * APPROACH: Single Pass with Minimum Tracking (Greedy) — Your Approach
 *
 * Core Idea:
 *
 * - The best profit at any day depends on:
 *     current price - minimum price seen so far
 *
 * - While traversing:
 *     • keep track of the minimum buying price
 *     • compute profit if sold today
 *     • update the maximum profit
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. Initialize:
 *      mini = prices[0]     // minimum price seen so far
 *      maxProfit = 0        // best profit so far
 *
 * 2. Traverse prices from day 0 to day n-1:
 *
 *    a) Compute profit if we SELL today:
 *         cost = prices[i] - mini
 *
 *    b) Update maximum profit:
 *         maxProfit = max(maxProfit, cost)
 *
 *    c) Update minimum buying price:
 *         mini = min(mini, prices[i])
 *
 * 3. After traversal, return maxProfit
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - You always BUY at the lowest price before today
 * - You always SELL after buying (time order preserved)
 * - Greedy choice ensures global maximum profit
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * prices = [7,1,5,3,6,4]
 *
 * Day 0:
 *   mini = 7, profit = 0
 *
 * Day 1:
 *   mini = 1
 *
 * Day 2:
 *   profit = 5 - 1 = 4 → maxProfit = 4
 *
 * Day 4:
 *   profit = 6 - 1 = 5 → maxProfit = 5
 *
 * Answer = 5
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Prices strictly decreasing → return 0
 * - Single day → return 0
 * - Large inputs handled efficiently
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
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Minimum so far + Maximum difference" problem
 *
 * Seen in:
 * - Stock buy/sell problems
 * - Maximum subarray variants
 * - Greedy optimization problems
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        int mini = prices[0];

        for (int i = 0; i < n; i++) {
            int cost = prices[i] - mini;
            maxProfit = max(maxProfit, cost);
            mini = min(mini, prices[i]);
        }
        return maxProfit;
    }
};

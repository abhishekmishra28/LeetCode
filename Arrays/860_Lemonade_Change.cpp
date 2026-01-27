/*
 * Problem: 860. Lemonade Change
 *
 * Statement:
 * You are running a lemonade stand where each lemonade costs $5.
 *
 * Customers pay with bills of value:
 *   5, 10, or 20
 *
 * You must provide the correct change to each customer
 * IN THE ORDER they arrive.
 *
 * Return true if you can give correct change to every customer,
 * otherwise return false.
 *
 * ------------------------------------------------------------
 * APPROACH: Greedy Cash Management — Your Approach
 *
 * Core Greedy Idea:
 *
 * - Always try to give change using the LARGEST bills possible
 *   (when dealing with $20)
 *
 * Why?
 * - $5 bills are the most valuable for making future change
 * - Preserving $5 bills increases future flexibility
 *
 * ------------------------------------------------------------
 * Variables Used:
 *
 * - fives  → number of $5 bills
 * - tens   → number of $10 bills
 * - twens  → number of $20 bills (not actually needed, but tracked)
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. Initialize counters:
 *      fives = 0
 *      tens  = 0
 *      twens = 0
 *
 * 2. Traverse each bill in `bills`:
 *
 *    Case 1: Customer pays with $5
 *    --------------------------------
 *    - No change required
 *    - Increment fives
 *
 *    Case 2: Customer pays with $10
 *    --------------------------------
 *    - Needs $5 change
 *    - If fives > 0:
 *         fives--
 *         tens++
 *      Else:
 *         return false
 *
 *    Case 3: Customer pays with $20
 *    --------------------------------
 *    - Needs $15 change
 *
 *    Preferred option:
 *      - If tens > 0 AND fives > 0:
 *           tens--
 *           fives--
 *           twens++
 *
 *    Fallback option:
 *      - Else if fives >= 3:
 *           fives -= 3
 *
 *    If neither option is possible:
 *      - return false
 *
 * 3. If all customers are processed successfully:
 *      → return true
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Greedy choice (use $10 + $5 first) preserves $5 bills
 * - Ensures maximum flexibility for future customers
 * - Order matters → decisions are irreversible
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * bills = [5, 5, 5, 10, 20]
 *
 * Step-by-step:
 *   5  → fives = 1
 *   5  → fives = 2
 *   5  → fives = 3
 *   10 → give 5 → fives = 2, tens = 1
 *   20 → give 10+5 → fives = 1, tens = 0
 *
 * Output = true
 *
 * ------------------------------------------------------------
 * Counter Example:
 *
 * bills = [5, 5, 10, 10, 20]
 *
 * At last $20:
 *   fives = 1, tens = 2
 *   Cannot give $15 → return false
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n)
 *   One pass through the bills
 *
 * Space Complexity:
 * - O(1)
 *   Only constant extra variables
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Greedy with Resource Management" problem
 *
 * Seen in:
 * - Cash register problems
 * - Resource allocation
 * - Simulation with constraints
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0;
        int tens = 0;
        int twens = 0; // optional, not required logically

        for (int bill : bills) {
            if (bill == 5) {
                fives++;
            }
            else if (bill == 10) {
                if (fives > 0) {
                    fives--;
                    tens++;
                } else {
                    return false;
                }
            }
            else { // bill == 20
                if (tens > 0 && fives > 0) {
                    tens--;
                    fives--;
                    twens++;
                }
                else if (fives >= 3) {
                    fives -= 3;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};

/*
 * Problem: Plus One
 * Given a non-empty array of decimal digits representing a non-negative integer,
 * increment the integer by one and return the resulting digits.
 *
 * Approach:
 * Traverse from right to left (least significant digit).
 * - If digit + 1 < 10 → update and return.
 * - Otherwise set digit to 0 and continue carrying.
 * If we exit the loop with carry (e.g., 999 → 000), insert 1 at the front.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1) — in-place modification
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for (int i = n - 1; i >= 0; i--) {

            // If adding 1 does NOT create a carry
            if (digits[i] + 1 != 10) {
                digits[i] += 1;
                return digits;   // done
            }

            // Otherwise: set digit to 0 and continue carry
            digits[i] = 0;

            // If we are at the most significant digit and still have carry
            if (i == 0) {
                digits.insert(digits.begin(), 1);
                return digits;
            }
        }

        return digits; // fallback (normally never reached)
    }
};

int main() {
    Solution sol;

    vector<int> digits = {9, 9, 9};
    vector<int> result = sol.plusOne(digits);

    cout << "Result: ";
    for (int d : result) cout << d << " ";
    cout << endl;

    return 0;
}

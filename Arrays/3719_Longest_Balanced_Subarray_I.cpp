/*
 * Problem: 3719. Longest Balanced Subarray I
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * You are given an integer array nums.
 *
 * A subarray is called balanced if:
 * - Number of DISTINCT even elements
 *   ==
 * - Number of DISTINCT odd elements
 *
 * Return the length of the longest such balanced subarray.
 *
 * ------------------------------------------------------------
 * APPROACH: Brute Force + Hashing
 *
 * ------------------------------------------------------------
 * KEY OBSERVATION:
 *
 * 1️⃣ Balance is based on DISTINCT values, not frequency.
 *
 * 2️⃣ Order matters → subarray must be contiguous.
 *
 * 3️⃣ For every possible subarray, we must:
 *    - Count distinct even numbers
 *    - Count distinct odd numbers
 *    - Compare both counts
 *
 * ------------------------------------------------------------
 * STRATEGY:
 *
 * - Fix a starting index `i`
 * - Extend subarray ending index `j` from `i` to `n-1`
 * - Use hash maps to track frequencies
 * - Increase distinct count only when an element appears first time
 *
 * ------------------------------------------------------------
 * DATA STRUCTURES USED:
 *
 * unordered_map<int,int> evFreq → frequency of even numbers
 * unordered_map<int,int> odFreq → frequency of odd numbers
 *
 * distEv → number of DISTINCT even elements
 * distOd → number of DISTINCT odd elements
 *
 * ------------------------------------------------------------
 * ALGORITHM STEPS:
 *
 * 1️⃣ Loop `i` from 0 to n-1
 * 2️⃣ Initialize empty maps and distinct counters
 * 3️⃣ Loop `j` from i to n-1
 * 4️⃣ Insert nums[j] into even/odd map
 * 5️⃣ If first occurrence, increment distinct count
 * 6️⃣ If distEv == distOd, update answer
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * nums = [1, 2, 3, 2]
 *
 * Subarray [2, 3]:
 * - distinct even = {2} → 1
 * - distinct odd  = {3} → 1
 * Balanced → length = 2
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 * - O(n²)
 *   (All possible subarrays are checked)
 *
 * Space Complexity:
 * - O(n)
 *   (Hash maps for frequency tracking)
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - This is NOT a sliding window problem
 * - Distinct count makes it unsuitable for prefix sums
 * - Brute force with hashing is optimal given constraints
 */

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        // Fix the starting index of subarray
        for (int i = 0; i < n; i++) {

            // Frequency maps for even and odd numbers
            unordered_map<int,int> evFreq, odFreq;

            // Count of distinct even and odd numbers
            int distEv = 0, distOd = 0;

            // Extend the subarray from i to j
            for (int j = i; j < n; j++) {

                // If current element is even
                if (nums[j] % 2 == 0) {
                    evFreq[nums[j]]++;

                    // First appearance → new distinct even
                    if (evFreq[nums[j]] == 1)
                        distEv++;
                }
                // If current element is odd
                else {
                    odFreq[nums[j]]++;

                    // First appearance → new distinct odd
                    if (odFreq[nums[j]] == 1)
                        distOd++;
                }

                // Check balance condition
                if (distEv == distOd)
                    ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};

/*
 * Problem: 350. Intersection of Two Arrays II
 *
 * Statement:
 * You are given two integer arrays `nums1` and `nums2`.
 * Your task is to return an array representing their INTERSECTION.
 *
 * Important Difference from Problem 349:
 * - Each element in the result should appear AS MANY TIMES
 *   as it shows in BOTH arrays.
 *
 * In other words:
 * - Frequency matters
 *
 * The order of elements in the result does NOT matter.
 *
 * ------------------------------------------------------------
 * Key Observations:
 *
 * - We are NOT looking for unique elements only
 * - If a number appears:
 *     • x times in nums1
 *     • y times in nums2
 *   → it should appear min(x, y) times in the result
 *
 * ------------------------------------------------------------
 * Approach: Frequency Counting using Hash Map (Your Approach)
 *
 * Core Idea:
 * - Count frequency of each element in nums1
 * - Traverse nums2:
 *     • If element exists in map with frequency > 0
 *     • Add it to result
 *     • Decrease its frequency
 *
 * This ensures:
 * - Correct count of duplicates
 * - No extra elements are added
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Approach):
 *
 * 1. Create an unordered_map `mpp`
 *    - Key   → element value
 *    - Value → frequency in nums1
 *
 * 2. Traverse nums1:
 *    - For each element nums1[i]:
 *        mpp[nums1[i]]++
 *
 * 3. Traverse nums2:
 *    - For each element nums2[i]:
 *        a) If nums2[i] exists in map AND frequency > 0:
 *            - Add nums2[i] to result
 *            - Decrement mpp[nums2[i]]
 *
 * 4. Return the result array
 *
 * ------------------------------------------------------------
 * Example 1:
 *
 * Input:
 * nums1 = [1,2,2,1]
 * nums2 = [2,2]
 *
 * Map after nums1:
 * 1 → 2
 * 2 → 2
 *
 * Traversing nums2:
 * - First 2 → freq = 2 → add 2 → freq becomes 1
 * - Second 2 → freq = 1 → add 2 → freq becomes 0
 *
 * Output:
 * [2,2]
 *
 * ------------------------------------------------------------
 * Example 2:
 *
 * nums1 = [4,9,5]
 * nums2 = [9,4,9,8,4]
 *
 * Map after nums1:
 * 4 → 1
 * 9 → 1
 * 5 → 1
 *
 * Traversing nums2:
 * - 9 → add
 * - 4 → add
 * - next 9 → freq = 0 → ignore
 * - next 4 → freq = 0 → ignore
 *
 * Output:
 * [9,4]  (order may vary)
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - No common elements → empty result
 * - One array empty
 * - Arrays with all identical elements
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n + m)
 *   n = size of nums1
 *   m = size of nums2
 *
 * Space Complexity:
 * - O(n)
 *   Hash map storing frequency of nums1
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Frequency map ensures correct duplicate handling
 * - Decrementing frequency prevents over-counting
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Frequency Map Intersection" problem
 *
 * Used in:
 * - Multiset intersection
 * - Inventory matching problems
 * - Duplicate-sensitive comparisons
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        unordered_map<int,int> mpp;

        // Step 1: Count frequencies in nums1
        for (int i = 0; i < n; i++) {
            mpp[nums1[i]]++;
        }

        vector<int> ans;

        // Step 2: Build intersection using nums2
        for (int i = 0; i < m; i++) {
            if (mpp.find(nums2[i]) != mpp.end() && mpp[nums2[i]] > 0) {
                ans.push_back(nums2[i]);
                mpp[nums2[i]]--;   // decrease frequency
            }
        }

        return ans;
    }
};

/*
 * Problem: 349. Intersection of Two Arrays
 *
 * Statement:
 * You are given two integer arrays `nums1` and `nums2`.
 * Your task is to return an array of their INTERSECTION.
 *
 * The intersection should contain:
 * - Each element that appears in BOTH arrays
 * - Each element should appear ONLY ONCE in the result
 *
 * The order of elements in the result does NOT matter.
 *
 * ------------------------------------------------------------
 * Key Observations:
 *
 * - We only care whether an element exists in both arrays
 * - Duplicates in the input arrays should NOT be duplicated
 *   in the output
 *
 * ------------------------------------------------------------
 * Approach: Hash Map for Presence Tracking (Your Approach)
 *
 * Core Idea:
 * - Store all elements of nums1 in a hash map
 * - Traverse nums2 and check if the element exists in the map
 * - Add it to result only ONCE
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Approach):
 *
 * 1. Create an unordered_map `mpp`
 *    - Key   → element value
 *    - Value → frequency (used as a presence flag)
 *
 * 2. Traverse nums1:
 *    - For each element nums1[i]:
 *        mpp[nums1[i]]++
 *
 * 3. Traverse nums2:
 *    - For each element nums2[i]:
 *        a) If nums2[i] exists in map AND frequency > 0:
 *            - Add nums2[i] to answer
 *            - Set mpp[nums2[i]] = 0
 *              (to avoid adding duplicates again)
 *
 * 4. Return the answer array
 *
 * ------------------------------------------------------------
 * Why set frequency to 0?
 *
 * - Ensures each common element is added ONLY ONCE
 * - Prevents duplicate entries in the result
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
 * - 2 exists and freq > 0 → add 2, set freq = 0
 * - next 2 → freq = 0 → ignored
 *
 * Output:
 * [2]
 *
 * ------------------------------------------------------------
 * Example 2:
 *
 * nums1 = [4,9,5]
 * nums2 = [9,4,9,8,4]
 *
 * Output:
 * [9,4]   (order may vary)
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
 *   Hash map for nums1
 *
 * ------------------------------------------------------------
 * Note:
 *
 * - This solution is clean and efficient
 * - Can also be solved using:
 *     • unordered_set
 *     • sorting + two pointers
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        unordered_map<int,int> mpp;

        // Step 1: Store elements of nums1
        for (int i = 0; i < n; i++) {
            mpp[nums1[i]]++;
        }

        vector<int> ans;

        // Step 2: Check elements of nums2
        for (int i = 0; i < m; i++) {
            if (mpp.find(nums2[i]) != mpp.end() && mpp[nums2[i]] > 0) {
                ans.push_back(nums2[i]);
                mpp[nums2[i]] = 0; // avoid duplicates
            }
        }

        return ans;
    }
};

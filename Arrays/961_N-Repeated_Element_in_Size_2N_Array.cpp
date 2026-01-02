
/*
 * Problem: 961. N-Repeated Element in Size 2N Array
 *
 * Statement:
 * You are given an integer array `nums` of size 2N.
 * The array contains exactly N + 1 distinct elements.
 * Out of these, exactly ONE element appears N times,
 * while all other elements appear exactly once.
 *
 * Your task is to find and return the element that appears N times.
 *
 * ------------------------------------------------------------
 * Key Observations:
 * - Array size = 2N
 * - Only one number has frequency = N
 * - Remaining N elements appear once each
 * - The problem guarantees that such an element ALWAYS exists
 *
 * ------------------------------------------------------------
 * Approach (Hash Map / Frequency Counting):
 *
 * 1. Compute N as (size of array) / 2.
 * 2. Traverse the array and store frequency of each element
 *    using an unordered_map.
 * 3. Traverse the map:
 *    - The element whose frequency equals N is the answer.
 *
 * Why this works:
 * - Since only one element repeats N times, frequency comparison
 *   uniquely identifies the required number.
 *
 * ------------------------------------------------------------
 * Example:
 *
 * nums = [5, 1, 5, 2, 5, 3, 5, 4]
 * size = 8 → N = 4
 *
 * Frequency map:
 * 5 → 4  ✅
 * 1 → 1
 * 2 → 1
 * 3 → 1
 * 4 → 1
 *
 * Answer = 5
 *
 * ------------------------------------------------------------
 * Edge Cases:
 * - Repeated element may appear at random positions
 * - Works even if repeated element is at the beginning or end
 * - No need to sort the array
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n): Single pass to build frequency map + map traversal
 *
 * Space Complexity:
 * - O(n): Extra space for hash map
 *
 * ------------------------------------------------------------
 * Note:
 * This solution prioritizes clarity and correctness.
 * There exists an O(1) space solution, but this is the
 * most intuitive and interview-friendly approach.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int size = nums.size();
        int N = size / 2;

        unordered_map<int, int> frequency;

        // Step 1: Count frequency of each element
        for (int value : nums) {
            frequency[value]++;
        }

        // Step 2: Identify the element repeated N times
        for (auto &entry : frequency) {
            if (entry.second == N) {
                return entry.first;
            }
        }

        // Problem guarantees a valid answer
        return -1;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {5, 1, 5, 2, 5, 3, 5, 4};
    int result = sol.repeatedNTimes(nums);

    cout << "Repeated Element: " << result << endl;

    return 0;
}

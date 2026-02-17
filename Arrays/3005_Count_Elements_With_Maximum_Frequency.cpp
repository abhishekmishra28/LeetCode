/*
 * Problem: 3005. Count Elements With Maximum Frequency
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given an integer array nums,
 * return the total number of elements that have
 * the maximum frequency.
 *
 * Example:
 * nums = [1,2,2,3,1,4]
 *
 * Frequencies:
 * 1 → 2
 * 2 → 2
 * 3 → 1
 * 4 → 1
 *
 * Maximum frequency = 2
 * Elements having max frequency = 1 and 2
 *
 * Total count = 2 + 2 = 4
 *
 * ------------------------------------------------------------
 * APPROACH: Frequency Counting (Hash Map)
 *
 * ------------------------------------------------------------
 * KEY OBSERVATIONS:
 *
 * 1️⃣ First, compute frequency of each element.
 *
 * 2️⃣ Find the maximum frequency.
 *
 * 3️⃣ Add frequencies of all elements
 *    whose frequency equals maximum frequency.
 *
 * ------------------------------------------------------------
 * STRATEGY:
 *
 * 1️⃣ Use unordered_map<int,int> to count frequencies.
 *
 * 2️⃣ Iterate through map:
 *    - Track maximum frequency.
 *
 * 3️⃣ Iterate again:
 *    - Add all frequencies equal to max frequency.
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * nums = [1,2,2,3,1,4]
 *
 * freq map:
 * {1:2, 2:2, 3:1, 4:1}
 *
 * maxfreq = 2
 *
 * Sum of elements with freq == 2:
 * 2 + 2 = 4
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 * - O(n)
 *
 * Space Complexity:
 * - O(n) (hash map)
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - Can be optimized to single pass:
 *   Maintain maxfreq and answer while counting.
 * - Very straightforward frequency problem.
 */

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {

        unordered_map<int, int> freq;

        // Count frequencies
        for (auto x : nums) {
            freq[x]++;
        }

        // Find maximum frequency
        int maxfreq = 0;
        for (auto& p : freq) {
            maxfreq = max(maxfreq, p.second);
        }

        // Sum frequencies equal to max frequency
        int cnt = 0;
        for (auto& p : freq) {
            if (p.second == maxfreq)
                cnt += p.second;
        }

        return cnt;
    }
};

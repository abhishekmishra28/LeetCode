/*
 * Problem: 2461. Maximum Sum of Distinct Subarrays With Length K
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given an integer array nums and an integer k,
 * find the maximum sum of a subarray of size k
 * such that all elements in the subarray are DISTINCT.
 *
 * If no such subarray exists, return 0.
 *
 * ------------------------------------------------------------
 * CORE IDEA:
 *
 * We must consider subarrays of length exactly k.
 * But only those windows are valid where:
 *
 *        all elements are unique.
 *
 * So we use:
 *
 *      Sliding Window + Hash Map
 *
 * to track frequencies of elements inside the window.
 *
 * ------------------------------------------------------------
 * KEY OBSERVATION:
 *
 * If the window size is k and the number of
 * distinct elements inside it is also k,
 * then all elements are unique.
 *
 * That means:
 *
 *      freq.size() == k
 *
 * ------------------------------------------------------------
 * APPROACH: Sliding Window + Frequency Map
 *
 * We maintain:
 *
 *      currWindow → sum of elements in current window
 *      freq       → frequency map of elements
 *      maxWindow  → maximum valid window sum
 *
 * ------------------------------------------------------------
 * ALGORITHM STEPS:
 *
 * 1️⃣ Build the first window of size k:
 *
 *      - add elements to currWindow
 *      - update frequency map
 *
 * 2️⃣ If freq.size() == k
 *      update maxWindow.
 *
 * 3️⃣ Slide the window across the array:
 *
 *      Add new element:
 *          currWindow += nums[i]
 *          freq[nums[i]]++
 *
 *      Remove old element:
 *          currWindow -= nums[i-k]
 *          freq[nums[i-k]]--
 *
 *      If frequency becomes 0
 *          erase from map
 *
 * 4️⃣ Check again if window has k distinct elements.
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * nums = [1,5,4,2,9,9,9]
 * k = 3
 *
 * Windows:
 *
 * [1,5,4] → sum = 10 → valid
 * [5,4,2] → sum = 11 → valid
 * [4,2,9] → sum = 15 → valid
 * [2,9,9] → duplicate → invalid
 * [9,9,9] → duplicate → invalid
 *
 * Maximum = 15
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 *      O(n)
 *
 * Space Complexity:
 *      O(k)
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * This is a classic combination of:
 *
 *      Sliding Window
 *      + Hash Map for distinct constraint
 *
 * Similar pattern appears in:
 *      • Longest substring with unique characters
 *      • Distinct window problems
 */

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        int n = nums.size();

        unordered_map<int,int> freq;

        long long maxWindow = 0;
        long long currWindow = 0;

        // Build initial window
        for(int i = 0; i < k; i++){

            currWindow += nums[i];
            freq[nums[i]]++;
        }

        if(freq.size() == k)
            maxWindow = currWindow;

        // Sliding window
        for(int i = k; i < n; i++){

            // Add new element
            currWindow += nums[i];
            freq[nums[i]]++;

            // Remove old element
            currWindow -= nums[i - k];
            freq[nums[i - k]]--;

            if(freq[nums[i - k]] == 0)
                freq.erase(nums[i - k]);

            // Check distinct condition
            if(freq.size() == k)
                maxWindow = max(maxWindow, currWindow);
        }

        return maxWindow;
    }
};

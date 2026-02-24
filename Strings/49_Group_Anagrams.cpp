/*
 * Problem: 49. Group Anagrams
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given an array of strings strs,
 * group the anagrams together.
 *
 * Return the grouped anagrams in any order.
 *
 * ------------------------------------------------------------
 * DEFINITION:
 *
 * Two strings are anagrams if:
 *   - They contain the same characters
 *   - With the same frequency
 *   - Order does not matter
 *
 * Example:
 * "eat" and "tea" → anagrams
 *
 * ------------------------------------------------------------
 * APPROACH: Sorting-Based Hashing
 *
 * ------------------------------------------------------------
 * KEY OBSERVATIONS:
 *
 * 1️⃣ If we sort a string,
 *    all its anagrams produce the SAME sorted string.
 *
 * Example:
 *   "eat" → "aet"
 *   "tea" → "aet"
 *   "ate" → "aet"
 *
 * 2️⃣ We can use sorted string as a KEY in a hash map.
 *
 * ------------------------------------------------------------
 * STRATEGY:
 *
 * 1️⃣ Create unordered_map<string, vector<string>>
 *
 * 2️⃣ For each string:
 *       - Create a copy
 *       - Sort it → key
 *       - Insert original string into map[key]
 *
 * 3️⃣ Extract all groups from map into result.
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * Input:
 * ["eat","tea","tan","ate","nat","bat"]
 *
 * Map:
 *
 * "aet" → ["eat","tea","ate"]
 * "ant" → ["tan","nat"]
 * "abt" → ["bat"]
 *
 * Output:
 * [
 *   ["eat","tea","ate"],
 *   ["tan","nat"],
 *   ["bat"]
 * ]
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Let:
 *   n = number of strings
 *   k = max length of string
 *
 * Time Complexity:
 * - O(n * k log k)
 *   (Sorting each string)
 *
 * Space Complexity:
 * - O(n * k)
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - Alternative optimization:
 *   Instead of sorting,
 *   use character frequency array of size 26 as key.
 *   → Reduces sorting cost.
 *
 * - Very common hashing problem.
 */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> result;

        unordered_map<string, vector<string>> mpp;

        for (auto& str : strs) {

            // Create sorted key
            string key = str;
            sort(key.begin(), key.end());

            // Group original string
            mpp[key].push_back(str);
        }

        // Transfer groups to result
        for (auto& [key, group] : mpp) {
            result.push_back(group);
        }

        return result;
    }
};

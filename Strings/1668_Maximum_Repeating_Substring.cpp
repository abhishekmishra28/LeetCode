/*
 * Problem: 1668. Maximum Repeating Substring
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * You are given two strings:
 *
 *      sequence → main string
 *      word     → pattern string
 *
 * A string word is said to be repeating k times if:
 *
 *      word repeated k times is a substring of sequence.
 *
 * Return the maximum value of k.
 *
 * ------------------------------------------------------------
 * EXAMPLE:
 *
 * sequence = "ababc"
 * word     = "ab"
 *
 * Repetitions:
 *
 * "ab"     → present
 * "abab"   → present
 * "ababab" → not present
 *
 * Answer = 2
 *
 * ------------------------------------------------------------
 * CORE IDEA:
 *
 * Try every starting index in sequence
 * and count how many consecutive times
 * "word" repeats from that position.
 *
 * ------------------------------------------------------------
 * APPROACH: Brute Force + Greedy Matching
 *
 * ------------------------------------------------------------
 * ALGORITHM STEPS:
 *
 * 1️⃣ Iterate over every index i in sequence.
 *
 * 2️⃣ For each i:
 *
 *      - Try matching "word"
 *      - If matched, move forward by length of word
 *      - Continue counting consecutive matches
 *
 * 3️⃣ Track the maximum count.
 *
 * ------------------------------------------------------------
 * MATCHING LOGIC:
 *
 * At index idx:
 *
 *      Compare substring of size m with word.
 *
 * If match:
 *
 *      cnt++
 *      idx += m
 *
 * Else:
 *
 *      break
 *
 * ------------------------------------------------------------
 * DRY RUN:
 *
 * sequence = "aaabaaaabaaabaaaabaaaabaaaabaaaaba"
 * word = "aaaba"
 *
 * Repeated matches are counted from each position.
 *
 * Maximum repetition is returned.
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 *      O(n * (n/m) * m)
 *      ≈ O(n²) in worst case
 *
 * Space Complexity:
 *      O(1)
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - Simple brute force approach.
 * - Can be optimized using string matching (KMP / rolling hash),
 *   but not required for constraints.
 */

class Solution {
public:
    int maxRepeating(string sequence, string word) {

        int n = sequence.size();
        int m = word.size();

        if(m > n)
            return 0;

        int maxK = 0;

        for(int i = 0; i <= n - m; i++){

            int cnt = 0;
            int idx = i;

            while(idx + m <= n){

                bool found = true;

                for(int j = 0; j < m; j++){
                    if(sequence[idx + j] != word[j]){
                        found = false;
                        break;
                    }
                }

                if(!found)
                    break;

                cnt++;
                idx += m;
            }

            maxK = max(maxK, cnt);
        }

        return maxK;
    }
};

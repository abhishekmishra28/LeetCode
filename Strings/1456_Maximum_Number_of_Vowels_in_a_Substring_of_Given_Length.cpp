/*
 * Problem: 1456. Maximum Number of Vowels in a Substring of Given Length
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given a string s and an integer k,
 * return the maximum number of vowel letters
 * in any substring of s with length exactly k.
 *
 * Vowels = {a, e, i, o, u}
 *
 * ------------------------------------------------------------
 * APPROACH: Fixed Size Sliding Window
 *
 * ------------------------------------------------------------
 * CORE IDEA:
 *
 * Since the substring size is fixed (k),
 * we use a sliding window of size k
 * to track the number of vowels efficiently.
 *
 * Instead of recalculating vowels for each substring
 * (which would take O(n*k)),
 * we maintain a running count of vowels
 * inside the current window.
 *
 * ------------------------------------------------------------
 * WINDOW MECHANISM:
 *
 * Current window: [i-k+1 ... i]
 *
 * When the window moves forward:
 *
 *   Add the new character entering the window
 *   Remove the character leaving the window
 *
 * This keeps the computation O(n).
 *
 * ------------------------------------------------------------
 * HELPER FUNCTION:
 *
 * isVowel(c):
 *     Returns true if character is
 *     one of {a,e,i,o,u}.
 *
 * ------------------------------------------------------------
 * ALGORITHM STEPS:
 *
 * 1️⃣ Count vowels in the first window of size k.
 *
 * 2️⃣ Store this value as the initial maximum.
 *
 * 3️⃣ Slide the window across the string:
 *
 *      - Add vowel if s[i] is vowel
 *      - Remove vowel if s[i-k] is vowel
 *
 * 4️⃣ Update maximum vowel count.
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * s = "abciiidef"
 * k = 3
 *
 * Windows:
 *
 * "abc" → 1 vowel
 * "bci" → 1 vowel
 * "cii" → 2 vowels
 * "iii" → 3 vowels
 * "iid" → 2 vowels
 *
 * Maximum = 3
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 *   O(n)
 *
 * Space Complexity:
 *   O(1)
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - Classic fixed window sliding technique.
 * - Very common pattern in substring problems.
 */

class Solution {
private:
    bool isVowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }

public:
    int maxVowels(string s, int k) {

        int vowelCnt = 0;

        // First window
        for(int i = 0; i < k; i++){
            if(isVowel(s[i])) vowelCnt++;
        }

        int maxCnt = vowelCnt;

        // Slide window
        for(int i = k; i < s.size(); i++){

            if(isVowel(s[i])) vowelCnt++;
            if(isVowel(s[i - k])) vowelCnt--;

            maxCnt = max(maxCnt, vowelCnt);
        }

        return maxCnt;
    }
};

/*
 * Problem: 3813. Vowel-Consonant Score
 *
 * Statement:
 * You are given a string `s` consisting of:
 * - lowercase English letters
 * - spaces
 * - digits
 *
 * Let:
 *   v = number of VOWELS in `s`
 *   c = number of CONSONANTS in `s`
 *
 * Vowels are: { a, e, i, o, u }
 * Any other English letter is a consonant.
 *
 * The SCORE is defined as:
 * - If c > 0  → score = floor(v / c)
 * - If c == 0 → score = 0
 *
 * Return the score.
 *
 * ------------------------------------------------------------
 * APPROACH: Single Pass Character Classification (Your Approach)
 *
 * Core Idea:
 * - Traverse the string once
 * - Consider ONLY alphabetic characters
 * - Count vowels and consonants separately
 * - Apply the formula at the end
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. Initialize:
 *      v = 0  → vowel count
 *      c = 0  → consonant count
 *
 * 2. Traverse each character `ch` in string `s`:
 *
 *    a) Convert character to lowercase
 *       (safety in case of mixed input)
 *
 *    b) Check if character is an English letter:
 *         'a' <= ch <= 'z'
 *
 *    c) If it is a vowel:
 *         increment v
 *
 *    d) Else (it is a consonant):
 *         increment c
 *
 *    e) Ignore:
 *         - digits
 *         - spaces
 *         - special characters
 *
 * 3. After traversal:
 *    - If c == 0:
 *         return 0
 *    - Else:
 *         return floor(v / c)
 *
 * ------------------------------------------------------------
 * Why floor(v / c) works directly in C++:
 *
 * - Both v and c are integers
 * - Integer division automatically performs FLOOR division
 *
 * Example:
 *   v = 5, c = 2 → v / c = 2
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * Input:
 * s = "a1b2c e"
 *
 * Letters considered:
 * a → vowel (v = 1)
 * b → consonant (c = 1)
 * c → consonant (c = 2)
 * e → vowel (v = 2)
 *
 * Score = floor(2 / 2) = 1
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - No consonants → return 0
 * - No vowels → return 0
 * - String with only digits or spaces
 * - Mixed content string
 *
 * ------------------------------------------------------------
 * Time Complexity:
 * - O(n)
 *   n = length of string
 *
 * Space Complexity:
 * - O(1)
 *   Only counters used
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Character Classification + Counting" problem
 *
 * Seen in:
 * - String scoring problems
 * - Text analysis
 * - Parsing and filtering characters
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int vowelConsonantScore(string s) {
        int c = 0;
        int v = 0;

        for (char ch : s) {
            ch = tolower(ch);

            // consider only alphabetic characters
            if (ch >= 'a' && ch <= 'z') {
                if (ch == 'a' || ch == 'e' || ch == 'i' ||
                    ch == 'o' || ch == 'u') {
                    v++;
                } else {
                    c++;
                }
            }
        }

        if (c == 0) return 0;
        return v / c;  // integer division = floor(v / c)
    }
};

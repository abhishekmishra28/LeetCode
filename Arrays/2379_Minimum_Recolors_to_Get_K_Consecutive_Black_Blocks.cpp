/*
 * Problem: 2379. Minimum Recolors to Get K Consecutive Black Blocks
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * You are given a string blocks consisting of characters:
 *
 *      'B' → Black block
 *      'W' → White block
 *
 * You want to obtain k consecutive black blocks.
 *
 * In one operation you can recolor a white block ('W')
 * into a black block ('B').
 *
 * Return the minimum number of recoloring operations needed.
 *
 * ------------------------------------------------------------
 * CORE IDEA:
 *
 * We need a substring of length k that contains
 * the minimum number of white blocks.
 *
 * Because every 'W' in that window must be recolored
 * to 'B'.
 *
 * So the problem becomes:
 *
 *      Find the window of size k with the
 *      minimum count of 'W'.
 *
 * ------------------------------------------------------------
 * APPROACH: Fixed Size Sliding Window
 *
 * Instead of checking every substring
 * in O(n*k), we maintain a sliding window
 * that tracks the number of white blocks.
 *
 * ------------------------------------------------------------
 * ALGORITHM STEPS:
 *
 * 1️⃣ Count number of 'W' in the first window of size k.
 *
 * 2️⃣ Store this value as the current minimum window.
 *
 * 3️⃣ Slide the window across the string:
 *
 *      - If new character entering window is 'W'
 *            increase counter.
 *
 *      - If character leaving window is 'W'
 *            decrease counter.
 *
 * 4️⃣ Update minimum window count.
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * blocks = "WBBWWBBWBW"
 * k = 7
 *
 * Windows:
 *
 * WBBWWBB → 3 W
 * BBWWBBW → 3 W
 * BWWBBWB → 3 W
 * WWBBW BW → 4 W
 *
 * Minimum recolors needed = 3
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 *      O(n)
 *
 * Space Complexity:
 *      O(1)
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * This is a classic
 *
 *      Fixed Window Sliding Window
 *
 * pattern where we track a property
 * (here number of 'W') inside the window.
 */

class Solution {
public:
    int minimumRecolors(string blocks, int k) {

        int n = blocks.size();

        // Count 'W' in the first window
        int minWindow = 0;

        for(int i = 0; i < k; i++){
            if(blocks[i] == 'W')
                minWindow++;
        }

        int currWindow = minWindow;

        // Slide the window
        for(int i = k; i < n; i++){

            if(blocks[i] == 'W')
                currWindow++;

            if(blocks[i - k] == 'W')
                currWindow--;

            minWindow = min(minWindow, currWindow);
        }

        return minWindow;
    }
};

/*
 * Problem: 1052. Grumpy Bookstore Owner
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * A bookstore owner keeps track of customers entering the shop.
 *
 * customers[i] → number of customers at minute i
 * grumpy[i]    → owner mood
 *
 *        0 → owner is NOT grumpy
 *        1 → owner is grumpy
 *
 * If the owner is grumpy, customers at that minute
 * leave unsatisfied.
 *
 * The owner has a secret technique that can suppress
 * grumpiness for exactly k consecutive minutes.
 *
 * Goal:
 * Maximize the number of satisfied customers.
 *
 * ------------------------------------------------------------
 * KEY OBSERVATION:
 *
 * Customers are already satisfied when:
 *
 *        grumpy[i] == 0
 *
 * These customers always count.
 *
 * The technique only helps recover customers
 * from minutes where:
 *
 *        grumpy[i] == 1
 *
 * ------------------------------------------------------------
 * STRATEGY:
 *
 * Break the problem into two parts:
 *
 * 1️⃣ Base satisfaction
 *      Customers already satisfied
 *      when owner is not grumpy.
 *
 * 2️⃣ Extra satisfaction
 *      Use sliding window of size k
 *      to recover maximum customers
 *      from grumpy minutes.
 *
 * ------------------------------------------------------------
 * SLIDING WINDOW IDEA:
 *
 * Consider a window of size k.
 *
 * Inside that window,
 * if grumpy[i] == 1,
 * those customers can be recovered.
 *
 * We track the window that produces
 * the maximum recoverable customers.
 *
 * ------------------------------------------------------------
 * ALGORITHM STEPS:
 *
 * Step 1:
 *      Compute base satisfied customers.
 *
 * Step 2:
 *      Build initial window of size k
 *      counting customers where grumpy = 1.
 *
 * Step 3:
 *      Slide window across array:
 *
 *          Add entering element
 *          Remove leaving element
 *
 * Step 4:
 *      Track maximum recoverable customers.
 *
 * Step 5:
 *      Final answer:
 *
 *          base + maxWindow
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * customers = [1,0,1,2,1,1,7,5]
 * grumpy    = [0,1,0,1,0,1,0,1]
 * k = 3
 *
 * Base satisfied:
 * minutes with grumpy = 0
 *
 * Sliding window recovers
 * maximum extra customers.
 *
 * Final result = base + best window.
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
 * This is a classic pattern:
 *
 *      "Fixed Sliding Window
 *       + Base Contribution"
 *
 * Similar idea appears in
 * several optimization problems.
 */

class Solution {
public:
    int maxSatisfied(vector<int>& customers,
                     vector<int>& grumpy,
                     int k) {

        int n = customers.size();

        // Customers already satisfied
        int base = 0;

        for(int i = 0; i < n; i++) {
            if(grumpy[i] == 0)
                base += customers[i];
        }

        int maxWindow = 0;
        int currWindow = 0;

        // Initial window
        for(int i = 0; i < k; i++) {
            if(grumpy[i] == 1)
                currWindow += customers[i];
        }

        maxWindow = currWindow;

        // Sliding window
        for(int i = k; i < n; i++) {

            if(grumpy[i] == 1)
                currWindow += customers[i];

            if(grumpy[i-k] == 1)
                currWindow -= customers[i-k];

            maxWindow = max(maxWindow, currWindow);
        }

        return base + maxWindow;
    }
};

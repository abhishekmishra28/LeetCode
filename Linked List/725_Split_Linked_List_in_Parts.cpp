/*
 * Problem: 725. Split Linked List in Parts
 *
 * Statement:
 * Given the head of a singly linked list and an integer k,
 * split the linked list into k consecutive parts.
 *
 * Rules:
 * - The length of each part should be as equal as possible
 * - No two parts should differ in size by more than 1
 * - Earlier parts should be larger if sizes are unequal
 * - Some parts may be NULL if the list is shorter than k
 *
 * ------------------------------------------------------------
 * APPROACH: Length Calculation + Controlled Splitting — Your Approach
 *
 * Core Idea:
 *
 * 1. First, count the total number of nodes (n)
 * 2. Decide the size of each part:
 *      - baseSize = n / k
 *      - extra    = n % k
 *
 * 3. The first `extra` parts will have:
 *        baseSize + 1 nodes
 *    The remaining parts will have:
 *        baseSize nodes
 *
 * 4. Traverse the list and cut it into k parts accordingly
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. Initialize:
 *
 *      result vector of size k (all nullptr)
 *
 * 2. Count total number of nodes:
 *
 *      Traverse the list once to compute `n`
 *
 * 3. Compute:
 *
 *      baseSize = n / k
 *      extra    = n % k
 *
 * 4. Reset pointer to head
 *
 * 5. For each part i from 0 to k-1:
 *
 *      a) Determine current part size:
 *
 *           currSize = baseSize + (i < extra ? 1 : 0)
 *
 *      b) Set result[i] = current node pointer
 *
 *      c) Move `currSize - 1` steps ahead
 *
 *      d) Cut the list:
 *           - Store next part start
 *           - Set current node’s next = NULL
 *           - Move temp to next part
 *
 *      e) If currSize == 0:
 *           - result[i] = NULL
 *
 * 6. Return result
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Integer division ensures minimal size difference
 * - Extra nodes are distributed to earlier parts
 * - Cutting links guarantees independent sublists
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * Input:
 *   head = [1,2,3,4,5,6,7]
 *   k = 3
 *
 * n = 7
 * baseSize = 7 / 3 = 2
 * extra = 1
 *
 * Parts:
 *   Part 0 → 3 nodes → [1,2,3]
 *   Part 1 → 2 nodes → [4,5]
 *   Part 2 → 2 nodes → [6,7]
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - n < k → some parts are NULL
 * - n == k → each part has exactly one node
 * - Empty list → all parts NULL
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - O(n)
 *   One pass to count + one pass to split
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(1) extra space (excluding output vector)
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Linked List Partitioning with Size Balancing"
 *
 * Seen in:
 * - Load balancing problems
 * - Fair distribution tasks
 * - Controlled list splitting
 */

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result(k, nullptr);

        // 1. Count total nodes
        int n = 0;
        ListNode* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }

        // 2. Calculate base size and extra nodes
        int baseSize = n / k;
        int extra = n % k;

        temp = head;

        // 3. Split into k parts
        for (int i = 0; i < k; i++) {
            int currSize = baseSize + (i < extra ? 1 : 0);

            if (currSize == 0) {
                result[i] = nullptr;
                continue;
            }

            result[i] = temp;

            for (int j = 0; j < currSize - 1; j++) {
                temp = temp->next;
            }

            ListNode* nextPart = temp->next;
            temp->next = nullptr;
            temp = nextPart;
        }

        return result;
    }
};

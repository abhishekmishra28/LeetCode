/*
 * Problem: 328. Odd Even Linked List
 *
 * Statement:
 * Given the head of a singly linked list, group all the nodes with
 * ODD indices together followed by the nodes with EVEN indices,
 * and return the reordered list.
 *
 * NOTE:
 * - Indexing is 1-based (not value-based)
 * - The relative order within odd and even groups must be preserved
 *
 * ------------------------------------------------------------
 * APPROACH: Pointer Rewiring (In-place) — Your Approach
 *
 * Core Idea:
 *
 * - Maintain two separate chains:
 *     odd  → nodes at positions 1, 3, 5, ...
 *     even → nodes at positions 2, 4, 6, ...
 *
 * - Traverse the list once and rewire pointers
 * - Finally, attach the even list after the odd list
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - We never create new nodes
 * - We only change `next` pointers
 * - Order is preserved because we move sequentially
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. Edge Case:
 *      If head == NULL:
 *          → return nullptr
 *
 * 2. Initialization:
 *
 *      odd  = head
 *      even = head->next
 *      temp = even     // store head of even list
 *
 * 3. Traverse while even and even->next exist:
 *
 *      a) odd->next = even->next
 *         odd = odd->next
 *
 *      b) even->next = odd->next
 *         even = even->next
 *
 *    This alternates nodes into odd and even chains
 *
 * 4. After traversal:
 *
 *      odd->next = temp
 *      // append even list after odd list
 *
 * 5. Return head
 *
 * ------------------------------------------------------------
 * Pointer Movement Visualization:
 *
 * Initial:
 *   odd = 1 → 2 → 3 → 4 → 5
 *   even = 2 → 3 → 4 → 5
 *
 * After rearrangement:
 *   odd list  : 1 → 3 → 5
 *   even list : 2 → 4
 *
 * Final:
 *   1 → 3 → 5 → 2 → 4
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * Input:
 *   1 → 2 → 3 → 4 → 5
 *
 * Output:
 *   1 → 3 → 5 → 2 → 4
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Empty list → return nullptr
 * - Single node → unchanged
 * - Two nodes → unchanged
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - O(n)
 *   Each node is visited once
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(1)
 *   In-place pointer manipulation
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Linked List Reordering using Pointer Manipulation"
 *
 * Seen in:
 * - List partitioning problems
 * - In-place linked list rearrangements
 */

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return nullptr;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* temp = even;   // head of even list

        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }

        odd->next = temp;
        return head;
    }
};

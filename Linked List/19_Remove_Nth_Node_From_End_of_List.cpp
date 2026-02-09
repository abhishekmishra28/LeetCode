/*
 * Problem: 19. Remove Nth Node From End of List
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given the head of a singly linked list and an integer n,
 * remove the n-th node from the end of the list and return
 * the head of the modified list.
 *
 * ------------------------------------------------------------
 * APPROACH: Two Pointer Technique (Fast & Slow Pointers)
 *
 * Core Idea:
 * - Maintain a gap of `n` nodes between two pointers.
 * - When the fast pointer reaches the end of the list,
 *   the slow pointer will be just before the node that
 *   needs to be removed.
 *
 * ------------------------------------------------------------
 * STEP-BY-STEP EXPLANATION:
 *
 * 1️⃣ Initialize two pointers:
 *    - `slow` → points to head
 *    - `fast` → points to head
 *
 * 2️⃣ Move `fast` pointer `n` steps ahead:
 *    - This creates a fixed gap of `n` nodes between `slow` and `fast`
 *
 * 3️⃣ Edge Case (Deleting the head):
 *    - If `fast` becomes NULL after moving `n` steps,
 *      it means the node to delete is the HEAD itself
 *    - So we simply return `head->next`
 *
 * 4️⃣ Move both pointers together:
 *    - Move `slow` and `fast` one step at a time
 *    - Stop when `fast->next` becomes NULL
 *
 * 5️⃣ Delete the target node:
 *    - `slow->next` is the n-th node from the end
 *    - Skip it by adjusting pointers
 *
 * 6️⃣ Return the updated head
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * Input:
 *   head = 1 → 2 → 3 → 4 → 5
 *   n = 2
 *
 * Fast pointer moves 2 steps:
 *   fast → 3
 *
 * Move both pointers:
 *   fast → 5
 *   slow → 3
 *
 * Node to delete:
 *   slow->next = 4
 *
 * Output:
 *   1 → 2 → 3 → 5
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 * - O(n) → Single traversal of the list
 *
 * Space Complexity:
 * - O(1) → No extra space used
 *
 * ------------------------------------------------------------
 * WHY THIS APPROACH IS OPTIMAL:
 *
 * ✅ One-pass solution
 * ✅ No need to calculate list length
 * ✅ Clean and efficient
 * ✅ Very common interview pattern
 *
 * ------------------------------------------------------------
 * IMPORTANT NOTES:
 *
 * - We delete the node explicitly to avoid memory leaks
 * - Works for all valid values of n
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // Step 1: Initialize pointers
        ListNode* slow = head;
        ListNode* fast = head;

        // Step 2: Move fast pointer n steps ahead
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Step 3: If fast is NULL, remove head
        if (fast == nullptr)
            return head->next;

        // Step 4: Move both pointers together
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        // Step 5: Delete the node
        ListNode* todelete = slow->next;
        slow->next = slow->next->next;
        delete todelete;

        // Step 6: Return head
        return head;
    }
};

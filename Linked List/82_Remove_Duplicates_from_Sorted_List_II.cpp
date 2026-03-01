/*
 * Problem: 82. Remove Duplicates from Sorted List II
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given the head of a sorted linked list,
 * delete ALL nodes that have duplicate numbers,
 * leaving only distinct numbers.
 *
 * Return the head of the modified list.
 *
 * ------------------------------------------------------------
 * IMPORTANT DIFFERENCE:
 *
 * This is NOT the simple duplicate removal problem.
 *
 * Example:
 *
 * Input:
 *   1 → 2 → 3 → 3 → 4 → 4 → 5
 *
 * Output:
 *   1 → 2 → 5
 *
 * (All 3s and 4s removed completely.)
 *
 * ------------------------------------------------------------
 * APPROACH: Dummy Node + Two Pointers
 *
 * ------------------------------------------------------------
 * KEY OBSERVATIONS:
 *
 * 1️⃣ The list is SORTED.
 *    So duplicates appear consecutively.
 *
 * 2️⃣ When we detect duplicates:
 *    We must skip ALL nodes with that value.
 *
 * 3️⃣ A dummy node helps handle edge cases,
 *    especially when the first nodes are duplicates.
 *
 * ------------------------------------------------------------
 * POINTERS USED:
 *
 * dummy → before head (for safety)
 * prev  → last confirmed unique node
 * curr  → current scanning node
 *
 * ------------------------------------------------------------
 * STRATEGY:
 *
 * 1️⃣ Create dummy pointing to head.
 *
 * 2️⃣ Traverse using curr:
 *
 *    If curr and curr->next have same value:
 *       - Skip all nodes with that value
 *       - Connect prev->next to first non-duplicate node
 *
 *    Else:
 *       - Move prev forward
 *
 * 3️⃣ Move curr forward each iteration.
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * 1 → 2 → 3 → 3 → 4 → 4 → 5
 *
 * At value 3:
 *   Skip all 3s
 *   prev->next = 4
 *
 * At value 4:
 *   Skip all 4s
 *   prev->next = 5
 *
 * Final:
 * 1 → 2 → 5
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 * - O(n)
 *
 * Space Complexity:
 * - O(1)
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - Always use dummy for linked list deletion problems.
 * - Be careful when head itself is duplicate.
 * - Very common pointer manipulation question.
 */

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        if (!head)
            return nullptr;

        // Dummy node to handle edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr) {

            // Detect duplicates
            if (curr->next &&
                curr->val == curr->next->val) {

                // Skip all nodes with same value
                while (curr->next &&
                       curr->val == curr->next->val) {

                    curr = curr->next;
                }

                // Remove duplicates
                prev->next = curr->next;
            }
            else {
                // Move prev only if no duplicate
                prev = prev->next;
            }

            curr = curr->next;
        }

        return dummy->next;
    }
};

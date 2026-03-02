/*
 * Problem: 83. Remove Duplicates from Sorted List
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given the head of a sorted linked list,
 * delete all duplicates such that each element
 * appears only once.
 *
 * Return the modified list.
 *
 * ------------------------------------------------------------
 * IMPORTANT DIFFERENCE (vs Problem 82):
 *
 * Here:
 *   Keep ONE copy of duplicate values.
 *
 * Example:
 *
 * Input:
 *   1 → 1 → 2 → 3 → 3
 *
 * Output:
 *   1 → 2 → 3
 *
 * ------------------------------------------------------------
 * APPROACH: Single Pointer Traversal
 *
 * ------------------------------------------------------------
 * KEY OBSERVATIONS:
 *
 * 1️⃣ The list is SORTED.
 *    So duplicates appear consecutively.
 *
 * 2️⃣ If current value equals next value:
 *    Simply skip the next node.
 *
 * 3️⃣ No need for dummy node here,
 *    because we never remove the first occurrence.
 *
 * ------------------------------------------------------------
 * STRATEGY:
 *
 * 1️⃣ Start with pointer curr = head.
 *
 * 2️⃣ While curr is not null:
 *
 *       While:
 *           curr->next exists AND
 *           curr->val == curr->next->val
 *
 *           Skip next node:
 *               curr->next = curr->next->next
 *
 *       Move curr forward.
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * 1 → 1 → 2 → 3 → 3
 *
 * At first 1:
 *   Skip second 1
 *
 * At 3:
 *   Skip second 3
 *
 * Final:
 *   1 → 2 → 3
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
 * - Much simpler than Problem 82.
 * - Key idea: Since sorted, duplicates are adjacent.
 * - Always check curr->next before accessing.
 */

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        if (!head)
            return nullptr;

        ListNode* curr = head;

        while (curr) {

            // Skip all duplicates of current value
            while (curr->next &&
                   curr->val == curr->next->val) {

                curr->next = curr->next->next;
            }

            curr = curr->next;
        }

        return head;
    }
};

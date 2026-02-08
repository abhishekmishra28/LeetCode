/*
 * Problem: 2487. Remove Nodes From Linked List
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * You are given the head of a linked list.
 * Remove every node which has a node with a strictly greater value
 * somewhere to the right side of it.
 *
 * Return the head of the modified linked list.
 *
 * ------------------------------------------------------------
 * APPROACH: Reverse + One Pass Filtering + Reverse Back
 *
 * Core Idea:
 * - It is hard to know whether a greater value exists on the RIGHT
 *   when traversing normally.
 * - So, reverse the linked list and convert the problem into:
 *   👉 remove nodes that have a GREATER value on the LEFT.
 *
 * ------------------------------------------------------------
 * STEP-BY-STEP EXPLANATION:
 *
 * 1️⃣ Reverse the linked list
 *    - Now, the "right side" of the original list becomes the "left side"
 *
 * 2️⃣ Traverse the reversed list
 *    - Maintain the maximum value seen so far
 *    - If next node's value is smaller than current node’s value:
 *        → it means a greater value existed to its right originally
 *        → remove that node
 *
 * 3️⃣ Reverse the list again
 *    - Restores the original order (after deletions)
 *
 * ------------------------------------------------------------
 * EXAMPLE:
 *
 * Input:
 *   5 -> 2 -> 13 -> 3 -> 8
 *
 * Reverse:
 *   8 -> 3 -> 13 -> 2 -> 5
 *
 * Remove nodes smaller than max seen:
 *   8 -> 13
 *
 * Reverse back:
 *   13 -> 8
 *
 * Output:
 *   13 -> 8
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 * - O(n) → 2 reversals + 1 traversal
 *
 * Space Complexity:
 * - O(1) → in-place operations
 *
 * ------------------------------------------------------------
 * WHY THIS APPROACH IS OPTIMAL:
 *
 * ✅ No extra stack or array
 * ✅ In-place linked list manipulation
 * ✅ Clean and interview-friendly
 *
 * ------------------------------------------------------------
 * KEY INSIGHT:
 * Reverse the list to turn a "right-side dependency" problem
 * into a "left-side comparison" problem.
 */

class Solution {
private:
    // Helper function to reverse a linked list
    ListNode* reverseList(ListNode* node) {
        ListNode* prev = nullptr;
        ListNode* curr = node;

        while (curr) {
            ListNode* Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    }

public:
    ListNode* removeNodes(ListNode* head) {

        // Step 1: Reverse the linked list
        head = reverseList(head);

        // Step 2: Remove nodes that are smaller than the max seen so far
        ListNode* temp = head;
        while (temp && temp->next) {
            if (temp->next->val < temp->val) {
                // Delete the smaller node
                temp->next = temp->next->next;
            } else {
                temp = temp->next;
            }
        }

        // Step 3: Reverse the list again to restore order
        head = reverseList(head);

        return head;
    }
};

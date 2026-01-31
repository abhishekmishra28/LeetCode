/*
 * Problem: 234. Palindrome Linked List
 *
 * Statement:
 * Given the head of a singly linked list, determine whether
 * the list is a PALINDROME.
 *
 * A linked list is a palindrome if it reads the same
 * forward and backward.
 *
 * ------------------------------------------------------------
 * APPROACH: Two Pointers + In-place Reverse — Your Approach
 *
 * Core Idea:
 *
 * - We cannot traverse backward in a singly linked list
 * - So we:
 *     1) Find the middle of the list
 *     2) Reverse the second half
 *     3) Compare the first half and reversed second half
 *
 * This allows palindrome checking in O(1) extra space.
 *
 * ------------------------------------------------------------
 * Step 1: Find the Middle of the Linked List
 *
 * Technique:
 * - Use two pointers:
 *     slow → moves 1 step
 *     fast → moves 2 steps
 *
 * When fast reaches the end:
 * - slow will be at the middle
 *
 * Code logic:
 *
 *   while (fast && fast->next):
 *       slow = slow->next
 *       fast = fast->next->next
 *
 * ------------------------------------------------------------
 * Step 2: Reverse the Second Half of the List
 *
 * Starting from `slow`, reverse the linked list in-place.
 *
 * Standard linked list reversal:
 *
 *   prev = nullptr
 *   curr = slow
 *
 *   while (curr):
 *       next = curr->next
 *       curr->next = prev
 *       prev = curr
 *       curr = next
 *
 * After this:
 * - `prev` becomes the head of the reversed second half
 *
 * ------------------------------------------------------------
 * Step 3: Compare Both Halves
 *
 * - left  pointer starts from head
 * - right pointer starts from reversed second half (prev)
 *
 * Compare values node by node:
 *
 *   while (right):
 *       if left->val != right->val:
 *           return false
 *       move both pointers forward
 *
 * If all values match → palindrome
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - First half remains in original order
 * - Second half is reversed to simulate backward traversal
 * - Only half the list is compared
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * Input:
 *   1 → 2 → 2 → 1
 *
 * Step 1:
 *   slow at second 2
 *
 * Step 2 (reverse second half):
 *   1 ← 2
 *
 * Step 3 (compare):
 *   1 == 1
 *   2 == 2
 *
 * → Palindrome ✔
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Empty list → palindrome
 * - Single node → palindrome
 * - Odd length list (middle element ignored naturally)
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - O(n)
 *   Each node is visited a constant number of times
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(1)
 *   In-place reversal, no extra data structures
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Fast & Slow Pointer + In-place Reversal"
 *
 * Seen in:
 * - Palindrome problems
 * - Linked list middle problems
 * - Cycle / reversal based questions
 */

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;

        // 1. Find middle
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Reverse second half
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // 3. Compare halves
        ListNode* left = head;
        ListNode* right = prev;
        while (right) {
            if (left->val != right->val)
                return false;
            left = left->next;
            right = right->next;
        }

        return true;
    }
};

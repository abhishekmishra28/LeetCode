/*
 * Problem: 1721. Swapping Nodes in a Linked List
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * You are given the head of a singly linked list and an integer k.
 * Swap the values of the k-th node from the beginning and the k-th node
 * from the end, and return the head of the modified linked list.
 *
 * ------------------------------------------------------------
 * APPROACH 2: One-Pass Two Pointer Technique (Efficient Approach)
 *
 * Idea:
 * - Find the k-th node from the beginning.
 * - Use two pointers to locate the k-th node from the end in the same traversal.
 * - Swap their values directly.
 *
 * ------------------------------------------------------------
 * STEP-BY-STEP EXPLANATION:
 *
 * 1️⃣ Initialize two pointers:
 *    - `left`  → starts from head (will reach k-th from end)
 *    - `right` → starts from head
 *
 * 2️⃣ Move `right` (k-1) steps forward
 *    - Now `right` is pointing to the k-th node from the start
 *    - Store this node as `end` (k-th from beginning)
 *
 * 3️⃣ Move both pointers together:
 *    - Move `right` to the end of the list
 *    - Simultaneously move `left`
 *    - When `right` reaches last node, `left` will be at k-th node from the end
 *
 * 4️⃣ Swap the values:
 *    - Swap `end->val` and `left->val`
 *
 * 5️⃣ Return head (structure unchanged, only values swapped)
 *
 * ------------------------------------------------------------
 * WHY THIS WORKS:
 *
 * - Distance between `right` and `left` is maintained.
 * - When `right` reaches the end, `left` automatically lands at the
 *   correct k-th position from the end.
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 * - O(n) → single traversal of the list
 *
 * Space Complexity:
 * - O(1) → no extra data structures used
 *
 * ------------------------------------------------------------
 * ADVANTAGE OVER ARRAY APPROACH:
 *
 * ✅ No extra memory
 * ✅ Faster in practice
 * ✅ Clean pointer-based logic (interview favorite)
 *
 * ------------------------------------------------------------
 * NOTE:
 * - We swap VALUES, not actual nodes.
 * - Swapping nodes would require pointer rewiring and more edge cases.
 */

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {

        // Step 1: Initialize pointers
        ListNode* left = head;
        ListNode* right = head;

        // Step 2: Move right pointer to k-th node from start
        for (int i = 0; i < k - 1; i++) {
            right = right->next;
        }

        // Store k-th node from beginning
        ListNode* end = right;

        // Step 3: Move both pointers till right reaches end
        while (right->next) {
            left = left->next;
            right = right->next;
        }

        // Step 4: Swap values
        swap(end->val, left->val);

        // Step 5: Return head
        return head;
    }
};

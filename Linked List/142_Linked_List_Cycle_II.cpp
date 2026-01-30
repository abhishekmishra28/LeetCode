/*
 * Problem: 142. Linked List Cycle II
 *
 * Statement:
 * Given the head of a linked list, return the node where the cycle begins.
 * If there is no cycle, return nullptr.
 *
 * Note:
 * - Do NOT modify the linked list.
 * - There may or may not be a cycle.
 *
 * ------------------------------------------------------------
 * APPROACH: Floyd’s Cycle Detection Algorithm (Tortoise & Hare)
 *           + Mathematical Insight — Your Approach
 *
 * This is a TWO-PHASE algorithm:
 *   Phase 1 → Detect if a cycle exists
 *   Phase 2 → Find the starting node of the cycle
 *
 * ------------------------------------------------------------
 * PHASE 1: Cycle Detection
 *
 * Core Idea:
 * - Use two pointers:
 *     slow → moves 1 step at a time
 *     fast → moves 2 steps at a time
 *
 * - If a cycle exists:
 *     slow and fast WILL meet inside the cycle
 *
 * - If no cycle exists:
 *     fast will reach NULL
 *
 * ------------------------------------------------------------
 * PHASE 2: Find Cycle Start
 *
 * Key Mathematical Insight:
 *
 * Let:
 * - Distance from head to cycle start = x
 * - Distance from cycle start to meeting point = y
 * - Length of cycle = c
 *
 * At meeting point:
 *   fast has traveled 2× the distance of slow
 *
 * After simplifying:
 *   x = c − y
 *
 * Meaning:
 * - If one pointer starts from HEAD
 * - Another starts from MEETING POINT
 * - Moving BOTH one step at a time
 *
 * → They will meet EXACTLY at the cycle start
 *
 * ------------------------------------------------------------
 * Step-by-Step Algorithm (Your Exact Logic):
 *
 * 1. Initialize pointers:
 *
 *      slow = head
 *      fast = head
 *      temp = head   // will be used in phase 2
 *
 * 2. Move pointers until fast reaches end:
 *
 *      while (fast != NULL && fast->next != NULL):
 *
 *          slow = slow->next
 *          fast = fast->next->next
 *
 *          if (slow == fast):
 *              // cycle detected
 *
 *              3. Find cycle start:
 *
 *                 while (temp != slow):
 *                     temp = temp->next
 *                     slow = slow->next
 *
 *                 return slow
 *
 * 4. If loop ends without meeting:
 *      → no cycle
 *      → return nullptr
 *
 * ------------------------------------------------------------
 * Why This Works:
 *
 * - Floyd’s algorithm guarantees detection in O(n)
 * - Mathematical property ensures correct cycle entry point
 * - No extra memory is used
 *
 * ------------------------------------------------------------
 * Example Walkthrough:
 *
 * Linked List:
 * 3 → 2 → 0 → -4
 *      ↑         ↓
 *      ← ← ← ← ←
 *
 * slow & fast meet at node -4
 *
 * temp starts from head (3)
 * slow continues from meeting point
 *
 * They meet at node 2 → cycle start
 *
 * ------------------------------------------------------------
 * Edge Cases:
 *
 * - Empty list → return nullptr
 * - Single node without cycle → nullptr
 * - Cycle starts at head
 *
 * ------------------------------------------------------------
 * Time Complexity:
 *
 * - O(n)
 *   Each pointer traverses the list a constant number of times
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(1)
 *   No extra data structures used
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Fast & Slow Pointer + Cycle Mathematics"
 *
 * Seen in:
 * - Cycle detection
 * - Linked list intersection
 * - Duplicate number problems
 */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {   // cycle detected
                while (temp != slow) {
                    temp = temp->next;
                    slow = slow->next;
                }
                return slow;      // cycle start
            }
        }
        return nullptr;           // no cycle
    }
};

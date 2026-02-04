# Stack 🧱

This folder contains problems solved using the **Stack** data structure.
Stacks follow the **Last In, First Out (LIFO)** principle and are widely used
in parsing, recursion, expression evaluation, and monotonic pattern problems.

---

## 🧠 When to Use Stack

A stack is typically useful when:
- You need to process elements in **reverse order**
- You want to **track previous/next greater or smaller elements**
- You need **nested structure handling** (parentheses, recursion)
- You want to **undo / backtrack** operations

---

## 🔑 Common Stack Patterns

Some frequently recurring stack-based patterns include:

- **Monotonic Stack**
  - Next Greater Element
  - Next Smaller Element
  - Stock Span problems

- **Parentheses Matching**
  - Valid parentheses
  - Minimum removals

- **Expression Evaluation**
  - Infix → Postfix
  - Postfix evaluation

- **Simulation**
  - Asteroid collision
  - Stack-based state tracking

---

## 🛠 Implementation Notes

- Most solutions use:
  - `stack<int>` or `stack<char>`
  - Sometimes `vector` or `deque` for manual stack control
- Pay attention to:
  - Empty stack checks
  - Order of operations
  - Index vs value storage

---

## ⏱ Complexity

Typical stack-based solutions run in:

- **Time:** `O(n)`  
- **Space:** `O(n)` (in worst case)

---

## 💡 Tips

- Always ask: *What should stay in the stack?*
- Try to maintain a **monotonic property** when applicable
- Many problems become easier once brute force is visualized
- Stack problems often look hard but simplify with the right invariant

---

## 📌 Notes

- Each solution includes comments explaining the intuition
- Edge cases are handled explicitly
- Problems are revisited and optimized when better approaches are learned

---

Happy stacking! 🚀

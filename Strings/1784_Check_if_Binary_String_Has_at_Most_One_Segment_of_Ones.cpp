/*
 * Problem: 1784. Check if Binary String Has at Most One Segment of Ones
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * A binary string is given consisting of characters:
 *
 *      '0' and '1'
 *
 * A segment of ones is defined as a contiguous sequence
 * of '1's.
 *
 * The task is to determine whether the string contains
 * at most one segment of '1'.
 *
 * Return:
 *
 *      true  → if there is at most one segment of '1'
 *      false → if there are multiple segments
 *
 * ------------------------------------------------------------
 * EXAMPLES:
 *
 * s = "110"
 *
 * Segments of '1':
 *      "11"
 *
 * Only one segment → return true
 *
 * ------------------------------------------------------------
 *
 * s = "1001"
 *
 * Segments of '1':
 *      "1" , "1"
 *
 * Two segments → return false
 *
 * ------------------------------------------------------------
 * KEY OBSERVATION:
 *
 * Multiple segments of '1' appear only when
 * we encounter the pattern:
 *
 *      "01"
 *
 * Because:
 *
 *      "01" means a segment of ones ended,
 *      and if another '1' appears later,
 *      it starts a new segment.
 *
 * Therefore:
 *
 * If the string contains "01",
 * then more than one segment exists.
 *
 * ------------------------------------------------------------
 * APPROACH:
 *
 * Simply check whether the substring "01"
 * exists inside the string.
 *
 * If it exists:
 *
 *      return false
 *
 * Otherwise:
 *
 *      return true
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 *      O(n)
 *
 * Space Complexity:
 *      O(1)
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTE:
 *
 * This problem tests the ability to
 * simplify a problem using pattern observation.
 */

class Solution {
public:
    bool checkOnesSegment(string s) {

        return !s.contains("01");
    }
};

/*
 * Problem: 997. Find the Town Judge
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * In a town of n people labeled from 1 to n,
 * there is a rumor that one person is the town judge.
 *
 * The town judge:
 *
 * 1️⃣ Trusts nobody.
 * 2️⃣ Is trusted by everyone else (n - 1 people).
 *
 * You are given an array trust where:
 *   trust[i] = [a, b]
 *   → person a trusts person b.
 *
 * Return the label of the town judge.
 * If no judge exists, return -1.
 *
 * ------------------------------------------------------------
 * APPROACH: In-degree / Out-degree Counting
 *
 * ------------------------------------------------------------
 * KEY OBSERVATIONS:
 *
 * 1️⃣ If person a trusts someone:
 *    → They CANNOT be the judge.
 *
 * 2️⃣ Judge must have:
 *    - Out-degree = 0
 *    - In-degree  = n - 1
 *
 * 3️⃣ Instead of maintaining two arrays,
 *    we can use ONE array:
 *
 *    cnt[i] =
 *       +1  for each person who trusts i
 *       -1  for each person i trusts
 *
 * 4️⃣ The judge will have:
 *       cnt[i] = n - 1
 *
 * ------------------------------------------------------------
 * STRATEGY:
 *
 * 1️⃣ Initialize count array of size n+1.
 *
 * 2️⃣ For each trust pair [a, b]:
 *       cnt[a]--   (a trusts someone)
 *       cnt[b]++   (b is trusted)
 *
 * 3️⃣ Traverse 1 to n:
 *       If cnt[i] == n - 1 → return i
 *
 * 4️⃣ If no such person → return -1
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * n = 3
 * trust = [[1,3],[2,3]]
 *
 * cnt:
 * 1 → -1
 * 2 → -1
 * 3 → +2
 *
 * Since n - 1 = 2,
 * person 3 is the judge.
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 * - O(n + m)
 *   n = people
 *   m = trust pairs
 *
 * Space Complexity:
 * - O(n)
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - This is a graph in-degree/out-degree problem.
 * - No need to build adjacency list.
 * - Very clean counting trick.
 */

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        // Count array
        vector<int> cnt(n + 1, 0);

        // Process trust relationships
        for (auto& e : trust) {

            // Person who trusts someone cannot be judge
            cnt[e[0]]--;

            // Person being trusted gains +1
            cnt[e[1]]++;
        }

        // Find candidate with n - 1 trust count
        for (int i = 1; i <= n; i++) {

            if (cnt[i] == n - 1)
                return i;
        }

        return -1;
    }
};

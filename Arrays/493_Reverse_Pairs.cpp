/*
 * Problem: 493. Reverse Pairs
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given an integer array nums,
 * return the number of reverse pairs.
 *
 * A reverse pair is defined as:
 *
 *   i < j  AND  nums[i] > 2 * nums[j]
 *
 * ------------------------------------------------------------
 * WHY NOT BRUTE FORCE?
 *
 * Brute force:
 *   Check all pairs → O(n²)
 *
 * Constraints are large → TLE.
 *
 * ------------------------------------------------------------
 * OPTIMAL APPROACH: Modified Merge Sort
 *
 * ------------------------------------------------------------
 * CORE IDEA:
 *
 * This is similar to counting inversions.
 *
 * During merge sort:
 *   Left half and right half are already sorted.
 *
 * For each element in left half,
 * we can efficiently count how many elements
 * in right half satisfy:
 *
 *     nums[i] > 2 * nums[j]
 *
 * Using two pointers.
 *
 * ------------------------------------------------------------
 * KEY OBSERVATION:
 *
 * Since both halves are sorted:
 *
 * If nums[i] > 2 * nums[j],
 * then all elements after j in right half
 * will also satisfy the condition.
 *
 * This allows counting in linear time
 * per merge step.
 *
 * ------------------------------------------------------------
 * ALGORITHM STRUCTURE:
 *
 * mergeSort(l, r):
 *     - Divide into two halves
 *     - Count in left
 *     - Count in right
 *     - Count cross pairs during merge
 *
 * ------------------------------------------------------------
 * COUNTING LOGIC (Before Merge):
 *
 * j = m + 1
 *
 * For i = l to m:
 *
 *     while j <= r AND
 *           nums[i] > 2LL * nums[j]:
 *         j++
 *
 *     count += (j - (m + 1))
 *
 * ------------------------------------------------------------
 * IMPORTANT:
 *
 * Use 2LL * nums[j]
 * to prevent integer overflow.
 *
 * ------------------------------------------------------------
 * AFTER COUNTING:
 *
 * Perform normal merge step
 * to keep array sorted.
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * nums = [1,3,2,3,1]
 *
 * Reverse pairs:
 * (3,1), (3,1)
 *
 * Answer = 2
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 * - O(n log n)
 *
 * Space Complexity:
 * - O(n) (temporary arrays)
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - Classic advanced merge sort pattern.
 * - Very important problem.
 * - Same structure used in inversion count.
 */

class Solution {
public:

    int merge(vector<int>& nums, int l, int m, int r) {

        int cnt = 0;

        // Count reverse pairs
        int j = m + 1;

        for (int i = l; i <= m; i++) {

            while (j <= r &&
                   (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }

            cnt += (j - (m + 1));
        }

        // Merge step
        int n1 = m - l + 1;
        int n2 = r - m;

        vector<int> L(n1), R(n2);

        for (int i = 0; i < n1; i++)
            L[i] = nums[l + i];

        for (int i = 0; i < n2; i++)
            R[i] = nums[m + 1 + i];

        int i = 0, k = l;
        j = 0;

        while (i < n1 && j < n2) {

            if (L[i] <= R[j])
                nums[k++] = L[i++];
            else
                nums[k++] = R[j++];
        }

        while (i < n1)
            nums[k++] = L[i++];

        while (j < n2)
            nums[k++] = R[j++];

        return cnt;
    }

    int mergeSort(vector<int>& nums, int l, int r) {

        if (l >= r)
            return 0;

        int cnt = 0;

        int m = l + (r - l) / 2;

        cnt += mergeSort(nums, l, m);
        cnt += mergeSort(nums, m + 1, r);
        cnt += merge(nums, l, m, r);

        return cnt;
    }

    int reversePairs(vector<int>& nums) {

        if (nums.empty())
            return 0;

        return mergeSort(nums, 0, nums.size() - 1);
    }
};

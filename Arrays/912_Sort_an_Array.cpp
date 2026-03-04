/*
 * Problem: 912. Sort an Array
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given an integer array nums,
 * sort the array in ascending order
 * and return it.
 *
 * You must solve it without using built-in sorting functions.
 *
 * ------------------------------------------------------------
 * APPROACH: Merge Sort (Divide and Conquer)
 *
 * ------------------------------------------------------------
 * CORE IDEA:
 *
 * Merge Sort works by repeatedly dividing
 * the array into smaller halves,
 * sorting them independently,
 * and then merging the sorted halves.
 *
 * Steps:
 *
 * 1️⃣ Divide the array into two halves.
 * 2️⃣ Recursively sort both halves.
 * 3️⃣ Merge the two sorted halves.
 *
 * ------------------------------------------------------------
 * WHY MERGE SORT?
 *
 * - Stable sorting algorithm
 * - Guaranteed O(n log n) time complexity
 * - Works well for large datasets
 *
 * ------------------------------------------------------------
 * MERGE PROCESS:
 *
 * During merge step:
 *
 * 1️⃣ Copy left and right halves into
 *    temporary arrays.
 *
 * 2️⃣ Compare elements of both halves.
 *
 * 3️⃣ Insert the smaller element back
 *    into the original array.
 *
 * 4️⃣ Copy remaining elements if any.
 *
 * ------------------------------------------------------------
 * ALGORITHM FLOW:
 *
 * mergeSort(nums, l, r):
 *
 *      if l >= r
 *          return
 *
 *      mid = (l + r) / 2
 *
 *      mergeSort(left half)
 *      mergeSort(right half)
 *
 *      merge both halves
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * nums = [5,2,3,1]
 *
 * Step 1: Divide
 * [5,2] [3,1]
 *
 * Step 2: Divide again
 * [5] [2] [3] [1]
 *
 * Step 3: Merge
 * [2,5] [1,3]
 *
 * Step 4: Merge again
 * [1,2,3,5]
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 *   O(n log n)
 *
 * Space Complexity:
 *   O(n)
 *   (temporary arrays used during merge)
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - Merge Sort is a classic Divide & Conquer algorithm.
 * - Often used when stable sorting is required.
 * - Also forms the base for problems like:
 *     • Inversion Count
 *     • Reverse Pairs
 *     • Count Smaller After Self
 */

class Solution {
private:

    void merge(vector<int> &nums, int l, int m, int r){

        int n1 = m - l + 1;
        int n2 = r - m;

        vector<int> L(n1), R(n2);

        // Copy left half
        for(int i = 0; i < n1; i++)
            L[i] = nums[l + i];

        // Copy right half
        for(int j = 0; j < n2; j++)
            R[j] = nums[m + 1 + j];

        int i = 0, j = 0, k = l;

        // Merge both halves
        while(i < n1 && j < n2){

            if(L[i] <= R[j])
                nums[k++] = L[i++];
            else
                nums[k++] = R[j++];
        }

        // Copy remaining elements
        while(i < n1)
            nums[k++] = L[i++];

        while(j < n2)
            nums[k++] = R[j++];
    }

    void mergeSort(vector<int> &nums, int l, int r){

        if(l >= r) return;

        int m = l + (r - l) / 2;

        mergeSort(nums, l, m);
        mergeSort(nums, m + 1, r);

        merge(nums, l, m, r);
    }

public:

    vector<int> sortArray(vector<int>& nums){

        mergeSort(nums, 0, nums.size() - 1);

        return nums;
    }
};

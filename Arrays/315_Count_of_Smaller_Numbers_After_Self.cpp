/*
 * Problem: 315. Count of Smaller Numbers After Self
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given an integer array nums,
 * return an array answer such that:
 *
 *   answer[i] = number of elements smaller than nums[i]
 *               that appear to its right.
 *
 * Example:
 * nums = [5,2,6,1]
 *
 * Output:
 * [2,1,1,0]
 *
 * Explanation:
 * 5 → smaller elements on right: {2,1} → 2
 * 2 → {1} → 1
 * 6 → {1} → 1
 * 1 → {} → 0
 *
 * ------------------------------------------------------------
 * WHY NOT BRUTE FORCE?
 *
 * Brute force approach:
 *   For each element check all elements to the right.
 *
 * Time Complexity:
 *   O(n²)
 *
 * For large n this becomes too slow.
 *
 * ------------------------------------------------------------
 * OPTIMAL APPROACH: Modified Merge Sort
 *
 * ------------------------------------------------------------
 * CORE IDEA:
 *
 * Similar to inversion counting.
 *
 * During merge sort:
 *
 *   Left half → earlier elements
 *   Right half → elements appearing later in the array
 *
 * If a right element is smaller than a left element,
 * it contributes to the count of that left element.
 *
 * ------------------------------------------------------------
 * IMPORTANT TRICK:
 *
 * Instead of storing only numbers,
 * store:
 *
 *      (value, original_index)
 *
 * This allows us to update the correct
 * position in the answer array.
 *
 * ------------------------------------------------------------
 * COUNTING LOGIC:
 *
 * When merging:
 *
 * If:
 *      arr[i].first > arr[j].first
 *
 * Then all elements from j to r are smaller
 * than arr[i] because the right half is sorted.
 *
 * So:
 *
 *      ans[arr[i].second] += (r - j + 1)
 *
 * ------------------------------------------------------------
 * MERGE PROCESS:
 *
 * 1️⃣ Compare elements of left and right halves.
 *
 * 2️⃣ If left element is larger:
 *       update count
 *
 * 3️⃣ Insert elements into temporary array
 *    to keep merged portion sorted.
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * nums = [5,2,6,1]
 *
 * pairs = (value,index)
 *
 * (5,0) (2,1) (6,2) (1,3)
 *
 * After merge operations:
 *
 * ans = [2,1,1,0]
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 *   O(n log n)
 *
 * Space Complexity:
 *   O(n)
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * This problem is closely related to:
 *
 *   • Inversion Count
 *   • Reverse Pairs
 *
 * All three use the same modified merge sort technique.
 */

class Solution {
private:

    void merge(vector<pair<int,int>> &arr,
               int l, int m, int r,
               vector<int> &ans) {

        vector<pair<int,int>> temp(r - l + 1);

        int i = l;
        int j = m + 1;
        int k = 0;

        while(i <= m && j <= r) {

            if(arr[i].first <= arr[j].first) {

                temp[k++] = arr[j++];
            }
            else {

                ans[arr[i].second] += (r - j + 1);

                temp[k++] = arr[i++];
            }
        }

        while(i <= m)
            temp[k++] = arr[i++];

        while(j <= r)
            temp[k++] = arr[j++];

        for(int x = l; x <= r; x++)
            arr[x] = temp[x - l];
    }

    void mergeSort(vector<pair<int,int>> &arr,
                   int l, int r,
                   vector<int> &ans) {

        if(l >= r) return;

        int mid = l + (r - l) / 2;

        mergeSort(arr, l, mid, ans);
        mergeSort(arr, mid + 1, r, ans);

        merge(arr, l, mid, r, ans);
    }

public:

    vector<int> countSmaller(vector<int>& nums) {

        int n = nums.size();

        vector<int> ans(n, 0);

        vector<pair<int,int>> arr;

        for(int i = 0; i < n; i++) {

            arr.push_back({nums[i], i});
        }

        mergeSort(arr, 0, n - 1, ans);

        return ans;
    }
};

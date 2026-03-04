/*
 * Problem: 315. Count of Smaller Numbers After Self
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given an integer array nums,
 * return an array answer such that:
 *
 * answer[i] = number of smaller elements
 *             to the right of nums[i].
 *
 * Example:
 * nums = [5,2,6,1]
 *
 * Output:
 * [2,1,1,0]
 *
 * Explanation:
 * 5 → {2,1} → 2
 * 2 → {1}   → 1
 * 6 → {1}   → 1
 * 1 → {}    → 0
 *
 * ------------------------------------------------------------
 * WHY NOT BRUTE FORCE?
 *
 * Brute force:
 *   For each element check all elements to the right.
 *
 * Time Complexity:
 *   O(n²)
 *
 * This will TLE for large inputs.
 *
 * ------------------------------------------------------------
 * OPTIMAL APPROACH: Modified Merge Sort
 *
 * ------------------------------------------------------------
 * CORE IDEA:
 *
 * Similar to inversion count.
 *
 * During merge sort:
 *   Left half = earlier elements
 *   Right half = elements appearing later
 *
 * If an element from the right side is placed before
 * a left element during merge,
 * it means that right element is smaller.
 *
 * ------------------------------------------------------------
 * KEY TRICK:
 *
 * Instead of storing only values,
 * store:
 *
 *     (value, original_index)
 *
 * This allows us to update the answer
 * for the correct position in the original array.
 *
 * ------------------------------------------------------------
 * COUNTING LOGIC:
 *
 * While merging:
 *
 * If:
 *     arr[left].first <= arr[right].first
 *
 * Then:
 *     All previously moved right elements
 *     are smaller than arr[left].
 *
 * So:
 *
 *     ans[arr[left].second] += rightCnt
 *
 * ------------------------------------------------------------
 * VARIABLES:
 *
 * rightCnt → number of elements from right side
 *            already placed in merged array.
 *
 * ------------------------------------------------------------
 * ALGORITHM STEPS:
 *
 * 1️⃣ Convert nums → pair array:
 *
 *     (value, original_index)
 *
 * 2️⃣ Perform merge sort.
 *
 * 3️⃣ During merge:
 *     track how many right elements moved first.
 *
 * 4️⃣ Update ans array using original index.
 *
 * ------------------------------------------------------------
 * DRY RUN EXAMPLE:
 *
 * nums = [5,2,6,1]
 *
 * pairs:
 * (5,0), (2,1), (6,2), (1,3)
 *
 * During merge:
 *
 * 1 moves before 5 → count++
 * 2 moves before 5 → count++
 *
 * result:
 * [2,1,1,0]
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
 * - Classic "count smaller to right" problem.
 * - Uses merge sort counting pattern.
 * - Same idea used in:
 *     Reverse Pairs
 *     Inversion Count
 */

class Solution {
private:

    void merge(vector<pair<int,int>> &arr,
               int l, int m, int r,
               vector<int> &ans){

        vector<pair<int,int>> temp;

        int left = l;
        int right = m + 1;

        int rightCnt = 0;

        while(left <= m && right <= r){

            if(arr[left].first <= arr[right].first){

                ans[arr[left].second] += rightCnt;

                temp.push_back(arr[left++]);
            }
            else{

                rightCnt++;

                temp.push_back(arr[right++]);
            }
        }

        while(left <= m){

            ans[arr[left].second] += rightCnt;

            temp.push_back(arr[left++]);
        }

        while(right <= r){

            temp.push_back(arr[right++]);
        }

        for(int i = l; i <= r; i++){

            arr[i] = temp[i - l];
        }
    }

    void mergeSort(vector<pair<int,int>> &arr,
                   int l, int r,
                   vector<int> &ans){

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

        for(int i = 0; i < n; i++){

            arr.push_back({nums[i], i});
        }

        mergeSort(arr, 0, n - 1, ans);

        return ans;
    }
};

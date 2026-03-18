/*
 * Problem: 238. Product of Array Except Self
 *
 * ------------------------------------------------------------
 * STATEMENT:
 * Given an integer array nums, return an array answer such that:
 *
 *      answer[i] = product of all elements in nums
 *                  except nums[i]
 *
 * Constraints:
 *
 * • You must solve it WITHOUT using division.
 * • Time complexity should be O(n).
 *
 * ------------------------------------------------------------
 * EXAMPLE:
 *
 * nums = [1,2,3,4]
 *
 * Output:
 *
 * [24,12,8,6]
 *
 * ------------------------------------------------------------
 * CORE IDEA:
 *
 * For each index i:
 *
 *      answer[i] = (product of all elements to the left)
 *                  ×
 *                  (product of all elements to the right)
 *
 * ------------------------------------------------------------
 * APPROACH:
 *
 * Instead of using extra prefix and suffix arrays,
 * we optimize space by storing results directly.
 *
 * ------------------------------------------------------------
 * STEP 1: PREFIX PRODUCT
 *
 * Build prefix product in answer array:
 *
 *      ans[i] = product of elements before i
 *
 * Example:
 *
 * nums = [1,2,3,4]
 *
 * ans = [1,1,2,6]
 *
 * ------------------------------------------------------------
 * STEP 2: SUFFIX PRODUCT
 *
 * Traverse from right and maintain suffix product:
 *
 *      suf = product of elements after i
 *
 * Multiply:
 *
 *      ans[i] = ans[i] * suf
 *
 * ------------------------------------------------------------
 * DRY RUN:
 *
 * nums = [1,2,3,4]
 *
 * Step 1 (prefix):
 *
 * ans = [1,1,2,6]
 *
 * Step 2 (suffix):
 *
 * suf=1 → ans[3]=6
 * suf=4 → ans[2]=8
 * suf=12 → ans[1]=12
 * suf=24 → ans[0]=24
 *
 * Result = [24,12,8,6]
 *
 * ------------------------------------------------------------
 * TIME & SPACE COMPLEXITY:
 *
 * Time Complexity:
 *      O(n)
 *
 * Space Complexity:
 *      O(1)
 *      (excluding output array)
 *
 * ------------------------------------------------------------
 * INTERVIEW NOTES:
 *
 * - Classic problem testing prefix/suffix logic.
 * - Key constraint: NO division.
 * - Space optimization is often expected.
 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();

        vector<int> ans(n, 1);

        /*-----------------------------------------
          PREFIX PRODUCT
        -----------------------------------------*/
        for(int i = 1; i < n; i++){
            ans[i] = ans[i-1] * nums[i-1];
        }

        /*-----------------------------------------
          SUFFIX PRODUCT
        -----------------------------------------*/
        int suf = 1;

        for(int i = n-1; i >= 0; i--){

            ans[i] = ans[i] * suf;

            suf *= nums[i];
        }

        return ans;
    }
};

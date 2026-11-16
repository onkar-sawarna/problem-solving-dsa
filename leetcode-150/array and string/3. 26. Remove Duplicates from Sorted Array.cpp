// 26. Remove Duplicates from Sorted Array
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// nums is sorted. Keep each value once, in place. Return the new length.

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        for (int j = 1; j < n; j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
// Pattern: Two Pointers - Write index lags the read index
// explanation:
/*
The array is already sorted, so equal values sit next to each other.
j reads every index from 1 onward. i stays on the last kept value.
When nums[j] differs from nums[i], i advances and that new value is written there.
Equal values are skipped, so they fall past the returned length i + 1.
*/

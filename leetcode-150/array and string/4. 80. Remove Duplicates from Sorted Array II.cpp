// 80. Remove Duplicates from Sorted Array II
// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
// nums is sorted. Keep each value at most twice, in place. Return the new length.

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

        int i = 2;
        for (int j = 2; j < n; j++) {
            if (nums[j] != nums[i - 2]) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
// Pattern: Two Pointers - Write index lags the read index
// explanation:
/*
Same as problem 26. i writes, j reads. The array is already sorted.
The first two numbers are always kept, so both pointers start at 2.
Write nums[j] when it is different from the number two places back.
A third copy matches that number, so it is skipped.
i is the new length.
*/

// 88. Merge Sorted Array
// https://leetcode.com/problems/merge-sorted-array/
// Merge sorted nums2 into sorted nums1 in place. nums1 holds m values and n empty slots.

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};

// Time Complexity: O(m + n)
// Space Complexity: O(1)
// Pattern: Two Pointers - From End to Start    
// explanation:
/*
 we start from the end of the arrays and compare the elements from the end.
 we place the larger element at the end of the first array.
 we continue this process until we have placed all the elements of the second array.
 if there are any elements left in the first array, we don't need to do anything because they are already in place.
 if there are any elements left in the second array, we place them at the beginning of the first array.
 this is because the first array is already sorted and the second array is also sorted.
 so we can place the elements at the beginning of the first array.
 this is the most efficient way to merge the two arrays because we are not using any extra space.
 we are using the same space to merge the two arrays.
 this is the most efficient way to merge the two arrays because we are not using any extra space.
*/
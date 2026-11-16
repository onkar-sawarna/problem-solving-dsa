// 27. Remove Element
// https://leetcode.com/problems/remove-element/
// Remove every val from nums in place. Return how many values remain in the front.

class Solution {
public:
    // Write index. Kept values stay in their original order.
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] != val) {
                nums[k++] = nums[i];
            }
        }
        return k;
    }

    // Sentinel plus sort. nums[i] is at most 50, so 105 cannot be a real value.
    int removeElementSentinel(vector<int>& nums, int val) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == val) {
                nums[i] = 105;
                count++;
            }
        }
        sort(nums.begin(), nums.end());
        return n - count;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
// Pattern: Two Pointers - Write index lags the read index
// explanation:
/*
i reads every element once.
When nums[i] is not val, it is written at k and k advances.
Values equal to val are skipped, so they fall outside the first k slots.
k is the count of kept elements. Order of the kept elements stays the same.
*/

// Time Complexity: O(n log n)
// Space Complexity: O(1)
// Pattern: Sentinel - Sort the marked values to the end
// explanation:
/*
Each nums[i] equal to val is overwritten with 105 and counted.
105 is safe because every real nums[i] is at most 50.
sort moves those 105 values behind the kept numbers.
n - count is the length of the kept prefix. The kept order becomes sorted order.
*/

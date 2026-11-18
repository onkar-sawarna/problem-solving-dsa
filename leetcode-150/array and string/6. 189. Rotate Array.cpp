// 189. Rotate Array
// https://leetcode.com/problems/rotate-array/
// Rotate nums to the right by k steps. k may be larger than n.

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
// Pattern: Reverse - Three reversals
// explanation:
/*
k %= n because a full turn of n steps puts every element back.
Reverse the whole array, then the first k, then the rest.
The last k values move to the front and stay in their original order.
One-by-one shifts would be O(nk), and both n and k can be 1e5.
*/

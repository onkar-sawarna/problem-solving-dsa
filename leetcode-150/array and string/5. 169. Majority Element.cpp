// 169. Majority Element
// https://leetcode.com/problems/majority-element/
// Return the value that appears more than n / 2 times. It always exists.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        for (int x : nums) {
            if (count == 0) candidate = x;
            if (x == candidate) count++;
            else count--;
        }
        return candidate;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
// Pattern: Boyer-Moore - Pair off different values
// explanation:
/*
Same value adds 1. A different value subtracts 1.
Count 0 means the old candidate was cancelled, so the current value becomes the candidate.
The majority is more than half the array, so it is the value left at the end.
*/

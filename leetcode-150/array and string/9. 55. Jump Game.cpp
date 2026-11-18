// 55. Jump Game
// https://leetcode.com/problems/jump-game/
// From index 0, nums[i] is the farthest jump you may take. Return whether the last index is reachable.

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int furthest = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (i > furthest) return false;
            furthest = max(furthest, i + nums[i]);
        }
        return true;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
// Pattern: Greedy - Furthest reach
// explanation:
/*
furthest is the largest index that can be reached from the indexes already scanned.
If i is past furthest, this index cannot be reached, so the end cannot either.
Otherwise i + nums[i] may extend furthest.
Trying every sequence of jumps is exponential. n can be 1e4, so one scan is the fit.
*/

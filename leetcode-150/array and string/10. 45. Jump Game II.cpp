// 45. Jump Game II
// https://leetcode.com/problems/jump-game-ii/
// nums[i] is the farthest jump from index i. The last index is reachable. Return the fewest jumps.

class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int furthest = 0;
        int end = 0;
        for (int i = 0; i < (int)nums.size() - 1; i++) {
            furthest = max(furthest, i + nums[i]);
            if (i == end) {
                jumps++;
                end = furthest;
            }
        }
        return jumps;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
// Pattern: Greedy - Furthest reach, counted in jumps
// explanation:
/*
end is the farthest index the current jump can land on.
Inside that range, furthest is the best landing spot for the next jump.
When i reaches end, one jump is spent and the next range opens out to furthest.
55 only asks whether furthest can pass the last index. Here each time the range ends, the jump count increases.
*/

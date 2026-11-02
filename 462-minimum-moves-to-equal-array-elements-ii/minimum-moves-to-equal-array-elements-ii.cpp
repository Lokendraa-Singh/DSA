class Solution {
public:
    int minMoves2(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int i = 0;
        int j = nums.size() - 1;
        int midPoint = (i + j) / 2;

        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            count = count + abs(nums[midPoint] - nums[i]);
        }

        return count;
    }
};
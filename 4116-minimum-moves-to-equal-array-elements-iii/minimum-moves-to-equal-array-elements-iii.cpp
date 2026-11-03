class Solution {
public:
    int minMoves(vector<int>& nums) {

        int largest = *max_element(nums.begin(), nums.end());

        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            count = count + abs(largest - nums[i]);
        }

        return count;
    }
};
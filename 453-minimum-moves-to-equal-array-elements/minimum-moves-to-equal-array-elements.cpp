
class Solution {
public:
    int minMoves(vector<int>& nums) {

        int smallest = *min_element(nums.begin(), nums.end());

        long long count = 0;

        for (int i = 0; i < nums.size(); i++) {

            count += nums[i] - smallest;

        }

        return count;
    }
};

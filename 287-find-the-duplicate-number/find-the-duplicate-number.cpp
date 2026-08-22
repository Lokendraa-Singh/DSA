class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int i = 0;
        int j = i + 1;

        while (i < nums.size() && j < nums.size()) {
            if (nums[i] == nums[j]) {
                return nums[i];
            } else {
                i++;
                j++;
            }
        }

        return 0;
    }
};
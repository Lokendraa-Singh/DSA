class Solution {
public:
    int M = 1e9 + 7;
    int numberOfGoodPartitions(vector<int>& nums) {

        unordered_map<int, int> mpp;

        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]] = i;
        }

        int i = 0;
        int j = mpp[nums[i]];
        int result = 1;

        while (i < nums.size()) {

            if (i > j) {
                result = (result * 2) % M;
            }

            j = max(j, mpp[nums[i]]);
            i++;
        }

        return result;
    }
};
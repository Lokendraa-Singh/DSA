class Solution {
public:
    int sumCounts(vector<int>& nums) {

        int ans=0;   
        for (int i = 0; i < nums.size(); i++) {

            unordered_map<int, int> mpp;
            for (int j = i; j < nums.size(); j++) {
                mpp[nums[j]]++;
                ans = ans + (mpp.size()) * (mpp.size());
            }
        }

        return ans;
    }
};
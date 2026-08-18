class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;

        for (int i = 0; i < nums.size(); i++) {

            for (int j = i; j < nums.size(); j++) {

                if (j - i + 1 == k) {

                    unordered_set<int> st;

                    for (int x = i; x <= j; x++) {
                        st.insert(nums[x]);
                    }

                    for (auto x : st) {
                        mpp[x]++;
                    }
                }
            }
        }

        int ans = -1;

        for (auto x : mpp) {
            if (x.second == 1) {
                ans = max(ans, x.first);
            }
        }

        return ans;
    }
};
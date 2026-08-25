class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int> st;

        for (int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
        }

        int i = 1;
        bool temp = true;
        while (temp) {
            int ans = k * i;
            if (st.find(ans) == st.end()) {
                return ans;
            }

            i++;
        }

        return 0;
    }
};
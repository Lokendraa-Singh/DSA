class Solution {
public:
    vector<int> getPSE(vector<int>& heights, int n) {
        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < heights.size(); i++) {

            while (!st.empty() && heights[st.top()] > heights[i]) {
                st.pop();
            }

            ans[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }

        return ans;
    }

    vector<int> getNSE(vector<int>& heights, int n) {
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            ans[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }

        return ans;
    }
    int maximumScore(vector<int>& nums, int k) {

        int n=nums.size(); 
        vector<int>PSE=getPSE(nums,n);
        vector<int>NSE=getNSE(nums,n);

        int ans=0;
        int maxScore;

        for (int i = 0; i < nums.size(); i++) {

            int left = PSE[i] + 1;
            int right = NSE[i] - 1;

            if (k >= left && k <= right) {
                maxScore = nums[i] * (right - left + 1);
                ans = max(ans, maxScore);
            }
        }

        return ans;
    }
};
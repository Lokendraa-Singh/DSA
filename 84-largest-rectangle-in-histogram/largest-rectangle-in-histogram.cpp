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

        for (int i = n-1; i>=0; i--) {

            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            ans[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }

        return ans;
    } 

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> PSE = getPSE(heights, n);
        vector<int> NSE = getNSE(heights, n);

        int ans = 0;
        int currArea;
        for (int i = 0; i < heights.size(); i++) {
            currArea = heights[i] * (NSE[i] - PSE[i] - 1);
            ans = max(ans, currArea);
        }

        return ans;
    }
};
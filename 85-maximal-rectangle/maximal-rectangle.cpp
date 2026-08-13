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
    int maximalRectangle(vector<vector<char>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();
        int result = 0;

        vector<vector<int>> prefixSum(m, vector<int>(n));

        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int i = 0; i < m; i++) {

                if (matrix[i][j] - '0' == 0) {
                    sum = 0;
                }
                sum = sum + matrix[i][j] - '0';

                prefixSum[i][j] = sum;
            }
        }

        for (int i = 0; i < prefixSum.size(); i++) {
            vector<int> ans;
            for (int j = 0; j < prefixSum[0].size(); j++) {

                ans.push_back(prefixSum[i][j]);
            }

            int maxHeight = largestRectangleArea(ans);
            result = max(result, maxHeight);
        }

        return result;
    }
};
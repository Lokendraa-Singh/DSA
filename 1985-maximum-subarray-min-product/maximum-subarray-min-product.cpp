class Solution {
public:

    vector<int> getPSE(vector<int>& nums, int n) {
        vector<int> ans(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {

            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return ans;
    }

    vector<int> getNSE(vector<int>& nums, int n) {
        vector<int> ans(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {

            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return ans;
    }

    int maxSumMinProduct(vector<int>& nums) {

        int n = nums.size();

        vector<int> PSE = getPSE(nums, n);
        vector<int> NSE = getNSE(nums, n);

        vector<long long> prefixSum(n + 1, 0);

        for(int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        long long ans = 0;

        for(int i = 0; i < n; i++) {

            long long sum = prefixSum[NSE[i]] - prefixSum[PSE[i]+1];

            long long minProd = sum * nums[i];

            ans = max(ans, minProd);
        }

        return ans % 1000000007;
    }
};
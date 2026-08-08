class Solution {
public:
    vector<int> getNSE(vector<int>& arr, int n) {
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            ans[i] = !st.empty() ? st.top() : n;

            st.push(i);
        }

        return ans;
    }

    vector<int> getPSE(vector<int>& arr, int n) {

        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {

            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            ans[i] = !st.empty() ? st.top() : -1;

            st.push(i);
        }

        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();

        vector<int> PSE = getPSE(arr, n);
        vector<int> NSE = getNSE(arr, n);

        long long sum = 0;
        int M = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            long long ls = i - PSE[i]; // left meh kitne smaller element honge;
            long long rs = NSE[i] - i; // right meh kitne smaller ele honge;

            long long totalWays = ls * rs * 1LL;
            long long totalSum = totalWays * arr[i];

            sum = (sum + totalSum) % M;
        }

        return sum;
    }
};
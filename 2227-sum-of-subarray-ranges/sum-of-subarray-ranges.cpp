class Solution {
public:

    // Next Smaller Element
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


    // Previous Smaller Element
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


    // Sum of all subarray minimums
    long long sumOfSubArrMin(vector<int>& arr) {

        int n = arr.size();

        vector<int> PSE = getPSE(arr, n);
        vector<int> NSE = getNSE(arr, n);

        long long sum = 0;

        for (int i = 0; i < n; i++) {

            long long ls = i - PSE[i];
            long long rs = NSE[i] - i;

            long long totalWays = ls * rs;

            sum += totalWays * arr[i];
        }

        return sum;
    }


    // Next Greater Element
    vector<int> getNGE(vector<int>& arr, int n) {

        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }

            ans[i] = !st.empty() ? st.top() : n;

            st.push(i);
        }

        return ans;
    }


    // Previous Greater Element
    vector<int> getPGE(vector<int>& arr, int n) {

        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {

            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }

            ans[i] = !st.empty() ? st.top() : -1;

            st.push(i);
        }

        return ans;
    }


    // Sum of all subarray maximums
    long long sumOfSubArrMax(vector<int>& arr) {

        int n = arr.size();

        vector<int> PGE = getPGE(arr, n);
        vector<int> NGE = getNGE(arr, n);

        long long sum = 0;

        for (int i = 0; i < n; i++) {

            long long ls = i - PGE[i];
            long long rs = NGE[i] - i;

            long long totalWays = ls * rs;

            sum += totalWays * arr[i];
        }

        return sum;
    }


    // Final answer
    long long subArrayRanges(vector<int>& nums) {

        return sumOfSubArrMax(nums) - sumOfSubArrMin(nums);
    }
};
class Solution {
public:

    int maxChunksToSorted(vector<int>& arr) {
        stack<int> st;

        for (int i = 0; i < arr.size(); i++) {

            if (st.empty() || st.top() <= arr[i]) {
                st.push(arr[i]);
            } else {

                int temp=st.top();
                st.pop();
                while (!st.empty() && st.top() > arr[i]) {
                    st.pop();
                }
                st.push(temp);
            }
            
        }
        return st.size();
    }
};
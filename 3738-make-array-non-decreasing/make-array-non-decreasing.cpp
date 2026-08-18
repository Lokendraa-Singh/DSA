class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {

        stack<int> st;

        for (int i = nums.size() - 1; i >= 0; i--) {
            
            while (!st.empty() && st.top() < nums[i]) {
                st.pop();
                
            }

            st.push(nums[i]);
        }

        return st.size();
    }
};
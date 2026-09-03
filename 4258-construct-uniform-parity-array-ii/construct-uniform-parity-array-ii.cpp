class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        int n = nums1.size();
        vector<int> nums2(n);

        stack<int> st;

        // all even check
        bool temp = true;
        for (int i = 0; i < nums1.size(); i++) {

            if (nums1[i] % 2 != 0) {
                temp = false;
                break;
            }
        }
        if (temp) {
            return true;
        }

        // all odd check
        temp = true;
        for (int i = 0; i < nums1.size(); i++) {

            if (nums1[i] % 2 == 0) {
                temp = false;
                break;
            }
        }

        if (temp) {
            return true;
        }

        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] % 2 != 0) {
                st.push(nums1[i]);
            }
        }
        
        // change only even no. to odd no.
        for (int i = 0; i < nums1.size(); i++) {

            if (nums1[i] % 2 == 0) {
                temp = false;
                while (!st.empty() && temp == false) {
                    if (nums1[i] - st.top() >= 1) {
                        nums2[i] = nums1[i] - st.top();
                        temp = true;
                    } else {
                        st.pop();
                    }
                }
            } else {
                nums2[i] = nums1[i];
            }
        }

        //check only odd no.
        temp = true;
        for (int i = 0; i < nums2.size(); i++) {
            if (nums2[i] % 2 == 0) {
                temp = false;
                break;
            }
        }

        return temp;
    }
};
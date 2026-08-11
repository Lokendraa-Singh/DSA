class Solution {
public:
    string removeKdigits(string num, int k) {

        stack<char> st;

        if (num.size() == k) {
            return "0";
        }

        for (int i = 0; i < num.size(); i++) {

            while (!st.empty() && k != 0 &&
                   st.top() - '0' > num[i] - '0') {

                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        string temp = "";

        while (!st.empty()) {
            temp.push_back(st.top());
            st.pop();
        }

        reverse(temp.begin(), temp.end());

        for (int i = 0; i < temp.size(); i++) {

            if (temp[i] != '0') {
                break;
            } 
            else {
                temp[i] = 'a';
            }
        }

        string ans = "";

        for (int i = 0; i < temp.size(); i++) {

            if (temp[i] != 'a') {
                ans.push_back(temp[i]);
            }
        }

        if (ans == "") {
            return "0";
        }

        return ans;
    }
};
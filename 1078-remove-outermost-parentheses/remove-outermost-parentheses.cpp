class Solution {
public:
    string removeOuterParentheses(string s) {

        stack<char> st;
        string temp = "";

        for (char ch : s) {
            if (ch == '(') {
                if (!st.empty()) {
                    temp += ch;
                }

                st.push(ch);
            } else {
                st.pop();
                if (!st.empty()) {
                    temp += ch;
                }
            }
        }

        return temp;
    }
};
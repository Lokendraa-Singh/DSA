class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        string a = "Push";
        string b = "Pop";

        set<int> st;
        stack<int> s;
        for (int i = 0; i < target.size(); i++) {
            st.insert(target[i]);
        }
        for (int i = 1; i <= n; i++) {

            if (i <= target[target.size() - 1]) {
                ans.push_back(a);
                s.push(i);
            }else{
                break;
            }
            if (st.find(i) == st.end()) {
                ans.push_back(b);
                s.pop();
            }
        }

        return ans;
    }
};
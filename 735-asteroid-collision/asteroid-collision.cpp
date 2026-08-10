class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> st;

        for (int i = 0; i < asteroids.size(); i++) {

            if (asteroids[i] > 0) {
                st.push(asteroids[i]);
                continue;
            }

            while (!st.empty() && st.top() > 0 && st.top() < -(asteroids[i])) {
                st.pop();
            }

            if (!st.empty() && st.top() == -(asteroids[i])) {
                st.pop();
            } else if (!st.empty() && st.top() > -(asteroids[i])) {
                continue;
            } else {
                st.push(asteroids[i]);
            }
        }

        vector<int> ans;
        if (st.empty()) {
            return ans;
        }

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
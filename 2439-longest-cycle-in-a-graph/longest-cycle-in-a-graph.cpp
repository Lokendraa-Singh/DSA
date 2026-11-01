class Solution {
public:
    int isCyclic(unordered_map<int, int>& mpp, vector<bool>& visited,
                 set<int>& st, unordered_map<int, int>& storePosition, int i) {

        if (st.find(i) != st.end()) {
            return st.size() - storePosition[i];
        }

        if (i == -1) {
            return -1;
        }

        if (visited[i]) {
            return -1;
        }

        storePosition[i] = st.size();
        st.insert(i);
        visited[i] = true;

        return isCyclic(mpp, visited, st, storePosition, mpp[i]);
    }

    int longestCycle(vector<int>& edges) {

        unordered_map<int, int> mpp;

        for (int u = 0; u < edges.size(); u++) {
            mpp[u] = edges[u];
        }

        vector<bool> visited(edges.size(), false);
        int ans = -1;

        for (int i = 0; i < edges.size(); i++) {

            if (!visited[i]) {

                set<int> st;
                unordered_map<int, int> storePosition;
                ans = max(ans, isCyclic(mpp, visited, st, storePosition, i));
            }
        }

        return ans;
    }
};
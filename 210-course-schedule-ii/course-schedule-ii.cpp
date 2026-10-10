class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        unordered_map<int, vector<int>> adj;

        for (auto vec : prerequisites) {
            int u = vec[0];
            int v = vec[1];

            adj[v].push_back(u);
        }

        vector<int> indegree(numCourses, 0);
        for (int u = 0; u < numCourses; u++) {

            for (int v : adj[u]) {
                indegree[v]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> result;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            result.push_back(u);

            for (int& v : adj[u]) {
                indegree[v]--;

                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        if (result.size() == numCourses) {
            return result;
        }

        return {};
    }
};
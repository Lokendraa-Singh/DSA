class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        unordered_map<int, vector<int>> adj;

        for (auto& prerequisite : prerequisites) {

            int u = prerequisite[0];
            int v = prerequisite[1];

            adj[v].push_back(u);
        }

        vector<int> indegree(numCourses, 0);
        queue<int> q;

        for (int u = 0; u < numCourses; u++) {

            for (int& v : adj[u]) {
                indegree[v]++;
            }
        }

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> result;
        while (!q.empty()) {
            int u = q.front();
            result.push_back(u);
            q.pop();

            for (int v : adj[u]) {
                indegree[v]--;

                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return numCourses == result.size();
    }
};
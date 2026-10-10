class Solution {
public:
    // USE DFS for check cycle in directed graph

    bool isCyclePresent(unordered_map<int, vector<int>> &adj, int u, vector<bool>& visited,
             vector<bool>& inRecursion) {

        visited[u] = true;
        inRecursion[u] = true;

        for (int &v : adj[u]) {

            if (!visited[v] && isCyclePresent(adj, v, visited, inRecursion)) {
                return true;  // cycle toh hh
            } else if (inRecursion[v] == true) {
                return true;
            }
        }

        inRecursion[u]=false;

        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        unordered_map<int, vector<int>> adj;
        for (auto& prerequisite : prerequisites) {

            int u = prerequisite[0];
            int v = prerequisite[1];

            adj[v].push_back(u);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> inRecursion(numCourses, false);

        for (int i = 0; i < numCourses; i++) {

            if (!visited[i] && isCyclePresent(adj, i, visited, inRecursion)) {
                return false; // course complete nhi kr skte
            }
        }

        return true;
    }
};
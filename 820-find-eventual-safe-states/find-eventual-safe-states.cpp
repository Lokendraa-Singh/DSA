class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<bool>& visited,
             vector<bool>& inRecursion, int u) {
        visited[u] = true;
        inRecursion[u] = true;

        for (int& v : graph[u]) {
            if (!visited[v] && dfs(graph, visited, inRecursion, v)) {
                return true;
            } else if (inRecursion[v] == true) {
                return true;
            }
        }

        inRecursion[u] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        vector<bool> visited(graph.size(), false);
        vector<bool> inRecursion(graph.size(), false);
        vector<int> safe;

        for (int i = 0; i < graph.size(); i++) {

            if (!dfs(graph, visited, inRecursion, i)) {
                safe.push_back(i);
            }
        }

        return safe;
    }
};
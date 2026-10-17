class Solution {
public:
    void DFS(vector<vector<int>>& adj, vector<bool>& visited, int u,
             vector<int>& result, vector<vector<int>>& ans) {

        visited[u] = true;
        result.push_back(u);

        if (u == adj.size() - 1) {
            ans.push_back(result);
        } else {
            for (int& v : adj[u]) {
                if (!visited[v]) {
                    DFS(adj, visited, v, result, ans);
                }
            }
        }
        result.pop_back();
        visited[u]=false;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        vector<vector<int>> adj(graph.size());
        vector<bool> visited(graph.size(), false);
        vector<int> result;
        vector<vector<int>> ans;

        for (int u = 0; u < graph.size(); u++) {
            for (int& v : graph[u]) {
                adj[u].push_back(v);
            }
        }

        DFS(adj,visited,0,result,ans);

        return ans;
    }
};
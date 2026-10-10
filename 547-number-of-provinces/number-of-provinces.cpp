class Solution {
public:
    void BFS(unordered_map<int, vector<int>>& adj, int u,
             vector<bool>& visited) {

        queue<int> q;
        visited[u] = true;
        q.push(u);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int& v : adj[u]) {

                if (!visited[v]) {
                    BFS(adj,v,visited);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();
        unordered_map<int, vector<int>> adj;

        // make graph
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {

                if (isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> visited(n, false);
        int count = 0; // provinces ko count krne ke liye
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                BFS(adj, i, visited);
                count++;
            }
        }

        return count;
    }
};
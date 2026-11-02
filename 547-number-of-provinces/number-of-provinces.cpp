class Solution {
public:
    void BFS(unordered_map<int, vector<int>>& mpp, vector<bool>& visited,
             int i) {
        visited[i] = true;
        queue<int> q;
        q.push(i);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int &v : mpp[u]) {
                if (!visited[v]) {
                    visited[v]=true;
                    q.push(v);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        unordered_map<int, vector<int>> mpp;

        for (int i = 0; i < isConnected.size(); i++) {
            for (int j = 0; j < isConnected.size(); j++) {

                if (isConnected[i][j] == 1) {
                    mpp[i].push_back(j);
                    mpp[j].push_back(i);
                }
            }
        }

        vector<bool> visited(isConnected.size(), false);
        int components = 0;

        for (int i = 0; i < isConnected.size(); i++) {
            if (!visited[i]) {
                BFS(mpp, visited, i);
                components++;
            }
        }

        return components;
    }
};
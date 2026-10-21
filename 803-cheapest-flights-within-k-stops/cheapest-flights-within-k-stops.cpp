class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        unordered_map<int, vector<pair<int, int>>> adj;

        for (auto& vec : flights) {
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];

            adj[u].push_back({v, w});
        }

        vector<int> result(n, INT_MAX);
        queue<pair<int, int>> q;

        q.push({src, 0});
        result[src] = 0;

        int stops = 0;

        while (!q.empty() && stops <= k) {
            int size = q.size();

            while (size--) {
                auto [node, cost] = q.front();
                q.pop();

                for (auto& it : adj[node]) {
                    int adjNode = it.first;
                    int wt = it.second;

                    if (cost + wt < result[adjNode]) {
                        result[adjNode] = cost + wt;
                        q.push({adjNode, cost + wt});
                    }
                }
            }

            stops++;
        }

        if (result[dst] == INT_MAX) {
            return -1;
        }

        return result[dst];
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        unordered_map<int, vector<pair<int, int>>> adj;

        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {

                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int dist = abs(x1 - x2) + abs(y1 - y2);
                adj[i].push_back({dist, j});
                adj[j].push_back({dist, i});
            }
        }

        vector<bool> visited(points.size(), false);
        int sum = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (visited[node] == true) {
                continue;
            }

            visited[node] = true;
            sum = sum + wt;

            for (auto& it : adj[node]) {
                int adjNode = it.second;
                int adjWt = it.first;

                if (visited[adjNode] == false) {
                    pq.push({adjWt, adjNode});
                }
            }
        }

        return sum;
    }
};
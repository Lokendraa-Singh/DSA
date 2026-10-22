
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        unordered_map<long long, vector<pair<long long, long long>>> adj;

        long long M = 1e9 + 7;

        for (auto& vec : roads) {
            long long u = vec[0];
            long long v = vec[1];
            long long w = vec[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        priority_queue<pair<long long, long long>,
                       vector<pair<long long, long long>>,
                       greater<pair<long long, long long>>>
            pq;

        vector<long long> result(n, LLONG_MAX);
        vector<long long> ways(n, 0);

        ways[0] = 1;
        result[0] = 0;

        pq.push({0, 0});

        while (!pq.empty()) {

            long long dist = pq.top().first;
            long long node = pq.top().second;
            pq.pop();
            
            for (auto& it : adj[node]) {

                long long adjNode = it.first;
                long long wt = it.second;

                if (dist + wt < result[adjNode]) {

                    result[adjNode] = dist + wt;
                    pq.push({dist + wt, adjNode});

                    ways[adjNode] = ways[node] % M;

                } else if (dist + wt == result[adjNode]) {

                    ways[adjNode] = (ways[adjNode] + ways[node]) % M;
                }
            }
        }

        return ways[n - 1] % M;
    }
};

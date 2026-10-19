
class Solution {
public:
    typedef pair<int, pair<int, int>> P;

    int minimumEffortPath(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));

        result[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            int dist = pq.top().first;
            pair<int, int> p = pq.top().second;
            pq.pop();

            int x = p.first;
            int y = p.second;

            if (x == m - 1 && y == n - 1) {
                return dist;
            }

            // top
            if (x > 0) {
                int d = abs(heights[x - 1][y] - heights[x][y]);
                int newDist = max(dist, d);

                if (newDist < result[x - 1][y]) {
                    result[x - 1][y] = newDist;
                    pq.push({newDist, {x - 1, y}});
                }
            }

            // down
            if (x < m - 1) {
                int d = abs(heights[x + 1][y] - heights[x][y]);
                int newDist = max(dist, d);

                if (newDist < result[x + 1][y]) {
                    result[x + 1][y] = newDist;
                    pq.push({newDist, {x + 1, y}});
                }
            }

            // left
            if (y > 0) {
                int d = abs(heights[x][y - 1] - heights[x][y]);
                int newDist = max(dist, d);

                if (newDist < result[x][y - 1]) {
                    result[x][y - 1] = newDist;
                    pq.push({newDist, {x, y - 1}});
                }
            }

            // right
            if (y < n - 1) {
                int d = abs(heights[x][y + 1] - heights[x][y]);
                int newDist = max(dist, d);

                if (newDist < result[x][y + 1]) {
                    result[x][y + 1] = newDist;
                    pq.push({newDist, {x, y + 1}});
                }
            }
        }

        return 0;
    }
};

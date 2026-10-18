
class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    int dist = 1;

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty())
            return -1;

        int m = grid.size();
        int n = grid[0].size();

        if (grid[0][0] != 0 || grid[m - 1][n - 1] != 0)
            return -1;

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));

        pq.push({0, {0, 0}});
        result[0][0] = 1;

        while (!pq.empty()) {
            int d = pq.top().first;
            pair<int, int> cell = pq.top().second;

            int x = cell.first;
            int y = cell.second;

            if (x == m - 1 && y == n - 1) {
                return d + 1;   // d==result[m-1][n-1]
            }

            pq.pop();

            // top
            if (x > 0 && grid[x - 1][y] == 0) {
                grid[x - 1][y] = 1;
                result[x - 1][y] = d + dist;
                pq.push({d + dist, {x - 1, y}});
            }

            // down
            if (x < m - 1 && grid[x + 1][y] == 0) {
                grid[x + 1][y] = 1;
                result[x + 1][y] = d + dist;
                pq.push({d + dist, {x + 1, y}});
            }

            // left
            if (y > 0 && grid[x][y - 1] == 0) {
                grid[x][y - 1] = 1;
                result[x][y - 1] = d + dist;
                pq.push({d + dist, {x, y - 1}});
            }

            // right
            if (y < n - 1 && grid[x][y + 1] == 0) {
                grid[x][y + 1] = 1;
                result[x][y + 1] = d + dist;
                pq.push({d + dist, {x, y + 1}});
            }

            // top-left
            if (x > 0 && y > 0 && grid[x - 1][y - 1] == 0) {
                grid[x - 1][y - 1] = 1;
                result[x - 1][y - 1] = d + dist;
                pq.push({d + dist, {x - 1, y - 1}});
            }

            // top-right
            if (x > 0 && y < n - 1 && grid[x - 1][y + 1] == 0) {
                grid[x - 1][y + 1] = 1;
                result[x - 1][y + 1] = d + dist;
                pq.push({d + dist, {x - 1, y + 1}});
            }

            // down-left
            if (x < m - 1 && y > 0 && grid[x + 1][y - 1] == 0) {
                grid[x + 1][y - 1] = 1;
                result[x + 1][y - 1] = d + dist;
                pq.push({d + dist, {x + 1, y - 1}});
            }

            // down-right
            if (x < m - 1 && y < n - 1 && grid[x + 1][y + 1] == 0) {
                grid[x + 1][y + 1] = 1;
                result[x + 1][y + 1] = d + dist;
                pq.push({d + dist, {x + 1, y + 1}});
            }
        }

        return -1;
    }
};

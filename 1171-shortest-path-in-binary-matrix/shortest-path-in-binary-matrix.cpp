
class Solution {
public:
    int steps = 1;

    int BFS(vector<vector<int>>& grid, queue<pair<int, int>>& q, int i,
            int j) {
        q.push({i, j});
        grid[i][j] = 1;

        int m = grid.size();
        int n = grid[0].size();

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                pair<int, int> P = q.front();
                q.pop();

                int x = P.first;
                int y = P.second;

                if (x == m - 1 && y == n - 1)
                    return steps;

                // top
                if (x > 0 && grid[x - 1][y] == 0) {
                    grid[x - 1][y] = 1;
                    q.push({x - 1, y});
                }

                // down
                if (x < m - 1 && grid[x + 1][y] == 0) {
                    grid[x + 1][y] = 1;
                    q.push({x + 1, y});
                }

                // left
                if (y > 0 && grid[x][y - 1] == 0) {
                    grid[x][y - 1] = 1;
                    q.push({x, y - 1});
                }

                // right
                if (y < n - 1 && grid[x][y + 1] == 0) {
                    grid[x][y + 1] = 1;
                    q.push({x, y + 1});
                }

                // top-left
                if (x > 0 && y > 0 && grid[x - 1][y - 1] == 0) {
                    grid[x - 1][y - 1] = 1;
                    q.push({x - 1, y - 1});
                }

                // top-right
                if (x > 0 && y < n - 1 && grid[x - 1][y + 1] == 0) {
                    grid[x - 1][y + 1] = 1;
                    q.push({x - 1, y + 1});
                }

                // down-left
                if (x < m - 1 && y > 0 && grid[x + 1][y - 1] == 0) {
                    grid[x + 1][y - 1] = 1;
                    q.push({x + 1, y - 1});
                }

                // down-right
                if (x < m - 1 && y < n - 1 && grid[x + 1][y + 1] == 0) {
                    grid[x + 1][y + 1] = 1;
                    q.push({x + 1, y + 1});
                }
            }

            //level khtm increse kro
            steps++;
        }

        return -1;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty())
            return -1;

        int m = grid.size();
        int n = grid[0].size();

        if (grid[0][0] != 0 || grid[m - 1][n - 1] != 0)
            return -1;

        queue<pair<int, int>> q;
        return BFS(grid, q, 0, 0);
    }
};

class Solution {
public:
    int count = 0;

    void BFS(vector<vector<int>>& grid, vector<vector<int>>& visited, int i,
             int j) {

        int m = grid.size();
        int n = grid[0].size();
        visited[i][j] = 1;
        queue<pair<int, int>> q;
        q.push({i, j});

        while (!q.empty()) {
            pair<int, int> P = q.front();
            q.pop();
            int i = P.first;
            int j = P.second;

            // top

            if (i > 0 && grid[i - 1][j] == 0 && visited[i - 1][j] == 0) {
                visited[i - 1][j] = 1;
                q.push({i - 1, j});
            }

            // down

            if (i < m - 1 && grid[i + 1][j] == 0 && visited[i + 1][j] == 0) {
                visited[i + 1][j] = 1;
                q.push({i + 1, j});
            }

            // left

            if (j > 0 && grid[i][j - 1] == 0 && visited[i][j - 1] == 0) {
                visited[i][j - 1] = 1;
                q.push({i, j - 1});
            }

            // right

            if (j < n - 1 && grid[i][j + 1] == 0 && visited[i][j + 1] == 0) {
                visited[i][j + 1] = 1;
                q.push({i, j + 1});
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));
         
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 0 && !visited[i][0])
                BFS(grid, visited, i, 0);

            if (grid[i][n - 1] == 0 && !visited[i][n - 1])
                BFS(grid, visited, i, n - 1);
        }

        for (int i = 0; i < n; i++) {
            if (grid[0][i] == 0 && !visited[0][i]) {
                BFS(grid, visited, 0, i);
            }

            if (grid[m - 1][i] == 0 && !visited[m - 1][i]) {
                BFS(grid, visited, m - 1, i);
            }
        }

        for (int i = 0; i <m ; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 0 && visited[i][j] == 0) {
                    BFS(grid, visited, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};
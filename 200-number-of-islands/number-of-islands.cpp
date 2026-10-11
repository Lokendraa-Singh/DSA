class Solution {
public:
    void BFS(vector<vector<char>>& grid,
             vector<vector<int>>& visited, int i, int j) {

        visited[i][j] = 1;
        queue<pair<int, int>> q;
        q.push({i, j});

        int n = grid.size();
        int m = grid[0].size();

        while (!q.empty()) {

            pair<int, int> P = q.front();
            q.pop();

            int i = P.first;
            int j = P.second;

            // top
            if (i > 0 && grid[i-1][j] == '1' && !visited[i-1][j]) {
                visited[i-1][j] = 1;
                q.push({i-1, j});
            }

            // down
            if (i < n-1 && grid[i+1][j] == '1' && !visited[i+1][j]) {
                visited[i+1][j] = 1;
                q.push({i+1, j});
            }

            // left
            if (j > 0 && grid[i][j-1] == '1' && !visited[i][j-1]) {
                visited[i][j-1] = 1;
                q.push({i, j-1});
            }

            // right
            if (j < m-1 && grid[i][j+1] == '1' && !visited[i][j+1]) {
                visited[i][j+1] = 1;
                q.push({i, j+1});
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        if (n == 0) return 0;

        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == '1' && !visited[i][j]) {
                    BFS(grid, visited, i, j);
                    count++;
                }
            }
        }

        return count;
    }
};
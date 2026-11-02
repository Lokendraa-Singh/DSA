class Solution {
public:
    int count = 0;

    void BFS(vector<vector<int>>& grid,
             vector<vector<bool>>& visited, int i, int j) {

        visited[i][j] = true;
        queue<pair<int, int>> q;
        q.push({i, j});

        int m = grid.size();
        int n = grid[0].size();

        int temp = 1;
        bool flag = false;

        while (!q.empty()) {
            pair<int, int> P = q.front();
            q.pop();

            int i = P.first;
            int j = P.second;

            if (i > 0) {
                if (grid[i-1][j] == -1) {
                    flag = true;
                }
                else if (grid[i-1][j] == 1 && !visited[i-1][j]) {
                    visited[i-1][j] = true;
                    temp++;
                    q.push({i-1, j});
                }
            }

            if (i < m-1) {
                if (grid[i+1][j] == -1) {
                    flag = true;
                }
                else if (grid[i+1][j] == 1 && !visited[i+1][j]) {
                    visited[i+1][j] = true;
                    temp++;
                    q.push({i+1, j});
                }
            }

            if (j > 0) {
                if (grid[i][j-1] == -1) {
                    flag = true;
                }
                else if (grid[i][j-1] == 1 && !visited[i][j-1]) {
                    visited[i][j-1] = true;
                    temp++;
                    q.push({i, j-1});
                }
            }

            if (j < n-1) {
                if (grid[i][j+1] == -1) {
                    flag = true;
                }
                else if (grid[i][j+1] == 1 && !visited[i][j+1]) {
                    visited[i][j+1] = true;
                    temp++;
                    q.push({i, j+1});
                }
            }
        }

        if (!flag) {
            count += temp;
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        
        for (int i = 0; i < n; i++) {
            if (grid[0][i] == 1) grid[0][i] = -1;
            if (grid[m-1][i] == 1) grid[m-1][i] = -1;
        }

        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1) grid[i][0] = -1;
            if (grid[i][n-1] == 1) grid[i][n-1] = -1;
        }

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    BFS(grid, visited, i, j);
                }
            }
        }

        return count;
    }
};
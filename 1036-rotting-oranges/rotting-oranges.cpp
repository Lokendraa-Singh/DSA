class Solution {
public:
    int count = 0;

    void BFS(vector<vector<int>>& grid,
             vector<vector<bool>>& visited,
             queue<pair<int, int>>& q) {

        int m = grid.size();
        int n = grid[0].size();

        while (!q.empty()) {

            int size = q.size();
            bool check = false;

            for (int k = 0; k < size; k++) {

                pair<int, int> P = q.front();
                q.pop();

                int i = P.first;
                int j = P.second;

                // top
                if (i > 0 && grid[i - 1][j] == 1 &&
                    !visited[i - 1][j]) {

                    grid[i - 1][j] = 2;
                    visited[i - 1][j] = true;
                    q.push({i - 1, j});
                    check = true;
                }

                // down
                if (i < m - 1 && grid[i + 1][j] == 1 &&
                    !visited[i + 1][j]) {

                    grid[i + 1][j] = 2;
                    visited[i + 1][j] = true;
                    q.push({i + 1, j});
                    check = true;
                }

                // left
                if (j > 0 && grid[i][j - 1] == 1 &&
                    !visited[i][j - 1]) {

                    grid[i][j - 1] = 2;
                    visited[i][j - 1] = true;
                    q.push({i, j - 1});
                    check = true;
                }

                // right
                if (j < n - 1 && grid[i][j + 1] == 1 &&
                    !visited[i][j + 1]) {

                    grid[i][j + 1] = 2;
                    visited[i][j + 1] = true;
                    q.push({i, j + 1});
                    check = true;
                }
            }

            if (check == true) {
                count++;
            }
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {

        count = 0;

        int m = grid.size();
        if (m == 0) return 0;

        int n = grid[0].size();
        if (n == 0) return 0;

        vector<vector<bool>> visited(
            m, vector<bool>(n, false)
        );

        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 2) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        // BFS ek hi baar chalega
        BFS(grid, visited, q);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return count;
    }
};
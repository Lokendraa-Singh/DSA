class Solution {
public:
    int BFS(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i,
            int j) {
        visited[i][j] = true;
        queue<pair<int, int>> q;
        q.push({i, j});

        int m = grid.size();
        int n = grid[0].size();
        int sum = 0;

        while (!q.empty()) {
            pair<int, int> P = q.front();
            q.pop();

            int i = P.first;
            int j = P.second;

            sum = sum + grid[i][j];

            if (i > 0 && grid[i - 1][j] != 0 && !visited[i - 1][j]) {
                visited[i - 1][j] = true;
                q.push({i - 1, j});
            }

            if (i < m - 1 && grid[i + 1][j] != 0 && !visited[i + 1][j]) {
                visited[i + 1][j] = true;
                q.push({i + 1, j});
            }

            if (j > 0 && grid[i][j - 1] != 0 && !visited[i][j - 1]) {
                visited[i][j - 1] = true;
                q.push({i, j - 1});
            }

            if (j < n - 1 && grid[i][j + 1] != 0 && !visited[i][j + 1]) {
                visited[i][j + 1] = true;
                q.push({i, j + 1});
            }
        }

        return sum;
    }
    int findMaxFish(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0 && !visited[i][j]) {
                    ans = max(ans, BFS(grid, visited, i, j));
                }
            }
        }

        return ans;
    }
};
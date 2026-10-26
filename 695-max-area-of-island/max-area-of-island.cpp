class Solution {
public:
    int BFS(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i,
            int j) {

        visited[i][j] = true;
        queue<pair<int, int>> q;
        q.push({i, j});
        int count = 0;

        int m = grid.size();
        int n = grid[0].size();

        while (!q.empty()) {
            pair<int, int> P = q.front();
            q.pop();

            int i = P.first;
            int j = P.second;

            count++;

            if (i > 0 && grid[i - 1][j] == 1 && !visited[i - 1][j]) {
                visited[i - 1][j] = true;
                q.push({i - 1, j});
            }

            if (i < m - 1 && grid[i + 1][j] == 1 && !visited[i + 1][j]) {
                visited[i + 1][j] = true;
                q.push({i + 1, j});
            }

            if (j > 0 && grid[i][j - 1] == 1 && !visited[i][j - 1]) {
                visited[i][j - 1] = true;
                q.push({i, j - 1});
            }

            if (j < n - 1 && grid[i][j + 1] == 1 && !visited[i][j + 1]) {
                visited[i][j + 1] = true;
                q.push({i, j + 1});
            }
        }

        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        vector<int> temp;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    temp.push_back(BFS(grid, visited, i, j));
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < temp.size(); i++) {
            if (temp[i] > ans) {
                ans = temp[i];
            }
        }

        return ans;
    }
};
class Solution {
public:
    vector<string> createGrid(int m, int n) {

        vector<vector<char>> grid(m, vector<char>(n, '#'));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;

        grid[0][0] = '.';
        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            pair<int, int> P = q.front();
            q.pop();

            int i = P.first;
            int j = P.second;

            if (j < n - 1 && !visited[i][j + 1]) {
                grid[i][j + 1] = '.';
                visited[i][j + 1] = true;
                q.push({i, j + 1});
            }

            if (i < m - 1 && j == n - 1 && !visited[i + 1][j]) {
                grid[i + 1][j] = '.';
                visited[i + 1][j] = true;
                q.push({i + 1, j});
            }
        }

        vector<string> ans;

        for (int i = 0; i < m; i++) {
            string temp = "";
            for (int j = 0; j < n; j++) {
                temp.push_back(grid[i][j]);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
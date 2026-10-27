
class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));

        deque<pair<int, int>> dq;

        result[0][0] = grid[0][0];
        dq.push_front({0, 0});

        while (!dq.empty()) {

            pair<int, int> P = dq.front();
            dq.pop_front();

            int i = P.first;
            int j = P.second;

            if (i > 0) {
                if (result[i][j] + grid[i - 1][j] < result[i - 1][j]) {

                    result[i - 1][j] = result[i][j] + grid[i - 1][j];

                    if (grid[i - 1][j] == 0)
                        dq.push_front({i - 1, j});
                    else
                        dq.push_back({i - 1, j});
                }
            }

            if (i < m - 1) {
                if (result[i][j] + grid[i + 1][j] < result[i + 1][j]) {

                    result[i + 1][j] = result[i][j] + grid[i + 1][j];

                    if (grid[i + 1][j] == 0)
                        dq.push_front({i + 1, j});
                    else
                        dq.push_back({i + 1, j});
                }
            }

            if (j > 0) {
                if (result[i][j] + grid[i][j - 1] < result[i][j - 1]) {

                    result[i][j - 1] = result[i][j] + grid[i][j - 1];

                    if (grid[i][j - 1] == 0)
                        dq.push_front({i, j - 1});
                    else
                        dq.push_back({i, j - 1});
                }
            }

            if (j < n - 1) {
                if (result[i][j] + grid[i][j + 1] < result[i][j + 1]) {

                    result[i][j + 1] = result[i][j] + grid[i][j + 1];

                    if (grid[i][j + 1] == 0)
                        dq.push_front({i, j + 1});
                    else
                        dq.push_back({i, j + 1});
                }
            }
        }

        return result[m - 1][n - 1] < health;
    }
};


class Solution {
public:
    void solve(vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O') {
                board[0][i] = 'Z';
            }

            if (board[m - 1][i] == 'O') {
                board[m - 1][i] = 'Z';
            }
        }

        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                board[i][0] = 'Z';
            }

            if (board[i][n - 1] == 'O') {
                board[i][n - 1] = 'Z';
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'Z') {
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        while (!q.empty()) {
            pair<int, int> P = q.front();
            q.pop();

            int i = P.first;
            int j = P.second;

            if (i > 0) {
                if (!visited[i - 1][j] && board[i - 1][j] == 'O') {
                    board[i - 1][j] = 'Z';
                    visited[i - 1][j] = true;
                    q.push({i - 1, j});
                }
            }

            if (i < m - 1) {
                if (!visited[i + 1][j] && board[i + 1][j] == 'O') {
                    board[i + 1][j] = 'Z';
                    visited[i + 1][j] = true;
                    q.push({i + 1, j});
                }
            }

            if (j > 0) {
                if (!visited[i][j - 1] && board[i][j - 1] == 'O') {
                    board[i][j - 1] = 'Z';
                    visited[i][j - 1] = true;
                    q.push({i, j - 1});
                }
            }

            if (j < n - 1) {
                if (!visited[i][j + 1] && board[i][j + 1] == 'O') {
                    board[i][j + 1] = 'Z';
                    visited[i][j + 1] = true;
                    q.push({i, j + 1});
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'Z') {
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

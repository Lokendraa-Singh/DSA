
class Solution {
public:
    void BFS(vector<vector<int>>& mat, vector<vector<int>>& dist,
             queue<pair<int, int>>& q) {

        int m = mat.size();
        int n = mat[0].size();

        while (!q.empty()) {
            pair<int, int> P = q.front();
            q.pop();

            int i = P.first;
            int j = P.second;

            // top
            if (i > 0 && dist[i - 1][j] == -1) {
                dist[i - 1][j] = dist[i][j] + 1;
                q.push({i - 1, j});
            }

            // down
            if (i < m - 1 && dist[i + 1][j] == -1) {
                dist[i + 1][j] = dist[i][j] + 1;
                q.push({i + 1, j});
            }

            // left
            if (j > 0 && dist[i][j - 1] == -1) {
                dist[i][j - 1] = dist[i][j] + 1;
                q.push({i, j - 1});
            }

            // right
            if (j < n - 1 && dist[i][j + 1] == -1) {
                dist[i][j + 1] = dist[i][j] + 1;
                q.push({i, j + 1});
            }
        }
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        queue<pair<int, int>> q;
        vector<vector<int>> dist(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        BFS(mat, dist, q);

        return dist;
    }
};

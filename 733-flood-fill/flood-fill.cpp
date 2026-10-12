class Solution {
public:
    void DFS(vector<vector<int>>& image, vector<vector<int>>& copy,
             vector<vector<bool>>& visited, int i, int j, int color) {

        copy[i][j] = color;
        visited[i][j] = true;

        int m = image.size();
        int n = image[0].size();

        // top

        if (i > 0 && image[i - 1][j] == image[i][j] && !visited[i - 1][j]) {
            DFS(image, copy, visited, i - 1, j, copy[i][j]);
        }

        // bottom

        if (i < m - 1 && image[i + 1][j] == image[i][j] && !visited[i + 1][j]) {
            DFS(image, copy, visited, i + 1, j, copy[i][j]);
        }

        // left

        if (j > 0 && image[i][j - 1] == image[i][j] && !visited[i][j - 1]) {
            DFS(image, copy, visited, i, j - 1, copy[i][j]);
        }

        // right

        if (j < n - 1 && image[i][j + 1] == image[i][j] && !visited[i][j + 1]) {
            DFS(image, copy, visited, i, j + 1, copy[i][j]);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {

        int m = image.size();
        int n = image[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        vector<vector<int>> copy = image;

        for (int i = 0; i < copy.size(); i++) {
            for (int j = 0; j < copy[0].size(); j++) {

                if (i == sr && j == sc) {
                    if (copy[i][j] != color && visited[i][j] == false) {
                        DFS(image, copy, visited, i, j, color);
                    }
                }
            }
        }

        return copy;
    }
};
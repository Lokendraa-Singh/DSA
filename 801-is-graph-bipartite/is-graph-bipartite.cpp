class Solution {
public:
    bool BFS(vector<vector<int>>& graph, int currNode, vector<int>& color,
             int currColor) {

        queue<pair<int, int>> q;
        q.push({currNode, currColor});

        color[currNode] = currColor;

        while (!q.empty()) {
            pair<int, int> P = q.front();
            q.pop();

            int u = P.first;
            int uColor = P.second;

            for (int& v : graph[u]) {

                if (color[v] == color[u]) {
                    return false;
                }

                if (color[v] == -1) {
                    if (color[u] == 1) {
                        color[v] = 0;
                        q.push({v, color[v]});
                    } else if (color[u] == 0) {
                        color[v] = 1;
                        q.push({v, color[v]});
                    }
                }
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {

        // 1--->Red
        // 0---Green
        //-1--->colorLess

        vector<int> color(graph.size(), -1);

        for (int i = 0; i < graph.size(); i++) {

            if (color[i] == -1) {
                if (BFS(graph, i, color, 1) ==
                    false) { // iska mtlb hh graph bipartite nhi hh
                    return false;
                }
            }
        }

        return true; // bipartite hh
    }
};
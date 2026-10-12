class Solution {
public:
    bool DFS(vector<vector<int>>& graph, int currNode, vector<int>& color,
             int currColor) {
        color[currNode] = currColor;

        for (int& v : graph[currNode]) {
            if (color[v] == color[currNode]) {
                return false;
            }

            if (color[v] == -1) {
                if (color[currNode] == 1) {
                    color[v] = 0;
                } else if (color[currNode] == 0) {
                    color[v] = 1;
                }

                if (DFS(graph, v, color, color[v]) == false) {
                    return false;
         
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
                if (DFS(graph, i, color, 1) ==
                    false) { // iska mtlb hh graph bipartite nhi hh
                    return false;
                }
            }
        }

        return true; // bipartite hh
    }
};
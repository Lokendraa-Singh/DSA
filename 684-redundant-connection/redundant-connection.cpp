class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x) {
        if (x == parent[x]) {
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void unionFind(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) {
            return;
        }

        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[y_parent] > rank[x_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        parent.resize(edges.size() + 1);
        rank.resize(edges.size() + 1, 0);
        vector<int> ans;
        for (int i = 0; i <= edges.size(); i++) {
            parent[i] = i;
        }

        for (auto& vec : edges) {
            int x = vec[0];
            int y = vec[1];

            if (find(x) == find(y)) {
                ans.clear();
                ans.push_back(x);
                ans.push_back(y);
            } else {
                unionFind(x, y);
            }
        }

        return ans;
    }
};
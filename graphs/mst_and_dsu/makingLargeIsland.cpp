class DS{
    public:
        vector<int> size, parent;

        DS(int n){
            size.resize(n + 1, 1);
            parent.resize(n + 1);
            for (int i = 0; i <= n; i++) parent[i] = i;
        }

        int findPar(int node){
            if (parent[node] == node) return node;
            return parent[node] = findPar(parent[node]);
        }

        void unionBySize(int u, int v){
            int p_u = findPar(u);
            int p_v = findPar(v);
            if (p_u == p_v) return;
            if (size[p_u] < size[p_v]){
                parent[p_u] = p_v;
                size[p_v] += size[p_u];
            } else {
                parent[p_v] = p_u;
                size[p_u] += size[p_v];
            }
        }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DS ds(n*n);

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 1){
                    int node = i * n + j;
                    for (int k = 0; k < 4; k++){
                        int nr = i + dr[k];
                        int nc = j + dc[k];

                        if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] == 1){
                            int adjNode = nr * n + nc;
                            if (ds.findPar(node) != ds.findPar(adjNode))
                                ds.unionBySize(node, adjNode);
                        }
                    }
                }
            }
        }

        int maxSize = INT_MIN;
        for (int i = 0; i < n * n; i++){
            if (ds.findPar(i) == i) maxSize = max(maxSize, ds.size[i]);
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 0){
                    int size = 1;
                    set<int> st;
                    for (int k = 0; k < 4; k++){
                        int nr = i + dr[k];
                        int nc = j + dc[k];

                        if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] == 1){
                            int adjNode = nr * n + nc;
                            int flag = 0;
                            for (auto it : st){
                                if (ds.findPar(adjNode) == ds.findPar(it))
                                    flag = 1;
                            }
                            if (!flag) size += ds.size[ds.findPar(adjNode)];
                            st.insert(adjNode);
                        }
                    }
                    maxSize = max(maxSize, size);
                }
            }
        }
        return maxSize;
    }
};
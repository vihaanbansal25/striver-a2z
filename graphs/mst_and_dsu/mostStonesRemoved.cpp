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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DS ds(n);
        for (int i = 0; i < n; i++){
            int x1 = stones[i][0], y1 = stones[i][1];
            for (int j = i + 1; j < n; j++){
                int x2 = stones[j][0], y2 = stones[j][1];
                if (x1 == x2 || y1 == y2){
                    ds.unionBySize(i, j);
                }
            }
        }

        // instead of this, count number of islands
        int maxi = 0;
        for (int i = 0; i < n; i++){
            if (ds.findPar(i) == i) maxi += ds.size[i] - 1;
        }
        return maxi;
    }
};
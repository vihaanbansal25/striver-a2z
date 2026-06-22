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
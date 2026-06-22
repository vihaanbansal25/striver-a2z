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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, int> mpp;
        int n = accounts.size();
        DS ds(n);
        for (int i = 0; i < n; i++){
            for (int j = 1; j < accounts[i].size(); j++){
                if (mpp.find(accounts[i][j]) != mpp.end()){
                    ds.unionBySize(mpp[accounts[i][j]], i);
                } else {
                    mpp[accounts[i][j]] = i;
                }
            }
        }

        vector<string> merged[n];
        for (auto it : mpp){
            string mail = it.first;
            int account = ds.findPar(it.second);
            merged[account].push_back(mail);
        }

        vector<vector<string>> ans;
        for (int i = 0; i < n; i++){
            if (merged[i].size() != 0){
                sort(merged[i].begin(), merged[i].end());
                vector<string> temp;
                temp.push_back(accounts[i][0]);
                for (auto it : merged[i]){
                    temp.push_back(it);
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
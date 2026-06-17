class Solution{
private:
    bool dfs(int n, vector<int> adj[], vector<int>& vis, vector<int>& pathVis){
        vis[n] = 1;
        pathVis[n] = 1;

        for (auto it : adj[n]){
            if (!vis[it]) {
                if (dfs(it, adj, vis, pathVis)) return true;
            } else if (pathVis[it]){
                return true;
            }
        }

        pathVis[n] = 0;
        return false;
    }
public:
    bool isCyclic(int N, vector<int> adj[]) {
        vector<int> vis(N, 0);
        vector<int> pathVis(N, 0);
        for (int i = 0; i < N; i++){
            if (!vis[i]){
                if (dfs(i, adj, vis, pathVis)) return true;
            }
        }
        return false;
    }
};

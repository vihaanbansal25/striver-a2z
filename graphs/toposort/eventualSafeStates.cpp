class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> adjRev[n];
        vector<int> indeg(n, 0);
        for (int i = 0; i < n; i++){
            // i -> it
            for (auto it : graph[i]){
                adjRev[it].push_back(i);
                indeg[i]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++){
            if (indeg[i] == 0) q.push(i);
        }
        vector<int> safeNodes;
        while (!q.empty()){
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for (auto it : adjRev[node]){
                indeg[it]--;
                if (indeg[it] == 0) q.push(it);
            }
        }

        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};
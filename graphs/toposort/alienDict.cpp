class Solution {
public:
	string findOrder(string dict[], int N, int K) {
        vector<int> adj[K];
		for (int i = 0; i < N - 1; i++){
            for (int j = 0; j < dict[i].size(); j++){
                if (j < dict[i + 1].size()){
                    if (dict[i][j] != dict[i + 1][j]){
                        adj[dict[i][j] - 'a'].push_back(dict[i + 1][j] - 'a');
                        break;
                    }
                }
            }
        }

        vector<int> indeg(K, 0);
        for (int i = 0; i < K; i++){
            for (auto it : adj[i]){
                indeg[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < K; i++){
            if (indeg[i] == 0) q.push(i);
        }
        string ordering = "";
        while (!q.empty()){
            int node = q.front();
            q.pop();
            ordering += (node + 'a');

            for (auto it : adj[node]){
                indeg[it]--;
                if (indeg[it] == 0) q.push(it);
            }
        }

        if (ordering.size() == K) return ordering;
        else return "";
	}
};

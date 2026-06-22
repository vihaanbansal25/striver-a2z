class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        for (int i = 0; i < flights.size(); i++){
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> dist(n, vector<int>(k + 2, 1e9));
        dist[src][k + 1] = 0;
        pq.push({0, src, k + 1});
        while (!pq.empty()){
            auto p = pq.top();
            pq.pop();
            int dis = p[0], node = p[1], stops = p[2];

            if (node == dst) return dis;

            if (stops == 0) continue;

            for (auto it : adj[node]){
                int adjNode = it.first;
                int wt = it.second;

                if (dis + wt < dist[adjNode][stops - 1]){
                    dist[adjNode][stops - 1] = dis + wt;
                    pq.push({dist[adjNode][stops - 1], adjNode, stops - 1});
                }
            }
        }

        return -1;
    }
};
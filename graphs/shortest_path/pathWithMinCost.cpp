class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dif(n, vector<int>(m, 1e9));
        dif[0][0] = 0;
        pq.push({0, {0, 0}});
        int delr[] = {-1, 0, 1, 0};
        int delc[] = {0, -1, 0, 1};
        while (!pq.empty()){
            int diff = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            for (int i = 0; i < 4; i++){
                int nr = r + delr[i];
                int nc = c + delc[i];

                if (nr >= 0 && nc >= 0 && nr < n && nc < m){
                    int d = abs(heights[nr][nc] - heights[r][c]);
                    int effort = max(d, diff);

                    if (effort < dif[nr][nc]){
                        dif[nr][nc] = effort;
                        pq.push({effort, {nr, nc}});
                    }
                }
            }
        }
        return dif[n - 1][m - 1];
    }
};
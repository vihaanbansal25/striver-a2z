class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) return -1;
        int n = grid.size();
        vector<vector<int>> vis(n , vector<int>(n, 0));

        int dr[] = {0, 1, 1, 1, 0, -1, -1, -1};
        int dc[] = {1, 1, 0, -1, -1, -1, 0, 1};
        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 1});
        vis[0][0] = 1;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dis = q.front().second;
            q.pop();

            if (r == n-1 && c == n - 1){
                return dis;
            }

            for (int i = 0; i < 8; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] == 0 && !vis[nr][nc]){
                    vis[nr][nc] = 1;
                    q.push({{nr, nc}, dis + 1});
                }
            }
        }
        return -1;
    }
};
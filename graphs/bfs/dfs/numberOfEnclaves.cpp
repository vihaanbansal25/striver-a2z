class Solution {
private:
    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& vis, int n, int m){
        vis[r][c] = true;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};
        for (int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] == 1 && !vis[nr][nc]){
                dfs(nr, nc, grid, vis, n, m);
            }
        }

    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++){
            if (grid[i][0] == 1 && !vis[i][0]) dfs(i, 0, grid, vis, n, m);
        }
        for (int i = 1; i < m; i++){
            if (grid[0][i] == 1 && !vis[0][i]) dfs(0, i, grid, vis, n, m);
        }
        for (int i = 1; i < n; i++){
            if (grid[i][m - 1] == 1 && !vis[i][m-1]) dfs(i, m - 1, grid, vis, n, m);
        }
        for (int i = 1; i < m - 1; i++){
            if (grid[n-1][i] == 1 && !vis[n-1][i]) dfs(n-1, i, grid, vis, n, m);
        }
        int total = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 1 && !vis[i][j]){
                    total++;
                }
            }
        }
        return total;
    }

    
};
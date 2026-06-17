class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        // vector<vector<int>> res(n, vector<int>(m, 0));
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (mat[i][j] == 0){
                    q.push({{i, j}, 0});
                    vis[i][j] = true;
                }
            }
        }

        int delr[] = {-1, 0, 1, 0};
        int delc[] = {0, -1, 0, 1};
        while (!q.empty()){
            auto p = q.front();
            q.pop();
            int r = p.first.first;
            int c = p.first.second;
            int dist = p.second;

            for (int i = 0; i < 4; i++){
                int nr = r + delr[i];
                int nc = c + delc[i];

                if (nr >= 0 && nc >= 0 && nr < n && nc < m && mat[nr][nc] == 1 && !vis[nr][nc]){
                    q.push({{nr, nc}, dist + 1});
                    vis[nr][nc] = true;
                    mat[nr][nc] = dist + 1;
                }
            }
        }
        return mat;
    }
};
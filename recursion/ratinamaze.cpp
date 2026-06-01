#include<bits/stdc++.h>
using namespace std;
// https://takeuforward.org/plus/dsa/problems/rat-in-a-maze?source=strivers-a2z-dsa-track

class Solution{
    private:
    void solve(int row, int col, vector<string>& res, string& path, vector<vector<int>>& grid,int n){
        if (row == n - 1 && col == n - 1){
            res.push_back(path);
            return;
        }

        grid[row][col] = 0;

        if (row + 1 < n && grid[row + 1][col]){
            path.push_back('D');
            solve(row + 1, col, res, path, grid, n);
            path.pop_back();
        }

        if (col + 1 < n && grid[row][col + 1]){
            path.push_back('R');
            solve(row, col + 1, res, path, grid, n);
            path.pop_back();
        }

        if (row - 1 >= 0 && grid[row - 1][col]){
            path.push_back('U');
            solve(row - 1, col, res, path, grid, n);
            path.pop_back();
        }

        if (col - 1 >= 0 && grid[row][col - 1]){
            path.push_back('L');
            solve(row, col - 1, res, path, grid, n);
            path.pop_back();
        }

        grid[row][col] = 1;
    }
    public:
    vector<string> findPath(vector<vector<int>> &grid) {
        //your code goes here
        int n = grid.size();
        vector<string> res;
        string path;
        if (grid[0][0] == 0){
            return res;
        }
        solve(0, 0, res, path, grid, n);
        return res;
    }
};
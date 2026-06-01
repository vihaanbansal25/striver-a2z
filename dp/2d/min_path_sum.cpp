#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-path-sum/description/

class Solution {
private:
    int sol(int r, int c, vector<vector<int>>& dp, vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        if (r == m - 1 && c == n - 1){
            return grid[m - 1][n - 1];
        }
        if (dp[r][c] != -1) return dp[r][c];

        int down = INT_MAX;
        if (r + 1 < m){
            down = grid[r][c] + sol(r + 1, c, dp, grid);
        }

        int right = INT_MAX;
        if (c + 1 < n){
            right = grid[r][c] + sol(r, c + 1, dp, grid);
        }

        return dp[r][c] = min(down, right);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return sol(0, 0, dp, grid);
    }
};
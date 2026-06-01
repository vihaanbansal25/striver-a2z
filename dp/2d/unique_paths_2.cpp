#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/unique-paths-ii/

class Solution {
private:
    int sol(int r, int c, vector<vector<int>>& dp, vector<vector<int>>& obstacleGrid){
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (r == m - 1 && c == n - 1){
            return 1;
        }
        if (dp[r][c] != -1) return dp[r][c];

        int down = 0;
        if (r + 1 < m && obstacleGrid[r + 1][c] == 0){
            down = sol(r + 1, c, dp, obstacleGrid);
        }

        int right = 0;
        if (c + 1 < n && obstacleGrid[r][c + 1] == 0){
            right = sol(r, c + 1, dp, obstacleGrid);
        }

        return dp[r][c] = down + right;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1) return 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return sol(0, 0, dp, obstacleGrid);
    }
};
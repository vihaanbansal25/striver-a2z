#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/unique-paths/description/

class Solution {
int paths(int r, int c, vector<vector<int>>&dp, int m, int n){
    if (r == m - 1 && c == n - 1){
        return 1;
    }
    if (dp[r][c] != -1) return dp[r][c];

    int left = 0;
    if (r + 1 < m){
        left = paths(r + 1, c, dp, m, n);
    }

    int right = 0;
    if (c + 1 < n){
        right = paths(r, c + 1, dp, m, n);
    }

    return dp[r][c] = left + right;
}
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return paths(0, 0, dp, m, n);
    }
};
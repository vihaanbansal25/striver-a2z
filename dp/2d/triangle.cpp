#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/triangle/description/

class Solution {
private:
    int path(int row, int ind, vector<vector<int>>& dp, vector<vector<int>>& triangle, int n){
        if (row == n){
            return 0;
        }
        if (dp[row][ind] != INT_MAX) return dp[row][ind];

        int left = triangle[row][ind] + path(row + 1, ind, dp, triangle, n);
        int right = triangle[row][ind] + path(row + 1, ind + 1, dp, triangle, n);
        return dp[row][ind] = min(left, right);

    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        // for (int i = 0; i < n; i++){
        //     vector<int> temp(i + 1, -1);
        //     dp[i] = temp;
        // }
        return path(0, 0, dp, triangle, n);
    }
};
#include<bits/sstdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-palindromic-subsequence/description/

class Solution {
private:
    int lcs(int i, int j, vector<vector<int>>& dp, string& s, string& t){
        if (i == 0 || j == 0){
            return 0;
        }
        if (dp[i][j] != -1) return dp[i][j];

        if (s[i - 1] == t[j - 1])
            return dp[i][j] = 1 + lcs(i - 1, j - 1, dp, s, t);
        else
            return dp[i][j] = max(lcs(i - 1, j, dp, s, t), lcs(i, j - 1, dp, s, t));
    }
public:
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return lcs(n, n, dp, s, t);
    }
};
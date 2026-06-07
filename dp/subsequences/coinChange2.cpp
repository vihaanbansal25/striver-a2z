#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/coin-change-ii/
class Solution {
private:
    int numCoins(int ind, int amt, vector<vector<int>>& dp, vector<int>& coins){
        // base case
        if (ind == 0){
            if (amt % coins[0] == 0) return 1;
            else return 0;
        }
        if (dp[ind][amt] != -1) return dp[ind][amt];

        int nt = numCoins(ind - 1, amt, dp, coins);
        int t = 0;
        if (coins[ind] <= amt){
            t = numCoins(ind, amt - coins[ind], dp, coins);
        }
        return dp[ind][amt] = nt + t;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return numCoins(n - 1, amount, dp, coins);
    }
};
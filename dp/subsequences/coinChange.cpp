#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/coin-change/description/

class Solution {
private:
    int numCoins(int ind, int amt, vector<vector<int>>& dp, vector<int>& coins){
        // base case
        if (ind == 0){
            if (amt % coins[0] == 0) return amt / coins[0];
            if (amt == 0) return 0;
            return (int)(1e9);
        }
        if (dp[ind][amt] != -1) return dp[ind][amt];

        int nt = 0 + numCoins(ind - 1, amt, dp, coins);
        int t = INT_MAX;
        if (coins[ind] <= amt){
            t = 1 + numCoins(ind, amt - coins[ind], dp, coins);
        }
        return dp[ind][amt] = min(nt, t);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, (int)(1e9)));
        // int ans = numCoins(n - 1, amount, dp, coins);
        for (int amt = 0; amt <= amount; amt++){
            if (amt % coins[0] == 0) dp[0][amt] = amt / coins[0];
        }

        for (int ind = 1; ind < n; ind++){
            for (int amt = 0; amt <= amount; amt++){
                int nt = 0 + dp[ind - 1][amt];
                int t = INT_MAX;
                if (coins[ind] <= amt){
                    t = 1 + dp[ind][amt - coins[ind]];
                }
                dp[ind][amt] = min(nt, t);
            }
        }
        if (dp[n - 1][amount] >= (int)(1e9)) return -1;
        else return dp[n - 1][amount];
    }
};
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

class Solution {
int solve(int i, int canBuy, int trans, vector<int>& prices, vector<vector<vector<int>>>& dp){
    if (trans == 0) return 0;
    if (i == prices.size()) return 0;
    if (dp[i][canBuy][trans] != -1) return dp[i][canBuy][trans];

    if (canBuy){
        return dp[i][canBuy][trans] = max(solve(i + 1, 0, trans, prices, dp) - prices[i], 
                   solve(i + 1, 1, trans, prices, dp));
    } else {
        return dp[i][canBuy][trans] = max(prices[i] + solve(i + 1, 1, trans - 1, prices, dp),
                    solve(i + 1, 0, trans, prices, dp));
    }
}
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int>(k + 1, -1)));
        return solve(0, 1, k, prices, dp);
    }
};
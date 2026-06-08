// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

class Solution {
int solve(int i, int canBuy, int trans, vector<int>& prices, vector<vector<vector<int>>>& dp){
    if (trans == 2) return 0;
    if (i == prices.size()) return 0;
    if (dp[i][canBuy][trans] != -1) return dp[i][canBuy][trans];

    if (canBuy){
        return dp[i][canBuy][trans] = max(solve(i + 1, 0, trans, prices, dp) - prices[i], 
                   solve(i + 1, 1, trans, prices, dp));
    } else {
        return dp[i][canBuy][trans] = max(prices[i] + solve(i + 1, 1, trans + 1, prices, dp),
                    solve(i + 1, 0, trans, prices, dp));
    }
}
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> after(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));
        
        // return solve(0, 1, 0, prices, dp);
        for (int i = n - 1; i >= 0; i--){
            for (int canBuy = 1; canBuy >= 0; canBuy--){
                for (int trans = 1; trans >= 0; trans--){
                    if (canBuy){
                        curr[canBuy][trans] = max(after[0][trans] - prices[i], 
                                                     after[1][trans]);
                    } else {
                        curr[canBuy][trans] = max(prices[i] + after[1][trans + 1],
                                                after[0][trans]);
                    }
                }
            }
            after = curr;
        }
        return after[1][0];
    }
};
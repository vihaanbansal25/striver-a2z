// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProf = 0;

        int i = 0, j = 0;
        while (j < n)
        {
            if (prices[j] < prices[i]){
                i = j;
            } else {
                maxProf = max(maxProf, prices[j] - prices[i]);
                j++;
            }
        }
        return maxProf;
    }
};
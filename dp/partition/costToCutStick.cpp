// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/

class Solution {
private:
    int cost(int i, int j, vector<int>& cuts, vector<vector<int>>& dp){
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;
        for (int k = i; k <= j; k++){
            int c = (cuts[j + 1] - cuts[i - 1])+ cost(i, k - 1, cuts, dp) + cost(k + 1, j, cuts, dp);
            mini = min(mini, c);
        }
        return dp[i][j] = mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
        return cost(1, c, cuts, dp);
    }
};
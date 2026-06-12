// https://leetcode.com/problems/partition-array-for-maximum-sum/description/

class Solution {
private:
    int solve(int i, vector<int>& arr, int k, int n, vector<int>& dp){
        if (i == n) return 0;
        if (dp[i] != -1) return dp[i];

        int maxsum = INT_MIN;
        int maxel = arr[i];
        for (int p = i; p < i + k && p < n; p++){
            maxel = max(maxel, arr[p]);
            int sum = maxel * (p - i + 1) + solve(p + 1, arr, k, n, dp);
            maxsum = max(sum, maxsum);
        }
        return dp[i] = maxsum;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(), -1);
        return solve(0, arr, k, arr.size(), dp);
    }
};
#include<bits/stdc++.h>
using namespace std;

// https://takeuforward.org/plus/dsa/problems/count-subsets-with-sum-k?source=strivers-a2z-dsa-track

class Solution{
    private:
    int solve(int ind, vector<vector<int>>& dp, int target, vector<int>& arr){
        if (target == 0){
            return 1;
        }
        if (ind == arr.size()){
            return 0;
        }
        if (dp[ind][target] != -1) return dp[ind][target];

        int nt = solve(ind + 1, dp, target, arr);
        int t = 0;
        if (target >= arr[ind]){
            t = solve(ind + 1, dp, target - arr[ind], arr);
        }
        return dp[ind][target] = t + nt;
    }
	public:
	int perfectSum(vector<int>&arr, int K){
        vector<vector<int>> dp(arr.size(), vector<int>(K + 1, -1));
        return solve(0, dp, K, arr);
	}
};  
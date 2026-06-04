#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/partition-equal-subset-sum/

class Solution {
private:
    bool solve(int ind, vector<vector<int>>& dp, int target, vector<int>& arr){
        if (target == 0){
            return true;
        }
        if (ind == arr.size()){
            return false;
        }
        if (dp[ind][target] != -1) return dp[ind][target];

        bool nt = solve(ind + 1, dp, target, arr);
        bool t = false;
        if (target >= arr[ind]){
            t = solve(ind + 1, dp, target - arr[ind], arr);
        }
        return dp[ind][target] = t || nt;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++){
            sum += nums[i];
        }

        if (sum % 2 != 0) return false;
        vector<vector<int>> dp(n, vector<int>(sum / 2 + 1, -1));
        return solve(0, dp, sum / 2, nums);
    }
};
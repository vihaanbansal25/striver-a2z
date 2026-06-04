#include<bits/stdc++.h>
using namespace std;

// https://takeuforward.org/plus/dsa/problems/subset-sum-equals-to-target?source=strivers-a2z-dsa-track

class Solution{
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
    bool isSubsetSum(vector<int>arr, int target){
        vector<vector<int>> dp(arr.size(), vector<int>(target + 1, -1));
        return solve(0, dp, target, arr);
    }
};
#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/house-robber-ii/description/

class Solution {
private:
    int money(int ind, vector<int>& dp, vector<int>& nums, int n){
        if (ind >= n){
            return 0;
        }
        if (dp[ind] != -1) return dp[ind];

        int maxsum = INT_MIN;
        for (int i = ind; i < n; i++){
            int sum = nums[i] + money(i + 2, dp, nums, n);
            maxsum = max(sum, maxsum);
        }
        return dp[ind] = maxsum;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n, -1);
        if (n == 1) return nums[0];
        int s1 = money(0, dp1, nums, n - 1);
        vector<int> dp2(n, -1);
        int s2 = money(1, dp2, nums, n);
        return max(s1, s2);
    }
};
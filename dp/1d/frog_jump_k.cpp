#include <bits/stdc++.h>
using namespace std;

// https://takeuforward.org/plus/dsa/problems/frog-jump-with-k-distances?source=strivers-a2z-dsa-track

class Solution {
int energy(int ind, vector<int>& dp, vector<int>& heights, int k){
    if (ind == 0) return 0;
    if (dp[ind] != -1) return dp[ind];

    int rec = INT_MAX;
    for (int i = 1; i <= k; i++){
        int r = INT_MAX;
        if (ind > i - 1)
            r = energy(ind - i, dp, heights, k) + abs(heights[ind] - heights[ind - i]);
        rec = min(rec, r);
    }

    return dp[ind] = rec;
    
}

public:
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> dp(n, -1);
        return energy(n - 1, dp, heights, k);
    }
};

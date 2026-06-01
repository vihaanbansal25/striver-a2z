#include <bits/stdc++.h>
using namespace std;

// https://takeuforward.org/plus/dsa/problems/frog-jump?source=strivers-a2z-dsa-track
class Solution {
private:
int energy(int n, vector<int>& dp, vector<int>& heights){
    if (n == 2) return abs(heights[0] - heights[2]);
    if (n == 1) return abs(heights[0] - heights[1]);

    if (dp[n] != -1) return dp[n];

    int s1 = abs(heights[n] - heights[n - 1]) + energy(n - 1, dp, heights);
    int s2 = abs(heights[n] - heights[n - 2]) + energy(n - 2, dp, heights);
    return dp[n] = min(s1, s2);
}
public:
    int frogJump(vector<int>& heights) {
        int n = heights.size();
        vector<int> dp(n, -1);
        return energy(n - 1, dp, heights);
    }
};
#include<bits/stdc++.h>
using namespace std;
// https://takeuforward.org/plus/dsa/problems/partition-a-set-into-two-subsets-with-minimum-absolute-sum-difference?source=strivers-a2z-dsa-track

class Solution{

  public:
	int minDifference(vector<int>&arr, int n)  { 
        int sum = 0;
        for (int i = 0; i < n; i++){
            sum += arr[i];
        }

        // tabulation
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
        for (int i = 0; i < n; i++){
            dp[i][0] = true;
        }
        dp[n - 1][arr[n - 1]] = true;

        for (int i = n - 2; i >= 0; i--){
            for (int target = sum; target >= 0; target--){
                bool nt = dp[i + 1][target];
                bool t = false;
                if (target >= arr[i]){
                    t = dp[i + 1][target - arr[i]];
                }
                dp[i][target] = t || nt;
            }
        }

        // check all possible partitions
        int minsum = INT_MAX;
        for (int i = 0; i <= sum / 2; i++){
            if (dp[0][i] == true){
                int s1 = i;
                int s2 = sum - i;
                minsum = min(minsum, abs(s2 - s1));
            }
        }

        return minsum;
	} 
};

// https://leetcode.com/problems/palindrome-partitioning-ii/description/

class Solution {
private:
    bool isPalindrome(int start, int end, string s){
        while (start < end){
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    int solve(int i, int n, string& s, vector<int>& dp){
        if (i == n) return 0;
        if (dp[i] != -1) return dp[i];
        int mini = INT_MAX;
        for (int ind = i; ind < n; ind++){
            if (isPalindrome(i, ind, s)){
                int partitions = 1 + solve(ind + 1, n, s, dp);
                mini = min(mini, partitions);
            }
        }
        return dp[i] = mini;
    }
public:
    int minCut(string s) {
        vector<int> dp(s.size() + 1, -1);
        return solve(0, s.size(), s, dp) - 1;
    }
};
#include <bits/stdc++.h>
using namespace std;
// https://takeuforward.org/plus/dsa/problems/palindrome-partitioning?source=strivers-a2z-dsa-track

class Solution {
private:
bool palindrome(string s){
    int n = s.size();
    int i = 0, j = n - 1;
    while (i < j){
        if (s[i] != s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
void solve(int ind, string s, vector<string>& temp, vector<vector<string>>& ans){
    if (ind == s.size()){
        ans.push_back(temp);
        return;
    }

    for (int len = 1; len <= s.size() - ind; len++){
        string sub = s.substr(ind, len);
        if (palindrome(sub)){
            temp.push_back(sub);
            solve(ind + len, s, temp, ans);
            temp.pop_back();
        }
    }
}
public:
    vector<vector<string>> partition(string s) {
        //your code goes here
        vector<vector<string>> ans;
        vector<string> temp;
        solve(0, s, temp, ans);
        return ans;
    }
};
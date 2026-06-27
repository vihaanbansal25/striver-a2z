class Solution {
  public:
    long long solve(vector<int>& bt) {
        //your code goes here
        sort(bt.begin(), bt.end());
        int n = bt.size();
        long long waitTime = 0;
        long long time = 0;
        for (int i = 0; i < n; i++){
            waitTime += time;
            time += bt[i];
        }
        return waitTime / n;
    }
};
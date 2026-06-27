class Solution{  
private:
    static bool comp(const vector<int>& a, const vector<int>& b){
        return a[2] > b[2];
    }
  public:  
    vector<int> JobScheduling(vector<vector<int>>& Jobs) { 
        //your code goes here
        sort(Jobs.begin(), Jobs.end(), comp);
        int n = Jobs.size();
        int maxProf = 0, jobs = 0;
        int maxDeadline = -1;
        for (int i = 0; i < n; i++){
            maxDeadline = max(maxDeadline, Jobs[i][1]);
        }
        vector<int> days(maxDeadline + 1, -1);
        for (int i = 0; i < n; i++){
            for (int j = Jobs[i][1]; j >= 1; j--){
                if (days[j] == -1){
                    days[j] = Jobs[i][0];
                    jobs++;
                    maxProf += Jobs[i][2];
                    break;
                }
            }
        }
        return {jobs, maxProf};
    } 
};
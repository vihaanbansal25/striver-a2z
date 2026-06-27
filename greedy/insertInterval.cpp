class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size();
        int insertPos = 0;
        while (insertPos < n){
            if (newInterval[0] >= intervals[insertPos][0]) insertPos++;
            else break;
        }

        intervals.insert(intervals.begin() + insertPos, newInterval);

        for (int i = 0; i < intervals.size(); i++){
            if (ans.empty() || intervals[i][0] > ans.back()[1])
                ans.push_back(intervals[i]);
            else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};
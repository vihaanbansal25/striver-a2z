class Solution {
private:
    bool possible(int days, vector<int>& bloomDay, int m, int k){
        int bouq = 0;
        int i = 0;
        int n = bloomDay.size();
        while (i < n){
            if (bloomDay[i] <= days){
                int temp = k;
                while (temp--){
                    if (i >= n) break;
                    if (bloomDay[i] > days)
                        break;
                    i++;
                }

                if (temp == -1) bouq++;
            } else {
                i++;
            }
        }
        return bouq >= m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long) m * k > bloomDay.size()) return -1;
        int ans = -1;
        int s = 1, e = 1e9;
        while (s <= e){
            int mid = (s + e) / 2;
            if (possible(mid, bloomDay, m, k)){
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};
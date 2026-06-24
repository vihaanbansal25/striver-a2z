class Solution {
private:
    bool possible(int k, vector<int>& piles, int h){
        int n = piles.size();
        int time = 0;
        for (int i = 0; i < n; i++){
            time += (piles[i] / k) + (piles[i] % k != 0);
        }
        return time <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1, e = INT_MAX;
        int ans = -1;
        while (s <= e){
            int mid = s + (e - s) / 2;
            if (possible(mid, piles, h)){
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};
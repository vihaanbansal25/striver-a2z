class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int i = 0, j = n - 1;
        int sum = 0;
        while (i < k){
            sum += cardPoints[i];
            i++;
        }

        i = k - 1;
        int maxsum = sum;
        while (i >= 0){
            sum = sum - cardPoints[i] + cardPoints[j];
            maxsum = max(sum, maxsum);
            i--;
            j--;
        }
        return maxsum;
    }
};
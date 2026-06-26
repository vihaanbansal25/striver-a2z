class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int hash[256] = {0};
        int i = 0, j = 0;
        int maxlen = 0;
        while (j < n){
            if (hash[s[j]] == 0){
                maxlen = max(j - i + 1, maxlen);
            } else {
                while (s[i] != s[j]){
                    hash[s[i]] = 0;
                    i++;
                }
                i++;
            }
            hash[s[j]] = 1;
            j++;
        }
        return maxlen;
    }
};
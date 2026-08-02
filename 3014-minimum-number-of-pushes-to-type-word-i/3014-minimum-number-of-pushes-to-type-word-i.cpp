class Solution {
public:
    int minimumPushes(string word) {
        int keyNo = 2;
        int freq[10] = {0};
        int i = 0;
        int n = word.size();
        int ans = 0;
        while(i < n){
            freq[keyNo]++;
            i++;
            ans += freq[keyNo];
            if(keyNo > 8) keyNo = 2;
            else keyNo++;
        }
        return ans;
    }
};
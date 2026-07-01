class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        vector<int> temp(123,0);
        for(int i = 0;i<n;i++){
            char ch = word[i];
            int t = (int)ch;
            temp[t]++;
        }
        int ans=0;
        for(int i = 65;i<=90;i++){
            if((temp[i+32]>0) && temp[i]>0) ans++;
        }
        return ans;
    }
};
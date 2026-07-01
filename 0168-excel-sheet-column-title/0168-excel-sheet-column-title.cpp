class Solution {
public:
    string convertToTitle(int columnNumber) {
        int n = columnNumber-1;
        int r;
        string ans;
        while(n>=0){
        r=n%26;
        n=n/26;
        ans.push_back(char(r+65));
        n=n-1;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
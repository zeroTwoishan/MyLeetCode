class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = t.size();
        int st = s.size();
        char xOr = t[0];
        for(int i = 0;i < n;i++){
            if(i<st) xOr=xOr^(s[i]);
            if(i>0) xOr=xOr^t[i];
        }
        return xOr;
    }
};
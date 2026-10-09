class Solution {
public:
    int minInsertions(string s) {
        int open = 0;
        int close = 0;
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ')' && s[i + 1] == ')'){
                close++;
                i++;
            }
            else if(s[i] == ')'){
                ans++;
                close++;
            }
            else if(s[i] == '(') open++;
            if(close > open){
                ans++;
                open++;
            }
        }
        ans += 2 * (open - close);
        return ans;

    }
};
class Solution {
public:
    string processStr(string s) {
        string ans;
        for(int i = 0;i < s.size();i++){
           switch(s[i]) {
            case '*':
                if(!ans.empty())
                    ans.pop_back();
                break;
            case '#':
                ans += ans;
                break;
            case '%':
                reverse(ans.begin(),ans.end());
                break;
            default:
                ans +=s[i];
            }
        }
        return ans;
    }
};
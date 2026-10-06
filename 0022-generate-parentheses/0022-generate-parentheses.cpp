class Solution {
public:
    void build(vector<string>& ans, string s, int open, int close, int n){
        if(open == n && close == n){
            ans.push_back(s);
            return;
        }
        if(open < n){
            s.push_back('(');
            build(ans, s, open + 1, close, n);
            s.pop_back();
        }
        if(close < open){
            s.push_back(')');
            build(ans, s, open, close + 1, n);
            s.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        build(ans, "", 0, 0, n);
        return ans;
    }
};
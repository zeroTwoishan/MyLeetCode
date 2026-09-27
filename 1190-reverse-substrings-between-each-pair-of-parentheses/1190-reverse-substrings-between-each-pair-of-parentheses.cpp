class Solution {
public:
    string reverseParentheses(string s) {
        string st;
        for(auto c : s){
            if(c == ')'){
                string rev;
                while(st.back() != '('){
                    rev.push_back(st.back());
                    st.pop_back();
                }
                st.pop_back();
                st += rev;
            }
            else{
                st.push_back(c);
            }
        }
        return st;
    }
};
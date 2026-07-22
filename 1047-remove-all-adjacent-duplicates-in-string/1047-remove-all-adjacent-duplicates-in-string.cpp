class Solution {
public:
    string removeDuplicates(string s) {
        vector<char> st;
        int n = s.size();
        st.reserve(n);
        for(int i = 0; i < n; i++){
            if(!st.empty() && st.back() == s[i]) st.pop_back();
            else st.push_back(s[i]);
        }
        string ans = "";
        for(auto& c : st){
            ans += c;
        }
        return ans;
    }
};
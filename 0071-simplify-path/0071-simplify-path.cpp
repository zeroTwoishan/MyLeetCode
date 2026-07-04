class Solution {
public:
    string simplifyPath(string path) {
        vector<string> tokens;
        stringstream ss(path);
        string token;
        while (getline(ss, token, '/')) {
            tokens.push_back(token);
        }
        int n = tokens.size();
        vector<string> st;
        for(auto& c : tokens){
        if(c == "..") {
            if(!st.empty()) st.pop_back();
        }
        else if(c == "." || c == "") continue;
        else st.push_back(c);
        }
        string ans = "";
        for(auto& c : st){
            ans += "/";
            ans += c;
        }
        return ans.empty() ? "/" : ans;
    }
};
/*
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
*/
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        int n = path.size();
        int i = 0;
        
        while (i < n) {
            while (i < n && path[i] == '/') i++;  // skip slashes
            if (i >= n) break;
            
            int start = i;
            while (i < n && path[i] != '/') i++;  // read one segment
            string c = path.substr(start, i - start);
            
            if (c == "..") {
                if (!st.empty()) st.pop_back();
            } else if (c == ".") {
                continue;
            } else {
                st.push_back(c);
            }
        }
        
        string ans;
        for (auto& c : st) {
            ans += "/";
            ans += c;
        }
        return ans.empty() ? "/" : ans;
    }
};
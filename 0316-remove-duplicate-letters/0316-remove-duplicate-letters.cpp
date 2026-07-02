class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        int lastIdx[26] = {0};
        for(int i = 0; i < n; i++){
            lastIdx[s[i] - 'a'] = i;
        }

        bool inStack[26] = {false};
        string st;

        for(int i = 0; i < n; i++){
            char c = s[i];
            if(inStack[c - 'a']) continue;

            while(!st.empty() && c < st.back() && i < lastIdx[st.back() - 'a']){
                inStack[st.back() - 'a'] = false;
                st.pop_back();
            }
            st.push_back(c);
            inStack[c - 'a'] = true;
        }

        return st; 
    }
};
/*
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        string ans = "";
        unordered_map<char,int>mpp(n);
        for(int i = 0; i < n; i++){
            mpp[s[i]] = i;
        }
        stack<char> st;
        unordered_set<char> ss;
        for(int i = 0; i < n; i++){
            if(ss.find(s[i]) == ss.end()){
                while(!st.empty() && s[i] < st.top() && i < mpp[st.top()]){
                    ss.erase(st.top());
                    st.pop();
                }
                st.push(s[i]);
                ss.insert(s[i]);
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
*/
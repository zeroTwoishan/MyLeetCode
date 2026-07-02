class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        int lastInd[26] = {-1};
        for(int i = 0; i < n; i++){
            lastInd[s[i] - 'a'] = i;
        }   
        bool inStack[26] = {false};
        string ans;
        for(int i = 0; i < n; i++){
            if(inStack[s[i] - 'a']) continue;
            while(!ans.empty() && ans.back() > s[i] && i < lastInd[ans.back() - 'a']){
                inStack[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            ans.push_back(s[i]);
            inStack[s[i] - 'a'] = true;
        }
        return ans;
    }
};
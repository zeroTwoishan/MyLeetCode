class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n = strs.size();
        if(n<2) return strs[0];
        string s1=strs[0];
        string s2=strs[n-1];
        string ans="";
        int i = 0;
        while(i<min(s1.size(),s2.size())){
            if(s1[i]==s2[i]) ans+=s1[i];
            else break;
            i++;
        }
        return ans;
    }
};
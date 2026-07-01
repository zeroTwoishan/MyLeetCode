class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        /*sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s==t)return true;
        return false;*/
        int freq[26]={0};
        for(int i = 0;i<s.size();i++){
            freq[s[i]-'a']++;
            freq[t[i]-'a']--;
        }
        for(int c :freq){
            if(c!=0) return false;
        }
        return true;
    }
};
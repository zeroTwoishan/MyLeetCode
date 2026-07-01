class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = p.size(), m = s.size();
        if(m < n) return {};
        vector<int> ans;
        vector<int> freqP(26, 0), freqW(26, 0);
        for(auto c : p) freqP[c - 'a']++;
        for(int i = 0; i < n; i++) freqW[s[i] - 'a']++;
        if(freqP == freqW) ans.push_back(0);
        for(int i = n; i < m; i++){
            freqW[s[i] - 'a']++;          
            freqW[s[i - n] - 'a']--;      
            if(freqP == freqW) ans.push_back(i - n + 1);
        }
        return ans;
    }
};
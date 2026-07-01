/*class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int>mpp;
        int count = 0;
        for(auto c : s) mpp[c]++;
        for(auto c : t){
            if(mpp[c] <= 0) count++;
            else mpp[c]--;
        }
        return count;
    }
};*/
class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.size();
        vector<int> freqs(26,0);
        for(auto ch: s) freqs[ch-'a']++;

        vector<int> freqt(26,0);
        for(auto ch: t) freqt[ch-'a']++;

        int ans = 0;
        for(int i = 0; i < 26; i++){
            ans += abs(freqs[i]-freqt[i]);
        }        
        return ans/2;
    }
};
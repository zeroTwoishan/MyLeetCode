class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char,int> smap, tmap;
        
        for(auto ch : s)      smap[ch]++;
        for(auto ch : target) tmap[ch]++;
        
        int count = INT_MAX;
        for(auto& [c, freq] : tmap) {
            count = min(count, smap[c] / freq);
        }
        return count;
    }
};
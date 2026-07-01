/*class Solution {
public:
    bool anagram(string s_i,string s){
        int freqS[26] = {0};
        for(auto c : s) freqS[c - 'a']++;
        for(auto c : s_i) freqS[c - 'a']--;
        for(auto i : freqS) if(i > 0) return false;
        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        int w = words.size();
        for(int i = w - 1; i >= 1; i--){
            if(words[i].size() != words[i - 1].size()) continue;
            else if(anagram(words[i - 1],words[i])){
                words[i] = std::move(words.back());
                words.pop_back();
            }
        }
        return words;
    }
};*/
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result = {words[0]};

        for(int i = 1; i < words.size(); i++){
            // size check is O(1) — quick reject
            if(words[i].size() != result.back().size()){
                result.push_back(words[i]);
                continue;
            }
            int freq[26] = {0};
            for(char c : words[i])      freq[c - 'a']++;
            for(char c : result.back()) freq[c - 'a']--;

            bool isAnagram = true;
            for(int j = 0; j < 26; j++){
                if(freq[j] != 0){ isAnagram = false; break; }
            }
            if(!isAnagram) result.push_back(words[i]);
        }
        return result;
    }
};
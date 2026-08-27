class Solution {
public:
    string REDO(string& ans, vector<int>& freq) {
        if (ans.empty()) return "";
        int redo = ans.back() - 'a';
        freq[redo]++;
        ans.pop_back();
        redo++;
        bool found = false;
        while (redo < 26) {
            if (freq[redo] > 0) {
                ans += char(redo + 'a');
                freq[redo]--;
                found = true;
                break; 
            }
            redo++;
        }
        if (!found) {
            if (ans.empty())
                return ans;         
            return REDO(ans, freq); 
        }
        return ans;
    }
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26, 0);
        for (auto& c : s)
            freq[c - 'a']++;
        vector<int> freq2(26, 0);
        for (auto& c : target)
            freq2[c - 'a']++;
        if (freq == freq2) {
            if (next_permutation(target.begin(), target.end()))
                return target;
            return "";
        }
        string ans = "";
        for (auto& c : target) {
            int index = (c - 'a');
            if (freq[index] > 0) {
                ans += c;
                freq[index]--;
            } else {
                while (index < 26 && freq[index] == 0)
                    index++;
                if (index == 26) {
                    ans = REDO(ans, freq);
                } else {
                    ans += char(index + 'a');
                    freq[index]--;
                }
                break;
            }
        }
        int index = 0;
        while (index < 26) {
            if (freq[index] > 0){
                ans += char(index + 'a');
                freq[index]--;
            }
            else
                index++;
        }
        return ((ans > target) ? ans : "");
    }
};
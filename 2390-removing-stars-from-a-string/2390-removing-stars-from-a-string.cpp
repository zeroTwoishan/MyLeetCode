class Solution {
public:
    string removeStars(string s) {
        /*string ans;
        for (auto ch : s) {
            if (ch == '*') ans.pop_back();
            else ans.push_back(ch);
        }
        return ans;*/
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') j--;
            else s[j++] = s[i];
        }
        return s.substr(0, j);
    }
};
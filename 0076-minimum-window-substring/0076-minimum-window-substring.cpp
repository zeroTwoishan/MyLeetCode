class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.size() < t.size()) return "";

        vector<int> need(128, 0);
        for (char c : t) need[c]++;

        int required = t.size();
        int i = 0, minLen = INT_MAX, start = 0;

        for (int j = 0; j < s.size(); j++) {
            if (need[s[j]] > 0) required--;
            need[s[j]]--;

            while (required == 0) {
                if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    start = i;
                }
                need[s[i]]++;
                if (need[s[i]] > 0) required++;
                i++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int ones = 0;
        for(auto& c : s) if(c =='1') ones++;
        if(ones < k) return "";

        int start = 0;
        int end;
        ones = 0;
        string ans = "";
        for(end = 0; end < s.size(); end++){
            if(s[end] == '1') ones++;
            while(ones == k){
                while(s[start] == '0') start++;
                string cand = s.substr(start, (end - start + 1));
                if (ans.empty() || cand.size() < ans.size() ||
                    (cand.size() == ans.size() && cand < ans)) {
                    ans = cand;
                }
                ones--;
                start++;
            }
        }
        return ans;
    }
};
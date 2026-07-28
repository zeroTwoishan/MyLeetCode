class Solution {
public:
    string smallestPalindrome(string s) {
        int freq[26] = {0};
        for (auto& c : s) freq[c - 'a']++;
        int n = s.size();
        string half = "";
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            // append all available pairs of this letter
            half.append(freq[i] / 2, char('a' + i));
            if (freq[i] % 2 == 1) mid = char('a' + i); // track odd leftover (only one letter can have this if input is valid)
        }

        string ans = half;
        if (n % 2 == 1) ans += mid;
        string temp = half;
        reverse(temp.begin(), temp.end());
        ans += temp;
        return ans;
    }
};
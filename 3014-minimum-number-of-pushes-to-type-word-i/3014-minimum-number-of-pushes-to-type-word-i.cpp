class Solution {
public:
    int minimumPushes(string word) {
        int freq[26] = {0};
        for (char c : word) freq[c - 'a']++;
        sort(freq, freq + 26, greater<int>());
        
        int ans = 0;
        for (int i = 0; i < 26 && freq[i] > 0; i++) {
            int multiplier = i / 8 + 1;
            ans += freq[i] * multiplier;
        }
        return ans;
    }
};
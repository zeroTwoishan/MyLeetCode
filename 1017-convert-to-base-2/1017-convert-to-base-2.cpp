class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0) return "0";
        string ans;
        ans.reserve(32);
        while (n != 0) {
            int r = n % (-2);
            n = n / (-2);
            if (r < 0) {
                r += 2;
                n += 1;
            }
            ans += char('0' + r);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
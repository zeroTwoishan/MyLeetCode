class Solution {
public:
    int calculate(string s) {
        vector<int> st;
        long long num = 0;
        char op = '+';
        int n = s.size();
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (isdigit(c)) num = num * 10 + (c - '0');
            if ((!isdigit(c) && c != ' ') || i == n - 1) {
                if (op == '+') st.push_back(num);
                else if (op == '-') st.push_back(-num);
                else if (op == '*') st.back() *= num;
                else if (op == '/') st.back() /= num;
                op = c;
                num = 0;
            }
        }
        int ans = 0;
        for (int x : st) ans += x;
        return ans;
    }
};
class Solution {
public:
    string toBinary(int n) {
        string res;
        while (n > 0) {
            res += char('0' + (n % 2));
            n /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    string convertDateToBinary(string date) {
        vector<int> parts;
        int start = 0;
        for (int i = 0; i <= (int)date.size(); i++) {
            if (i == (int)date.size() || date[i] == '-') {
                parts.push_back(stoi(date.substr(start, i - start)));
                start = i + 1;
            }
        }
        return toBinary(parts[0]) + "-" + toBinary(parts[1]) + "-" + toBinary(parts[2]);
    }
};
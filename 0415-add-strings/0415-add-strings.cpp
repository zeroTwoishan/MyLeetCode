class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;

        string ans = "";
        int c = 0;

        while (i >= 0 && j >= 0) {
            int sum = (num1[i] - '0') + (num2[j] - '0') + c;

            if (sum > 9) {
                c = 1;
                sum -= 10;
            }
            else {
                c = 0;
            }

            ans += char(sum + '0');
            i--;
            j--;
        }

        while (i >= 0) {
            int sum = (num1[i] - '0') + c;

            if (sum > 9) {
                c = 1;
                sum -= 10;
            }
            else {
                c = 0;
            }

            ans += char(sum + '0');
            i--;
        }

        while (j >= 0) {
            int sum = (num2[j] - '0') + c;   

            if (sum > 9) {
                c = 1;
                sum -= 10;
            }
            else {
                c = 0;
            }

            ans += char(sum + '0');
            j--;
        }

        if (c == 1) ans += '1';   

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
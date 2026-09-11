class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> seen;
        int n = digits.size();
        for (int i = 0; i < n; i++) {
            if (digits[i] == 0) continue;          // no leading zero
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) continue;
                    if (digits[k] % 2 != 0) continue; // must end even
                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    seen.insert(num);
                }
            }
        }
        return seen.size();
    }
};
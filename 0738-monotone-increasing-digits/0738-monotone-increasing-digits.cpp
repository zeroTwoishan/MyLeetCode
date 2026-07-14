class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string digits = to_string(n);
        int len = digits.size();
        
        // marker: from this index onward, everything should be set to '9'
        int markFrom = len; // len means "no marking needed"
        
        // scan from right to left, comparing each digit to the one before it
        for (int i = len - 1; i > 0; i--) {
            if (digits[i - 1] > digits[i]) {
                // violation: digit at i-1 is bigger than digit at i
                // decrease digits[i-1] by 1, and remember everything from i onward
                // should become '9' to maximize the result
                digits[i - 1]--;
                markFrom = i;
            }
        }
        
        // apply the '9' fill from markFrom to the end
        for (int i = markFrom; i < len; i++) {
            digits[i] = '9';
        }
        
        return stoi(digits);
    }
};
class Solution {
public:
    int countCommas(int n) {
        int num = n;
        int digits = 0;
        while(num > 0){
            digits++;
            num /= 10;
        }
        if(digits < 4) return 0;

        return (((digits - 1) / 3) * (n - 999));
    }
};
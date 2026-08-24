class Solution {
public:
    bool checkDivisibility(int n) {
        int num = n;
        int sum = 0;
        int product = 1;
        while(num > 0){
            int r = num % 10;
            sum += r;
            product *= r;
            num /= 10;
        }
        return ((n % (sum + product)) == 0);
    }
};
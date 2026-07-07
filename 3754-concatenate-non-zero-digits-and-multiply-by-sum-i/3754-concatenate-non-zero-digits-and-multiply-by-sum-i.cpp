class Solution {
public:
    long long sumAndMultiply(int n) {
        long long numr = 0;
        long long sum = 0;
        while(n > 0){
            int r = n % 10;
            if(r != 0){
                numr = r + (numr * 10);
                sum += r;
            }
            n /= 10;
        }
        long long num = 0;
        while(numr > 0){
            int r = numr % 10;
                num = r + (num * 10);
            numr /= 10;
        }
        return num * sum ;
    }
};
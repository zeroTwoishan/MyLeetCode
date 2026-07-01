class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) return INT_MAX;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        long long div = abs((long long)dividend);
        long long d   = abs((long long)divisor);
        bool negative = (dividend < 0) ^ (divisor < 0);

        long long q = 0;
        while (div >= d) {
            long long temp = d, multiple = 1;
            while (div >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            div -= temp;
            q += multiple;
        }

        if (negative) q = -q;
        return (int)q;
    }
};
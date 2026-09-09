class Solution {
public:
    long long countCommas(long long n) {
        auto p = [](int e) {
            long long r = 1;
            while (e--) r *= 10;
            return r;
        };

        long long c1 = p(6) - p(3);       
        long long c2 = (p(9) - p(6)) * 2; 
        long long c3 = (p(12) - p(9)) * 3;
        long long c4 = (p(15) - p(12)) * 4;

        if (n < p(3)) return 0;
        if (n < p(6)) return (n - p(3) + 1);
        if (n < p(9)) return c1 + (n - p(6) + 1) * 2;
        if (n < p(12)) return c1 + c2 + (n - p(9) + 1) * 3;
        if (n < p(15)) return c1 + c2 + c3 + (n - p(12) + 1) * 4;
        if (n == p(15)) return c1 + c2 + c3 + c4 + 5;

        return -1; 
    }
};
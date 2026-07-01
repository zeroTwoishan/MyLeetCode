class Solution {
public:
    int m = 1e9 + 7;
    long long power(long long base,long long p){
        if(p == 0) return 1;
        long long half = power(base,p/2) % m;
        long long result = (half * half) % m;
        if(p % 2 == 1) return (result * base) % m;
        return result;
    }
    int countGoodNumbers(long long n) {
        return (int)(((power(5,(n+1)/2) % m) * (power(4, n/2) % m)) % m);
    }
};
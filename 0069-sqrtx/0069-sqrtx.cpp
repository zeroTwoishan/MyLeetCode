class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;
        
        long long low = 1, high = x;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long sq = mid * mid;
            if (sq == x) return (int)mid;
            if (sq > x) high = mid - 1;
            else low = mid + 1;
        }
        return (int)high;
    }
};
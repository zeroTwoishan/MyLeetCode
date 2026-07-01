class Solution {
public:
    long long C(int n, int r) {
        r = min(r, n - r); 
        long long ans = 1;
        for (int i = 0; i < r; i++) {
            ans = ans * (n - i) / (i + 1);
        }
        return ans;
    }
    int uniquePaths(int m, int n) {
        return C(m + n - 2, n - 1);
    }
};
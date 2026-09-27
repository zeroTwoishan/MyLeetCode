class Solution {
public:
    int numberOfChild(int n, int k) {
        int period = 2 * (n - 1);
        int r = k % period;
        return r < n ? r : period - r;
    }
};
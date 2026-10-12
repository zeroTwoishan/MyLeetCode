class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int M = 1e9 + 7;
        int cnt[32] = {};
        for (int x : nums)
            for (int b = 0; b < 32; b++)
                if (x & (1 << b)) cnt[b]++;

        long long ans = 0;
        while (k--) {
            long long cur = 0;
            for (int b = 0; b < 32; b++) {
                if (cnt[b] > 0) {
                    cur = (cur | (1LL << b));
                    cnt[b]--;
                }
            }
            ans = (ans + (cur % M) * (cur % M)) % M;
        }
        return ans;
    }
};
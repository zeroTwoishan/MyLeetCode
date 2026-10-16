class Solution {
    static const long long MOD = 1e9 + 7;
    vector<long long> s1, s2, lz;

    void apply(int o, int l, int r, long long v) {
        long long len = r - l + 1;
        s2[o] = (s2[o] + 2 * v % MOD * s1[o] + v * v % MOD * len) % MOD;
        s1[o] = (s1[o] + v * len) % MOD;
        lz[o] = (lz[o] + v) % MOD;
    }

    void push(int o, int l, int r) {
        if (lz[o]) {
            int m = (l + r) / 2;
            apply(o * 2, l, m, lz[o]);
            apply(o * 2 + 1, m + 1, r, lz[o]);
            lz[o] = 0;
        }
    }

    void update(int o, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) { apply(o, l, r, 1); return; }
        push(o, l, r);
        int m = (l + r) / 2;
        if (ql <= m) update(o * 2, l, m, ql, qr);
        if (qr > m) update(o * 2 + 1, m + 1, r, ql, qr);
        s1[o] = (s1[o * 2] + s1[o * 2 + 1]) % MOD;
        s2[o] = (s2[o * 2] + s2[o * 2 + 1]) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        s1.assign(4 * n, 0);
        s2.assign(4 * n, 0);
        lz.assign(4 * n, 0);
        unordered_map<int, int> last;
        long long ans = 0;
        for (int j = 0; j < n; j++) {
            int p = last.count(nums[j]) ? last[nums[j]] : -1;
            update(1, 0, n - 1, p + 1, j);   // f[i] += 1 for i in (p, j]
            ans = (ans + s2[1]) % MOD;       // sum of f[i]^2 for subarrays ending at j
            last[nums[j]] = j;
        }
        return ans;
    }
};
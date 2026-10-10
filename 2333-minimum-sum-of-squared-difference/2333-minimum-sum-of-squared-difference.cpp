class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = (long long)k1 + k2;
        int n = nums1.size();
        vector<int> gaps(n);
        for (int i = 0; i < n; i++) gaps[i] = abs(nums1[i] - nums2[i]);

        int high = *max_element(gaps.begin(), gaps.end());
        vector<long long> t(high + 1, 0);
        for (int g : gaps) t[g]++;

        for (int i = high; i > 0 && k > 0; i--) {
            long long m = t[i];
            if (m <= k) {          // lower every element at height i
                t[i - 1] += m;
                t[i] = 0;
                k -= m;
            } else {               // only k of them can be lowered
                t[i - 1] += k;
                t[i] -= k;
                k = 0;
            }
        }

        long long ans = 0;
        for (long long i = 1; i <= high; i++) ans += t[i] * i * i;
        return ans;
    }
};
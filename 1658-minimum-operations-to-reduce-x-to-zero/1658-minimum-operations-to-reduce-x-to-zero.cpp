class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        long long target = total - x;
        if (target < 0) return -1;

        int n = nums.size(), best = -1, l = 0;
        long long sum = 0;
        for (int r = 0; r < n; r++) {
            sum += nums[r];
            while (sum > target) sum -= nums[l++];
            if (sum == target) best = max(best, r - l + 1);
        }
        return best == -1 ? -1 : n - best;
    }
};
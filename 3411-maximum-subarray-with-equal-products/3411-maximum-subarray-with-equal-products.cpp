class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxx = 1;
        for (int i = 0; i < n; i++) {
            unsigned long long prod = 1;
            int gcdd = 0;
            unsigned long long lcmm = 1;
            for (int j = i; j < n; j++) {
                prod *= nums[j];
                gcdd = gcd(gcdd, nums[j]);
                lcmm = lcm(lcmm, (unsigned long long)nums[j]);
                if (prod == (unsigned long long)gcdd * lcmm) maxx = max(maxx, j - i + 1);
            }
        }
        return maxx;
    }
};
class Solution {
public:
    static bool rule(int a, int b){
        return abs(a) < abs(b);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return (long long)nums[0] * nums[0];

        sort(nums.begin(), nums.end(), rule);

        int even = 0;                                // + slots: 0, 2, 4, ...
        int odd  = (n % 2 == 0) ? n - 1 : n - 2;     // largest odd index (a - slot)

        while(even < odd){
            if(abs(nums[even]) < abs(nums[odd])) swap(nums[even], nums[odd]);
            even += 2;
            odd -= 2;
        }

        long long score = 0;
        for(int i = 0; i < n; i++){
            long long term = (long long)nums[i] * nums[i];
            if(i % 2 == 0) score += term;
            else score -= term;
        }
        return score;
    }
};
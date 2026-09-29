class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total_sum = 0;

        int normal_max = INT_MIN, sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            total_sum += nums[i];
            if (sum < 0) sum = 0;
            sum += nums[i];
            normal_max = max(normal_max, sum);
        }

        if (normal_max < 0) return normal_max;
        int max_sum = INT_MIN;
        sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (sum < 0) sum = 0;
            sum += -nums[i];
            max_sum = max(max_sum, sum);
        }

        return max(normal_max, total_sum + max_sum);
    }
};
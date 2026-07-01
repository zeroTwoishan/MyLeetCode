class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        long long maxi = LLONG_MIN;
        long long max1 = LLONG_MIN;
        long long max2 = LLONG_MIN;

        for (int i = 0; i < n; i++)
            if (nums[i] > maxi) maxi = nums[i];

        for (int i = 0; i < n; i++)
            if (nums[i] > max1 && nums[i] != maxi) max1 = nums[i];

        for (int i = 0; i < n; i++)
            if (nums[i] > max2 && nums[i] != maxi && nums[i] != max1) max2 = nums[i];

        return (max2 == LLONG_MIN) ? (int)maxi : (int)max2;
    }
};
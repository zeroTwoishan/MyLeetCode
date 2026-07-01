class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = accumulate(nums.begin(),nums.begin() + k,0.0);
        double maxAvg = sum / k;
        int i = 0;
        int j = k;
        while(j < nums.size()){
            sum += nums[j];
            sum -= nums[i];
            maxAvg = max(maxAvg, sum / k);
            j++;
            i++;
        }
        return maxAvg;
    }
};
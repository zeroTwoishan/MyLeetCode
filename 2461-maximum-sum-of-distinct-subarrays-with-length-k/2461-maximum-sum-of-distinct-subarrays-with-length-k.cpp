class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        long long sumMax = 0, sum = 0;
        int i = 0, j = 0, len = 0;
        while(j < (int)nums.size()){
            if(!mpp.count(nums[j])){
                mpp[nums[j]]++;
                sum += nums[j];
                j++;
                len++;
                if(len == k){                    
                    sumMax = max(sumMax, sum);
                    sum -= nums[i];
                    mpp.erase(nums[i]);
                    i++;
                    len--;
                }
            } else {
                sum -= nums[i];                  
                mpp.erase(nums[i]);
                i++;
                len--;
            }
        }
        return sumMax;
    }
};
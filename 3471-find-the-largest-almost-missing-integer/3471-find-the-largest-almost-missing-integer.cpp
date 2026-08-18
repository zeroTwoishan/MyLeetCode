class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int mpp[51] = {0};
        if(k == 1){
            int maxx = -1;
            for(auto num : nums) mpp[num]++;
            for(auto num : nums){
                if(mpp[num] < 2) maxx = max(maxx,num);
            }
            return maxx;
        }
        else if(k == nums.size()) return *max_element(nums.begin(),nums.end());
        else{
            for(auto num : nums) mpp[num]++;
            if(mpp[nums[0]] < 2 && (nums[0] > nums[nums.size() - 1]|| mpp[nums[nums.size() - 1]] > 1)) return nums[0];
            else if(mpp[nums[nums.size() - 1]] < 2 && (nums[0] < nums[nums.size() - 1] || mpp[nums[0]] > 1)) return nums[nums.size() - 1];
        }
        return -1;
    }
};
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int sum = 0;
        int n = nums.size();
        //int ans_st=0 , start=0 , ans_ed=0;
        for(int i = 0;i<n;i++){
            //if(sum == 0) start = i;
            sum+=nums[i];
            if(sum>maxi){
                maxi = sum;
                // ans_st = start;
                // ans_ed = i;
            }
            if(sum<0) sum = 0;
        }
        return maxi;
    }
};
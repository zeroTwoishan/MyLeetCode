class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int leftsum = 0;
        int sum = accumulate(nums.begin(),nums.end(),0);
        int rightsum = 0;
        vector<int> ans;
        for(int i = 0;i < nums.size(); i++){
            if(i==0){
                leftsum = 0;
                rightsum = sum - nums[i];
            }
            else{
                leftsum += nums[i-1];
                rightsum -= nums[i];
            }
            ans.push_back(abs(leftsum - rightsum));
        }
        return ans;
    }
};
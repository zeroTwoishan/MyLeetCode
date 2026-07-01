class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] % 2 == 0) nums[i] = 0;
            else nums[i] = 1;
        }
        int i = 0;
        int j = n - 1;
        while(i<=j){
            if(nums[i] == nums[j] && nums[i] == 0) i++; 
            else if (nums[i] == nums[j] && nums[i] == 1) j--;
            else if (nums[i] > nums[j]){
                nums[i] = nums[i] + nums[j] - (nums[j] = nums[i]);
                i++;
                j--;
            }
            else{
                i++;
                j--;
            }
        }
        return nums;
    }
};
class Solution {
public:
    int firstPosition(vector<int>&nums,int target){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = -1;
        while(low<=high){
            int mid = low + (high - low) / 2;
            if(target == nums[mid]){
                ans=mid;
                high = mid-1;
            }
            else if(target>nums[mid]) low=mid+1;
            else high = mid-1;
        }
        return ans;
    }
    int secondPosition(vector<int>&nums,int target){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = -1;
        while(low<=high){
            int mid = low + (high - low) / 2;
            if(target == nums[mid]){ 
            ans= mid;
            low = mid+1;
            }
            else if(target>nums[mid]) low=mid+1;
            else high = mid-1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {       
        return {firstPosition(nums,target),secondPosition(nums,target)};
    }
};
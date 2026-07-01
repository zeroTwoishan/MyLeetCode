class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid = low + (high - low)/2 ;
            int last = 0;
            int count = 1;
            for(int i = 0;i < nums.size();i++){
                if(last + nums[i] <= mid){
                last+=nums[i];
                }
                else{
                count++;
                last = nums[i];
                }
            }
            if(count > k) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};
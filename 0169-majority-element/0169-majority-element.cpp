class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int n = nums.size();
       /*map<int,int>mpp;
        for(int i = 0;i<n;i++){
            mpp[nums[i]]++;
        }
        
        for(auto it : mpp){
            if(it.second >= (float)n/2) return it.first;
        }
        return -1;*/
        int maj=nums[0];
        int count = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==maj) count++;
            else count--;
            if(count==0){
                maj=nums[i+1];
            }
        }
        return maj;
    }
};
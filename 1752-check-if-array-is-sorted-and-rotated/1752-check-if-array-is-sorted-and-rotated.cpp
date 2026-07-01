class Solution {
public:
    bool check(vector<int>& nums) {
        int len=nums.size();  
        if(len==0 || len==1) return true;
       int count=0;      
        for(int i=0;i<len-1;i++){
            if(nums[i]>nums[i+1]) count+=1 ;
        }
        if(nums[0]<nums[len-1]) count++;
        if(count<=1)return true;
        return false;     
    }
};
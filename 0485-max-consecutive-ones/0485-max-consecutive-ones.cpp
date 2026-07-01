class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
       int max=0;
       int count=0;
       int n = nums.size();
       for(int i = 0;i<n;i++){
           if(nums[i]==0) count=0; 
           else{
           count++;
           if(max<count) max=count;
           }
       } 
       return max;
    }
};
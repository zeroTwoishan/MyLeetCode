class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp=nums;
        int pI=0,nI=1;
        for(int i =0;i<n;i++){
            if(temp[i]<0){
                nums[nI]=temp[i];
                nI+=2;
            }else{
                nums[pI]=temp[i];
                pI+=2;
            }
        }
        return nums;
    }
};
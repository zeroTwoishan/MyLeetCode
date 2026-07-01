class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       /* Brute Force
       set<int> s;
        for(auto it:nums){
            s.insert(it);
        }
        int index=0;
        for(auto it:s){
            nums[index]=it;
            index++;
        }
        return index;*/
        int len=nums.size();
        int j;
        int i=0;
        for(j=1;j<len;j++){
            if(nums[i]!=nums[j]){
                nums[i+1]=nums[j];
                i++;
            }
            
        }
        return i+1;

    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /* Brute
        int n = nums.size();
        int i=0,j=1;
        while(i<=n){
            for(j=i+1;j<=n;j++){
                if(nums[i]==target-nums[j]){
                    return{i,j};
                }
            }
            i++;
        }
        return{-1};*/
        
        /* Better */
        int n = nums.size();
        map<int,int>mpp;
        for(int i=0;i<=n;i++){
            int num = nums[i];
            int more = target-num;
            if(mpp.find(more)!=mpp.end()){
                return {mpp[more],i};
            }
            mpp[num] = i;
        }
        return{-1,-1};
    }
};
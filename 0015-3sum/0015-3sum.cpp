class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            //for(int j = i+1;j<n;j++){
                //if(j!=(i+1) && nums[j]==nums[j-1]) continue;
                int k=n-1,j=i+1;
                while(j<k){
                    int sum=nums[k]+nums[i]+nums[j];
                    if(sum==0){
                        vector<int>temp ={nums[i],nums[j],nums[k]};
                        ans.push_back(temp);
                        j++;
                        k--;
                        while(j<k && nums[j]==nums[j-1]) j++;
                        while(j<k && nums[k]==nums[k+1]) k--;
                    }
                    else if(sum<0){
                        j++;
                    }
                    else k--;
                }
            //}
        }
        return ans;
    }
};
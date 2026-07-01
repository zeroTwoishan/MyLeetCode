class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    map<int,int> mpp;
    int sum=0;
    int n=nums.size();
    int count=0;
    int res;
    mpp[sum]++;
    for (int i = 0; i < n; i++){
        sum+=nums[i];
        res=sum-k;
        count+=mpp[res];
        mpp[sum]++;
    }
    return count;  
    }
};
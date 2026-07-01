class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        /*
        long long t = (n*(n+1))/2;
        long long sum = accumulate(nums.begin(),nums.end(),0);
        return (int)(t-sum);
        */
        int xorAll = n;
        for(int i = 0;i < n;i++){
            xorAll = xorAll ^ i;
            xorAll = xorAll ^ nums[i];
        }
        return xorAll;        
    }
};
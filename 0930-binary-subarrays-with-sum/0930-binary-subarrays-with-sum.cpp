class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> mpp;
        mpp[0] = 1;         
        int sum = 0, ans = 0;

        for (int x : nums) {
            sum += x;
            if (mpp.contains(sum - goal))
                ans += mpp[sum - goal];
            mpp[sum]++;
        }
        return ans;
    }
};
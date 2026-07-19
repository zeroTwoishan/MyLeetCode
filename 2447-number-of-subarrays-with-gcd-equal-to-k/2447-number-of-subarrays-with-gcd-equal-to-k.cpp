class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for(int j = 0; j < n; j++){
            int gcdd = 0;
            for(int i = j; i < n; i++){
                gcdd = gcd(gcdd,nums[i]);
                if(gcdd == k) ans++;
                else if(gcdd < k) break;
            }
        }
        return ans;
    }
};
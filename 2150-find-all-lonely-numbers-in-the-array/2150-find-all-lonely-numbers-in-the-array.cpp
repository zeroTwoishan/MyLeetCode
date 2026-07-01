class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return nums;
        vector<int> ans = {};
        /*
        unordered_map<int,int> mpp;
        for(int i = 0; i < n; i++) mpp[nums[i]]++;
        for(int i = 0; i < n; i++) if(!(mpp.count(nums[i] - 1) || mpp.count(nums[i] + 1) || mpp[nums[i]] > 1)) ans.push_back(nums[i]);
        */
        sort(nums.begin(),nums.end());
        for(int i = 0; i < n; i++){
            bool noDup = (i == 0 || nums[i] != nums[i - 1]);
            bool noLeft = (i == 0 || (nums[i] - nums[i - 1] > 1));
            bool noRight = (i == n - 1 || (nums[i + 1] - nums[i] > 1));
            if(noDup && noLeft && noRight) ans.push_back(nums[i]);
        }
        return ans;
    }
};
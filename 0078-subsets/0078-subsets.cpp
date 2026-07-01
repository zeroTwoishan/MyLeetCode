class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int sub = 1 << n;
        vector<vector<int>> ans(sub);
        for(int i = 0; i < sub; i++){
            vector<int> temp;
            for(int j = 0; j < n; j++){
                if((i & (1 << j)) != 0) temp.push_back(nums[j]);
            }
            ans[i] = temp;
        }
        return ans;
    }
};
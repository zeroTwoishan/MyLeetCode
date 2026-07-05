class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> ss;
        int n = nums.size();
        int sub = 1 << n;
        for(int i = 0; i < sub; i++){
            vector<int> temp;
            for(int j = 0; j < n; j++){
                if((i & (1 << j)) != 0) temp.push_back(nums[j]);
            }
            ss.insert(temp);
        }
        vector<vector<int>> ans(ss.begin(),ss.end());
        return ans;
    }
};
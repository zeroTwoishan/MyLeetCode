class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        if(nums.empty()) return {};
        
        int n = nums.size();

        vector<bool> present(n + 1, false);

        for(auto num : nums) present[num] = true;

        vector<int> ans;

        for(int i = 1; i < n + 1; i++) if(!present[i]) ans.push_back(i);

        return ans;
    }
};
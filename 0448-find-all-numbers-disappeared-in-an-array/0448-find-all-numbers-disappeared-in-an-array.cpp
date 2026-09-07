class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int idx = abs(nums[i]) - 1;   // target index for this value
            if (nums[idx] > 0) {
                nums[idx] = -nums[idx];   // mark as "seen"
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) ans.push_back(i + 1);
        }

        return ans;
    }
};
/*
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
*/
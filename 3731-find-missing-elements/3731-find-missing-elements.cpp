class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        if (nums.empty()) return {};
        int low = INT_MAX;
        int high = INT_MIN;
        for(auto& num : nums){
            if(num < low) low = num;
            if(num > high) high = num;
        }
        int size = high - low + 1;
        vector<bool> noPresent(size, false);
        for(auto& num : nums) noPresent[num - low] = true;
        vector<int> ans;
        for(int i = 0; i < (high - low + 1); i++) if(noPresent[i] == false) ans.push_back(i + low);
        return ans;
    }
};
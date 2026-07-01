class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;
        for(int j = 0; j < nums.size(); j++){
            if(window.count(nums[j])) return true;  
            window.insert(nums[j]);
            if(window.size() > k)                  
                window.erase(nums[j - k]);
        }
        return false;
    }
};
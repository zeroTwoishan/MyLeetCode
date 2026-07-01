class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n =nums.size();
        unordered_set<int> sett;
        for(int i = 0;i<n;i++){
            if(sett.count(nums[i])){
                return true;
            }
            sett.insert(nums[i]);
        }
        return false;
    }
};
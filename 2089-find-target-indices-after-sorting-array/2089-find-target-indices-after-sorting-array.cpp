class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int less = 0, equal = 0;
        for(auto& n : nums){
            if(n < target) less++;
            else if(n == target) equal++;
        }
        if(equal == 0) return {};
        vector<int> ans;
        ans.reserve(equal);
        for(int i = 0; i < equal; i++){
            ans.push_back(less + i);
        }
        return ans;
    }
};
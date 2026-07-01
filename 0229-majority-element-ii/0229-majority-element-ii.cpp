class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>mpp;
        vector<int>ans;
        int n = nums.size();
        for(int i =0;i<n;i++){
            mpp[nums[i]]++;
        }
        for(auto& p : mpp){
        if(p.second > n/3)
        ans.push_back(p.first);
}
        return ans;

    }
};
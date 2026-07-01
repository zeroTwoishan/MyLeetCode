class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        string s ="";
        vector<int> ans;
        int num = nums.size();
        for(int i = 0;i<num;i++){
            s+=to_string(nums[i]);
        }
        int n  = s.size();
        for(int i = 0;i<n;i++){
            ans.push_back(s[i]-'0');
        }
        return ans;
    }
};
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int ans = INT_MIN;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(nums[i] == INT_MAX) continue;
            int index = i;
            int curr = 0;
            while(nums[index] != INT_MAX){
                int temp = index;
                index = nums[index];
                nums[temp] = INT_MAX;
                curr++;
            }
            ans = max(ans,curr);
        }
        return ans;
    }
};
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int,int>> arr;
        arr.reserve(n);
        int curr = -1;
        for(int i = 0; i < n; i++){
            curr = max(curr,nums[i]);
            arr.push_back({curr,0});
        }
        curr = INT_MAX;
        for(int i = n - 1; i >= 0; i--){
            curr = min(curr,nums[i]);
            arr[i].second = curr;
        }
        for(int i = 0; i < n; i++)
            if((arr[i].first - arr[i].second) <= k) return i;

        return -1;
    }
};
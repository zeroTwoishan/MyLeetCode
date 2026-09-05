class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> arr(n);         
        int curr = INT_MAX;
        for (int i = n - 1; i >= 0; i--) {
            curr = min(curr, nums[i]);
            arr[i] = curr;         
        }

        int maxx = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxx = max(maxx, nums[i]); 
            if (maxx - arr[i] <= k) return i;
        }

        return -1;
    }
};